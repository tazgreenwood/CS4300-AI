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

const bool DEBUGGING_ON = false;

Cube::Cube()
{
    mColorTracker = 0;
    mCube["white"] = vector<string>();
    mCube["green"] = vector<string>();
    mCube["red"] = vector<string>();
    mCube["blue"] = vector<string>();
    mCube["orange"] = vector<string>();
    mCube["yellow"] = vector<string>();
}

void Cube::importValues(string color)
{
    mColorTracker += 1;
    if (color == " " || color == "\n")
    {
    }
    else if (mColorTracker <= 9)
    {
        mCube["white"].push_back(color);
    }
    else if (mColorTracker <= 18)
    {
        mCube["green"].push_back(color);
    }
    else if (mColorTracker <= 27)
    {
        mCube["red"].push_back(color);
    }
    else if (mColorTracker <= 36)
    {
        mCube["blue"].push_back(color);
    }
    else if (mColorTracker <= 45)
    {
        mCube["orange"].push_back(color);
    }
    else
    {
        mCube["yellow"].push_back(color);
    }
}

void Cube::showCube()
{
    if (DEBUGGING_ON)
    {
        cout << "RUNNING showCube()" << endl;
    }
    int colorIndex = 0;
    string currentColor;
    for (int j = 0; j < mCube.size(); j++)
    {
        switch(colorIndex){
            case 0  :
               currentColor = "white";
               break; //optional
            case 1  :
               currentColor = "green";
               break; //optional
            case 2  :
               currentColor = "red";
               break; //optional
            case 3  :
               currentColor = "blue";
               break; //optional
            case 4  :
               currentColor = "orange";
               break; //optional
            case 5  :
               currentColor = "yellow";
               break; //optional
           
            default : //Optional
               break;
         }
        for (int i = 0; i < mCube[currentColor].size(); i++)
        {
            if (mCube[currentColor][i] != " " || mCube[currentColor][i] != "\n")
            {
                if (i % 3 == 0 || i % 3 == 1)
                {
                    cout << mCube[currentColor][i] << " ";
                }
                if (i % 3 == 2)
                {
                    cout << mCube[currentColor][i] << endl;
                }
                if (i % 9 == 8)
                {
                    cout << endl;
                }
            }
        }
        colorIndex += 1;
    }
}

void Cube::rotate(string color, string direction)
{
    if (color == "white")
    {
        rotateWhite(direction);
    }
    else if (color == "green")
    {
        rotateGreen(direction);
    }
    else if (color == "red")
    {
        rotateRed(direction);
    }
    else if (color == "blue")
    {
        rotateBlue(direction);
    }
    else if (color == "orange")
    {
        rotateOrange(direction);
    }
    else if (color == "yellow")
    {
        rotateYellow(direction);
    }
    else 
    {
        cout << "invalid color: " << color << endl;
    }
}

bool Cube::operator==(const Cube rhs) const
{
    
    // grab values for each color
    // see if they are the same for both cubes
    string color;
    vector<string> a;
    vector<string> b;
    for (int i = 0; i < this->mCube.size(); i++)
    {
        if (i==0)
            color ="white";
        if (i==1)
            color = "green";
        if (i==2)
            color = "red";
        if (i==3)
            color = "blue";
        if (i==4)
            color = "orange";
        if (i==5)
            color = "yellow";

        a = this->mCube.find(color)->second;
        b = rhs.mCube.find(color)->second;
        
        for (int j = 0; j < a.size(); j++)
        {
            if (a[j] != b[j])
            {
                return false;
            }
        }
        
    }
    return true;
}

void Cube::rotateFace(string color, string direction)
{
    if (DEBUGGING_ON)
    {
        cout << "RUNNING rotateFace()" << endl;
    }
    std::map <std::string, std::vector<std::string>> tempCube = mCube;
    if (direction == "ccw")
    {
        tempCube[color][6] = mCube[color][0];
        tempCube[color][3] = mCube[color][1];
        tempCube[color][0] = mCube[color][2];
        tempCube[color][1] = mCube[color][5];
        tempCube[color][2] = mCube[color][8];
        tempCube[color][5] = mCube[color][7];
        tempCube[color][8] = mCube[color][6];
        tempCube[color][7] = mCube[color][3];
        mCube = tempCube;
    }
    if (direction == "cw")
    {
        tempCube[color][2] = mCube[color][0];
        tempCube[color][5] = mCube[color][1];
        tempCube[color][8] = mCube[color][2];
        tempCube[color][7] = mCube[color][5];
        tempCube[color][6] = mCube[color][8];
        tempCube[color][3] = mCube[color][7];
        tempCube[color][0] = mCube[color][6];
        tempCube[color][1] = mCube[color][3];
        mCube = tempCube;
    }
}

