//
//  MapReader.hpp
//  RPG
//
//  Created by Matthew Colvin de Valle on 02/02/2020.
//  Copyright © 2020 Matthew Colvin de Valle. All rights reserved.
//

#ifndef MapReader_hpp
#include <SDL2/SDL.h>
//#include <stdio.h>
//#include <stdbool.h>
#define MapReader_hpp



// defines
#define ROWS 40
#define COLUMNS 80

// Functions
void LoadBackground(char[], char[ROWS][COLUMNS]);
bool LoadMedia(SDL_Surface*);
void DrawBackground(SDL_Surface*,char[ROWS][COLUMNS]);
SDL_Surface* getTileName(char tileIdent);

#endif /* MapReader_hpp */
