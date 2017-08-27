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

void Cube::getValues()
{
    for (int i = 0; i <= mCube.size(); i++)
    {
        if (i == 0)
        {
            cout << endl;
        }
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
            cout << mCube[i] << endl;
            
        }
        if (i % 9 == 8)
        {
            cout << endl;
        }
    }
}

void Cube::readSecondCube(string value)
{
    if (value != " " || value != "\n")
    {
        mTempCube.push_back(value);
    }
    if (mTempCube.size() == mCube.size())
    {
        cout << "HIT THE END OF THE LINE" << endl;
        bool result = isEqual();
        if (result)
        {
            cout << "TRUE" << endl;
        }
        else
        {
            cout << "FALSE" << endl;
        }
    }
    
}

bool Cube::isEqual()
{
    for (int i = 0; i <= mCube.size(); i++)
    {
        if (mCube[i] != mTempCube[i])
        {
            return false;
        }
    }
    return true;
}

void Cube::rotate(string color, string direction)
{
    // RED SIDE
    if (color == "red")
    {
        if (direction == "cw")
        {
            rotateRed();
        }
        else if (direction == "ccw")
        {
            rotateRed();
            rotateRed();
            rotateRed();
        }
    }
    
    // GREEN SIDE
    else if (color == "green")
    {
        if (direction == "cw")
        {
            rotateGreen();
        }
        else if (direction == "ccw")
        {
            rotateGreen();
            rotateGreen();
            rotateGreen();
        }
    }
    
    // WHITE SIDE
    else if (color == "white")
    {
        if (direction == "cw")
        {
            rotateWhite();
        }
        else if (direction == "ccw")
        {
            rotateWhite();
            rotateWhite();
            rotateWhite();
        }
    }
    
    // YELLOW SIDE
    else if (color == "yellow")
    {
        if (direction == "cw")
        {
            rotateYellow();
        }
        else if (direction == "ccw")
        {
            rotateYellow();
            rotateYellow();
            rotateYellow();
        }
    }
    
    // BLUE SIDE
    else if (color == "blue")
    {
        if (direction == "cw")
        {
            rotateBlue();
        }
        else if (direction == "ccw")
        {
            rotateBlue();
            rotateBlue();
            rotateBlue();
        }
    }
    
    // ORANGE SIDE
    else if (color == "orange")
    {
        if (direction == "cw")
        {
            rotateOrange();
        }
        else if (direction == "ccw")
        {
            rotateOrange();
            rotateOrange();
            rotateOrange();
        }
    }
}

