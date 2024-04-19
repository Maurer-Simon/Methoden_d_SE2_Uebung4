#include "fighter.h"   // Include the header file for the Fighter class

// Constructor with initialization list to initialize base class and member variables
Fighter::Fighter(const std::string& name, int health, int gold, int strength)
        : Npc(name, health, gold, armor, magicResistance), strength(strength) {
    if (strength < 0) {
        throw InvalidArgument("Fighter::Fighter: Negative value");
    }
}

void Fighter::attack(Character* enemy) {
    // Calculate damage using a random number plus the fighter's strength minus enemy's armor
    int damage = RandomUtil::generateRandomInt(5, 10) + strength - enemy->getArmor();

    // Output the attack result
    std::cout << *this << " trifft " << *enemy << " fuer " << damage << " Lebenspunkte!" << std::endl;

    // Reduce enemy's health by the calculated damage
    enemy->setHealth(enemy->getHealth() - damage);
}

// Setter method to set the strength of the fighter
void Fighter::setStrength(int newStrength) {
    if (newStrength < 0) {
        throw InvalidArgument("Fighter::setStrength: Negative value");
    }
    this->strength = newStrength;
}