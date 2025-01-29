#pragma once
#pragma once
#include<SFML/Graphics.hpp>
#include "Animation.h"
#include<iostream>
using namespace sf;

class Parrot
{public:
	Parrot(Texture* text, Vector2u imagecount, float switchtime);
	~Parrot();
	//fuction
	void renderparrot(RenderWindow* window);

	void updateparrot(float deltatime, RenderWindow* window);

	RectangleShape body1;
private:
	//other class that is been used
	Animation animation;


};