void Cube::rotateRed() {
    vector<string> tempCube = mCube;
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

void Cube::rotateGreen()
{
    vector<string> tempCube = mCube;
    // rotate green edges
    // white to red
    tempCube[18] = mCube[0];
    tempCube[21] = mCube[3];
    tempCube[24] = mCube[6];
    
    // red to yellow
    tempCube[45] = mCube[18];
    tempCube[48] = mCube[21];
    tempCube[51] = mCube[24];
    
    // yellow to orange
    tempCube[44] = mCube[45];
    tempCube[41] = mCube[48];
    tempCube[38] = mCube[51];
    
    // orange to white
    tempCube[0] = mCube[44];
    tempCube[3] = mCube[41];
    tempCube[6] = mCube[38];
    
    // rotate green face
    tempCube[9] = mCube[12];
    tempCube[10] = mCube[9];
    tempCube[11] = mCube[10];
    tempCube[14] = mCube[11];
    tempCube[17] = mCube[14];
    tempCube[16] = mCube[17];
    tempCube[15] = mCube[16];
    tempCube[12] = mCube[15];
    
    mCube = tempCube;
}

void Cube::rotateWhite()
{
    vector<string> tempCube = mCube;
    // rotate green edges
    // orange to blue
    tempCube[27] = mCube[36];
    tempCube[28] = mCube[37];
    tempCube[29] = mCube[38];
    
    // blue to red
    tempCube[18] = mCube[27];
    tempCube[19] = mCube[28];
    tempCube[20] = mCube[29];
    
    // red to green
    tempCube[9] = mCube[18];
    tempCube[10] = mCube[19];
    tempCube[11] = mCube[20];
    
    // green to orange
    tempCube[36] = mCube[9];
    tempCube[37] = mCube[10];
    tempCube[38] = mCube[11];
    
    // rotate white face
    tempCube[0] = mCube[3];
    tempCube[1] = mCube[0];
    tempCube[2] = mCube[1];
    tempCube[5] = mCube[2];
    tempCube[8] = mCube[5];
    tempCube[7] = mCube[8];
    tempCube[6] = mCube[7];
    tempCube[3] = mCube[6];
    
    mCube = tempCube;
}

void Cube::rotateYellow()
{
    vector<string> tempCube = mCube;
    // rotate green edges
    // orange to blue
    tempCube[42] = mCube[33];
    tempCube[43] = mCube[34];
    tempCube[44] = mCube[35];
    
    // blue to red
    tempCube[33] = mCube[24];
    tempCube[34] = mCube[25];
    tempCube[35] = mCube[26];
    
    // red to green
    tempCube[24] = mCube[15];
    tempCube[25] = mCube[16];
    tempCube[26] = mCube[17];
    
    // green to orange
    tempCube[15] = mCube[42];
    tempCube[16] = mCube[43];
    tempCube[17] = mCube[44];
    
    // rotate yellow face
    tempCube[45] = mCube[48];
    tempCube[46] = mCube[45];
    tempCube[47] = mCube[46];
    tempCube[50] = mCube[47];
    tempCube[53] = mCube[50];
    tempCube[52] = mCube[53];
    tempCube[51] = mCube[52];
    tempCube[48] = mCube[51];
    
    mCube = tempCube;
}

void Cube::rotateBlue()
{
    vector<string> tempCube = mCube;
    // rotate green edges
    // orange to yellow
    tempCube[47] = mCube[42];
    tempCube[50] = mCube[39];
    tempCube[53] = mCube[36];
    
    // yellow to red
    tempCube[20] = mCube[47];
    tempCube[23] = mCube[50];
    tempCube[26] = mCube[53];
    
    // red to white
    tempCube[2] = mCube[20];
    tempCube[5] = mCube[23];
    tempCube[8] = mCube[26];
    
    // white to orange
    tempCube[36] = mCube[8];
    tempCube[39] = mCube[5];
    tempCube[42] = mCube[2];
    
    // rotate blue face
    tempCube[27] = mCube[30];
    tempCube[28] = mCube[27];
    tempCube[29] = mCube[28];
    tempCube[32] = mCube[29];
    tempCube[35] = mCube[32];
    tempCube[34] = mCube[35];
    tempCube[33] = mCube[34];
    tempCube[30] = mCube[33];
    
    mCube = tempCube;
}

void Cube::rotateOrange()
{
    vector<string> tempCube = mCube;
    // rotate orange edges
    // white to green
    tempCube[9] = mCube[2];
    tempCube[12] = mCube[1];
    tempCube[15] = mCube[0];
    
    // green to yellow
    tempCube[51] = mCube[9];
    tempCube[52] = mCube[12];
    tempCube[53] = mCube[15];
    
    // yellow to blue
    tempCube[35] = mCube[51];
    tempCube[32] = mCube[52];
    tempCube[29] = mCube[53];
    
    // blue to white
    tempCube[2] = mCube[35];
    tempCube[1] = mCube[32];
    tempCube[0] = mCube[29];
    
    // rotate orange face
    tempCube[36] = mCube[39];
    tempCube[37] = mCube[36];
    tempCube[38] = mCube[37];
    tempCube[41] = mCube[38];
    tempCube[44] = mCube[41];
    tempCube[43] = mCube[44];
    tempCube[42] = mCube[43];
    tempCube[39] = mCube[42];
    
    mCube = tempCube;
}
