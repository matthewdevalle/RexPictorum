//
//  MapReader.cpp
//  RPG
//
//  Created by Matthew Colvin de Valle on 02/02/2020.
//  Copyright © 2020 Matthew Colvin de Valle. All rights reserved.
//

#include "MapReader.hpp"
#include <cstring>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>


#define NUM_TILES 5

// The surfaces contained in the window
SDL_Surface* gTile;
SDL_Surface* tileList[5];

struct player_character{
    int operation_points;
    int move_distance;
    int current_xloc; // max 79
    int current_yloc; // max 39
    int damage;
    char symbol; // the ascii character that will represent this player in the game
};

MapReader::MapReader(){
}
MapReader::~MapReader(){
}

void MapReader::LoadTiles(void){
    char asset_path[5][65] = {
                            {"/Users/macd/Projects/RexPictorum/RPG/assets/tiles_bmp/grass.bmp"},
                            {"/Users/macd/Projects/RexPictorum/RPG/assets/tiles_bmp/path.bmp"},
                            {"/Users/macd/Projects/RexPictorum/RPG/assets/tiles_bmp/road.bmp"},
                            {"/Users/macd/Projects/RexPictorum/RPG/assets/tiles_bmp/tree.bmp"},
                            {"/Users/macd/Projects/RexPictorum/RPG/assets/tiles_bmp/wall.bmp"}
                        };
    
    for(int numTiles=0; numTiles < NUM_TILES; numTiles++){
        tileList[numTiles] = SDL_LoadBMP(&asset_path[numTiles][0]);
    }
}

void MapReader::LoadBackground(char pathname[], char screenMap[ROWS][COLUMNS]) {
    FILE *fptr;
    int row = 0;
    int column = 0;
    int ch;
    fptr = fopen(pathname,"r");
    
    for (row=0;row<ROWS;row++){
        for(column=0;column<COLUMNS;column++){
            ch = fgetc(fptr);
            if ((ch!=EOF)){
                printf("%c",ch);
                screenMap[row][column] = (char)ch;
            }
        }
    }
}

bool MapReader::LoadMedia(SDL_Surface *tile, char tileName[]){
    //success flag
    bool success = true;
    // pathname for assets
    char assetPath[] = "/Users/macd/Projects/RexPictorum/RPG/assets/tiles_bmp/";
   
    char src[60], dest[12];
    strcpy(dest, assetPath);
    strcpy(src, tileName);
    strcat(dest,src);
    tile = SDL_LoadBMP(dest);
    
    if (gTile==NULL){
        //printf("Unable to load image! SDL Error: %s\n", SDL_GetError());
        success = false;
    }
    return success;
}

void DrawBackground(SDL_Surface* screenSurface, char screenMap[ROWS][COLUMNS]) {
    int row=0;
    int column=0;
    int ch;
    
    SDL_Surface *tileName;
   
    int success = -1;
    
    SDL_Rect rect;
    rect.w = 16;
    rect.h = 16;
    rect.x = 0;
    rect.y = 0;
    
    MapReader::LoadTiles();
    
    for (row=0;row<ROWS;row++){
        for(column=0;column<COLUMNS;column++){
            ch = screenMap[row][column];
            tileName = MapReader::getTileName(ch);
            success = SDL_BlitSurface(tileName, NULL, screenSurface, &rect);
            rect.x += 16;
        }
        rect.x = 0;
        rect.y += 16;
    }
    printf("\n total rows = %i",row);
    printf("\n total columns = %i \n", column);
}

SDL_Surface*  getTileName(char tileIdent)
{
    SDL_Surface *tileName;
    //tileName = (char *)"";
    //printf("\ntileIdent is %c", tileIdent);
    switch (tileIdent){
        case 'g':
            tileName = tileList[0];
            printf("tileIdent = '%c'\n",tileIdent);
            break;
        case 'p':
            tileName = tileList[1];
            printf("tileIdent = '%c'\n",tileIdent);
            break;
        case 'r':
            tileName = tileList[2];
            printf("tileIdent = '%c\n'",tileIdent);
            break;
        case 't':
            tileName = tileList[3];
            printf("tileIdent = '%c'\n",tileIdent);
            break;
        case 'w':
            tileName = tileList[4];
            printf("tileIdent = '%c'\n",tileIdent);
            break;
        default:
            tileName = tileList[2];
            printf("tileIdent = '%c'\n",tileIdent);
            break;
    }
    
    return tileName;
}
