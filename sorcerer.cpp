#include "sorcerer.h"

// Constructor with initialization list to initialize base class and member variables
Sorcerer::Sorcerer(const std::string& name, int health, int gold, int magic)
        : Npc(name, health, gold, armor, magicResistance), magicPower(magic) {
    if (magicPower < 0) {
        throw InvalidArgument("Sorcerer::Sorcerer: Negative value");
    }
}

void Sorcerer::attack(Character *enemy) {
    // Calculate damage using a random number plus the sorcerer's magic power minus enemy's magic resistance
    int damage = RandomUtil::generateRandomInt(5, 10) + magicPower - enemy->getMagicResistance();

    // Output the attack result
    std::cout << *this << " trifft " << *enemy << " fuer " << damage << " Lebenspunkte!" << std::endl;

    // Reduce enemy's health by the calculated damage
    enemy->setHealth(enemy->getHealth() - damage);
}

// Setter method to set the magic power of the sorcerer
void Sorcerer::setmagicPower(int magic) {
    if (magicPower < 0) {
        throw InvalidArgument("Sorcerer::setMagicPower: Negative value");
    }
    this->magicPower = magic;
}