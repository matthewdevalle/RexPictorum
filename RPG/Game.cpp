//
//  Game.cpp
//  RPG
//
//  Created by Matthew Colvin de Valle on 24/07/2020.
//  Copyright © 2020 Matthew Colvin de Valle. All rights reserved.
//

#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "Map.hpp"
#include "ECS.hpp"
#include "Components.hpp"

SDL_Texture* playerTex;
SDL_Rect srcR, destR;

GameObject* player;
Map* map;

Manager manager;
auto& newPlayer(manager.addEntity());

SDL_Renderer* Game::renderer = nullptr;

// ctor
Game::Game(){}
// dtor
Game::~Game(){}

void Game::handleEvents(){
    SDL_Event event;
    SDL_PollEvent(&event);
    
    switch(event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
    }
}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen){
    int flags = 0;
    
    if (fullscreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }
    
    if (SDL_Init(SDL_INIT_EVERYTHING)==0){
        std::cout << "Subsystems initialised" << std::endl;
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window) {
            std::cout << "Window created..." << std::endl;
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer){
            std::cout << "Renderer created..." << std::endl;
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        }
        isRunning = true;
    } else{
        isRunning = false;
    }
    
    player = new GameObject("/Users/macd/Projects/RexPictorum/RPG/assets/player.png", 0, 0);
    map = new Map();
    
    newPlayer.addComponent<PositionComponent>();
    newPlayer.getComponent<PositionComponent>().setPos(500,500);
    
}

void Game::update(){
    player->Update();
    manager.update();
    std::cout << newPlayer.getComponent<PositionComponent>().x() << "," << newPlayer.getComponent<PositionComponent>().y() << std::endl;
}

void Game::render(){
    SDL_RenderClear(renderer);
    map->DrawMap();
    player->Render();
    SDL_RenderPresent(renderer);
}

void Game::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned" << std::endl;
}

