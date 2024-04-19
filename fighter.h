#ifndef UEBUNG1_FIGHTER_H
#define UEBUNG1_FIGHTER_H

#include "npc.h"          // Include necessary header files
#include "RandomUtil.h"   // Include necessary header files

// Define class Fighter inheriting from class Npc
class Fighter : public Npc {
protected:
    int strength;  // Protected member variable representing the strength of the fighter

public:
    // Constructor with initialization list to initialize base class and member variables
    Fighter(const std::string& name, int health, int gold, int strength);

    // Override the attack method
    void attack(Character* enemy) override;

    // Getter method to retrieve the strength of the fighter
    int getStrength() const { return strength; }

    // Setter method to set the strength of the fighter
    void setStrength(int strength);
};

#endif //UEBUNG1_FIGHTER_H
