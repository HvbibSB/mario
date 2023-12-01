#include <stdlib.h>
#include <stdio.h>

#include "charactere.h"
//mettre des define ?


void chargerMario(Personnage* mario, Map* map, SDL_Renderer *renderer)
{
    mario -> image=malloc(sizeof(SDL_Texture*)*NUMBER_IMAGE_MARIO);
    mario-> image[0] = loadImage("img/Mario1.png", renderer);
    mario-> image[1] = loadImage("img/Mario2.png", renderer);
    mario-> image[2] = loadImage("img/Mario3.png", renderer);
    mario-> image[3] = loadImage("img/Mario4.png", renderer);
    mario-> image[4] = loadImage("img/Mario5.png", renderer);
    mario-> image[5] = loadImage("img/Mario6.png", renderer);
    mario -> position.x=100;
    mario -> position.y=100;
    mario -> position.w=WIDTH_MARIO;
    mario -> position.h=HEIGHT_MARIO;
    mario -> jump=0;
    mario -> jumptime=0;
    mario -> gravite=0;
    mario -> direction=0;
    mario -> temp=0; // pas sûr de celle là
    mario -> win=0;
    mario -> invisible=0;
    mario -> lvl;
}

void afficherPerso(Personnage* mario, int xscroll, int yscroll , SDL_Renderer *renderer) {
	SDL_Rect rectangleSource = {0,0,WIDTH_MARIO,HEIGHT_MARIO};
	SDL_Rect rectangleDest = {0,0,mario->position,mario->position};

        if(mario->direction=1)
        {
	        SDL_RenderCopy(renderer, mario->image[1],&rectangleSource,&rectangleDest);
        }

        else if(mario->direction=2)
        {
            SDL_RenderCopy(renderer, mario->image[2],&rectangleSource,&rectangleDest);
        }
}


//retourne soit numéro1 soit numéro2 pour alterner entre 2 sprite sur un mouvement.
int chooseSpriteMovement(Personnage* mario, int numero1, int numero2) {
    
    return numero1;
}

void freePersonnage(Personnage* mario) { //faudra ajouter ", Personnage **goomba, int nbGoomba" après le mario
    free (mario);
}
