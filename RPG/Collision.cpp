//
//  Collision.cpp
//  RPG
//
//  Created by Matthew Colvin de Valle on 03/10/2020.
//  Copyright © 2020 Matthew Colvin de Valle. All rights reserved.
//

#include <stdio.h>
#include "Collision.h"
#include "SDL2/SDL.h"

bool Collision::AABB(const SDL_Rect& recA, const SDL_Rect& recB){
    if (recA.x + recA.w >= recB.x &&
        recB.x + recB.w >= recA.x &&
        recA.y + recA.h >= recB.x &&
        recB.y + recB.h >= recA.y) {
        return true;
    }
    return false;
}
