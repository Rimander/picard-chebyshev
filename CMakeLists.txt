cmake_minimum_required(VERSION 3.15)
project(codigo C)

set(CMAKE_C_STANDARD 99)

add_executable(codigo main.c kepleruniversal.c kepleruniversal.h picardchebyshevdemo.c picardchebyshevdemo.h vmpcm.c vmpcm.h matlab.c matlab.h)