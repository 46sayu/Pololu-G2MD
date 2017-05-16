/*
 * PololuG2MD.hpp
 *
 *  Created on: Apr 8, 2017
 *      Author: 46sayu
 */

#ifndef POLOLUG2MD_HPP_
#define POLOLUG2MD_HPP_


#include "stm32f4xx_hal.h"

#define ABS(X) ((X) >= 0 ? (X) : (-X))

class PololuG2MD {
public:
    PololuG2MD(TIM_HandleTypeDef *PWM_htim,
               uint32_t PWM_Channel,
               GPIO_TypeDef *DIR_GPIOx,
               uint16_t DIR_GPIO_Pin);
    virtual ~PololuG2MD();

    void init(void);

    void setMotorSpeed(float speed);

    float getMotorSpeed(void) const;


private:
    /* PWM */
    TIM_HandleTypeDef *htim;
    uint32_t pwmChannel;

    /* DIR */
    GPIO_TypeDef *dirGPIOx;
    uint16_t dirPin;

    /* Timer-Counter Period*/
    uint32_t pwmMax;

    /* Timer-Counter Compare*/
    uint32_t pwmCompare;

    float motorSpeed;

};

#endif /* POLOLUG2MD_HPP_ */
