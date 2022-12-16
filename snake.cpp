#include <iostream>
#include <SDL2/SDL.h>
#include "renderwindow.h"
#include "entity.h"
#include <vector>
#include <ctime>
#define element Entity(0,0,tail)
using namespace std;
const int width=1600;
const int height=896;
int main(int argc,char* args[])
{
    SDL_Renderer* renderer;
    RenderWindow window("snake", width, height);
    SDL_Texture* grass = window.loadTexture("Texturi/grass.png");
    SDL_Texture* snaketex = window.loadTexture("Texturi/snakeup.png");
	SDL_Texture* fruit = window.loadTexture("Texturi/fruit.png");
	SDL_Texture* tail = window.loadTexture("Texturi/tail.png");
	Entity entities[3] = { Entity(0,0, grass),
						  Entity(768 / 2, 768 / 2, snaketex),
						  Entity(rand() % 25 * 64, rand() % 14 * 64, fruit) };
	std::vector <Entity> body(50, element);
    bool GameRunning=true;
    SDL_Event e;

    enum Direction {UP,DOWN,LEFT,RIGHT};
	int dir = -1;
	int tails = 0;

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
		for (int i = tails; i > 0; i--) {
			body[i].x = int(body[i - 1].x);
			body[i].y = int(body[i - 1].y);
		}
		body[0].x = int(entities[1].x);
		body[0].y = int(entities[1].y);

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
		for (int i = 0; i < tails; i++) {
			if (entities[1].x == body[i].x && entities[1].y == body[i].y)
				GameRunning = false;
		}
		if (entities[1].x == entities[2].x && entities[1].y == entities[2].y) {
			entities[2].x = rand() % 25 * 64;
			entities[2].y = rand() % 14 * 64;
			tails++;
		}
		for(int i=0;i<tails;i++)
		{
			if(entities[2].x==body[i].x&&entities[2].y==body[i].y)
			{
				entities[2].x = rand() % 25 * 64;
				entities[2].y = rand() % 14 * 64;
			}
		}
		if(entities[1].x<0)
		entities[1].x=25*64;
		if(entities[1].x>25*64)
		entities[1].x=0;
		if(entities[1].y<0)
		entities[1].y=14*64;
		if(entities[1].y>14*64)
		entities[1].y=0;
		

    window.Clear();
	window.Render(entities[0]);
	window.Render(entities[1]);
	window.Render(entities[2]);
	for (int i = 0; i < tails; i++)
		window.Render(body[i]);
    window.Display();
	SDL_Delay(200);
	}

	window.Clean();
	SDL_Quit();

    return 0;
}

