
#ifndef ES_H_INCLUDED
#define ES_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>


typedef struct 
{
	SDL_Rect pos1;
        SDL_Rect pos2;
	SDL_Surface* right;
	SDL_Surface* left;
	SDL_Surface* battleImage;
	
}Ennemi;

void initEnnemi(Ennemi*e);
void afficherEnnemi(Ennemi e, SDL_Surface * screen);
void animerEnnemi( Ennemi * e);
void deplacer( Ennemi * e);
int collisionBB( personne p, Ennemi e);
void deplacerIA( Ennemi * e, SDL_Rect posPerso);

#endif // ES_H_INCLUDED
