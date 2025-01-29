#include"parrot.h"

Parrot::Parrot(Texture* text, Vector2u imagecount, float switchtime) :
	animation(text, imagecount, switchtime)
{
	//Setting the postion,size,origin(mid point of the image), and scale(it is also the size)
	//body.setPosition(200.0f, 815.0f);
	body1.setSize(Vector2f(90.0, 120.0f));
	body1.setOrigin(body1.getSize() / 2.0f);
	body1.setPosition(rand() % 2340 + 3970, 760);
	body1.setScale(Vector2f(1.50f, 1.50f));
	//loading image as texture
	body1.setTexture(text);


}
Parrot::~Parrot() {}

void Parrot::updateparrot(float deltatime, RenderWindow* window)
{
	unsigned int row1 = 0;
	animation.updateparrot1(row1, deltatime);
	body1.setTextureRect(animation.uvRect);

}

void Parrot::renderparrot(RenderWindow* window)
{
	window->draw(body1);
}