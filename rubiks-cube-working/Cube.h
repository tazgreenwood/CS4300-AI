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
#include <map>

class Cube
{
public:
    Cube();
    void importValues(std::string color);
    void showCube();
    void rotate(std::string color, std::string direction);
    bool operator==(const Cube rhs) const;

protected:
    void rotateFace(std::string color, std::string direction);
    void rotateWhite(std::string direction);
    void rotateGreen(std::string direction);
    void rotateRed(std::string direction);
    void rotateBlue(std::string direction);
    void rotateOrange(std::string direction);
    void rotateYellow(std::string direction);

private:
    std::map <std::string, std::vector<std::string>> mCube;
    int mColorTracker;
};


#endif /* Cube_h */
