/**
 * \file level.c
 * \author CALVADOS Cindy, CHAUMULON Cassandra, CHELLI Célia, OUSMANOVA Karina
 * \version 1.0
 * \date janvier 2020
 * \brief Programme qui gère les niveaux : affichage et destruction des niveaux
 */
#include "level.h"
#include "constantes.h"

#include "baseGame.h"

Level level; /**< Structure d'un niveau */

/**
 * \fn extern Level* getLevel()
 * \brief Fonction qui permet d'accéder à la structure d'un niveau
 * \return Un pointeur sur une structure de données de type Level
*/
extern Level* getLevel()
{
   return &level;
}

/**
 * \fn extern void setNiveau(int niveau) 
 * \brief Fonction qui permet de mettre a jour le niveau du joueur
 * \details
 * \param niveau numero du niveau
 * \return pas de valeur de retour (void)
*/
extern void setNiveau(int niveau) 
{
   getPlayer()->niveau = niveau;
}

/**
 * \fn extern void ChargerNiveau()
 * \brief Fonction qui permet de charger un niveau
 * \details Initialisation des listes (ennemis, bullets,items et colliders)
 * \return pas de valeur de retour (void)
*/
extern void ChargerNiveau()
{
   printf("Chargement Niveau\n");
   
   //Initialisation des listes
   init_List(&listEnnemis);
   init_List(&bullet);
   init_List(&items);
   init_List(&listCollider);
      
   //Chargement du niveau 1
   if(  getPlayer()->niveau == 1 )
   {
      //Chargement de toutes les entites (sauf joueur)
      Chargement_CreationPNJ(getCollider(),"files_assets/niveau1.txt") ;

      //Chargement des ennemis
      ChargementEnnemis("files_assets/ennemi.txt");

      //Chargement des textures
      SDL_Texture * itemTex = ChargerTexture("graphics_assets/coin.png");
      ChargementItems("files_assets/coin.txt", itemTex);
      ChargerTextureManager( &level.levelTextures[0], "graphics_assets/level_1/back.png");
      ChargerTextureManager( &level.levelTextures[1], "graphics_assets/level_1/front.png");

   }  

   //Chargement du niveau 2
   else if(  getPlayer()->niveau == 2 )
   {  
         //Destruction du niveau precedent
         DestructionNiveau();
         //Chargement de toutes les entites (sauf joueur)
         Chargement_CreationPNJ(getCollider(),"files_assets/niveau2.txt") ;
         // ChargementEnnemis("files_assets/ennemi.txt");

         //Chargement des textures
         SDL_Texture * itemTex = ChargerTexture("graphics_assets/coin.png");
         suppListe(getItems()); //Suppression de la liste d'item precedente
         ChargementItems("files_assets/coin.txt", itemTex);
         ChargerTextureManager( &level.levelTextures[0], "graphics_assets/level_2/back.png");
         ChargerTextureManager( &level.levelTextures[1], "graphics_assets/level_2/front.png");
   }
   
   printf("Fin chargement niveau\n");
}

/**
 * \fn extern void NiveauSuivant()
 * \brief Fonction qui permet de charger un niveau suivant
 * \details Appel de la fonction ChargerNiveau()
 * \return pas de valeur de retour (void)
*/
extern void NiveauSuivant()
{
   ChargerNiveau();
}

/**
 * \fn extern void Debug_AfficherCollider() 
 * \brief Fonction qui permet de mettre a jour le niveau du joueur
 * \details
 * \param niveau numero du niveau
 * \return pas de valeur de retour (void)
*/
extern void Debug_AfficherCollider() 
{
   SDL_Rect rect;
   SDL_Texture * texColider = ChargerTexture("graphics_assets/rect10.png");
   for(Node* pt = getCollider()->tete ; pt != NULL ; pt = pt->suivant )
   {
          rect = (SDL_Rect) {  pt->rect->x- camera.x ,pt->rect->y-  camera.y ,pt->rect->w,pt->rect->h };
         SDL_RenderCopy(getRenderer(), texColider , NULL, &rect);
   }
}

extern void afficher_textures_niveau(int niveau)
{
   SDL_Rect renderQuad = {0, 0, camera.w ,  camera.h };
   SDL_RenderCopy( getRenderer() , getLevel()->levelTextures[niveau].texture,&camera, &renderQuad);

}

extern void Affichage_Niveau ()
{  

   // printf("Affichage Niveau\n");
   
   if(  getPlayer()->niveau == 1 )
   {

      afficher_textures_niveau(0);
      AfficherJoueur();
      afficher_textures_niveau(1);
      
   }  
   else if(  getPlayer()->niveau == 2 )
   {  
      afficher_textures_niveau(1);
      
   }
   
    
}

extern void DestructionNiveau()
{
   printf("Destruction Niveau\n");
   
   LibererRessources( &getLevel()->levelTextures[0] );
   LibererRessources( &getLevel()->levelTextures[1] );

   printf("Fin Destruction Niveau\n");
}