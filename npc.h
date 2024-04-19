#ifndef UEBUNG1_NPC_H
#define UEBUNG1_NPC_H

#include "character.h"  // Include necessary header files

class Npc : public Character {  // Define class Npc inheriting from class Character
public:
    using Character::Character;  // Inherit constructors from the base class Character
};

#endif //UEBUNG1_NPC_H