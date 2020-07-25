//
//  GameObject.cpp
//  RPG
//
//  Created by Matthew Colvin de Valle on 25/07/2020.
//  Copyright © 2020 Matthew Colvin de Valle. All rights reserved.
//

#include "GameObject.hpp"
#include "TextureManager.hpp"

GameObject::GameObject(const char* texturesheet, int x, int y){
    objTexture = TextureManager::LoadTexture(texturesheet);
    xpos = x;
    ypos = y;
}

void GameObject::Update(){
    xpos++;
    ypos++;
    
    srcRect.h = 16;
    srcRect.w = 16;
    srcRect.x = 0;
    srcRect.y = 0;
    
    destRect.x = xpos;
    destRect.y = ypos;
    destRect.h = srcRect.h * 2;
    destRect.w = srcRect.w *2;
}

void GameObject::Render(){
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}
