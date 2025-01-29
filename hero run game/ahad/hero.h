#pragma once
#include<SFML/Graphics.hpp>
#include "Animation.h"
#include<iostream>
using namespace sf;

class Hero
{
public:
	// publich functions
	//constructor
	Hero(Texture* text, Vector2u imagecount, float switchtime);
	~Hero();
	//fuction
	void renderhero(RenderWindow* window);

	void updatehero(float deltatime, RenderWindow* window);
	
	void herocollision(RectangleShape &a1, RectangleShape& a2, RectangleShape& a3, RectangleShape& a4 , RenderWindow* window);
private:
	RectangleShape body;
	Clock ck;
	//other class that is been used
	Animation animation;

};