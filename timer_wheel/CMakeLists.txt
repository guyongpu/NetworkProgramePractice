cmake_minimum_required(VERSION 3.15)
project(timer_wheel)

set(CMAKE_CXX_STANDARD 14)

add_executable(timer_wheel main.cpp tw_timer.cpp tw_timer.h time_wheel.cpp time_wheel.h)