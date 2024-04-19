#ifndef CHARACTER_H
#define CHARACTER_H

#include <memory>
#include "item.h"         // Include necessary header files
#include "RandomUtil.h"   // Include necessary header files
#include "exceptions.h"

class Character {
protected:
    static const int inventorySize = 10;   // Maximum size of the inventory
    std::string name;                      // Name of the character
    int health;                            // Health points of the character
    int gold;                              // Gold amount of the character
    std::shared_ptr<Item> items[inventorySize];            // Inventory of the character (up to 10 items)
    int armor;                             // Armor value of the character
    int magicResistance;                   // Magic resistance value of the character

public:
    // Constructor to initialize character with name, health, gold, armor, and magic resistance
    Character(const std::string &name, int health, int gold, int armor, int magicResistance);

    // Virtual destructor for polymorphic behavior
    ~Character();

    // Pure virtual function for attack action, to be implemented by derived classes
    virtual void attack(Character* enemy) = 0;

    // Setter for character's name
    void setName(const std::string &name);

    // Getter for character's name
    std::string getName() const { return this->name; }

    // Setter for character's armor
    void setArmor(int armor) { this->armor = armor; }

    // Getter for character's armor
    int getArmor() const { return armor; }

    // Setter for character's magic resistance
    void setMagicResistance(int magicResistance) { this->magicResistance = magicResistance; };

    // Getter for character's magic resistance
    int getMagicResistance() const { return magicResistance; }

    // Setter for character's health points
    void setHealth(int newHealth) { this->health = newHealth; }

    // Getter for character's health points
    int getHealth() const { return this->health; }

    // Setter for character's gold amount
    void setGold(int newGold);

    // Getter for character's gold amount
    int getGold() const { return this->gold; }

    // Getter for an item in character's inventory based on the index
    std::shared_ptr<Item> getItem(int index);

    // Adds an item to character's inventory and returns the index where the item was added
    int addInventoryItem(std::shared_ptr<Item> item);

    // Removes an item from character's inventory based on the slot and returns the removed item
    std::shared_ptr<Item> removeInventoryItem(int slot);

    // Getter for the size of the inventory
    int getInventorySize() const { return inventorySize; }

    // Getter for the amount of free space in the inventory
    int getFreeInvSpace() const;
};

// Overloaded stream insertion operator to allow printing of Character objects
std::ostream& operator<<(std::ostream& os, const Character& ch);

#endif // CHARACTER_H
