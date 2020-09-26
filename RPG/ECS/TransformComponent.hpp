//
//  PositionComponent.hpp
//  RPG
//
//  Created by Matthew Colvin de Valle on 01/08/2020.
//  Copyright © 2020 Matthew Colvin de Valle. All rights reserved.
//

#ifndef PositionComponent_hpp
#define PositionComponent_hpp

#include <stdio.h>
#include "Components.hpp"
#include "Vector2d.h"


class TransformComponent : public Component {

public:
    
    Vector2D position;
    
    TransformComponent(){
        position.x = 0.0f;
        position.y = 0.0f;
    }
    
    TransformComponent(float x, float y){
        position.x = x;
        position.y = y;
    }
    
    int x() { return position.x; }
    int y() { return position.y; }
    
    void init() override{
        position.x = 0;
        position.y = 0;
    }
    
    void update() override{
       
    }
    

};

#endif /* PositionComponent_hpp */
