#include <simtown/building.h>
#include <iostream>	
#include <simtown/dyn_array.h>
#include <simtown/rock.h>


int main(int argc, char** argv) {
	
	std::cout << "Map generation in progress..." << std::endl;

	DynArray<Building> street;

	std::cout << "Oh, hi Marc. Please enter IDs (-99 to end)" << std::endl;
	int id = -1; //default id 
	std::cin >> id;
	while(id!=-99){
		Building tmp(id, 5);
		street.push_back(tmp);
		std::cin >> id;
	}
	
	for(unsigned int i = 0; i < street.size(); ++i) {
		std::cout << street[i] << std::endl;
	}	
	if(street.size() >= 2){
		street[0].swap_rock(street[1], 2, 4);
	}
	std::cout << "End of program" << std::endl;
	
	return 0; // Normal termination
};