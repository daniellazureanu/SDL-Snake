#include <iostream>
#include <SDL2/SDL.h>
#include "renderwindow.h"
#include "entity.h"
#include <vector>
using namespace std;
const int width=768;
const int height=768;
int main(int argc,char* args[])
{
    SDL_Renderer* renderer;
    RenderWindow window("snake", width, height);
    SDL_Texture* grass = window.loadTexture("Texturi/grass.png");
    SDL_Texture* snaketex = window.loadTexture("Texturi/snakeup.png");
    Entity entities[2] = {Entity(0,0, grass), Entity(768/2, 768/2, snaketex)};
    bool GameRunning=true;
    SDL_Event e;

    enum Direction {UP,DOWN,LEFT,RIGHT};
	int dir = -1;

    while(GameRunning){
		while(SDL_PollEvent(&e)){
			if(e.type == SDL_QUIT)
				GameRunning = false;
			if(e.type == SDL_KEYDOWN){
				switch(e.key.keysym.sym){
					case SDLK_LEFT:
						dir=LEFT;
						entities[1].tex=window.loadTexture("Texturi/snakeleft.png");
						break;
					case SDLK_DOWN:
						dir=DOWN;
						entities[1].tex=window.loadTexture("Texturi/snakedown.png");
						break;
					case SDLK_UP:
						dir=UP;
						entities[1].tex=window.loadTexture("Texturi/snakeup.png");
						break;
					case SDLK_RIGHT:
						dir=RIGHT;
						entities[1].tex=window.loadTexture("Texturi/snakeright.png");
						break;

				}
			}
		}

		switch(dir){
			case LEFT: // if dir = LEFT atunci
				entities[1].x-=64;
				break;
			case DOWN: // if dir = DOWN atunci
				entities[1].y+=64;
				break;
			case UP:
				entities[1].y-=64;
				break;
			case RIGHT:
				entities[1].x+=64;
				break;
		}
    window.Clear();
	window.Render(entities[0]);
	window.Render(entities[1]);
    window.Display();
	SDL_Delay(200);
	}
	window.Clean();
	SDL_Quit();

    return 0;
}

