#include "sorcerer.h"   // Include the header file for the Sorcerer class

void Sorcerer::attack(Character *enemy) {
    // Calculate damage using a random number plus the sorcerer's magic power minus enemy's magic resistance
    int damage = RandomUtil::generateRandomInt(5, 10) + magicPower - enemy->getMagicResistance();

    // Output the attack result
    std::cout << *this << " trifft " << *enemy << " fuer " << damage << " Lebenspunkte!" << std::endl;

    // Reduce enemy's health by the calculated damage
    enemy->setHealth(enemy->getHealth() - damage);
}