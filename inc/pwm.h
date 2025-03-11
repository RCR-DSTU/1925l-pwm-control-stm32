#pragma once
#ifndef _PWM_H_
#define _PWM_H_

#ifdef USE_HAL_DRIVER
#if defined(STM32F407xx) || defined(STM32F401xC) || defined(STM32F411xE)
#include "stm32f4xx_hal.h"
#elif defined(STM32F103xx)
#include "stm32f1xx_hal.h"
#endif

typedef struct {
	GPIO_TypeDef *port;
	uint16_t dir_pin;
    uint32_t *arr;
    uint32_t *channel;
    uint8_t is_inverted_signal;
}pwm_t;

#include "stdlib.h"
#include "string.h"
#include "stdarg.h"
#include <stdbool.h>
#include <math.h>

typedef enum {
	STATUS_OK = 0x0,
	OBJECT_NULL = 0x1,
	INVALID_DATA_TYPE = 0x2,
	UNDEFINED_DATA_TYPE = 0x3,
	SENDING_ERROR = 0x4,
	RECEIVING_ERROR = 0x5,
	ALLOCATE_ERROR = 0x6,
	LIB_NOT_FOUND = 0x7,
	INVALID_RECEIVED_DATA_FRAME = 0x8,
	END_FUNCTION_WITH_ERROR = 0xF,
}status_t;

#ifndef NDEBUG
#define VALUE_CAN_BE_NULL(value)			assert_param(value != NULL)
#define VA_ARGS_SIZE_CAN_BE_INVALID(args)	assert_param(args != 0)
#define DATA_TYPE_CAN_BE_ZERO(type)			assert_param(type != 0)
#define MALLOC_CAN_RETURN_NULL(result)		assert_param(result != NULL)
#else /* NDEBUG */
#define VALUE_CAN_BE_NULL(expression)	do {if(expression == NULL) return OBJECT_NULL;} while(0)
#define DATA_TYPE_CAN_BE_ZERO(type)		do {if(type == 0) return INVALID_DATA_TYPE;} while(0)
#define MALLOC_CAN_RETURN_NULL(result)	do {if(result == NULL) return ALLOCATE_ERROR;} while(0)
#endif /* NDEBUG */

status_t pwm_init(
    pwm_t *object, 
    TIM_HandleTypeDef *timer, 
    uint8_t channel, 
    GPIO_TypeDef *group, uint16_t pin,
    uint8_t is_inverted_signal);

status_t pwm_set_duty(
    pwm_t *object, 
    float duty);

#endif /*USE_HAL_DRIVER*/
#endif /*_PWM_H_*/