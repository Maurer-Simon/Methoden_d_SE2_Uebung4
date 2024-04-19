#ifndef CHARACTER_H
#define CHARACTER_H

#include "item.h"         // Include necessary header files
#include "RandomUtil.h"   // Include necessary header files
#include "exceptions.h"

class Character {
public:
    // Constructor to initialize character with name, health, gold, armor, and magic resistance
    Character(const std::string &name, int health, int gold, int armor, int magicResistance)
            : name(name), health(health), gold(gold), armor(armor), magicResistance(magicResistance) {
        for (int i = 0; i < inventorySize; i++) {
            items[i] = nullptr;
        }
        if (name.size() == 0) {
            throw InvalidArgument("Character::Character: Empty string");
        }
        if (gold < 0) {
            throw InvalidArgument("Character::Character: Negative value");
        }
    }

    // Virtual destructor for polymorphic behavior
    virtual ~Character() {
        for (int i = 0; i < inventorySize; i++) {
            delete items[i]; // Destroy items in the inventory
        }

    };

    // Setter for character's name
    void setName(const std::string &name) {
        if (name.size() == 0) {
            throw InvalidIndexException("Character::getInventory(): Invalid index");
        }
        this->name = name;
    }

    // Getter for character's armor
    int getArmor() const {
        return armor;
    }

    // Setter for character's armor
    void setArmor(int armor) {
        this->armor = armor;
    }

    // Getter for character's magic resistance
    int getMagicResistance() const {
        return magicResistance;
    }

    // Setter for character's magic resistance
    void setMagicResistance(int magicResistance) {
        this->magicResistance = magicResistance;
    };

    // Pure virtual function for attack action, to be implemented by derived classes
    virtual void attack(Character* enemy) = 0;

    // Setter for character's health points
    void setHealth(int newHealth) {
        this->health = newHealth;
    }

    // Getter for character's health points
    int getHealth() const {
        return this->health;
    }

    // Setter for character's gold amount
    void setGold(int newGold) {
        if (newGold < 0) {
            throw InvalidArgument("Character::getGold: Negative value");
        }
        this->gold = newGold;
    }

    // Getter for character's gold amount
    int getGold() const {
        return this->gold;
    }

    // Getter for character's name
    std::string getName() const {
        return this->name;
    }

    // Getter for an item in character's inventory based on the index
    Item* getItem(int index) {
        if (index < 0 || index >= inventorySize) {
            throw InvalidIndexException("Character::getInventory(): Invalid index");
        }
        return items[index];
    }

    // Adds an item to character's inventory and returns the index where the item was added
    int addInventoryItem(Item* item);

    // Removes an item from character's inventory based on the slot and returns the removed item
    Item* removeInventoryItem(int slot);

    // Getter for the size of the inventory
    int getInventorySize() const {
        return inventorySize;
    }

    // Getter for the amount of free space in the inventory
    int getFreeInvSpace() const;

protected:
    static const int inventorySize = 10;   // Maximum size of the inventory
    std::string name;                      // Name of the character
    int health;                            // Health points of the character
    int gold;                              // Gold amount of the character
    Item* items[inventorySize];            // Inventory of the character (up to 10 items)
    int armor;                             // Armor value of the character
    int magicResistance;                   // Magic resistance value of the character
};

// Overloaded stream insertion operator to allow printing of Character objects
std::ostream& operator<<(std::ostream& os, const Character& ch);

#endif // CHARACTER_H
