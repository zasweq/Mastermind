//
//  Code.hpp
//  Something
//
//  Created by Zach Reyes on 12/10/19.
//  Copyright © 2019 Zach Reyes. All rights reserved.
//

#ifndef Code_hpp
#define Code_hpp

#include <stdio.h>
#include "Color.hpp"

class Code {
public:
    Code() {
        
    }
    
    void setColors(Color colors[]) {
        for (int i = 0; i < 4; i++) {
            fColors[i] = colors[i];
        }
    }
    
    Color operator[](int index) {
        return fColors[index];
    }
    
    Color* getColors() {
        return fColors;
    }
    
    /*ResponseColor* response(Code* otherCode){
        
    }*/
    
private:
    Color fColors[4];
};
#endif /* Code_hpp */
