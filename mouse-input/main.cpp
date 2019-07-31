//In this lecture we will learn how to make cubes

#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>

int main(){

    //Here we are rendering the window in video mode
    //For videomode we need to give two parameters, the dimensions of the screen and the name
    //We can also give the style of the window
    sf::RenderWindow window(sf::VideoMode(1024, 1024),"SFML Tutorials", sf::Style::Default);

    //Clear window on first render to make sure no pixels in the memory buffer add crap to the screen.
    window.clear();

    //Making a simple circle
    sf::CircleShape player(10.0f, 30UL);
    
    //We can fill the color for the player
    player.setFillColor(sf::Color::Green);

    //Need a game loop
    while(window.isOpen()){

        //Create an event
        sf::Event event;
        while(window.pollEvent(event)){

            //Check for a series of event
            switch(event.type){

                //First we check for the closed event
                case sf::Event::Closed:
                    window.clear();
                    window.close();
                    break;

                //Next we check for the event when the window is resized
                case sf::Event::Resized:
                    //event.size gives us the screen dimension
                    std::cout << "The width is: " << event.size.width << std::endl;
                    std::cout << "The height is: " << event.size.height << std::endl;
                    break;
                
                //Get user input
                //checks if text entered
                case sf::Event::TextEntered:
                    if(event.text.unicode < 128){
                        printf("%c", event.text.unicode);
                    }
                    break;
            }
        }   

        //Taking mouse user from the user
        //sf::Mouse::isButtonPressed(sf::Mouse::Left)
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){

            //how to get mouse position
            //to get the mouse position we use sf::Mouse::getPosition
            //Trouble is this function takes origin from the monitor's origin, not the screen's
            //To rectify this, we pass it as a param a WINDOW
            //this in returns a 2D vector in integer format
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);

            //setPosition totally overwrites the original position
            player.setPosition((float)mousePos.x , (float)mousePos.y);
        }

        //draw player
        window.draw(player);

        //display the player
        window.display();
    }

    return EXIT_SUCCESS;
}   