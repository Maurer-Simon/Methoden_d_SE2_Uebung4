#ifndef UEBUNG1_FIGHTER_H
#define UEBUNG1_FIGHTER_H

#include "npc.h"          // Include necessary header files
#include "RandomUtil.h"   // Include necessary header files

class Fighter : public Npc {  // Define class Fighter inheriting from class Npc
public:
    // Constructor with initialization list to initialize base class and member variables
    Fighter(const std::string& name, int health, int gold, int strength)
            : Npc(name, health, gold, armor, magicResistance), strength(strength) {
        if (strength < 0) {
            throw InvalidArgument("Fighter::Fighter: Negative value");
        }
    }

    // Override the attack method
    virtual void attack(Character* enemy) override;

    // Getter method to retrieve the strength of the fighter
    int getStrength() const {
        return strength;
    }

    // Setter method to set the strength of the fighter
    void setStrength(int strength) {
        if (strength < 0) {
            throw InvalidArgument("Fighter::setStrength: Negative value");
        }
        this->strength = strength;
    }

protected:
    int strength;  // Protected member variable representing the strength of the fighter
};

#endif //UEBUNG1_FIGHTER_H
