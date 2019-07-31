//In this lecture we will learn how to make cubes

#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>

int main(){

    //Here we are rendering the window in video mode
    //For videomode we need to give two parameters, the dimensions of the screen and the name
    //We can also give the style of the window
    sf::RenderWindow window(sf::VideoMode(512, 512),"SFML Tutorials", sf::Style::Close | sf::Style::Resize);

    //Making a simple rectangle
    //For size we give a vector ==> x and y coordinate, these can suffice for width and height
    sf::RectangleShape player(sf::Vector2f(50.0f, 50.0f));

    //We can fill the color for the player
    player.setFillColor(sf::Color::Magenta);

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
        //clear the screen after every frame
        window.clear();
        
        //draw player
        window.draw(player);

        //display the player
        window.display();
    }

    return EXIT_SUCCESS;
}   