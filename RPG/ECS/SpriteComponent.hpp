//
//  SpriteComponent.hpp
//  RPG
//
//  Created by Matthew Colvin de Valle on 01/08/2020.
//  Copyright © 2020 Matthew Colvin de Valle. All rights reserved.
//

#ifndef SpriteComponent_hpp
#define SpriteComponent_hpp

#include <stdio.h>
//#include "ECS.hpp"
#include "Components.hpp"
#include "TextureManager.hpp"
#include "SDL2/SDL.h"



class SpriteComponent : public Component {

private:
    TransformComponent* transform;
    SDL_Texture* texture;
    SDL_Rect srcRect, destRect;
    
    
public:
    SpriteComponent() = default;
    SpriteComponent(const char* path){
        SetTex(path);
    }
    
    void SetTex(const char* path){
        texture = TextureManager::LoadTexture(path);
    }
    
    void init() override{

        transform = &entity->getComponent<TransformComponent>();
        
        srcRect.x = srcRect.y = 0;
        srcRect.h = srcRect.w = 16;
        destRect.h = destRect.w = 32;
    }
    
    void update() override{
        destRect.x = (int)transform->position.x;
        destRect.y = (int)transform->position.y;
    }
    
    void draw() override{
        TextureManager::Draw(texture, srcRect, destRect);
    }
};

#endif /* SpriteComponent_hpp */
