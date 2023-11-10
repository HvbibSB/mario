#include "game.h"
#include "file.h"
#include "charactere.h"
#include "event.h"

int jouer(SDL_Renderer* renderer) {
    
	//charger image et personnage.
    Personnage *mario = malloc(sizeof(Personnage));
    Map* map = malloc(sizeof(Map));
    chargerMario(mario,map,renderer);
    //Là où on chargeait toutes les images de Mario (les 6), nécessite d'être là pour que la ligne 15 fonctionne.
    SDL_Rect rectangleSource = {0,0,500,500};
	SDL_Rect rectangleDest = {0,0,500,500};
    //SDL_RenderCopy(renderer, Mario1,&rectangleSource,&rectangleDest);
    SDL_RenderPresent(renderer);
    


    int continuer = 1; //a utiliser pour savoir si on continue la boucle du jeu ou si on arrête. 
    SDL_Event event;


    
    SDL_SetRenderDrawColor(renderer,255,255,255,0);

    while(continuer){ //coeur du jeu ici, les actions seront repété pour faire le déplacement des différentes images, ...
    SDL_RenderClear(renderer);
        //gérer les différentes actions. 
        while (SDL_PollEvent(&event)){
            switch (event.type){
                case SDL_QUIT:
                    continuer=0;
                    break;
                    case SDL_KEYDOWN:
            		    switch(event.key.keysym.sym)
					    {
                            case SDLK_d:
                            SDL_Log("droite");
                            mario-> direction=1; 
                            SDL_Log("direction= %d",mario->direction);
                            break;

                            case SDLK_q:
                            SDL_Log("gauche");
                            mario-> direction=2;
                            SDL_Log("direction= %d", mario->direction);
                            break;

                            case SDLK_SPACE:
                            SDL_Log("saut");
                            break;

                            case SDLK_ESCAPE:
                            continuer=0;
                            break;
					    }

            }
        }
        //ici on choisit if droite =1 alors on déplace vers la droite de 10pixels sur l'axe x (ou y je sais pas encore)
        //afficher mario et déplacer mario
        SDL_RenderPresent(renderer);
        
    }
    
	//a vous de compléter, au fur et à mesure, les deux fonctions en dessous pour bien faire le nettoyage. 
    //LibererMap(map, sprites);
    freePersonnage(mario); //faudra ajouter ", goomba, nbGoomba" juste après le mario 

    return continuer;
}
