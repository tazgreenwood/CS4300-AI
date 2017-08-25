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
    void getName();
    void getValues();
    void addTile(std::string value);
    void rotate(std::string color, std::string direction);
    
private:
    char mName;
    std::vector<std::string> mCube;
    
};


#endif /* Cube_h */
