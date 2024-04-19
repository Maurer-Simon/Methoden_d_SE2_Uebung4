#include "item.h"   // Include the header file for the Item class

// Overloaded stream insertion operator to allow printing of Item objects
std::ostream& operator<<(std::ostream& out, const Item& item) {
    out << item.getName() << " (Wert: " << item.getWorth() << ")";  // Output the name and value of the item
    return out;
}