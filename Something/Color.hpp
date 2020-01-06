#ifndef Color_hpp
#define Color_hpp

#include <stdio.h>
#include <map>

enum Color {
    Blue,
    Green,
    Orange,
    Purple,
    Red,
    Yellow
};

enum ResponseColor {
    Black,
    White,
    Null
};


//One solution, or use map
/*
static const char* ResponseColorStrings[] = {"B ", "W ", "N "};

const char* ResponseColorString(int index) {
    return ResponseColorStrings[index];
}
*/

#endif /* Color_hpp */
