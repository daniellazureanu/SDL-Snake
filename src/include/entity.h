#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Entity{
public:
	Entity(float p_x, float p_y, SDL_Texture* p_tex);
	float getX();
	float getY();
	SDL_Texture* getTex();
	SDL_Rect getCurrentFrame();
	SDL_Point getSize(SDL_Texture* texture);
	float x, y;
	SDL_Texture* tex;
private:
	SDL_Rect currentFrame;
};
