#ifndef building_h
#define building_h
#include <iostream>
#include <simtown/dyn_array.h>
#include <simtown/rock.h>

class Building
{
public:
    // ! \\ Creates a Building with identifier and a number of rocks in its
    // collection
    Building( int id, unsigned int nb_rocks );
    Building();
    Building( const Building& rhs );
    Building& operator=( const Building& rhs );
    ~Building();

    const Rock* get_rock( unsigned int index )
        const; // const here so that this fction is only an accessor, it won't
               // modify the other objects.
    void swap_rock( Building partner, unsigned int i, unsigned int i_partner );

private:
    friend std::ostream& operator<<( std::ostream& out, const Building& rhs );
    int id_;
    DynArray< Rock* > rocks_;
};

#endif
