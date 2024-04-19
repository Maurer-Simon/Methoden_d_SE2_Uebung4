
all: prototyp4

prototyp4: main.o hero.o character.o item.o npc.o fighter.o sorcerer.o
	g++ -o prototyp4 main.o hero.o character.o item.o npc.o fighter.o sorcerer.o -Werror

main.o: main.cpp
	g++ -c main.cpp -Werror

hero.o: hero.cpp hero.h
	g++ -c hero.cpp -Werror

character.o: character.cpp character.h
	g++ -c character.cpp -Werror

item.o: item.cpp item.h
	g++ -c item.cpp -Werror

npc.o: npc.cpp npc.h
	g++ -c npc.cpp -Werror

fighter.o: fighter.cpp fighter.h
	g++ -c fighter.cpp -Werror

sorcerer.o: sorcerer.cpp sorcerer.h
	g++ -c sorcerer.cpp -Werror

clean:
	rm *.o prototyp4

