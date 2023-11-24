#include <SDL2/SDL_image.h>

#include "file.h"


/*permet de charger une image dans une SDL_Texture avec l'option SDL_TEXTUREACCESS_TARGET
pour pouvoir modifier la texture après. */
SDL_Texture *loadImage(const char path[], SDL_Renderer *renderer)
{
    SDL_Surface *surface = NULL; 
    SDL_Texture *tmp = NULL, *texture = NULL;
    surface = IMG_Load(path);
    if(NULL == surface)
    {
        fprintf(stderr, "Erreur IMG_Load : %s", SDL_GetError());
        return NULL;
    }
    tmp = SDL_CreateTextureFromSurface(renderer, surface);
    if(NULL == tmp)
    {
        fprintf(stderr, "Erreur SDL_CreateTextureFromSurface : %s", SDL_GetError());
        return NULL;
    }
    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, 
                            SDL_TEXTUREACCESS_TARGET, surface->w, surface->h); 
    if(texture == NULL) 
    {
        fprintf(stderr, "Erreur SDL_CreateTextureFromSurface : %s", SDL_GetError());
        return NULL;
    }
    SDL_SetRenderTarget(renderer, texture); /* La cible de rendu est maintenant texture. */
    SDL_SetTextureBlendMode(tmp, SDL_BLENDMODE_NONE); /* gère la transparence du fond des images*/
    SDL_RenderCopy(renderer, tmp, NULL, NULL); /* On copie tmp sur texture */
    SDL_DestroyTexture(tmp); //nettoyage
    SDL_FreeSurface(surface); //nettoyage
    SDL_SetRenderTarget(renderer, NULL); /* La cible de rendu est de nosuveau le renderer. */
    return texture;
}

Sprites* chargerImages(SDL_Renderer* renderer){
    Sprites* nsprite = malloc(10*sizeof(Sprites));
    nsprite[0].sprite = loadImage("img/sky.png",renderer);
    nsprite[0].traverser = 0;

    nsprite[1].sprite = loadImage("img/sol.png",renderer);
    nsprite[1].traverser = 1;    

    nsprite[2].sprite = loadImage("img/block.png",renderer);
    nsprite[2].traverser = 1;

    nsprite[3].sprite = loadImage("img/boîte.png",renderer);
    nsprite[3].traverser = 1;

    nsprite[4].sprite = loadImage("img/tuyau1.png",renderer);
    nsprite[4].traverser = 1;

    nsprite[5].sprite = loadImage("img/tuyau2.png",renderer);
    nsprite[5].traverser = 1;

    nsprite[6].sprite = loadImage("img/tuyau3.png",renderer);
    nsprite[6].traverser = 1;

    nsprite[7].sprite = loadImage("img/tuyau4.png",renderer);
    nsprite[7].traverser = 1;

    nsprite[8].sprite = loadImage("img/fin1.png",renderer);
    nsprite[8].traverser = 1;

    nsprite[9].sprite = loadImage("img/fin2.png",renderer);
    nsprite[9].traverser = 0;
    
    return nsprite;
}

void readlvl(Map *map){

    FILE *niveau = fopen("level/niveau0.lvl", "r");
    if( niveau == NULL){
        perror("fopen:");
        exit(0);
    }
    char lvl[10];
    fgets(lvl ,10, niveau);
    
    int nb;
    fscanf(niveau, "%d",&nb);
    map->width = nb;
    
    int nb2;
    fscanf(niveau,"%d",&nb2);
    map->height = nb2;
    int *tab = malloc((map->width)*sizeof(int*));
    for(int i=0; i<map->width; i++){
        map->LoadedMap[i]=malloc(sizeof(int)*map->height);   
    }

    for(int j=0; j<map->width; j++){
        for(int k=0; k<map->height; k++){
            fscanf(niveau,"%d",map->LoadedMap[j][k]);
        }

    }  


   fclose(niveau);
    return map;
    
}

void afficherMap(Map* map, Sprites* sprites, SDL_Renderer *renderer) {

    SDL_Rect rectangleSource = {0,0,40,40};
    SDL_Rect rectangleDest = {0,0,32,32};
    for (int i = 0; i < map->height; i++)
    {
        for (int j = 0; j < map->width; j++)
        {
            rectangleDest.x = j*32;
            rectangleDest.y = i*32;
            SDL_RenderCopy(renderer, sprites[map->LoadedMap[i][j]].sprite, &rectangleSource, &rectangleDest);

        }
        
    }
}

void LibererMap(Map* map, Sprites* sprites)
{
  
}
