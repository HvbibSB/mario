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
	SDL_Window *window;
	window = SDL_CreateWindow("LeJeu",100,200,LARGEUR_FENETRE,HAUTEUR_FENETRE,SDL_WINDOW_SHOWN);
	SDL_Renderer *renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
	SDL_Texture *MenuTexture = loadImage("img/menu.jpg", renderer);
	SDL_SetRenderDrawColor(renderer,255,255,255,255);
	SDL_RenderClear(renderer);
	SDL_Rect rectangleSource = {0,0,1200,1200};
	SDL_Rect rectangleDest = {0,0,LARGEUR_FENETRE,HAUTEUR_FENETRE};
	SDL_RenderCopy(renderer, MenuTexture,&rectangleSource,&rectangleDest);
	SDL_RenderPresent(renderer);

	SDL_Event event;
	int continuer = 1;
	while (continuer){
		while (SDL_PollEvent(&event)){
			switch (event.type){
				case SDL_QUIT : 
					continuer = 0;
					break;
				case SDL_KEYDOWN:
            		switch(event.key.keysym.sym)
					{
						case SDLK_1 :
							printf("touche appuyée ");
							
							printf("avant continuer ");
							continuer = jouer(renderer);
							printf("fin op ");
							return 0;
							break;
					}
					break;
			}
		}
	}


	SDL_DestroyTexture(MenuTexture);
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	return 0;
}
