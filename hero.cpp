#include <random>
#include <iostream>
#include "hero.h"

// Constructor
Hero::Hero(const std::string& name, int health, int gold, int armor, int magicResistance)
        : Character(name, health, gold, armor, magicResistance) {

    for (int i = 0; i < inventorySize; i++) {
        items[i] = nullptr;
    }
    for (int i = 0; i < equipmentSize; i++){
        equip[i] = nullptr;
    }
};

// The hero attacks a specified enemy and inflicts random damage between 5 and 15 health points.
void Hero::attack(Character* enemy)
{
    int damage = RandomUtil::generateRandomInt(5, 15);

    // Output that the hero hit the enemy and how much damage was dealt
    std::cout << *this << " trifft " << *enemy << " fuer " << damage << " Lebenspunkte!" << std::endl;

    // Decrease the enemy's health points by the generated damage
    enemy->setHealth(enemy->getHealth() - damage);
}

// Simulates a fight between the hero and an enemy, consisting of multiple rounds.
// In each round, the attack() function of both the hero and the enemy is called alternately,
// until one of the parties runs out of health points.
// Returns true if the hero wins, false otherwise.
bool Hero::fight(Character* enemy)
{
    while (this->getHealth() > 0 && enemy->getHealth() > 0)
    {
        attack(enemy);
        if (enemy->getHealth() <= 0)
        {
            enemy->setHealth(0);
            setGold(getGold() + enemy->getGold());
            enemy->setGold(0);
            // Output when the enemy is defeated
            std::cout << *enemy << " wurde besiegt! " << *this << " hat den Kampf gewonnen!" << std::endl;

            try {
                addInventoryItem(retrieveRandomLoot(enemy));
            } catch(InventoryFullException& e) {
                std::cout << "Kein freier Platz im Inventar!" << std::endl;
            } catch(InvalidItemException& e) {

            }
            return true;
        }

        enemy->attack(this);
        if (getHealth() <= 0)
        {
            setHealth(0);
            enemy->setGold(enemy->getGold() + getGold());
            setGold(0);
            // Output when the hero is defeated
            std::cout << *this << " wurde besiegt! " << *enemy << " hat den Kampf gewonnen!"<< std::endl;
            return false;
        }
    }
    return false;
}

// Getter for item in equipment by index
std::shared_ptr<Item> Hero::getEquip(int index) {
    if (index < 0 || index > 1) {
        throw InvalidIndexException("Hero::getGear(): Invalid index");
    }
    return equip[index];
}

// Get size of equipment
int Hero::getEquipmentSize() {
    return equipmentSize;
}

// Adds an item to the hero's equipment.
// Returns the index of the added item or -1 if there is no more space available.
int Hero::addEquipmentItem(std::shared_ptr<Item> item)
{
    for (int i = 0; i < equipmentSize; i++)
    {
        if (equip[i] == nullptr)
        {
            equip[i] = item;
            return i;
        }
    }
    throw GearFullException("Hero::addEquipmentItem(): Full gear");
}

// Removes an item from the hero's equipment based on the specified slot.
// Returns the removed item or an invalid item if the slot is invalid.
std::shared_ptr<Item> Hero::removeEquipmentItem(int slot){
    std::shared_ptr<Item> tmp;
    if (slot < 0 || slot >= equipmentSize) {
        throw InvalidIndexException("Hero::removeEquipmentItem(): Invalid index");
    } else if (equip[slot]) {
        tmp = equip[slot];
        equip[slot] = nullptr;
        return tmp;
    } else {
        throw InvalidItemException("Hero::removeEquipmentItem(): Invalid item");
    }
};

// Retrieves a random loot item from a defeated enemy.
std::shared_ptr<Item> Hero::retrieveRandomLoot(Character* enemy) {
    // Get a random item from the defeated enemy
    int maxCount = -1;
    for (int i = 0; i < enemy->getInventorySize(); i++)
    {
        if (enemy->getItem(i) != nullptr){
            maxCount += 1;
        }
    }

    if (maxCount <= 0) {
        throw InvalidItemException("Hero::removeEquipmentItem(): Enemy has no Items");
    }

    int random = RandomUtil::generateRandomInt(0,maxCount);

    std::shared_ptr<Item> randomItem = enemy->getItem(random);
    enemy->removeInventoryItem(random);

    return randomItem;
}

// Sells an item from the hero's inventory based on the specified index.
// Increases the hero's gold by the value of the sold item.
void Hero::sellItem(int index){
    if (index >= 0 && index < inventorySize){
        if (items[index] != nullptr) {
            gold += items[index]->getWorth();
            std::cout << "Item " << *items[index] << " wurde verkauft. " << *this << " hat nun "
                      << this->getGold() << " Gold."<< std::endl;
        } else {
            throw InvalidItemException("Hero::sellItem(): Invalid item");
        }
    } else {
        throw InvalidIndexException("Hero::sellItem(): Invalid index");
    }
}

