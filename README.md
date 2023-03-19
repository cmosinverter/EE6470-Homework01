## Median and Mean filter

This is the project that implements ee6470 homework 1, (40 pt) Median and mean filters with FIFO channels

## Usage
1. Clone the file
```properties
git clone https://github.com/cmosinverter/ee6470_hw1.git
```
2. Open Windows Powershell
```properties
winpty docker run -h ubuntu --rm --cap-add SYS_ADMIN -it -e LOCAL_USER_ID=$(id -u $USER) -v $HOME:/home/user ee6470/ubuntu-ee6470:latest
```
```properties
/usr/local/bin/entrypoint.sh
```
```properties
cd ~/ee6470/ee6470_hw1/build
```
```properties
source bashrc
```
3. Run the program
```properties
make run
```