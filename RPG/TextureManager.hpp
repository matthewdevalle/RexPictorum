//
//  TextureManager.hpp
//  RPG
//
//  Created by Matthew Colvin de Valle on 25/07/2020.
//  Copyright © 2020 Matthew Colvin de Valle. All rights reserved.
//

#ifndef TextureManager_hpp
#define TextureManager_hpp

#include <stdio.h>
#include "Game.hpp"

class TextureManager {

public:
    static SDL_Texture* LoadTexture(const char* filename);
    static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
};

#endif /* TextureManager_hpp */
