#include <iostream>
#include <SDL2/SDL.h>
#include "renderwindow.h"
using namespace std;
const int width=1280;
const int height=720;
int main(int argc,char* args[])
{
    RenderWindow window("snake", width, height);
    bool GameRunning=true;
    SDL_Event e;
    while(GameRunning==true)
    {
        while(SDL_PollEvent(&e))
        {
            if(e.type == SDL_QUIT)   
            {GameRunning = false;}
        }
    }
    window.Clean();
    SDL_Quit();
    return 0;
}
