#ifndef UEBUNG1_SORCERER_H
#define UEBUNG1_SORCERER_H

#include "npc.h"          // Include necessary header files
#include "RandomUtil.h"   // Include necessary header files

class Sorcerer : public Npc {  // Define class Sorcerer inheriting from class Npc
public:
    // Constructor with initialization list to initialize base class and member variables
    Sorcerer(const std::string& name, int health, int gold, int magic)
            : Npc(name, health, gold, armor, magicResistance), magicPower(magic) {
        if (magicPower < 0) {
            throw InvalidArgument("Sorcerer::Sorcerer: Negative value");
        }
    }

    virtual void attack(Character *enemy) override;  // Declaration of the attack method

    // Getter method to retrieve the magic power of the sorcerer
    int getmagicPower() const {
        return magicPower;
    }

    // Setter method to set the magic power of the sorcerer
    void setmagicPower(int magic) {
        if (magicPower < 0) {
            throw InvalidArgument("Sorcerer::setMagicPower: Negative value");
        }
        this->magicPower = magic;
    }

protected:
    int magicPower;  // Protected member variable representing the magic power of the sorcerer
};

#endif //UEBUNG1_SORCERER_H
