#ifndef dyn_array_h
#define dyn_array_h
#include <iostream>	
#include<assert.h>

template <class T> class DynArray{
	public: 
	DynArray();
	DynArray(unsigned int capacity);
	DynArray(const DynArray<T>& rhs);
	~DynArray();
	DynArray<T>& operator=(const DynArray<T>& rhs);
	
	unsigned int size() const;
	unsigned int push_back(const T& item);
	const T& operator[](unsigned int i) const;
	T& operator[](unsigned int i);
	
	private:
		unsigned int size_;
		T* elements_;
		unsigned int capacity_;
};

template <class T> DynArray<T>::DynArray() : size_(0), capacity_(2){
	std::cout << "DynArray::DynArray()" << std::endl;
	elements_ = new T[capacity_];
}

template <class T> DynArray<T>::DynArray(unsigned int capacity) : size_(capacity), capacity_{(capacity>=1) ? capacity : 2}{
	std::cout << "DynArray::DynArray()" << std::endl;
	// assert( size_ >= 0);
	elements_ = new T[capacity_];
}

template <class T> DynArray<T>::~DynArray(){
	std::cout << "DynArray::~DynArray()" << std::endl;
	delete[] elements_;
}

template <class T> unsigned int DynArray<T>::size()const{
	std::cout << "DynArray::size()" << std::endl;
	return size_;
}

template <class T> unsigned int DynArray<T>::push_back(const T& item){
	std::cout << "DynArray::push_back()" << std::endl;
	if (size_ == capacity_) {
		capacity_ *= 2;
		T* bigger_array = new T[capacity_];
		for(unsigned int i = 0; i < size_; ++i) {
			bigger_array[i] = elements_[i];
		}
		delete[] elements_;
		elements_ = bigger_array;	
	}
	elements_[size_] = item;
	++size_;
	return size_ - 1; //renvoi de la position du dernier élément ajouté.
}

template <class T> const T& DynArray<T>::operator[](unsigned int i)const{
	std::cout << "DynArray::operator[]" << std::endl;
	//assert(i > -1);
	assert(i < size_);
	return elements_[i];
}

template <class T> T& DynArray<T>::operator[](unsigned int i){
	std::cout << "DynArray::operator[]" << std::endl;
	//assert(i > -1); // on a tout mis en unsigned int donc forcement entier positif.
	assert(i < size_);
	return elements_[i];
}

template <class T> DynArray<T>::DynArray(const DynArray<T>& rhs) : size_(rhs.size_), capacity_(rhs.capacity_){
	elements_ = new T[capacity_];
	for( unsigned int i = 0; i < rhs.size_; ++i){
		elements_[i] = rhs.elements_[i];
	}
};

template <class T> DynArray<T>& DynArray<T>::operator=(const DynArray<T>& rhs){
	if( this != &rhs){
		delete[] elements_;
		size_ = rhs.size_;
		capacity_ = rhs.capacity_;
		elements_ = new T[capacity_]; //new T[size_]; fonctionnerai aussi et minimiserai l'usage mémoire. Mais un clonage parfait peut éviter certaines erreurs !
		for (unsigned int i = 0; i < rhs.size_; ++i){
			elements_[i] = rhs.elements_[i];
		}
	}
	return *this;
}


#endif
