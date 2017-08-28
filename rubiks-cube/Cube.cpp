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

bool DEBUGGING_ON = false;

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
    if (DEBUGGING_ON)
    {
        cout << "RUNNING GETVALUES" << endl;
    }
    for (int i = 0; i <= mCube.size()-1; i++)
    {
        if (i % 3 == 0)
        {
            if (DEBUGGING_ON)
            {
                cout << mCube[i] << i << " ";
            }
            else
            {
                cout << mCube[i] << " ";
            }
        }
        else if (i % 3 == 1)
        {
            if (DEBUGGING_ON)
            {
                cout << mCube[i] << i << " ";
            }
            else
            {
                cout << mCube[i] << " ";
            }
        }
        else if (i % 3 == 2)
        {
            if (DEBUGGING_ON)
            {
                cout << mCube[i] << i << endl;
            }
            else
            {
                cout << mCube[i] << endl;
            }

        }
        if (i % 9 == 8)
        {
            cout << "\n";
        }
    }
}

void Cube::readSecondCube(string value)
{
    if (value != " " || value != "\n")
    {
        mTempCube.push_back(value);
    }

    if (mTempCube.size() == 54)
    {
        if (DEBUGGING_ON)
        {
        cout << "ALL VALUES OF SECOND CUBE HAVE BEEN READ." << endl;
        }
        isEqual();
    }
}

bool Cube::isEqual()
{
    if (DEBUGGING_ON)
    {
        cout << "RUNNING ISEQUAL" << endl;
    }

    for (int i = 0; i <= mCube.size(); i++)
    {
        if (mCube[i] != mTempCube[i])
        {
            cout << "FALSE" << endl;
            return false;
        }
    }
    cout << "TRUE" << endl;
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
            rotateRedCCW();
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
            rotateGreenCCW();
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
            rotateWhiteCCW();
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
            rotateYellowCCW();
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
            rotateBlueCCW();
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
            rotateOrangeCCW();
        }
    }
}

