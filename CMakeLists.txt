cmake_minimum_required(VERSION 3.15)
project(codigo C)

set(CMAKE_C_STANDARD 99)

add_executable(codigo main.c src/kepleruniversal.c src/kepleruniversal.h src/picardchebyshevdemo.c src/picardchebyshevdemo.h src/vmpcm.c src/vmpcm.h src/matlab.c src/matlab.h)