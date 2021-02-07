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
    ~SpriteComponent(){
        SDL_DestroyTexture(texture);
    }
    
    void SetTex(const char* path){
        texture = TextureManager::LoadTexture(path);
    }
    
    void init() override{

        transform = &entity->getComponent<TransformComponent>();
        
        srcRect.x = srcRect.y = 0;
        srcRect.h = transform->height;
        srcRect.w = transform->width;
        
    }
    
    void update() override{
        destRect.x = static_cast<int>(transform->position.x);
        destRect.y = static_cast<int>(transform->position.y);
        destRect.h = transform->height * transform->scale;
        destRect.w = transform->width * transform->scale;
    }
    
    void draw() override{
        TextureManager::Draw(texture, srcRect, destRect);
    }
};

#endif /* SpriteComponent_hpp */
