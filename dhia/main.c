#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "code.h"


int main()
{
	int collision ,distance =10 , sens=0;
    SDL_Event event;
	minimap m;
    Personne p , pM , pMprochaine;
	temps t;
	SDL_Surface *screen = NULL,*imageDeFond=NULL , *masked=NULL;
	SDL_Rect position_BG ;
   int longueurM=3211 , largeurM=600 , longueur =1080 , largeur=210;
	screen = SDL_SetVideoMode(1080, 210 , 32, SDL_SWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
	TTF_Init();
    if(screen==NULL)
    	{
        	printf("ERREUR: %s\n", SDL_GetError());
        	return 1;
       }


position_BG.x=0;
position_BG.y=0;

	imageDeFond = IMG_Load("map.png");
       int continuer= 1;
       initmap( &m);
       initialiser_temps(&t);

       masked=IMG_Load("mask.png");

    p.sprite=IMG_Load("joueurmini.png");
    p.position_perso.x=400;
    p.position_perso.y=20;



    pM.sprite=IMG_Load("hero.png");
    pM.position_perso.x=0;
    pM.position_perso.y=105;


    pMprochaine.position_perso.h=180;
    pMprochaine.position_perso.w=110;
    pMprochaine.position_perso.x=pM.position_perso.x;
    pMprochaine.position_perso.y=pM.position_perso.y;
    
	while (continuer)
{
	sens=0;

    SDL_BlitSurface(imageDeFond, NULL, screen, &position_BG);
	afficherminimap ( m,screen);
    SDL_BlitSurface(p.sprite, NULL, screen, &p.position_perso);
    SDL_BlitSurface(pM.sprite, NULL, screen, &pM.position_perso);
	afficher_temps(&t,screen);
    

	while(SDL_PollEvent(&event))
	{

     switch(event.type)
    {
            case SDL_QUIT:
                continuer = 0;
        break ;
        case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                	case SDLK_ESCAPE:
                            continuer = 0;
             		break;
                	case SDLK_RIGHT :
                    sens=1;
                	break;

                	case SDLK_LEFT :
                    sens=-1;
                    break;
                }
            }
            	
            }
            mouvement(&p ,&pM ,&pMprochaine,distance,longueur,longueurM , masked ,  sens );
            SDL_Flip(screen);

}
free_minimap (&m);
SDL_FreeSurface(p.sprite);
free_temps(&t,screen);
SDL_FreeSurface(screen);
TTF_Quit();
SDL_Quit();
	return EXIT_SUCCESS;
}
