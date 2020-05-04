/**
 * \file menuPrincipal.h
 * \author CALVADOS Cindy, CHAUMULON Cassandra, CHELLI Célia, OUSMANOVA Karina
 * \version 1.0
 * \date mars 2020
 * \brief programme qui gere le menu  pricipal du  jeu.
 */

#ifndef _MENU_PRINCIPAL_H
/**< \def _MENU_PRINCIPAL_H*/
#define _MENU_PRINCIPAL_H

#include "texture.h"

/** @brief  Nombre maximum d'options disponibles dans un menu */
#define MAX_NUMBER 3 


/**
 *\struct component
 *\details Structure gérant les caractéristiques liées à un component
 */
typedef struct component
{
    int largeur; /**< la largeur de l'option*/
    int hauteur; /**< la hauteur de l'option*/
    const char * nomOption;/**<le nom de l'option*/
    SDL_Texture *texture;/**< le texture de l'option*/
    int x;/**<la position en x de l'option*/
    int y;/**<la position en y de l'option*/
    char * filename[4];/**<le fichiers contenant la texture de l'option*/

}Component;
/**< Les components sont toujours liés à un gameObject,ils définissent le comportement de ce GameObject.  */

typedef struct gameObject GameObject;
/**< le GameObject représente une boîte vide qui ne fait pas grand chose tout seul, il agit comme un conteneur pour les components. */


/**
 *\struct gameObject
 *\details GameObject
 */
struct gameObject
{
    int selectedOption;/**<selection de l'option*/
    Component components[4];/**< le menu*/
    Mix_Chunk *son;/**< le son du menu*/
    TTF_Font * police;/**< la police utilise pour le menu*/
    SDL_Texture * bg;/**< Texture en arrière-plan */
    Mix_Music * bgm;/**< Musique du jeux en arriere plan*/
    char * nom_menu; /**< Nom du GameObject*/

};


extern void UpdateComponent(Component * component, int etat); /**< fonction de mise à jour du component d'un gameObject */
extern void UpdateImage_Component(Component * component, const char * filename);/**< fonction de mise à jour d'image du component d'un gameObject*/
extern int getTouchePresse(GameObject *gameObject);/**< fonction sur les touches du menu*/

extern void ToucheHaut(GameObject * gameObject);/**< fonction pour la touche haut du menu*/
extern void ToucheBas(GameObject *gameObject );/**<touche bas*/

extern void Droite(GameObject *gameObject, int nombreOptions);/**< pour aller a droite*/
extern void Gauche(GameObject *gameObject,int nombreOptions);/**< pour aller a gauche*/

extern void Dessiner_Menu(GameObject* gameObject, int nombresOptions, int posX, int posY , int largeurBG, int hauteurBG);
extern void Init_MenuPrincipal();/**<initialise le menu*/
extern void Input_MenuPrincipal(SDL_Event* event);

extern void ChargerData_Menu(int numero,int num_image, GameObject * gameObject,  char * nomOption,  char * image_on,  char * image_off,
int positionX, int positionY ); /**<rechargement du menu*/

extern void Nettoyer_Menu(GameObject * gameObject, int nombreOptions);/**<fonction nettoyer le menu remmetre a zero*/




#endif
