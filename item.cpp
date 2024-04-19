#include "item.h"   // Include the header file for the Item class

Item::~Item(){
    std::cout << *this << " hat sich zu Staub zersetzt!" << std::endl;
// Output farewell message indicating the destruction of the Hero object
}

// Overloaded stream insertion operator to allow printing of Item objects
std::ostream& operator<<(std::ostream& out, const Item& item) {
    out << item.getName() << " (Wert: " << item.getWorth() << ")";  // Output the name and value of the item
    return out;
}