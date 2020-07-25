//
//  GameObject.hpp
//  RPG
//
//  Created by Matthew Colvin de Valle on 25/07/2020.
//  Copyright © 2020 Matthew Colvin de Valle. All rights reserved.
//

#ifndef GameObject_hpp
#define GameObject_hpp

#include <stdio.h>
#include "Game.hpp"

class GameObject{
public:
    GameObject(const char* texturesheet, int x, int y);
    ~GameObject();
    
    void Update();
    void Render();
    
private:
    int xpos;
    int ypos;
    
    SDL_Rect srcRect, destRect;
    SDL_Texture* objTexture;
    
};

#endif /* GameObject_hpp */
