#include <iostream>
#include <simtown/rock.h>

unsigned int Rock::rock_counter_ = 0;
Rock::Rock() : rid_( rock_counter_ )
{
    std::cout << "Oh hi Rock. Please do take a seat, we have mineral source "
                 "water if you want"
              << std::endl;
    rock_counter_++;
}

Rock::~Rock()
{
    std::cout << "| Wow that crusher really liked your rocks !" << rid_ << " |"
              << std::endl;
}

std::ostream& operator<<( std::ostream& out, const Rock& rhs )
{
    out << "|| " << rhs.rid_ << " ||";
    return out;
}