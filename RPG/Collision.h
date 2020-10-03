//
//  Collision.h
//  RPG
//
//  Created by Matthew Colvin de Valle on 03/10/2020.
//  Copyright © 2020 Matthew Colvin de Valle. All rights reserved.
//

#ifndef Collision_h
#define Collision_h


#endif /* Collision_h */
#include "SDL2/SDL.h"

class Collision {
public:
    // Axis Aligned Bounding Box
    static bool AABB(const SDL_Rect& recA, const SDL_Rect& recB);
};
