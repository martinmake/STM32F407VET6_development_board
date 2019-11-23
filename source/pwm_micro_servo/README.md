# pwm_micro_servo

PWM frequency for driving micro servo has to be `50Hz` (`20ms` == `20 000ms`).

We can change the *PWM pulse width* to transmit desired *angle* or *rotation direction* (depends on micro servo controller).

Using `ADC1` in polling mode to determine potentiometer rotation.

Using `TIM4` `CH1` to generate PWM signal.

[<img src="https://asciinema.org/a/283150.png" width=50%>](https://asciinema.org/a/283150)

[<img src="https://raw.githubusercontent.com/martinmake/STM32F407VET6_development_board/master/resources/pwm_micro_servo/example_video_thumbnail.jpg" width=50%>](https://raw.githubusercontent.com/martinmake/STM32F407VET6_development_board/master/resources/pwm_micro_servo/example_video.mp4)

<img src="https://raw.githubusercontent.com/martinmake/STM32F407VET6_development_board/master/resources/pwm_micro_servo/stm32cubemx.png">
