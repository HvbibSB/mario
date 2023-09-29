#include <stdlib.h>
#include <stdio.h>

#include "charactere.h"
//mettre des define ?


void chargerMario(Personnage* mario, Map* map, SDL_Renderer *renderer)
{
    mario -> image=malloc(sizeof(SDL_Texture)*NUMBER_IMAGE_MARIO);
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

   
}


//retourne soit numéro1 soit numéro2 pour alterner entre 2 sprite sur un mouvement.
int chooseSpriteMovement(Personnage* mario, int numero1, int numero2) {
    
    return numero1;
}

void freePersonnage(Personnage* mario) { //faudra ajouter ", Personnage **goomba, int nbGoomba" après le mario
    free (mario);
}
