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
class MapReader{
public:
    
// Public Functions
    MapReader();
    ~MapReader();
    
    void LoadBackground(char[], char[ROWS][COLUMNS]);
    static void LoadTiles(void);
    bool LoadMedia(SDL_Surface*, char tileName[]);
    void DrawBackground(SDL_Surface*,char[ROWS][COLUMNS]);
    static SDL_Surface* getTileName(char tileIdent);

private:
    //nothing in here yet
    
};
#endif /* MapReader_hpp */
