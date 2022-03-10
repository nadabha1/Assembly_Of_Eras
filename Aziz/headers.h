#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#include <SDL/SDL.h>

#include <SDL/SDL_mixer.h>

#include <SDL/SDL_image.h> 

#include "SDL/SDL_ttf.h"



typedef struct 

{

 char question[256]; 

 char rep1[256]; 

 char rep2[256]; 

 char rep3[256]; 

 SDL_Surface * quest_bg; 

 SDL_Rect quest;

 int CorrectAnswer;

}enigmeimg;



void InitEnigmeIMG(enigmeimg * e, char *nomfichier); 

void afficherEnigmeIMG(enigmeimg e, SDL_Surface *screen); 

void animerenigmeIMG(enigmeimg *e);

void HandleCharCostumes(int isInOptions); // extra points

void HandleInputKeySystem(int isInOptions, SDL_Event * event); // extra points
#endif // ENIGME_H_INCLUDED
