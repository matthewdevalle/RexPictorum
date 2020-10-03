//
//  ColliderComponent.h
//  RPG
//
//  Created by Matthew Colvin de Valle on 03/10/2020.
//  Copyright © 2020 Matthew Colvin de Valle. All rights reserved.
//

#ifndef ColliderComponent_h
#define ColliderComponent_h


#endif /* ColliderComponent_h */
#include <string>
#include "SDL2/SDL.h"
#include "Components.hpp"

class ColliderComponent : public Component
{
public:
    SDL_Rect collider;
    std::string tag;
    
    TransformComponent* transform;
    
    ColliderComponent(std::string t){
        tag = t;
    }
    
    void init() override{
        if(!entity->hasComponent<TransformComponent>()){
            entity->addComponent<TransformComponent>();
        }
        transform = &entity->getComponent<TransformComponent>();
        
    }
    
    void update() override {
        collider.x = static_cast<int>(transform->position.x);
        collider.y = static_cast<int>(transform->position.y);
        collider.w = transform->width * transform->scale;
        collider.h = transform->height * transform->scale;
    }
    
};


