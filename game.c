#include "game.h"
#include "file.h"
#include "charactere.h"
#include "event.h"

int jouer(SDL_Renderer* renderer) {
    
	//charger image et personnage. 
    Map *map = malloc(sizeof(Map*)); 
    map->width = 
    int continuer = 1; //a utiliser pour savoir si on continue la boucle du jeu ou si on arrête. 
    SDL_Event events;
    SDL_Event event;

    while(continuer){ //coeur du jeu ici, les actions seront repété pour faire le déplacement des différentes images, ...
        
        //gérer les différentes actions. 
        while (SDL_PollEvent(&event)){
            switch (event.type){
                case SDL_QUIT:
                continuer=0; //test
                break;
            }
        }
        
    }
    free (map);
	//a vous de compléter, au fur et à mesure, les deux fonctions en dessous pour bien faire le nettoyage. 
    /*LibererMap(map, sprites);
    freePersonnage(mario, goomba, nbGoomba);
*/
    return continuer;
}