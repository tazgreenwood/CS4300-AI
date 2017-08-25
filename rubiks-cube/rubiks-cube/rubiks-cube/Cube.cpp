//
//  Cube.cpp
//  rubiks-cube
//
//  Created by Taz Greenwood on 8/23/17.
//  Copyright © 2017 tazgreenwood. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include "Cube.h"
using namespace std;

Cube::Cube()
{
}

void Cube::addTile(string value)
{
    if (value != " " || value != "\n")
    {
        mCube.push_back(value);
    }
}

void Cube::getName()
{
    cout << "Taz" << endl;
}

void Cube::getValues()
{
    for (int i = 0; i <= mCube.size(); i++)
    {
        if (i % 3 == 0)
        {
            cout << mCube[i] << " ";
        }
        else if (i % 3 == 1)
        {
            cout << mCube[i] << " ";
        }
        else if (i % 3 == 2)
        {
            if (i% 9 == 0 )
            {
                cout << "\n" << endl;
            }
            cout << mCube[i] << endl;
            
        }
    }
}

void Cube::rotate(string color, string direction)
{
    vector<string> tempCube = mCube;
    cout << color << " " << direction << endl;
    if (color == "red")
    {
        if (direction == "cw")
        {
            
            // rotate red edges
            // green to white
            tempCube[6] = mCube[17];
            tempCube[7] = mCube[14];
            tempCube[8] = mCube[11];
            
            // white to blue
            tempCube[27] = mCube[6];
            tempCube[30] = mCube[7];
            tempCube[33] = mCube[8];
            
            // blue to yellow
            tempCube[47] = mCube[27];
            tempCube[46] = mCube[30];
            tempCube[45] = mCube[33];
            
            // yellow to green
            tempCube[17] = mCube[47];
            tempCube[14] = mCube[46];
            tempCube[11] = mCube[45];

            // rotate red face
            tempCube[18] = mCube[21];
            tempCube[19] = mCube[18];
            tempCube[20] = mCube[19];
            tempCube[23] = mCube[20];
            tempCube[26] = mCube[23];
            tempCube[25] = mCube[26];
            tempCube[24] = mCube[25];
            tempCube[21] = mCube[24];
            
            mCube = tempCube;
        }
        else if (direction == "ccw")
        {
            // rotate red edges
            // white to green
            tempCube[17] = mCube[6];
            tempCube[14] = mCube[7];
            tempCube[11] = mCube[8];
            
            // blue to white
            tempCube[6] = mCube[27];
            tempCube[7] = mCube[30];
            tempCube[8] = mCube[33];
            
            // yellow to blue
            tempCube[27] = mCube[47];
            tempCube[30] = mCube[46];
            tempCube[33] = mCube[45];
            
            // green to yellow
            tempCube[47] = mCube[17];
            tempCube[46] = mCube[14];
            tempCube[45] = mCube[11];
            
            // rotate red face
            tempCube[21] = mCube[18];
            tempCube[18] = mCube[19];
            tempCube[19] = mCube[20];
            tempCube[20] = mCube[23];
            tempCube[23] = mCube[26];
            tempCube[26] = mCube[25];
            tempCube[25] = mCube[24];
            tempCube[24] = mCube[21];
            
            mCube = tempCube;
        }
    }
}
