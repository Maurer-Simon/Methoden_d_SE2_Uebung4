#ifndef HERO_H
#define HERO_H

#include <string>
#include "item.h"
#include "character.h"
#include "RandomUtil.h"

// Forward declaration of Character class
class Character;

class Hero : public Character {
protected:
    static const int equipmentSize = 2;  // Size of the equipment array
    Item* equip[equipmentSize];           // Array to store equipped items

public:
    // Constructor
    Hero(const std::string& name, int health, int gold, int armor, int magicResistance)
            : Character(name, health, gold, armor, magicResistance) {

        for (int i = 0; i < inventorySize; i++) {
            items[i] = nullptr;
        }
        for (int i = 0; i < equipmentSize; i++) {
            equip[i] = nullptr;
        }

    };  // Initialize base class

    ~Hero() {
        for (int i = 0; i < equipmentSize; i++) {
            delete equip[i];
        }

        std::cout << *this << " verabschiedet sich und reitet in den Sonnenuntergang!" << std::endl;
        // Output farewell message indicating the destruction of the Hero object
    }

    // Attack function
    virtual void attack(Character* enemy) override;

    // Fight simulation
    bool fight(Character* enemy);

    // Getter for item in equipment by index
    Item* getEquip(int index) {
        if (index < 0 || index > 1) {
            throw InvalidIndexException("Hero::getGear(): Invalid index");
        }
        return equip[index];
    }

    // Add an item to equipment
    int addEquipmentItem(Item* item);

    // Remove an item from equipment
    Item* removeEquipmentItem(int slot);

    // Remove random item from attacker of hero wins
    Item* retrieveRandomLoot(Character* enemy);

    // Get size of equipment
    static int getEquipmentSize() {
        return equipmentSize;
    }

    // Sell an item from inventory
    void sellItem(int index);

};

#endif // HERO_H