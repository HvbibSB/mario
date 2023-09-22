#include "game.h"
#include "file.h"
#include "charactere.h"
#include "event.h"

int jouer(SDL_Renderer* renderer) {
    
	//charger image et personnage.
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window;
    SDL_Texture *Mario1 = loadImage("img/Mario1.png", renderer);
    SDL_Texture *Mario2 = loadImage("img/Mario2.png", renderer);
    SDL_Texture *Mario3 = loadImage("img/Mario3.png", renderer);
    SDL_Texture *Mario4 = loadImage("img/Mario4.png", renderer);
    SDL_Texture *Mario5 = loadImage("img/Mario5.png", renderer);
    SDL_Texture *Mario6 = loadImage("img/Mario6.png", renderer);
    SDL_Rect rectangleSource = {0,0,500,500};
	SDL_Rect rectangleDest = {0,0,500,500};
    SDL_RenderCopy(renderer, Mario1,&rectangleSource,&rectangleDest);
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

			    case SDLK_1://appuie sur 1
                       	    case SDLK_ESCAPE://appuie sur echap    
				    
                            continuer = 0;
                            break;
                            case SDLK_d:
                            SDL_Log("droite");
                            break;
                            case SDLK_q:
                            SDL_Log("gauche");
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
        SDL_RenderPresent(renderer);
        
    }
    
	//a vous de compléter, au fur et à mesure, les deux fonctions en dessous pour bien faire le nettoyage. 
    /*LibererMap(map, sprites);
    freePersonnage(mario, goomba, nbGoomba);
*/
    return continuer;
}
