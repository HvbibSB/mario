#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>

#include "file.h"
#include "game.h"

//ligne de compilation gcc main.c file.c game.c event.c charactere.c -o mario -lSDL2main -lSDL2_image -lSDL2

int init(SDL_Window **window, SDL_Renderer **renderer, int w, int h);

int main(int argc, char *argv[])
{


    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("mario",0,0,LARGEUR_FENETRE, HAUTEUR_FENETRE,SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window , -1 ,SDL_RENDERER_ACCELERATED);


    SDL_Texture *textureMenu = loadImage("img/menu.jpg",renderer);

    SDL_SetRenderDrawColor(renderer, 255,255,255,0);
    SDL_RenderClear(renderer);
    SDL_Rect rectangleSource = {0,0,600,600};
    SDL_Rect rectangleDestination = {0,0,LARGEUR_FENETRE, HAUTEUR_FENETRE};
    SDL_RenderCopy(renderer, textureMenu, &rectangleSource, &rectangleDestination);
    SDL_RenderPresent(renderer);

    

// Maintenant on fais les evenement du clavier pour sortir du jeu avec echap et de jouer au jeu en appuyant sur 1
    int continuer = 1;
    SDL_Event events;

    while(continuer)
    { //coeur du jeu ici, les actions seront repété pour faire le déplacement des différentes images, ...
        while (SDL_PollEvent(&events))
        {
            switch (events.type)
            {
                case SDL_QUIT:
                    continuer = 0;
                    break;
                case SDL_KEYDOWN:// a utiliser quand on appuie sur une touche 
                    switch(events.key.keysym.sym)
                    {
                        case SDLK_1://appuie sur 1
                        continuer = jouer(renderer);
                        break;
                        case SDLK_ESCAPE://appuie sur echap  
                        continuer = 0;  
                            break;
                    }
        }
    
    }
    
    //commencement de la map

    //oublies pas d ajouter le free 
    SDL_DestroyTexture(textureMenu);
    return 0;
}
