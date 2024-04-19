#include "character.h"
#include "hero.h"
#include "fighter.h"
#include "sorcerer.h"


int main() {

    try {
        // Hero wird erstellt und initialisiert
        Hero hero("Annina", 150, 300, 4, 1);

        // Charakter/Angreifer1 wird erstellt und initialisiert
        Fighter angreifer1("Matthias", 100, 50, 3);
        angreifer1.addInventoryItem(new Item("Rubin", 50));
        angreifer1.addInventoryItem(new Item("Dolch", 25));
        angreifer1.addInventoryItem(new Item("Armbrust", 280));

        std::cout << std::endl;

        // Charakter/Angreifer2 wird erstellt und initialisiert
        Sorcerer angreifer2("Pascal", 100, 85, 2);
        // Jedem Angreifer werden 3 Items zugewiesen
        angreifer2.addInventoryItem(new Item("Diamant", 780));
        angreifer2.addInventoryItem(new Item("Schwert", 450));
        angreifer2.addInventoryItem(new Item("Schild", 10));

        std::cout << std::endl;

        // Hero kämpft gegen Angreifer1 und falls Hero gewinnt, kämpft Hero gegen Angreifer2
        if (hero.fight(&angreifer1))
        {
            std::cout << std::endl;
            hero.fight(&angreifer2);
        }

        std::cout << std::endl;

        try {
            // Verkaufe alle gültigen Gegenstände im Inventar der Heldin
            for (int i = 0; i < hero.getInventorySize(); i++)
            {
                if (hero.getItem(i) != nullptr)
                {
                    hero.sellItem(i);
                }
            }
        } catch (InvalidItemException& e) {}

        std::cout << std::endl;

        hero.removeEquipmentItem(5); // Test Exception

    } catch(std::exception& e) {
        std::cout << "\nCaught exception in main: " << e.what() << std::endl;
    }
}