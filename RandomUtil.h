#ifndef RANDOMUTIL_H
#define RANDOMUTIL_H

#include <iostream>
#include <random>

// Klasse und Funktion, um einen zufälligen Wert zwischen min und max zu generieren.
class RandomUtil
{
public:
	// Generiert einen zufälligen Integer-Wert im Bereich von min bis max (einschließlich).
	static int generateRandomInt(int min, int max) {
		std::random_device rd; // Erzeugt ein Random-Device-Objekt
		std::mt19937 gen(rd()); // Initialisiert den Mersenne-Twister-Zufallszahlengenerator mit dem Seed
		std::uniform_int_distribution<> dis(min, max); // Definiert die Verteilung für den Zufallszahlengenerator
		return dis(gen); // Gibt eine zufällige Zahl innerhalb des definierten Bereichs zurück
	}
};

#endif // RANDOMUTIL_H
