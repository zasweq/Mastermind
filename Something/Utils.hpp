#ifndef Utils_hpp
#define Utils_hpp

#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include "Code.hpp"

void gameOnePlayer(int turns);

void gameTwoPlayer(int turns);

std::vector<ResponseColor> response(Code breaker, Code maker);

void solveCodeIn5Turns() {
    
}

Code createRandomCode() {
    int random;
    Code computerCode;
    srand(time(NULL));
    for (int i = 0; i < 4; i++) {
        random = rand() % 6;
        *(computerCode.getColors() + i) = static_cast<Color>(random); //figure out this logic, and if randomization is correct
    }
    return computerCode;
}

Code setUpCode(std::string guess) { //Interesting, if this guess passed empty string, sets up default array of Enums which sets to blue
    Code code;
    int index = 0;
    for (int i = 0; i < guess.size(); i++) {
        Color color;
        if (guess[i] != ' ') {
            switch (guess[i]) {
                case 'B':
                    color = Blue;
                    break;
                case 'G':
                    color = Green;
                    break;
                case 'O':
                    color = Orange;
                    break;
                case 'P':
                    color = Purple;
                    break;
                case 'R':
                    color = Red;
                    break;
                case 'Y':
                    color = Yellow;
                    break;
            }
            *(code.getColors() + index) = color;
            index++;
        }
    }
    return code;
}

//Need to randomize order of vector
void printResponseVector(std::vector<ResponseColor> response) {
    std::random_shuffle(response.begin(), response.end());
    for (ResponseColor responseColor: response) {
        std::string toPrint;
        switch (responseColor) {
            case Black:
                toPrint = "B ";
                break;
            case White:
                toPrint = "W ";
                break;
            case Null:
                toPrint = "N ";
                break;
        }
        std::cout << toPrint;
    }
    std::cout << "\n";
}

//setUpGame

//GameLoop

//Move this random code into a random method

void gameLoopOnePlayer(int turns) { //Hardcoded, fix later
    //Come up with a randomized code
    Code computerCode = createRandomCode();
    
    std::string guess;
    Code breakerCode;
    
    for (int i = 0; i <= turns; i++) {
        //Select from six options Blue B, Green G, Orange O, Purple P, Red R, Yellow Y
        if (i != 0)
            std::cout << "Please enter your guess seperated by spaces: \n";
        //std::cin >> guess;
        std::getline(std::cin, guess);
        if (guess == "")
            continue;
        //Iterate through string
        breakerCode = setUpCode(guess);
        printResponseVector(response(breakerCode, computerCode));
    }
}

//Do this later
void gameTwoPlayer(int turns) {
    
}


//Perhaps decouple this method later
std::vector<ResponseColor> response(Code breaker, Code maker) {
    std::vector<ResponseColor> responses;
    //Let me try a hashmap of indiecies
    std::map<int, int> mapIndexes; //maps
    mapIndexes.insert(std::pair<int, int>(1, 0));
    mapIndexes.insert(std::pair<int, int>(2, 0));
    mapIndexes.insert(std::pair<int, int>(3, 0));
    mapIndexes.insert(std::pair<int, int>(4, 0));
    
    //Maps how many each, as you iterate through get rid of in both maps
    //Maybe have this be state in the Code class
    std::map<Color, int> mapBreaker;
    std::map<Color, int> mapMaker;
    mapBreaker.insert(std::pair<Color, int>(Blue, 0));
    mapMaker.insert(std::pair<Color, int>(Blue, 0));
    mapBreaker.insert(std::pair<Color, int>(Green, 0));
    mapMaker.insert(std::pair<Color, int>(Green, 0));
    mapBreaker.insert(std::pair<Color, int>(Orange, 0));
    mapMaker.insert(std::pair<Color, int>(Orange, 0));
    mapBreaker.insert(std::pair<Color, int>(Purple, 0));
    mapMaker.insert(std::pair<Color, int>(Purple, 0));
    mapBreaker.insert(std::pair<Color, int>(Red, 0));
    mapMaker.insert(std::pair<Color, int>(Red, 0));
    mapBreaker.insert(std::pair<Color, int>(Yellow, 0));
    mapMaker.insert(std::pair<Color, int>(Yellow, 0));
    
    for (int i = 0; i < 4; i++) {
        mapBreaker[breaker[i]] += 1;
        mapMaker[maker[i]] += 1;
    }

    //Those that are equal,
    for (int i = 0; i < 4; i++) {
        if (breaker[i] == maker[i]) {
            mapBreaker[breaker[i]] -= 1;
            mapMaker[maker[i]] -= 1;
            mapIndexes[i + 1] = i + 1;
        }
    }
    
    //For those that aren't equal (map hasn't been set to a number) search for others
    for (int i = 0; i < 4; i++) {
        if (mapIndexes[i + 1] != i + 1) { //not already mapped to something
            if (mapBreaker[breaker[i]] == mapMaker[breaker[i]]) { //checking for the clause of the numbers of colors left are equal
                mapIndexes[i + 1] = -1; //represents a hit
            }
        }
    }
    
    //"No indication is given of the fact that the code also includes a second black." - so I guess that means I need to create another hashmap that maps colors to numbers of colors
    for (int i = 0; i < 4; i++) {
        if (mapIndexes[i + 1] == i + 1) {
            responses.push_back(Black);
            continue;
        } else if (mapIndexes[i + 1] == -1) {
            responses.push_back(White);
            continue;
        } else { //==0, means that it isn't either in correct place or incorrect place with colors left equal
            responses.push_back(Null);
            continue;
        }
    }
    //responses.push_back(Black);
    return responses;
}

#endif /* Utils_hpp */
