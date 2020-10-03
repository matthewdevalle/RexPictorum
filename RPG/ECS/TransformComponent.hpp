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
    Vector2D velocity;
    
    int speed = 3;
    int height = 32;
    int width = 32;
    int scale = 1;
    
    TransformComponent(){
        position.x = 0.0f;
        position.y = 0.0f;
    }
    
    TransformComponent(int sc){
        position.x = 0.0f;
        position.y = 0.0f;
        scale = sc;
    }
    
    TransformComponent(float x, float y){
        position.x = x;
        position.y = y;
    }
    
    TransformComponent(float x, float y, int h, int w, int sc){
        position.x = x;
        position.y = y;
        height = h;
        width = w;
        scale = sc;
    }
    
    int x() { return position.x; }
    int y() { return position.y; }
    
    /*
     void init() override{
        position.x = 0;
        position.y = 0;
    }
    */
    void update() override{
        position.x += velocity.x * speed;
        position.y += velocity.y * speed;
    }
    
    void init() override{
        velocity.x = 0;
        velocity.y = 0;
    }
    

};

#endif /* PositionComponent_hpp */
