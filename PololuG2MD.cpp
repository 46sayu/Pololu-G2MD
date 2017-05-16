/*
 * PololuG2MD.cpp
 *
 *  Created on: Apr 8, 2017
 *      Author: 46sayu
 */

#include "PololuG2MD.hpp"

PololuG2MD::PololuG2MD(TIM_HandleTypeDef *PWM_htim,
                       uint32_t PWM_Channel,
                       GPIO_TypeDef *DIR_GPIOx,
                       uint16_t DIR_GPIO_Pin)

    : htim(PWM_htim),
      pwmChannel(PWM_Channel),
      dirGPIOx(DIR_GPIOx),
      dirPin(DIR_GPIO_Pin),
      motorSpeed(0.0)
{
    // TODO Auto-generated constructor stub

}

PololuG2MD::~PololuG2MD() {
    // TODO Auto-generated destructor stub
}

void PololuG2MD::init(void) {
    pwmMax = __HAL_TIM_GET_AUTORELOAD(htim);

    HAL_TIM_PWM_Start(htim, pwmChannel);
    setMotorSpeed(motorSpeed);
}

void PololuG2MD::setMotorSpeed(float speed) {
    /* speed is over! */
    if (ABS(speed) > 100.0) {
        if (speed >= 0.0) speed = 100.0;
        else              speed = -100.0;
    }

    if (speed >= 0.0) {
        /* Forward */
        HAL_GPIO_WritePin(dirGPIOx, dirPin, GPIO_PIN_SET);
        pwmCompare = (uint32_t)(speed * pwmMax / 100.0);
    } else {
        /* Reverse */
        HAL_GPIO_WritePin(dirGPIOx, dirPin, GPIO_PIN_RESET);
        pwmCompare = (uint32_t)(-speed * pwmMax / 100.0);
    }

    /* set PWM compare */
    __HAL_TIM_SET_COMPARE(htim, pwmChannel, pwmCompare);

    /* update motor speed */
    motorSpeed = speed;
}

float PololuG2MD::getMotorSpeed(void) const {
    return motorSpeed;
}
