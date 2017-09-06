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

const bool DEBUGGING_ON = false;

int main() {
    if (DEBUGGING_ON)
    {
        cout << "RUNNING main()" << endl;
    }

    // Create initial variables
    string input;
    Cube block;
    Cube testBlock;        
    bool initial = false;
    bool secondary = false;
    int counter = 0;

    while (cin >> input)
    {
        // =====================
        // Handle Cube Rotations
        // =====================
        if (input == "rotate")
        {
            initial = false;
            string color, direction;
            cin >> color;
            if (color == "done")
            {   

            }
            else
            {
                cin >> direction;
                block.rotate(color, direction);
            }
        }

        // ===============
        // Initialize Cube
        // ===============
        if (initial)
        {
            block.importValues(input);
        }
        if (input == "initial")
        {
            initial = true;
        }


        // =======================
        // Show Current Cube State
        // =======================
        if (input == "show")
        {
            block.showCube();
        }

        // ==============
        // Handle isEqual
        // ==============
        if (secondary)
        {
            counter += 1;
            testBlock.importValues(input);
        }
        if (input == "isequal")
        {
            secondary = true;
        }
        if (counter == 54)
        {
            if (block == testBlock)
            {
                cout << "TRUE" << endl;
            }
            else
            {
                cout << "FALSE" << endl;
            }
        }
    }
    return 0;
}
