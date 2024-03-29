# STM32F407VET6_development_board

## Board

![IMAGE OF THE BOARD](https://raw.githubusercontent.com/martinmake/STM32F407VET6_development_board/master/resources/STM32F407VET6_development_board.jpg)

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
$ cmake .. [OPTIONS]
$ make
```

## Useful make targets

### Upload `.bin` file

``` console
$ make upload_<project_name>
```

### Connect over serial port

``` console
$ make connection_over_serial_port
```

### Connect over virtual COM port

``` console
$ make connection_over_virtual_com_port
```

### List all targets

``` console
$ make help
```
