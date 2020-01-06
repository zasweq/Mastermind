
#ifndef Tests_hpp
#define Tests_hpp

#include <stdio.h>
#include "Utils.hpp"

void unitTests() { //test both functional, and negative
    Code code1 = setUpCode("B B B B");
    Code code2 = setUpCode("B B B B");
    printResponseVector(response(code1, code2));
    code1 = setUpCode("B B P P");
    code2 = setUpCode("P P B B");
    printResponseVector(response(code1, code2));
    code1 = setUpCode("B B P P");
    code2 = setUpCode("P B B B");
    printResponseVector(response(code1, code2));
    code1 = setUpCode("B B B P");
    code2 = setUpCode("O O O Y");
    printResponseVector(response(code1, code2));
    code1 = setUpCode("B O B O");
    code2 = setUpCode("B B O B");
    printResponseVector(response(code1, code2));
}

#endif /* Tests_hpp */
