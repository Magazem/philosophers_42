cmake_minimum_required(VERSION 3.29)
project(philo2 C)

set(CMAKE_C_STANDARD 99)

add_executable(philo2
        init.c
        philo.c
        utils.c
        check.c
        routine.c)
