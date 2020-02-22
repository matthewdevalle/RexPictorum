//
//  mapreader.c
//
//  Created by Matthew Colvin de Valle on 01/09/2017.
//  Copyright © 2017 Matthew Colvin de Valle. All rights reserved.
//
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
//#include "mapreader.h"


// Defines
#define ROWS 40
#define COLUMNS 80

// Functions
//char LoadBackground(char[]);
//void DrawBackground(char[ROWS][COLUMNS]);

// Globals
char asset_path[] = "/Users/macd/Projects/RexPictorum/RPG/assets/tiles_bmp/";
// The surfaces contained in the window
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gTile;

struct player_character{
    int operation_points;
    int move_distance;
    int current_xloc; // max 79
    int current_yloc; // max 39
    int damage;
    char symbol; // the ascii character that will represent this player in the game
};



char LoadBackground(char pathname[]) {
    FILE *fptr;
    int row = 0;
    int column = 0;
    int ch;
    
    char screenMap[ROWS][COLUMNS];
    
    fptr = fopen(pathname,"r");
    
    for (row=0;row<=ROWS;row++){
        for(column=0;column<=COLUMNS;column++){
            ch = fgetc(fptr);
            if (ch!=EOF){
                screenMap[row][column] = ch;
            }
        }
    }
    
    return screenMap[ROWS-1][COLUMNS-1];
}

bool LoadMedia(void){
    //success flag
    bool success = true;
    //Load splash image
    //char asset_path[] = "/Users/macd/Projects/RexPictorum/RPG/assets/tiles_bmp/";
    gTile = SDL_LoadBMP("/Users/macd/Projects/RexPictorum/RPG/assets/tiles_bmp/grass.bmp");
    
    if (gTile==NULL){
        printf("Unable to load image %s! SDL Error: %s\n", "/Users/macd/Projects/RexPictorum/RPG/assets/tiles_bmp/grass.bmp", SDL_GetError());
        success = false;
    }
    return success;
}

void DrawBackground(char screenMap[ROWS][COLUMNS], SDL_Window *window) {
    int row=0;
    int column=0;
    char ch;
    
    for (row=0;row<ROWS;row++){
        for(column=0;column<COLUMNS;column++){
            ch = screenMap[row][column];
            printf("%c",ch);
            }
    }
    printf("\n total rows = %i",row);
    printf("\n total columns = %i \n", column);


}