void Cube::rotateWhite(string direction)
{
    rotateFace("white", direction);
    
    std::map <std::string, std::vector<std::string>> tempCube = mCube;    
    if (direction == "ccw")
    {
        tempCube["orange"][2] = mCube["blue"][2];
        tempCube["orange"][1] = mCube["blue"][1];
        tempCube["orange"][0] = mCube["blue"][0];

        tempCube["blue"][2] = mCube["red"][2];
        tempCube["blue"][1] = mCube["red"][1];
        tempCube["blue"][0] = mCube["red"][0];

        tempCube["red"][2] = mCube["green"][2];
        tempCube["red"][1] = mCube["green"][1];
        tempCube["red"][0] = mCube["green"][0];

        tempCube["green"][2] = mCube["orange"][2];
        tempCube["green"][1] = mCube["orange"][1];
        tempCube["green"][0] = mCube["orange"][0];
    }
    else if (direction == "cw")
    {
        tempCube["orange"][2] = mCube["green"][2];
        tempCube["orange"][1] = mCube["green"][1];
        tempCube["orange"][0] = mCube["green"][0];

        tempCube["green"][2] = mCube["red"][2];
        tempCube["green"][1] = mCube["red"][1];
        tempCube["green"][0] = mCube["red"][0];

        tempCube["red"][2] = mCube["blue"][2];
        tempCube["red"][1] = mCube["blue"][1];
        tempCube["red"][0] = mCube["blue"][0];

        tempCube["blue"][2] = mCube["orange"][2];
        tempCube["blue"][1] = mCube["orange"][1];
        tempCube["blue"][0] = mCube["orange"][0];
    }
    else
    {
        cout << "invalid direction: " << direction << endl;
    }
    mCube = tempCube;
}

void Cube::rotateGreen(string direction)
{
    rotateFace("green", direction);
    
    std::map <std::string, std::vector<std::string>> tempCube = mCube;    
    if (direction == "ccw")
    {
        tempCube["white"][0] = mCube["red"][0];
        tempCube["white"][3] = mCube["red"][3];
        tempCube["white"][6] = mCube["red"][6];

        tempCube["red"][0] = mCube["yellow"][0];
        tempCube["red"][3] = mCube["yellow"][3];
        tempCube["red"][6] = mCube["yellow"][6];

        tempCube["yellow"][0] = mCube["orange"][8];
        tempCube["yellow"][3] = mCube["orange"][5];
        tempCube["yellow"][6] = mCube["orange"][2];

        tempCube["orange"][8] = mCube["white"][0];
        tempCube["orange"][5] = mCube["white"][3];
        tempCube["orange"][2] = mCube["white"][6];
    }
    else if (direction == "cw")
    {
        tempCube["white"][6] = mCube["orange"][2];
        tempCube["white"][3] = mCube["orange"][5];
        tempCube["white"][0] = mCube["orange"][8];

        tempCube["orange"][8] = mCube["yellow"][0];
        tempCube["orange"][5] = mCube["yellow"][3];
        tempCube["orange"][2] = mCube["yellow"][6];

        tempCube["yellow"][0] = mCube["red"][0];
        tempCube["yellow"][3] = mCube["red"][3];
        tempCube["yellow"][6] = mCube["red"][6];

        tempCube["red"][0] = mCube["white"][0];
        tempCube["red"][3] = mCube["white"][3];
        tempCube["red"][6] = mCube["white"][6];
    }
    else
    {
        cout << "invalid direction: " << direction << endl;
    }
    mCube = tempCube;
}

void Cube::rotateRed(string direction)
{
    rotateFace("red", direction);
    
    std::map <std::string, std::vector<std::string>> tempCube = mCube;    
    if (direction == "ccw")
    {
        tempCube["white"][6] = mCube["blue"][0];
        tempCube["white"][7] = mCube["blue"][3];
        tempCube["white"][8] = mCube["blue"][6];

        tempCube["blue"][0] = mCube["yellow"][2];
        tempCube["blue"][3] = mCube["yellow"][1];
        tempCube["blue"][6] = mCube["yellow"][0];

        tempCube["yellow"][2] = mCube["green"][8];
        tempCube["yellow"][1] = mCube["green"][5];
        tempCube["yellow"][0] = mCube["green"][2];

        tempCube["green"][8] = mCube["white"][6];
        tempCube["green"][5] = mCube["white"][7];
        tempCube["green"][2] = mCube["white"][8];
    }
    else if (direction == "cw")
    {
        tempCube["white"][6] = mCube["green"][8];
        tempCube["white"][7] = mCube["green"][5];
        tempCube["white"][8] = mCube["green"][2];

        tempCube["green"][2] = mCube["yellow"][0];
        tempCube["green"][5] = mCube["yellow"][1];
        tempCube["green"][8] = mCube["yellow"][2];

        tempCube["yellow"][0] = mCube["blue"][6];
        tempCube["yellow"][1] = mCube["blue"][3];
        tempCube["yellow"][2] = mCube["blue"][0];

        tempCube["blue"][6] = mCube["white"][8];
        tempCube["blue"][3] = mCube["white"][7];
        tempCube["blue"][0] = mCube["white"][6];
    }
    else
    {
        cout << "invalid direction: " << direction << endl;
    }
    mCube = tempCube;
}

