#include "entity.h"

Entity::Entity(float p_x, float p_y, SDL_Texture* p_tex)
: x(p_x), y(p_y), tex(p_tex){
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = getSize(tex).x;
	currentFrame.h = getSize(tex).y;
}

float Entity::getX(){
	return x;
}

float Entity::getY(){
	return y;
}

SDL_Texture* Entity::getTex(){
	return tex;
}

SDL_Rect Entity::getCurrentFrame(){
	return currentFrame;
}

SDL_Point Entity::getSize(SDL_Texture* texture) {
    SDL_Point size;
    SDL_QueryTexture(texture, NULL, NULL, &size.x, &size.y);
    return size;
}
//test
