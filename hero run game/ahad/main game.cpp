#include"SFML\Window.hpp"
#include"SFML\Graphics.hpp"
#include<iostream>
#include"hero.h"
#include"parrot.h"

using namespace sf;
using namespace std;
int main() {

    string y; 
    cout << ".................................\"How to play the game\"......................................\n";
    cout << ".....................................\"For movemennt\".........................................\n";
    cout << ".....................................\"W for jumping\".........................................\n";
    cout << ".....................................\"S for rolling\".........................................\n";
    cout << "...............................\"For each object dodged you get 10 points\"....................\n";
    cout << "....................\"If u touch and object the game ends \"...................................\n";
    cout << "..............................\"Hopefully you will enjoy the game\"...........................\n";
    cout << "\n\nPlease enter \"Your name\" to start the game: ";
    cin >> y;
    int score=0;
    // creating a window
    RenderWindow window(VideoMode(1920, 1080), "PROJECT", Style::Fullscreen);
    //setting frame rate
    window.setFramerateLimit(60);
    //creating texture type variable to load hero
    Texture HERO;
    HERO.setSmooth(true);
    // loading hero in texture type variable(hero)
    HERO.loadFromFile("content/hero.png");
    Hero hero(&HERO, Vector2u(6, 3), 0.1);


    //texture type variable for the paret
    Texture prt;
    prt.loadFromFile("content/prt.png");
    Parrot parrot(&prt, Vector2u(10, 1), 0.1);

    //texture type variable for the background
    Texture bg;
    //loading the background
    if (!bg.loadFromFile("content/sky.png"))
    {
        cout << " cant not load " << endl;
    }
    //creating a rectangle shape for the background
    RectangleShape bx, bx1;
    //giving the backg round to the rectangleshape 
    bx.setTexture(&bg);
    bg.setSmooth(true);
    //setting size of the background
    bx.setSize(Vector2f(1920, 1080));
    // another background
    bx1.setTexture(&bg);
    bg.setSmooth(true);
    //setting size of the background
    bx1.setSize(Vector2f(1920, 1080));
    bx1.setPosition(1920.f, 0.f);




    //getting the GRASS.png
    Texture grasstex;
    Sprite grass;

    grasstex.loadFromFile("content/grass.png");
    grasstex.setSmooth(true);
    grass.setTexture(grasstex);

    //setting the size and scale of grass
    grass.setScale(3.4f, 1.5f);
    grass.setPosition(0.f, 650.f);
    //another variable for grass 2 
    Sprite grass1;

    grass1.setTexture(grasstex);
    //setting the size and scale of grass
    grass1.setScale(3.4f, 1.5f);
    grass1.setPosition(1920.f, 650.f);
   //variable for wood and stone (objects to jump over)
    Texture stone;
    stone.loadFromFile("content/Stone.png");

    Texture wood;
    wood.loadFromFile("content/Wood.png");
    
    //rectangle shaps for stone and wood
    RectangleShape st, wd;
    //seeting the size and positions of the stone
    st.setTexture(&stone);
    stone.setSmooth(true);
    st.setSize(Vector2f(200, 150));
    st.setPosition(2400.f, 800.f);
    //wood
    //seeting the size and positions of the wood
    wd.setTexture(&wood);
    wood.setSmooth(true);
    wd.setSize(Vector2f(100, 150));
    wd.setPosition(1960, 820);
    wd.rotate(450.f);
    //wood 2 
    RectangleShape wd1;

    //wood 2 seeting size

    wd1.setTexture(&wood);
    wood.setSmooth(true);
    wd1.setSize(Vector2f(100, 150));
    wd1.setPosition(3160, 820);
    wd1.rotate(450.f);
    
    
    //a clock that record the time 
    Clock cll, dll;
    // variable to store the current time
    float deltatime;
    // class that handles time
   // Time time;

   
        //main game loop
        while (window.isOpen())
        { 
            Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
            }
            //update
            deltatime = cll.restart().asSeconds();
            //grass
            //grass moves
            {
                grass.move(-10.f, 0.f);
            }
            if (grass.getPosition().x <= -1920)
            {

                grass.setPosition(1920.f, 650.f);

            }
            //grass1 movement
            {
                grass1.move(-10.f, 0.f);
            }
            if (grass1.getPosition().x <= -1920)
            {

                grass1.setPosition(1920.f, 650.f);

            }
            //background movement

            bx.move(-10.0f, 0.0f);
            if (bx.getPosition().x <= -1920)
            {
                bx.setPosition(1920.f, 0.f);
            }
            bx1.move(-10.0f, 0.0f);
            if (bx1.getPosition().x <= -1920)
            {
                bx1.setPosition(1920.f, 0.f);
            }

            //wood movement
            wd.move(-10.f, 0.f);
            if (wd.getPosition().x <= -wd.getSize().x)
            {
                score = score + 10;
                wd.setPosition(rand() % 3640 + 1920 + wd.getSize().x, 820.f);
            }
            //wood 2 movement
            wd1.move(-10.f, 0.f);
            if (wd1.getPosition().x <= -wd1.getSize().x - 400)
            {
                score = score + 10;
                wd1.setPosition(rand() % 3840 + 2000 + wd1.getSize().x, 820.f);
            }



            //stone movement0
            st.move(-10.f, 0.f);
            if (st.getPosition().x <= -st.getSize().x)
            {
                score = score + 10;
                //st.setPosition(window.getSize().x + st.getSize().x*2, 800.f);
                st.setPosition(rand() % 2340 + 1990, 800.f);
            }
            parrot.body1.move(-11.7f, 0.f);
            if (parrot.body1.getPosition().x <= -parrot.body1.getSize().x)
            {
                score = score + 10;
                
                parrot.body1.setPosition(rand() % 2340 + 3970, 760);
            }
           
            //collision
            hero.herocollision( st, wd, wd1,parrot.body1 , &window);



            //updating hero
            hero.updatehero(deltatime, &window);
            parrot.updateparrot(deltatime, &window);


            //clearing the window
            window.clear();



            //drawing the background
            window.draw(bx);
            window.draw(bx1);
            //drawing the grass
            window.draw(grass);
            window.draw(grass1);
            //drawing the stone and wood
            window.draw(st);
            window.draw(wd);
            window.draw(wd1);

           
               
            
            hero.renderhero(&window);
            parrot.renderparrot(&window);
            //displaying the window
            window.display();
            //saving the time elapsed kind of a stop watch
          //  time = dll.getElapsedTime();


        }
        cout << "\n your total score is " << score<<endl<<endl;
   

    return 0;
}