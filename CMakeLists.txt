cmake_minimum_required(VERSION 3.26)
project(uebung1)

set(CMAKE_CXX_STANDARD 17)

add_executable(uebung1 main.cpp
        hero.cpp
        item.cpp
        item.h
        hero.h
        character.h
        character.cpp
        RandomUtil.h
        npc.h
        sorcerer.cpp
        sorcerer.h
        fighter.cpp
        fighter.h
        exceptions.h)
