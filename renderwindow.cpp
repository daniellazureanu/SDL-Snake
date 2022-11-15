#include <RenderWindow.h>

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h)
:window(NULL), renderer(NULL){
    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);
    if(window == NULL)
        printf("Window-ul nu a putut fi creat:\n", SDL_GetError());
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