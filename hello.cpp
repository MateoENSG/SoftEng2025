#include <iostream>
#include <HelloProjectConfig.h>

void hello_world(){
	std::cout<<"Hello World!\n";
}

void print_version() {
	std::cout << "project version is "
		<< HelloProject_VERSION_MAJOR
		<< "."
		<< HelloProject_VERSION_MINOR
		<< std::endl;
}

int main()
{
	hello_world();
	print_version();
	return 0;
}