#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <ostream>
#include <iostream>
#include "exceptions.h"

// Item: Represents an item with a name, value, and a flag indicating whether the item is valid.
class Item {
private:
    std::string name;  // Name of the item
    int gold;          // Value of the item

public:
    // Constructor initializes item with name, value, and sets isValid to true
    Item(const std::string& name, int gold)
            : name(name), gold(gold) {
        if (name.size() == 0) {
            throw InvalidArgument("Item::Item: Empty string");
        }
        if (gold < 0) {
            throw InvalidArgument("Item::Item: Negative Item Worth");
        }
    }

    ~Item() {
    };

    // Function to get the value of the item
    int getWorth() const {
        return gold;
    }

    void setWorth(int gold) {
        if (gold < 0) {
            throw InvalidArgument("Item::Item: Negative Item Worth");
        }
        this->gold = gold;
    }

    // Function to get the name of the item
    std::string getName() const {
        return name;
    }

    void setName(std::string text) {
        if (name.size() == 0) {
            throw InvalidArgument("Item::Item: Empty string");
        }
        this->name = text;
    }
};

// Overloaded stream insertion operator to allow printing of Item objects
std::ostream& operator<<(std::ostream& out, const Item& item);

#endif // ITEM_H