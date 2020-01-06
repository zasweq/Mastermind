#ifndef AutoSolve_hpp
#define AutoSolve_hpp

#include <stdio.h>
#include <iostream>
#include <set>
#include <stdlib.h>
#include "Utils.hpp"
#include "Color.hpp"
#include "Code.hpp"

//To use user defined types as key, use a comparator function object class for it

struct CodeCompare {
    bool operator() (const Code& one, const Code& two) const {
        return true;
    }
};

//This set may need to persist statically
std::set<Code, CodeCompare> setUpSet() {
    std::set<Code, CodeCompare> codes;
    Code code;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            for (int k = 0; k < 6; k++) {
                for (int l = 0; l < 6; l++) {
                    *(code.getColors()) = static_cast<Color>(i);
                    *(code.getColors() + 1) = static_cast<Color>(j);
                    *(code.getColors() + 2) = static_cast<Color>(k);
                    *(code.getColors() + 3) = static_cast<Color>(l);
                    codes.insert(code);
                }
            }
        }
    }
    return codes;
}

//Needs response

//Takes out all the possible codes that couldn't have returned that response
void handleSetFromResponse(Code code, std::set<Code, CodeCompare> codes) {
    //I could brute force it and run it against response a ton of times, yeah I'm going to do that
    //Two options for this: either I construct some sort of mapping each iteration, or I have a seperate modular method that doesn't scramble
    
}

void autoSolveIn5Turns() {
    Code computerCode = createRandomCode();
    std::set<Code, CodeCompare> codes = setUpSet();
    Code initial = setUpCode("B B G G");
    printResponseVector(response(computerCode, initial));
}

#endif /* AutoSolve_hpp */
