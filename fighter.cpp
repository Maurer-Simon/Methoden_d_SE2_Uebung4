#include "fighter.h"   // Include the header file for the Fighter class

void Fighter::attack(Character* enemy) {
    // Calculate damage using a random number plus the fighter's strength minus enemy's armor
    int damage = RandomUtil::generateRandomInt(5, 10) + strength - enemy->getArmor();

    // Output the attack result
    std::cout << *this << " trifft " << *enemy << " fuer " << damage << " Lebenspunkte!" << std::endl;

    // Reduce enemy's health by the calculated damage
    enemy->setHealth(enemy->getHealth() - damage);
}
