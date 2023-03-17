#include <cmath>
#include <vector>
#include "DoubleFilter.h"

DoubleFilter::DoubleFilter(sc_module_name n) : sc_module(n) {
  SC_THREAD(do_filter);
  sensitive << i_clk.pos();
  dont_initialize();
  reset_signal_is(i_rst, false);
}




void DoubleFilter::do_filter() {
  while (true) {

    // Median filter
    std::vector<int> reds, greens, blues;
    int center_r, center_g, center_b;
    int sum_r = 0;
    int sum_g = 0;
    int sum_b = 0;


    for (unsigned int v = 0; v < MASK_Y; ++v) {
      for (unsigned int u = 0; u < MASK_X; ++u) {
        reds.push_back(i_r.read());
        greens.push_back(i_g.read());
        blues.push_back(i_b.read());
      }

    center_r = reds[reds.size() / 2];
    center_g = greens[greens.size() / 2];
    center_b = blues[blues.size() / 2];

    std::sort(reds.begin(), reds.end());
    std::sort(greens.begin(), greens.end());
    std::sort(blues.begin(), blues.end());
    }
    
    // Mean filter
    for (auto x: reds) {
        sum_r += x;
    }
    for (auto x: greens) {
        sum_g += x;
    }
    for (auto x: blues) {
        sum_b += x;
    }
    o_r.write(round((sum_r - center_r + 2 * reds[reds.size() / 2]) / 10));
    o_g.write(round((sum_g - center_g + 2 * greens[greens.size() / 2]) / 10));
    o_b.write(round((sum_b - center_b + 2 * blues[blues.size() / 2]) / 10));

    // o_r.write(reds[reds.size() / 2]);
    // o_g.write(greens[greens.size() / 2]);
    // o_b.write(blues[blues.size() / 2]);

    reds.clear();
    greens.clear();
    blues.clear();


    wait(10); //emulate module delay
  }
}
