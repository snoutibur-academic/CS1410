cmake_minimum_required(VERSION 3.29)
project(U10_WHERE_BRAIN)

set(CMAKE_CXX_STANDARD 20)

add_executable(U10_WHERE_BRAIN main.cpp
        Employee.h
        SalariedEmployee.h
        WagedEmployee.h
        Date.h
        Address.h
        SalesEmployee.h)
