#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED
#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <string.h>

void afficherEnigme(enigme e, SDL_Surface * screen);
void InitEnigme(enigme * e, char *nomfichier);
void animer (enigme * e);
void sauvegarder (personne p, background b, char * nomfichier);
int charger ( personne * p, background *b , char * nomfichier);




#endif

