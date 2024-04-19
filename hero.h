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
    static const int equipmentSize = 2;                // Size of the equipment array
    std::shared_ptr<Item> equip[equipmentSize];        // Array to store equipped items

public:
    // Constructor
    Hero(const std::string& name, int health, int gold, int armor, int magicResistance);

    // Attack function
    void attack(Character* enemy) override;

    // Fight simulation
    bool fight(Character* enemy);

    // Getter for item in equipment by index
    std::shared_ptr<Item> getEquip(int index);

    // Get size of equipment
    static int getEquipmentSize();

    // Add an item to equipment
    int addEquipmentItem(std::shared_ptr<Item> item);

    // Remove an item from equipment
    std::shared_ptr<Item> removeEquipmentItem(int slot);

    // Remove random item from attacker of hero wins
    static std::shared_ptr<Item> retrieveRandomLoot(Character* enemy);

    // Sell an item from inventory
    void sellItem(int index);
};

#endif // HERO_H