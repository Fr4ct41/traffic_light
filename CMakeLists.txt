cmake_minimum_required(VERSION 3.8.0)
project(T_intersection VERSION 0.1.0 LANGUAGES C CXX)


add_executable(T_intersection src/main.cpp src/traffic_light.cpp)

target_include_directories(T_intersection PUBLIC includes)

