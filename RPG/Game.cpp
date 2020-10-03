//
//  Game.cpp
//  RPG
//
//  Created by Matthew Colvin de Valle on 24/07/2020.
//  Copyright © 2020 Matthew Colvin de Valle. All rights reserved.
//

#include "Game.hpp"
#include "TextureManager.hpp"
#include "Map.hpp"
#include "MapReader.hpp"
#include "ECS/Components.hpp"
#include "Vector2D.h"
#include "Collision.h"
//#include "ECS/PositionComponent.hpp"

SDL_Texture* playerTex;
SDL_Rect srcR, destR;
SDL_Event Game::event;
Map* map;

Manager manager;

SDL_Renderer* Game::renderer = nullptr;

auto& player(manager.addEntity());
auto& wall(manager.addEntity());

// ctor
Game::Game(){}
// dtor
Game::~Game(){}

void Game::handleEvents(){
    
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
    
    map = new Map();
    
    player.addComponent<TransformComponent>(2);
    player.addComponent<SpriteComponent>("/Users/macd/Projects/RexPictorum/RPG/assets/player.png");
    player.addComponent<KeyboardController>();
    player.addComponent<ColliderComponent>("player");
    
    wall.addComponent<TransformComponent>(100.0f, 100.0f, 32, 32, 2);
    wall.addComponent<SpriteComponent>("/Users/macd/Projects/RexPictorum/RPG/assets/tiles_png/wall.png");
    wall.addComponent<ColliderComponent>("wall");
    
}

void Game::update(){
    manager.refresh();
    manager.update();
    if(Collision::AABB(player.getComponent<ColliderComponent>().collider, wall.getComponent<ColliderComponent>().collider)){
        std::cout << "Wall Hit!" << std::endl;
    }
}

void Game::render(){
    SDL_RenderClear(renderer);
    map->DrawMap();
    manager.draw();
    SDL_RenderPresent(renderer);
}

void Game::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned" << std::endl;
}

