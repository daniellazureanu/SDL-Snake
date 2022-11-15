#include <RenderWindow.h>

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h)
:window(NULL), renderer(NULL){
    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}
void RenderWindow::Clean(){
    SDL_DestroyWindow(window);
}

void RenderWindow::Clear(){
    SDL_RenderClear(renderer);
}


void RenderWindow::Display(){
    SDL_RenderPresent(renderer);
}
SDL_Texture* RenderWindow::loadTexture(const char* p_filepath){
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, p_filepath);
    return texture;
}
void RenderWindow::Renderer(SDL_Texture* p_texture){
    SDL_RenderCopy(renderer,p_texture,NULL,NULL);
}