void Cube::rotateRed() {
    if (DEBUGGING_ON)
    {
        cout << "RUNNING rotateRed()" << endl;
    }
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

void Cube::rotateRedCCW() {
    if (DEBUGGING_ON)
    {
        cout << "RUNNING rotateRedCCW()" << endl;
    }
    vector<string> tempCube = mCube;
    // rotate red edges
    // green to white
    tempCube[17] = mCube[6];
    tempCube[14] = mCube[7];
    tempCube[11] = mCube[8];

    // white to blue
    tempCube[6] = mCube[27];
    tempCube[7] = mCube[30];
    tempCube[8] = mCube[33];

    // blue to yellow
    tempCube[27] = mCube[47];
    tempCube[30] = mCube[46];
    tempCube[33] = mCube[45];

    // yellow to green
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

void Cube::rotateGreen()
{
    if (DEBUGGING_ON)
    {
        cout << "RUNNING rotateGreen()" << endl;
    }
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

void Cube::rotateGreenCCW()
{
    if (DEBUGGING_ON)
    {
        cout << "RUNNING rotateGreenCCW()" << endl;
    }
    vector<string> tempCube = mCube;
    // rotate green edges
    // white to red
    tempCube[0] = mCube[18];
    tempCube[3] = mCube[21];
    tempCube[6] = mCube[24];

    // red to yellow
    tempCube[18] = mCube[45];
    tempCube[21] = mCube[48];
    tempCube[24] = mCube[51];

    // yellow to orange
    tempCube[45] = mCube[44];
    tempCube[48] = mCube[41];
    tempCube[51] = mCube[38];

    // orange to white
    tempCube[44] = mCube[0];
    tempCube[41] = mCube[3];
    tempCube[38] = mCube[6];

    // rotate green face
    tempCube[12] = mCube[9];
    tempCube[9] = mCube[10];
    tempCube[10] = mCube[11];
    tempCube[11] = mCube[14];
    tempCube[14] = mCube[17];
    tempCube[17] = mCube[16];
    tempCube[16] = mCube[15];
    tempCube[15] = mCube[12];

    mCube = tempCube;
}

void Cube::rotateWhite()
{
    if (DEBUGGING_ON)
    {
        cout << "RUNNING rotateWhite()" << endl;
    }
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

void Cube::rotateWhiteCCW()
{
    if (DEBUGGING_ON)
    {
        cout << "RUNNING rotateWhiteCCW()" << endl;
    }
    vector<string> tempCube = mCube;
    // rotate green edges
    // orange to blue
    tempCube[36] = mCube[27];
    tempCube[37] = mCube[28];
    tempCube[38] = mCube[29];

    // blue to red
    tempCube[27] = mCube[18];
    tempCube[28] = mCube[19];
    tempCube[29] = mCube[20];

    // red to green
    tempCube[18] = mCube[9];
    tempCube[19] = mCube[10];
    tempCube[20] = mCube[11];

    // green to orange
    tempCube[9] = mCube[36];
    tempCube[10] = mCube[37];
    tempCube[11] = mCube[38];

    // rotate white face
    tempCube[3] = mCube[0];
    tempCube[0] = mCube[1];
    tempCube[1] = mCube[2];
    tempCube[2] = mCube[5];
    tempCube[5] = mCube[8];
    tempCube[8] = mCube[7];
    tempCube[7] = mCube[6];
    tempCube[6] = mCube[3];

    mCube = tempCube;
}

void Cube::rotateYellow()
{
    if (DEBUGGING_ON)
    {
        cout << "RUNNING rotateYellow()" << endl;
    }
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

void Cube::rotateYellowCCW()
{
    if (DEBUGGING_ON)
    {
        cout << "RUNNING rotateYellowCCW()" << endl;
    }
    vector<string> tempCube = mCube;
    // rotate green edges
    // orange to blue
    tempCube[33] = mCube[42];
    tempCube[34] = mCube[43];
    tempCube[35] = mCube[44];

    // blue to red
    tempCube[24] = mCube[33];
    tempCube[25] = mCube[34];
    tempCube[26] = mCube[35];

    // red to green
    tempCube[15] = mCube[24];
    tempCube[16] = mCube[25];
    tempCube[17] = mCube[26];

    // green to orange
    tempCube[42] = mCube[15];
    tempCube[43] = mCube[16];
    tempCube[44] = mCube[17];

    // rotate yellow face
    tempCube[48] = mCube[45];
    tempCube[45] = mCube[46];
    tempCube[46] = mCube[47];
    tempCube[47] = mCube[50];
    tempCube[50] = mCube[53];
    tempCube[53] = mCube[52];
    tempCube[52] = mCube[51];
    tempCube[51] = mCube[48];

    mCube = tempCube;
}

void Cube::rotateBlue()
{
    if (DEBUGGING_ON)
    {
        cout << "RUNNING rotateBlue()" << endl;
    }
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

void Cube::rotateBlueCCW()
{
    if (DEBUGGING_ON)
    {
        cout << "RUNNING rotateBlueCCW()" << endl;
    }
    vector<string> tempCube = mCube;
    // rotate green edges
    // orange to yellow
    tempCube[42] = mCube[47];
    tempCube[39] = mCube[50];
    tempCube[36] = mCube[53];

    // yellow to red
    tempCube[47] = mCube[20];
    tempCube[50] = mCube[23];
    tempCube[53] = mCube[26];

    // red to white
    tempCube[20] = mCube[2];
    tempCube[23] = mCube[5];
    tempCube[26] = mCube[8];

    // white to orange
    tempCube[8] = mCube[36];
    tempCube[5] = mCube[39];
    tempCube[2] = mCube[42];

    // rotate blue face
    tempCube[30] = mCube[27];
    tempCube[27] = mCube[28];
    tempCube[28] = mCube[29];
    tempCube[29] = mCube[32];
    tempCube[32] = mCube[35];
    tempCube[35] = mCube[34];
    tempCube[34] = mCube[33];
    tempCube[33] = mCube[30];

    mCube = tempCube;
}

void Cube::rotateOrange()
{
    if (DEBUGGING_ON)
    {
        cout << "RUNNING rotateOrange()" << endl;
    }
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

void Cube::rotateOrangeCCW()
{
    if (DEBUGGING_ON)
    {
        cout << "RUNNING rotateOrangeCCW()" << endl;
    }
    vector<string> tempCube = mCube;
    // rotate orange edges
    // white to green
    tempCube[2] = mCube[9];
    tempCube[1] = mCube[12];
    tempCube[0] = mCube[15];

    // green to yellow
    tempCube[9] = mCube[51];
    tempCube[12] = mCube[52];
    tempCube[15] = mCube[53];

    // yellow to blue
    tempCube[51] = mCube[35];
    tempCube[52] = mCube[32];
    tempCube[53] = mCube[29];

    // blue to white
    tempCube[35] = mCube[2];
    tempCube[32] = mCube[1];
    tempCube[29] = mCube[0];

    // rotate orange face
    tempCube[39] = mCube[36];
    tempCube[36] = mCube[37];
    tempCube[37] = mCube[38];
    tempCube[38] = mCube[41];
    tempCube[41] = mCube[44];
    tempCube[44] = mCube[43];
    tempCube[43] = mCube[42];
    tempCube[42] = mCube[39];

    mCube = tempCube;
}
