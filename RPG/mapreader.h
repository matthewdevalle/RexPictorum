//
//  mapreader.h
//  RPG
//
//  Created by Matthew Colvin de Valle on 30/11/2019.
//  Copyright © 2019 Matthew Colvin de Valle. All rights reserved.
//
#include <stdbool.h>
#ifndef mapreader_h
#define mapreader_h

// defines
#define ROWS 40
#define COLUMNS 80

// Functions
char LoadBackground(char[]);
bool LoadMedia(void);
void DrawBackground(char[ROWS][COLUMNS], SDL_Window*);

#endif /* mapreader_h */
