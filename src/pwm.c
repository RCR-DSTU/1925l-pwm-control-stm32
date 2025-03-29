#include "pwm.h"

status_t pwm_init(
    pwm_t *object, 
    TIM_HandleTypeDef *timer, 
    uint32_t channel, 
    GPIO_TypeDef *group, uint16_t pin,
    uint8_t is_inverted_signal)
{
    VALUE_CAN_BE_NULL(object);
    VALUE_CAN_BE_NULL(timer);
    VALUE_CAN_BE_NULL(group);
    assert_param(IS_TIM_CCX_INSTANCE(timer->Instance, channel));

    object->arr = (uint32_t *)&timer->Instance->ARR;
    object->channel = (uint32_t *)(&timer->Instance->CCR1 + channel);
    object->port = group;
    object->dir_pin = pin;

    HAL_TIM_PWM_Start(timer, channel);

    if(is_inverted_signal != 0) object->is_inverted_signal = 1; 
    else object->is_inverted_signal = 0;

    return STATUS_OK;
}

status_t pwm_set_duty(pwm_t *object, float duty)
{
    VALUE_CAN_BE_NULL(object);
    VALUE_CAN_BE_NULL(object->channel);
    VALUE_CAN_BE_NULL(object->port);

    if(isnanf(duty) || isinf(duty)) duty = 0.0f;
    if(duty > 1.0f) duty = 1.0f;
    if(duty < -1.0f) duty = -1.0f;

    bool expression = (!(duty >= 0.0) && !(object->is_inverted_signal == 0)) ||
                        ((duty >= 0.0) && (object->is_inverted_signal == 0));

    if(expression)
    {
        *object->channel = ((int32_t)(*object->arr) * fabs(duty) );
        HAL_GPIO_WritePin(object->port, object->dir_pin, GPIO_PIN_RESET);
    } else
    {
        *object->channel = ((int32_t)(*object->arr + ((*object->arr * fabs(duty) ))));
        HAL_GPIO_WritePin(object->port, object->dir_pin, GPIO_PIN_SET);
    }
    return STATUS_OK;
}