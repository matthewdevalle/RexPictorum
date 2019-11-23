//
//  main.cpp
//  RPG
//
//  Created by Matthew Colvin de Valle on 17/11/2019.
//  Copyright © 2019 Matthew Colvin de Valle. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

//prototypes;
bool init(void);
bool loadMedia(void);
void close(void);
// Window we'll be rendering to
SDL_Window* gWindow = NULL;

// The surfaces contained in the window
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gTile;

// Screnn Dimension Constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char * argv[]) {
    // insert code here...

    
    if(!init()){
        printf("Failed to Intialise!\n");
    }
    else{
        // Load Media
        if(!loadMedia()){
            printf("Failed to Load Media!");
        }
        else{
            // Apply the image
            SDL_BlitSurface(gTile,NULL,gScreenSurface, NULL);
            // Update the WIndow Surface
            SDL_UpdateWindowSurface(gWindow);
        }
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

bool loadMedia(){
    //success flag
    bool success = true;
    //Load splash image
    char* path = ".//assets//tiles_bmp//grass.bmp";
    gTile = SDL_LoadBMP(path);
    
    if (gTile==NULL){
        printf("Unable to load image %s! SDL Error: %s\n", path,SDL_GetError());
        success = false;
    }
    return success;
}

void close(){
    //Deallocate surface
    SDL_FreeSurface(gTile);
    gTile = NULL;
    
    // Destroy the Window
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    
    // Quite the SDL Subsystem
    SDL_Quit();
}
