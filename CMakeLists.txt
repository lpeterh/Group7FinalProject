cmake_minimum_required(VERSION 3.19)
project(FinalProj)

set(CMAKE_CXX_STANDARD 20)

add_executable(FinalProj main.cpp Element.cpp Element.h Node.cpp Node.h Source.cpp Source.h VSource.cpp VSource.h ISource.cpp ISource.h Load.cpp Load.h Resistor.cpp Resistor.h Capacitor.cpp Capacitor.h Inductor.cpp Inductor.h JuniorWork.cpp EWork.cpp PeterWork.cpp)