//
//  main.cpp
//  rubiks-cube
//
//  Created by Taz Greenwood on 8/23/17.
//  Copyright © 2017 tazgreenwood. All rights reserved.
//

#include <iostream>
#include "Cube.h"
using namespace std;

int main(int argc, const char * argv[]) {
    
    bool initialFlag = false;

    Cube block;
    string input;
    
    while (cin >> input)
    {
        if (input == "rotate")
        {
            initialFlag = false;
            string color;
            string direction;
            cin >> color;
            
            if (color != "done")
            {
                cin >> direction;
                block.rotate(color, direction);
            }
            else
            {
            }
        }
        
        
        if (initialFlag) {
            block.addTile(input);
        }
        
        if (input == "show")
        {
            block.getValues();
        }
 
        
        if (input == "initial")
        {
            initialFlag = true;
        }
    }
    return 0;
}
