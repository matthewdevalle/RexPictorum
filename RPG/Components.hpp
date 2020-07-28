//
//  Components.hpp
//  RPG
//
//  Created by Matthew Colvin de Valle on 26/07/2020.
//  Copyright © 2020 Matthew Colvin de Valle. All rights reserved.
//

#ifndef Components_hpp
#define Components_hpp

#include <stdio.h>
#include "ECS.hpp"

class PositionComponent : public Component{
private:
    int xpos;
    int ypos;
    
public:
    int x() { return xpos; }
    int y() { return ypos; }
    
    void init() override{
        xpos = 0;
        ypos = 0;
    }
    
    void update() override{
        xpos++;
        ypos++;
    }
    
    void setPos(int x, int y){
        xpos = x;
        ypos = y;
    }
};

#endif /* Components_hpp */
