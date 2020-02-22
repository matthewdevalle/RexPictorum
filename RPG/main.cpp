//
//  main.cpp
//  RPG
//
//  Created by Matthew Colvin de Valle on 17/11/2019.
//  Copyright © 2019 Matthew Colvin de Valle. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>
// #include <SDL_image/SDL2_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include "MapReader.hpp"


//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 640;



//prototypes;
bool init(void);
bool loadMedia(void);
void close(void);

// Window we'll be rendering to
SDL_Window* gWindow = NULL;

// The surfaces contained in the window
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gxTile;

// Screen Dimension Constants
char pathName[] = "/Users/macd/Projects/RexPictorum/RPG/assets/maps/start.txt";
char screenMap[ROWS][COLUMNS];

int main(int argc, char * argv[]) {
    // insert code here...

    
    if(!init()){
        printf("Failed to Intialise!\n");
    }
    else{
        // read in the text file
        LoadBackground(pathName, screenMap);
        // Create the Background
        DrawBackground(gScreenSurface,screenMap);
        // Update the Window Surface
        SDL_UpdateWindowSurface(gWindow);
        SDL_Delay(2000);
    }
    // go through the event queue once
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
        // do nothing
    }
    
    if (getchar()){
        close();
    }
    return 0;
}

bool init(){
    bool success = true;
    
    // Intitialize the SDL
    if (SDL_Init( SDL_INIT_VIDEO ) < 0){
        printf("SDL Could not be initialized! SDL Error %s\n", SDL_GetError() );
        success = false;
    }
    else {
        gWindow = SDL_CreateWindow("Rex Pictorum", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        SDL_SetWindowTitle(gWindow, "Rex Pictorum");
        
    }
    
    //Intitalize the Window
    if(gWindow==NULL){
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }
    else{
        // Getwindow surface
        gScreenSurface = SDL_GetWindowSurface(gWindow);
    }
    
    return success;
}



void close(){
    //Deallocate surface
    SDL_FreeSurface(gxTile);
    gxTile = NULL;
    
    // Destroy the Window
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    
    // Quite the SDL Subsystem
    SDL_Quit();
}
