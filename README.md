# STM32F407VET6_black_pill

## Board

![IMAGE OF THE BOARD](https://raw.githubusercontent.com/martinmake/STM32F407VET6_black_pill/master/resources/STM32F407VET6_DEV_BOARD.jpg)

* TFT 320RGBx240 display (16bit ILI9341)
* NRF24L01
* UART
* RTC
* SD card
* buttons
* SWD
* USB
* GPIO
* other

## How to compile

### The easy way

``` console
$ make
```

### The advanced way

``` console
$ mkdir build
$ cd build
$ cmake .. <CMAKE_OPTIONS>
$ make
```

## Useful make targets

### Upload `.bin` file

``` console
$ make upload_<project_name>
```

### Connect over serial

``` console
$ make connection_over_serial
```

### Connect over virtual COM port

``` console
$ make connection_over_virtual_com_port
```
