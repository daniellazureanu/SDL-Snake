#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "entity.h"
#include <stdio.h>

using namespace std;
class RenderWindow{
public:
    RenderWindow(const char* p_title, int p_w, int p_h);
	SDL_Texture* loadTexture(const char* p_filePath);
	void Clean();
	void Clear();
	void Render(Entity& p_entity);
	void Display();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};
