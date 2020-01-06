#include <iostream>
#include <vector>
#include <map>
#include <stdlib.h>
#include <time.h>
#include "Code.hpp"
#include "Utils.hpp"
#include "Tests.hpp"
#include "AutoSolve.hpp"

//Code algorithm that automatically solves it

//Command line arguments - Number of turns, number of players, figure out logic for number of turns

//Maybe make this into a class, maybe come up with a computer that plays against you

void setUpGame() {
    int players;
    int turns;
    std::cout << "One Player or Two Player (1 or 2) ? ";
    std::cin >> players;
    if (players != 1 && players != 2) {
        std::cout << "Cannot have that many players" << std::endl;
        return;
    }
    std::cout << "Number of turns (must be even) ? "; //endl just represents newline pretty much
    std::cin >> turns;
    if (turns % 2 != 0) {
        std::cout << "Turns are not even \n" << std::endl;
        return;
    }
    
    if (players == 1) {
        gameLoopOnePlayer(turns);
    } else {
        gameTwoPlayer(turns);
    }
}


int main(int argc, const char* argv[]) {
    //unitTests();
    //setUpGame();
    setUpSet();
}
