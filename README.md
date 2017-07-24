# Pololu-G2MD
The STM32 library using HAL of [Pololu G2 High-Power Motor Driver](https://www.pololu.com/product/2994).

## How to use

#### Software

##### Initialize
Set the TIM peripheral and GPIO pin to use as constructor arguments.

```cpp
// Example
PololuG2MD md(&htim1, TIM_CHANNEL_1, GPIOB, GPIO_PIN_10);
```

Please call the function `init()`, after the initialization of TIM and GPIO peripherals.

##### Operate
void setMotorSpeed(float speed)
 - Setting motor's speed
 - `speed` : value of motor speed. (-100.0 to 100.0)

float getMotorSpeed(void)
 - Get the speed set by function `setMotorSpeed()`

#### Hardware
Connect signals to the Motor Drier's Pins as below:

```
  MCU       MD
-------     ---
DIR pin --- DIR
PWM pin --- PWM
```
