//In this file we will work with textures

#include <SFML/Graphics.hpp>
#include <iostream>

#define SCREEN_WIDTH 512.0f
#define SCREEN_HEIGHT 512.0f

int main(){

    //render a window
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML Tutorial", sf::Style::Default);

    //make a simple circle
    sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));
    
    //we set it an initial position
    player.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

    //creating the texture for the player
    sf::Texture playerTexture;

    //once we have created the texture object, we load it from the file system
    playerTexture.loadFromFile("tux_from_linux.png");

    //apply texture to player
    player.setTexture(&playerTexture);

    //enter game while loop
    while(window.isOpen()){

        //Make an event
        sf::Event event;

        //we need to poll the event
        while(window.pollEvent(event)){
            //check all possible events and handle them
            switch(event.type){

                //close event
                case sf::Event::Closed:
                    //clear the window and close it
                    window.close();
                    break;
            }

        }

        //clear the window after every frame
        window.clear();

        //draw the player to the window
        window.draw(player);

        //display the window and its contents
        window.display();

    }

    return EXIT_SUCCESS;
}