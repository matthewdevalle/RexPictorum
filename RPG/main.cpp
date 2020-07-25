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
#include <string>
#include <fstream>
#include "MapReader.hpp"
#include "Game.hpp"


//Screen dimension constants
const int SCREEN_WIDTH = 1264;
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

// other SDL stuff
SDL_Event event;

// Screen Dimension Constants
char pathName[] = "/Users/macd/Projects/RexPictorum/RPG/assets/maps/start.txt";
char screenMap[ROWS][COLUMNS];
Game* game = nullptr;

int main(int argc, char * argv[]) {
    const int FPS = 60;
    const int frameDelay = 1000/FPS;
    
    Uint32 frameStart;
    int frameTime;
    
    game = new Game();
    game->init("RexPictorum", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, false);
    
    while(game->running()){
        //Get current time
        frameStart = SDL_GetTicks();
        
        // Run game loop
        game->handleEvents();
        std::cout << "Handled events..." << std::endl;
        game->update();
        std::cout << "Updating game objects..." << std::endl;
        game->render();
        std::cout << "Rendering screen..." << std::endl;
        
        // Calculate time for one pass through the game loop
        frameTime = SDL_GetTicks() - frameStart;
        
        if (frameDelay > frameTime){
            SDL_Delay(frameDelay - frameTime);
        }
    }
    
    game->clean();
 /*
    // stuff here
    MapReader* mr = new MapReader();
    
    if(!init()){
        printf("Failed to Intialise!\n");
    }
    else{
        // read in the text file
        mr->LoadBackground(pathName, screenMap);
        // Create the Background
        mr->DrawBackground(gScreenSurface,screenMap);
        // Update the Window Surface
        SDL_UpdateWindowSurface(gWindow);
    }
*/
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
        gWindow = SDL_CreateWindow("Rex Pictorum", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH,SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
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
