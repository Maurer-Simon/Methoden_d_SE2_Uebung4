#ifndef UEBUNG1_SORCERER_H
#define UEBUNG1_SORCERER_H

#include "npc.h"          // Include necessary header files
#include "RandomUtil.h"   // Include necessary header files

// Define class Sorcerer inheriting from class Npc
class Sorcerer : public Npc {
protected:
    int magicPower;  // Protected member variable representing the magic power of the sorcerer

public:
    // Constructor with initialization list to initialize base class and member variables
    Sorcerer(const std::string& name, int health, int gold, int magic);

    // Declaration of the attack method
    virtual void attack(Character *enemy) override;

    // Getter method to retrieve the magic power of the sorcerer
    int getmagicPower() const { return magicPower; }

    // Setter method to set the magic power of the sorcerer
    void setmagicPower(int magic);
};

#endif //UEBUNG1_SORCERER_H
