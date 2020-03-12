#ifndef __INPUT_H_
#define __INPUT_H_

#include "commun.h"




typedef struct input
{
    bool left, right, up, down, jump, attack, enter, erase, pause, escape;
    SDL_Event event;
 
} Input;

extern void ProcessInput(SDL_Event* event);



#endif