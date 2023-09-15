#include <stdlib.h>
#include <stdio.h>

#include "charactere.h"
//mettre des define ?


void chargerMario(Personnage* mario, Map* map, SDL_Renderer *renderer)
{
	Personnage *mario = malloc(sizeof(Personnage));
    mario -> jump=0;
    mario -> jumptime=0;
    mario -> gravite=0;
    mario -> direction=0;
    mario -> temp=;
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

void freePersonnage(Personnage* mario, Personnage **goomba, int nbGoomba) {
    
}
