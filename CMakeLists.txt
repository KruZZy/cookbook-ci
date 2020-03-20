cmake_minimum_required(VERSION 3.15)
project(cookbook_ci)

set(CMAKE_CXX_STANDARD 17)

add_executable(cookbook_ci main.cpp ingredient/ingredient.cpp ingredient/ingredient.h cookbook/cookbook.cpp cookbook/cookbook.h parser.h)