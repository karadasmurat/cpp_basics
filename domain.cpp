#include <iostream>
#include "domain.h"

using namespace mkdomain;
using namespace std;


// constructor \w member initializer
Box::Box(int cap): capacity(cap){}

// classic version to add
Box Box::add(const Box &other) const {
    return Box(capacity + other.getCapacity());
}
// operator overloading
Box Box::operator+(const Box &other) const {
    return Box(capacity + other.getCapacity());
}

// To get cout to accept a Box object after the insertion operator, overload the insertion operator to recognize an ostream object on the left and a Box on the right. 
// like toString()

// cout is an object of ostream class and cin is an object of istream class  operators must be overloaded as a global function - if we want to make them a member method, then they must be made members of ostream and istream classes, which is not a good option most of the time.
// think the parameters like f(this, other)

// The overloaded operator returns a reference to the original ostream object, which means you can combine insertions
ostream& operator << (ostream& os, const Box& box){
    os << box.getCapacity() << endl;
    return os;
}





// DEFINITION 
// into cpp file
Entity::Entity() : Entity("Default") {}

// A default parameter is only used in the declaration.
Entity::Entity(const string& n, int s) : e_name(n), e_size(s){
    cout << "Construct Entity obj" 
        << endl;
}
Entity::~Entity() { cout << "Destruct Entity obj " << e_name << endl; }




/* 
#include <iostream>

namespace mkdomain {
    
    class Vehicle{

        int capacity;

    public:
    
        // Constructor with an optional parameter and initializer list
        // Also a default constructor then ?!
        Vehicle(int vcapacity = 1): capacity(vcapacity){}

        void move() {
            std::cout << "The vehicle is moving by default!" << std::endl;
        }

    };

    enum class BicycleType{

        Mountain, City, Road, Gravel
    };

    class Bicycle: public Vehicle{

        public:
            BicycleType type;
            int gears;

            Bicycle(BicycleType btype, int gears=18, int capacity=1): Vehicle(capacity){
                type = btype;
            }

            void move() {
                std::cout << "Cycling with a " << int(type) << std::endl;
            }


    };
} // namespace
*/