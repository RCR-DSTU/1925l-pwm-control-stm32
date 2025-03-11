# 1925-pwm-control-stm32
Библиотека для ШИМ управления двигателями с микроконтроллера STM32

Для загрузки через CmakeLists.txt
```
include(FetchContent)

# PWM-CONTROL cmake extension (uses github main branch)
set(PWM_PATH  ${PROJECT_SOURCE_DIR}/Drivers/1925-pwm-control-stm32)
set(PWM_SOURCE_DIR ${PWM_PATH}/src)
set(PWM_HEADER_DIR ${PWM_PATH}/inc)
if(NOT EXISTS ${PWM_PATH})
FetchContent_Declare(pwm_control
                     GIT_REPOSITORY https://github.com/RCR-DSTU/1925-pwm-control-stm32
                     GIT_TAG main
                     DOWNLOAD_DIR ${PWM_PATH}
                     SOURCE_DIR ${PWM_PATH})

FetchContent_MakeAvailable(pwm_control)
endif()

target_sources(${CMAKE_PROJECT_NAME} PRIVATE
    ${PWM_SOURCE_DIR}/pwm.c)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    ${PWM_PATH}/inc/
)
```
