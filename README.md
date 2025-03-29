# 1925l-pwm-control-stm32
Библиотека для ШИМ управления двигателями с микроконтроллера STM32

Для загрузки через CmakeLists.txt
```
include(FetchContent)

# PWM-CONTROL cmake extension (uses github main branch)
if(NOT EXISTS ${PROJECT_SOURCE_DIR}/Bsp/1925l-pwm-control-stm32/CmakeLists.txt)
FetchContent_Declare(pwm_control
                     GIT_REPOSITORY https://github.com/RCR-DSTU/1925l-pwm-control-stm32
                     GIT_TAG main
                     DOWNLOAD_DIR ${PROJECT_SOURCE_DIR}/Bsp/1925l-pwm-control-stm32
                     SOURCE_DIR ${PROJECT_SOURCE_DIR}/Bsp/1925l-pwm-control-stm32)
FetchContent_MakeAvailable(pwm_control)
endif()
add_subdirectory(Bsp/1925l-pwm-control-stm32)
```
