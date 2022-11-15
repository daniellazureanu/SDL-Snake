#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
class RenderWindow{
public:
    RenderWindow(const char* p_title, int p_w, int p_h);
    void Clean();
    void Clear();
    void Display();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};