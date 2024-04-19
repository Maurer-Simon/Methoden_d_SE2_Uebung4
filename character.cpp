#include "character.h"  // Include the header file for Character class

// Add an item to the character's inventory and return the index where the item was added
int Character::addInventoryItem(Item* item) {
    // Iterate through the inventory to find an empty slot
    for (int index = 0; index < inventorySize; ++index) {
        if (items[index] == nullptr) {
            items[index] = item; // Add the item to the first empty slot in the inventory
            std::cout << "Item " << *item << " wurde zum Inventar von " << *this << " hinzugefuegt." << std::endl;
            return index; // Return the index where the item was added
        }
    }
    throw InventoryFullException("Character::addInventarItem(): Full inventory");
}

// Remove an item from the character's inventory based on the slot and return the removed item
Item* Character::removeInventoryItem(int slot) {
    Item* tmp;
    // Check if the slot is valid and the item in the slot is valid
    if (slot < 0 || slot >= inventorySize) {
        throw InvalidIndexException("Character::removeInventarItem(): Invalid index");
    } else if (items[slot]) {
        tmp = items[slot]; // Store the item in a temporary variable
        items[slot] = nullptr; // Initialize the item in the inventory
        return tmp; // Return the removed item
    } else {
        throw InvalidItemException("Character::removeInventarItem(): Invalid item");
    }
}

// Get the number of free spaces in the character's inventory
int Character::getFreeInvSpace() const {
    int count = 0;
    for (int i = 0; i < getInventorySize(); i++) {
        if (items[i] == nullptr) {
            count += 1; // Count the number of valid items in the inventory
        }
    }
    if (count > 0) {
        return count; // Return the count
    }
    throw InventoryFullException("Character::addInventarItem(): Full inventory");
}

// Overloaded stream insertion operator to print the character's information
std::ostream& operator<<(std::ostream& out, const Character& ch) {
    out << ch.getName() << " (Gold: " << ch.getGold() << ", Lebenspunkte: " << ch.getHealth() << ")";
    return out; // Return the output stream
}
