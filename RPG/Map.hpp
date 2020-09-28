//
//  Map.hpp
//  RPG
//
//  Created by Matthew Colvin de Valle on 25/07/2020.
//  Copyright © 2020 Matthew Colvin de Valle. All rights reserved.
//

#ifndef Map_hpp
#define Map_hpp

#include <stdio.h>
#include "Game.hpp"

#define ROWS 40
#define COLUMNS 80

class Map {
public:
    Map();
    ~Map();
    
    void LoadMap();
    void DrawMap();
    
private:
    
    SDL_Rect src, dest;
    
    SDL_Texture* dirt;
    SDL_Texture* grass;
    SDL_Texture* water;
    SDL_Texture* tree;
    
    int map[ROWS][COLUMNS];
};

#endif /* Map_hpp */
