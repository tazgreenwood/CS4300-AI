//
//  Cube.h
//  rubiks-cube
//
//  Created by Taz Greenwood on 8/23/17.
//  Copyright © 2017 tazgreenwood. All rights reserved.
//

#ifndef Cube_h
#define Cube_h
#include <vector>

class Cube
{
public:
    Cube();
    void getValues();
    bool isEqual();
    void readSecondCube(std::string value);
    void addTile(std::string value);
    void rotate(std::string color, std::string direction);
    void rotateRed();
    void rotateGreen();
    void rotateWhite();
    void rotateYellow();
    void rotateBlue();
    void rotateOrange();

private:
    std::vector<std::string> mCube;
    std::vector<std::string> mTempCube;    
};


#endif /* Cube_h */
