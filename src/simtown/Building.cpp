#include <iostream>
#include <simtown/building.h>

Building::Building(int id, unsigned int nb_rocks) : id_(id), rocks_(nb_rocks){
	std::cout << "Building::Building(" << id << ") Created at " << this << std::endl;
	for(unsigned int ir = 0; ir < rocks_.size(); ++ir){
		rocks_[ir] = new  Rock;
	}
}

Building::Building(): id_(-1), rocks_(0) { 
	std::cout << "Building::Building(), id_= " << id_ << " at " << this << std::endl;
}

Building::~Building(){
	std::cout << "Building::~Building("<< id_ <<") at " << this << std::endl;
	std::cout << "Reappropriation de vos biens par le Gouvernement Celeste de la Fronce !!!" << std::endl;
	for(unsigned int ir = 0; ir < rocks_.size(); ++ir){
		delete rocks_[ir];
	}
}

Building::Building(const Building& rhs): id_(rhs.id_), rocks_(rhs.rocks_){
	std::cout << "Building::Building(Building&), id_= " << id_ << " at " << this << std::endl;
	for( unsigned int i = 0; i < rocks_.size(); ++i){
		rocks_[i] = new Rock(*rhs.rocks_[i]);
	}
}


Building& Building::operator=(const Building& rhs){
	std::cout << "Building::operator=(" << &rhs << ", " << rhs.id_ << "), id_ = " << id_ << " at " << this << std::endl;
	if(this != &rhs) {
		// do what the destructor does 
		for(unsigned int ir = 0; ir < rocks_.size(); ++ir){
			delete rocks_[ir];
		}
		// do what the copy constructor does : 
		id_ = rhs.id_;
		//rocks_ = rhs.rocks_; NUL
		for (unsigned int i = 0; i < rhs.rocks_.size(); ++i){
			rocks_[i] = new Rock(*rhs.rocks_[i]);
		}
	}
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Building& rhs) {
	out << "|" << &rhs << " - " << rhs.id_ << "|\n";
	for(unsigned int i = 0; i < rhs.rocks_.size(); ++i){
		out << "	| " << rhs.rocks_[i] << " | << \n";
	}
	return out;
}

const Rock* Building::get_rock(unsigned int index) const {
	std::cout << rocks_[index] << std::endl; //test affichage pour savoir s'il le trouve bien
	return rocks_[index];
}

void Building::swap_rock(Building partner, unsigned int i, unsigned int i_partner){
	if(i < rocks_.size() && i_partner < partner.rocks_.size() ){
		Rock* exchange_area = rocks_[i];
		rocks_[i] = partner.rocks_[i_partner];
		partner.rocks_[i_partner] = exchange_area;
	}
}