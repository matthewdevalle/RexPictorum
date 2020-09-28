//
//  KeyboardController.h
//  RPG
//
//  Created by Matthew Colvin de Valle on 28/09/2020.
//  Copyright © 2020 Matthew Colvin de Valle. All rights reserved.
//

#ifndef KeyboardController_h
#define KeyboardController_h


#endif /* KeyboardController_h */

#include "Game.hpp"
#include "ECS.hpp"
#include "Components.hpp"

class KeyboardController : public Component
{
    TransformComponent *transform;
public:
    void init() override{
        transform = &entity->getComponent<TransformComponent>();
    }
    
    void update() override{
        if(Game::event.type == SDL_KEYDOWN){
            switch(Game::event.key.keysym.sym){
                case SDLK_UP:
                    transform->velocity.y = -1;
                    break;
                case SDLK_LEFT:
                    transform->velocity.x = -1;
                    break;
                case SDLK_RIGHT:
                    transform->velocity.x = 1;
                    break;
                case SDLK_DOWN:
                    transform->velocity.y = 1;
                    break;
                default:
                    break;
            }
        }
        
        if(Game::event.type == SDL_KEYUP){
            switch(Game::event.key.keysym.sym){
                case SDLK_UP:
                    transform->velocity.y = 0;
                    break;
                case SDLK_LEFT:
                    transform->velocity.x = 0;
                    break;
                case SDLK_RIGHT:
                    transform->velocity.x = 0;
                    break;
                case SDLK_DOWN:
                    transform->velocity.y = 0;
                    break;
                default:
                    break;
            }
        }
    }
};

