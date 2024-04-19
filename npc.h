#ifndef UEBUNG1_NPC_H
#define UEBUNG1_NPC_H

#include "character.h"  // Include necessary header files

class Npc : public Character {  // Define class Npc inheriting from class Character
public:
    using Character::Character;  // Inherit constructors from the base class Character

    ~Npc() {  // Destructor definition
        std::cout << *this << " verabschiedet sich und reitet in den Sonnenuntergang!" << std::endl;
        // Output farewell message indicating the destruction of the Npc object
    }
};

#endif //UEBUNG1_NPC_H