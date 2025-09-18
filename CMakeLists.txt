cmake_minimum_required(VERSION 3.10)

# set the project name
project(HelloProject VERSION 1.0)

#export configuration to source code
configure_file(HelloProjectConfig.h.in HelloProjectConfig.h)

# add the executable target named HelloWorld
add_executable(HelloWorld hello.cpp)