#ifndef __LOAD_SAVE_H
#define __LOAD_SAVE_H


#include "commun.h"
#include "baseGame.h"

extern void ChargerPartie();
extern void SauvegarderPartie();

extern void SaveCollider_Position();

extern void ChargementCollider(const char * filename);
extern void Chargement_CreationPNJ(LinkedList*lst, char * filename);
extern void ChargementEnnemis(const char * filename);
extern void ChargementItems(const char * filename, SDL_Texture * tex);



#endif