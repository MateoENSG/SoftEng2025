#include <iostream>
#include <HelloProjectConfig.h>
#include <basic/message.h>

//print of the word "Hello"
void hello_world(){
	std::cout<<"Hello World!\n";
}

//print of the version
void print_version() {
	std::cout << "project version is "
		<< HelloProject_VERSION_MAJOR
		<< "."
		<< HelloProject_VERSION_MINOR
		<< std::endl;
}