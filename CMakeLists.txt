cmake_minimum_required(VERSION 3.10)

# set the project name
project(HelloProject VERSION 1.0)

# specify the C++ standard
# use the CMAKE_CXX_STANDARD variable_requires
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

#export configuration to source code
configure_file(HelloProjectConfig.h.in HelloProjectConfig.h)

# add the executable target named HelloWorld
add_executable(HelloWorld hello.cpp)

# add binary tree to the list of paths to search includes
target_include_directories(HelloWorld PUBLIC "${PROJECT_BINARY_DIR}")