void Cube::rotateBlue(string direction)
{
    rotateFace("blue", direction);
    
    std::map <std::string, std::vector<std::string>> tempCube = mCube;    
    if (direction == "ccw")
    {
        tempCube["white"][8] = mCube["orange"][0];
        tempCube["white"][5] = mCube["orange"][3];
        tempCube["white"][2] = mCube["orange"][6];

        tempCube["orange"][0] = mCube["yellow"][8];
        tempCube["orange"][3] = mCube["yellow"][5];
        tempCube["orange"][6] = mCube["yellow"][2];

        tempCube["yellow"][8] = mCube["red"][8];
        tempCube["yellow"][5] = mCube["red"][5];
        tempCube["yellow"][2] = mCube["red"][2];

        tempCube["red"][8] = mCube["white"][8];
        tempCube["red"][5] = mCube["white"][5];
        tempCube["red"][2] = mCube["white"][2];
    }
    else if (direction == "cw")
    {
        tempCube["white"][8] = mCube["red"][8];
        tempCube["white"][5] = mCube["red"][5];
        tempCube["white"][2] = mCube["red"][2];

        tempCube["red"][8] = mCube["yellow"][8];
        tempCube["red"][5] = mCube["yellow"][5];
        tempCube["red"][2] = mCube["yellow"][2];

        tempCube["yellow"][8] = mCube["orange"][0];
        tempCube["yellow"][5] = mCube["orange"][3];
        tempCube["yellow"][2] = mCube["orange"][6];

        tempCube["orange"][0] = mCube["white"][8];
        tempCube["orange"][3] = mCube["white"][5];
        tempCube["orange"][6] = mCube["white"][2];
    }
    else
    {
        cout << "invalid direction: " << direction << endl;
    }
    mCube = tempCube;
}

void Cube::rotateOrange(string direction)
{
    rotateFace("orange", direction);
    
    std::map <std::string, std::vector<std::string>> tempCube = mCube;    
    if (direction == "ccw")
    {
        tempCube["white"][0] = mCube["green"][6];
        tempCube["white"][1] = mCube["green"][3];
        tempCube["white"][2] = mCube["green"][0];

        tempCube["green"][6] = mCube["yellow"][8];
        tempCube["green"][3] = mCube["yellow"][7];
        tempCube["green"][0] = mCube["yellow"][6];

        tempCube["yellow"][8] = mCube["blue"][2];
        tempCube["yellow"][7] = mCube["blue"][5];
        tempCube["yellow"][6] = mCube["blue"][8];

        tempCube["blue"][2] = mCube["white"][0];
        tempCube["blue"][5] = mCube["white"][1];
        tempCube["blue"][8] = mCube["white"][2];
    }
    else if (direction == "cw")
    {
        tempCube["white"][0] = mCube["blue"][2];
        tempCube["white"][1] = mCube["blue"][5];
        tempCube["white"][2] = mCube["blue"][8];

        tempCube["blue"][2] = mCube["yellow"][8];
        tempCube["blue"][5] = mCube["yellow"][7];
        tempCube["blue"][8] = mCube["yellow"][6];

        tempCube["yellow"][8] = mCube["green"][6];
        tempCube["yellow"][7] = mCube["green"][3];
        tempCube["yellow"][6] = mCube["green"][0];

        tempCube["green"][6] = mCube["white"][0];
        tempCube["green"][3] = mCube["white"][1];
        tempCube["green"][0] = mCube["white"][2];
    }
    else
    {
        cout << "invalid direction: " << direction << endl;
    }
    mCube = tempCube;
}

void Cube::rotateYellow(string direction)
{
    rotateFace("yellow", direction);
    
    std::map <std::string, std::vector<std::string>> tempCube = mCube;    
    if (direction == "ccw")
    {
        tempCube["red"][6] = mCube["blue"][6];
        tempCube["red"][7] = mCube["blue"][7];
        tempCube["red"][8] = mCube["blue"][8];

        tempCube["blue"][6] = mCube["orange"][6];
        tempCube["blue"][7] = mCube["orange"][7];
        tempCube["blue"][8] = mCube["orange"][8];

        tempCube["orange"][6] = mCube["green"][6];
        tempCube["orange"][7] = mCube["green"][7];
        tempCube["orange"][8] = mCube["green"][8];

        tempCube["green"][6] = mCube["red"][6];
        tempCube["green"][7] = mCube["red"][7];
        tempCube["green"][8] = mCube["red"][8];
    }
    else if (direction == "cw")
    {
        tempCube["red"][6] = mCube["green"][6];
        tempCube["red"][7] = mCube["green"][7];
        tempCube["red"][8] = mCube["green"][8];

        tempCube["green"][6] = mCube["orange"][6];
        tempCube["green"][7] = mCube["orange"][7];
        tempCube["green"][8] = mCube["orange"][8];

        tempCube["orange"][6] = mCube["blue"][6];
        tempCube["orange"][7] = mCube["blue"][7];
        tempCube["orange"][8] = mCube["blue"][8];

        tempCube["blue"][6] = mCube["red"][6];
        tempCube["blue"][7] = mCube["red"][7];
        tempCube["blue"][8] = mCube["red"][8];
    }
    else
    {
        cout << "invalid direction: " << direction << endl;
    }
    mCube = tempCube;
}