cmake_minimum_required(VERSION 3.22)

# Setup compiler settings
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

# Enable CMake support for ASM and C languages
enable_language(CXX C ASM)

target_sources(${CMAKE_PROJECT_NAME} PRIVATE
    src/pwm.c)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    inc/)
