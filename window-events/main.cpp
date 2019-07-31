//In this lecture we will learn how to work with events
#include <SFML/Graphics.hpp>
#include <iostream>

int main(){

    //Here we are rendering the window in video mode
    //For videomode we need to give two parameters, the dimensions of the screen and the name
    //We can also give the style of the window
    sf::RenderWindow window(sf::VideoMode(512, 512),"SFML Tutorials", sf::Style::Close | sf::Style::Resize);

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
            }
        }        
    }

    return EXIT_SUCCESS;
}   