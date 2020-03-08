#ifndef _MENU_PRINCIPAL_H
#define _MENU_PRINCIPAL_H

#include "texture.h"

#define MAX_NUMBER 3


/**
 *\struct option
 *\details Structure gérant les caractéristiques liées à une option
 */
typedef struct option
{   
    int largeur, hauteur;
    const char * nomOption;
    SDL_Texture *texture;
    SDL_Color couleur;
    int x, y;
    char * filename[2];

}Options_t;

/**
 *\struct menu
 *\details Structure 
 */
typedef struct menu
{
    int selectedOption;
    Options_t menu[3];
    Mix_Chunk *son;
    TTF_Font * police;
    SDL_Texture * bg;
    Mix_Music * bgm;

}Menu_t;


// extern void UpdateOption(Options_t * );
extern void UpdateOption(Options_t * menut, int etat);
extern int getTouchePresse();

extern void ToucheHaut();
extern void ToucheBas();

extern void Init_MenuPrincipal();
extern void Dessiner_MenuPrincipal();

extern void Input_MenuPrincipal(SDL_Event* event);


extern void Nettoyer_MenuPrincipal();



#endif