//
//  Map.cpp
//  RPG
//
//  Created by Matthew Colvin de Valle on 25/07/2020.
//  Copyright © 2020 Matthew Colvin de Valle. All rights reserved.
//

#include "Map.hpp"
#include "TextureManager.hpp"

int lvl1[20][25] = { {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                     {0,0,0,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                     {0,0,2,1,1,1,1,1,1,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                     {0,0,2,1,1,3,3,3,1,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                     {0,2,1,1,1,3,3,1,3,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                     {0,0,2,2,2,2,2,1,1,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,2,1,1,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,2,1,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
                    };

char pathName[] = "/Users/macd/Projects/RexPictorum/RPG/assets/maps/start.txt";

Map::Map(){
    dirt = TextureManager::LoadTexture("/Users/macd/Projects/RexPictorum/RPG/assets/tiles_bmp/path.bmp");
    grass = TextureManager::LoadTexture("/Users/macd/Projects/RexPictorum/RPG/assets/tiles_bmp/grass.bmp");
    water = TextureManager::LoadTexture("/Users/macd/Projects/RexPictorum/RPG/assets/tiles_bmp/water.bmp");
    tree = TextureManager::LoadTexture("/Users/macd/Projects/RexPictorum/RPG/assets/tiles_bmp/tree.bmp");
    
    LoadMap();
    src.x = 0;
    src.y = 0;
    src.h = 16;
    src.w = 16;
    
    dest.x = 0;
    dest.y = 0;
    dest.h = 16;
    dest.w = 16;
}
Map::~Map(){}

void Map::LoadMap(){
    
    FILE *fptr;
    int row = 0;
    int column = 0;
    int ch;
    fptr = fopen(pathName,"r");
    
    for (row=0; row<ROWS; row++){
        for(column=0; column<COLUMNS; column++){
            ch = fgetc(fptr);
            if ((ch!=EOF)){
                printf("%c", ch);
                map[row][column] = (char)ch;
            }
        }
    }
 /*
    for (int row = 0; row <20; row++){
        for(int column = 0; column <25; column++){
            map[row][column] = arr[row][column];
        }
    }
*/
}

void Map::DrawMap(){
    int type = 0;
    
    for (int row = 0; row < ROWS; row++){
        for(int column = 0; column < COLUMNS; column++){
            type = map[row][column];
            
            dest.x = column * 16;
            dest.y = row * 16;
            
            switch(type){
                case 'w':
                    TextureManager::Draw(water, src, dest);
                    break;
                case 'g':
                    TextureManager::Draw(grass, src, dest);
                    break;
                case 'r':
                    TextureManager::Draw(dirt, src, dest);
                    break;
                case 't':
                    TextureManager::Draw(tree, src, dest);
                    break;
                default:
                    break;
            }
        }
    }
}

