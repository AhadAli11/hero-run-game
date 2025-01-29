#include"hero.h"
#include<thread>

Hero::Hero(Texture* text, Vector2u imagecount, float switchtime) :
	animation(text, imagecount, switchtime)
{
	//Setting the postion,size,origin(mid point of the image), and scale(it is also the size)
	body.setSize(Vector2f(150.0, 200.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(200.0f, 835.0f);
	body.setScale(Vector2f(1.50f, 1.50f));
	//loading image as texture
	body.setTexture(text);


}
Hero::~Hero() {}



	void Hero::updatehero(float deltatime, RenderWindow* window)
{
	//variable for the rows of the image
	unsigned int row ;
	if (body.getPosition().y == 835.f)
		row = 2;
	else if (body.getPosition().y < 835.f)
		row = 0;
	// speed at which the object will move or jump up 
	static float jumpSpeed = 0.0f;
	static float down = 0.8f;
	if(body.getPosition().y==835.0f)
	{
	if (Keyboard::isKeyPressed(Keyboard::Key::W ) ) {
		// Simulating a jump when 'W' is pressed
		jumpSpeed = -23.0f; // Set the initial jump speed (negative value moves the character up)

		row = 0; // Set the row for the jump animation
	
	}
	}
	jumpSpeed += down;
	
	body.move(0.0f, jumpSpeed);

	// Check if the character is on the ground 
	if (body.getPosition().y >= 835.0f) {
		// Ensure the character stays on the ground
		jumpSpeed = 0.0f;
		body.setPosition(body.getPosition().x, 835.0f);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::S)&& body.getPosition().y==835.0f)
	{
		row = 1;
		Mouse::getPosition(*window);
		Mouse::setPosition(Vector2i(200.f, 885.f));

	}
	else {
		Mouse::getPosition(*window);
		Mouse::setPosition(Vector2i(body.getPosition()));

	}

	if (Keyboard::isKeyPressed(Keyboard::Key::S)&& body.getPosition().y<835.0f)
	{
		down = 2.5f;
		
	}
	else
	{
		down = 0.8f;
	}
	animation.update(row, deltatime);
	body.setTextureRect(animation.uvRect);
	//setting  the mouse pointer 
	}

	void Hero::herocollision(RectangleShape& a1, RectangleShape& a2, RectangleShape& a3, RectangleShape& a4, RenderWindow* window)
	{

		Vector2i mousePosition = Mouse::getPosition(*window);
		if (FloatRect(float(mousePosition.x), float(mousePosition.y), 1.f, 100.f).intersects(a1.getGlobalBounds()) ||
			FloatRect(float(mousePosition.x), float(mousePosition.y), 1.f, 100.f).intersects(a2.getGlobalBounds()) ||
			FloatRect(float(mousePosition.x), float(mousePosition.y), 1.f, 100.f).intersects(a3.getGlobalBounds()) ||
			FloatRect(float(mousePosition.x), float(mousePosition.y), 1.f, 100.f).intersects(a4.getGlobalBounds()))
		{

			window->close();


		}
	}




void Hero::renderhero(RenderWindow* window)
{
	window->draw(body);
}