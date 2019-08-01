//In this file we will work with textures

#include <SFML/Graphics.hpp>
#include <iostream>

#define SCREEN_WIDTH 512.0f
#define SCREEN_HEIGHT 512.0f

int main(){

    //We render a window
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Blue Jay Way", sf::Style::Default);
    
    //Always clear the window
    window.clear();

    //We make a simple rectangular object
    sf::RectangleShape player(sf::Vector2f(100.0f, 150.0f));

    //Set it to an initial position
    player.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

    //Make a texture object
    sf::Texture playerTexture;

    //load a texture from memory
    playerTexture.loadFromFile("blue-jay.png");

    //set the texture to the player
    player.setTexture(&playerTexture);

    //Now we mess around with the texture
    //To get the specific blue jay I need, I will divide the texture 
    //by 3 from width and 3 from height

    //First I need to get the size of the texture
    //We are returned a 2d vector
    sf::Vector2u textureSize = playerTexture.getSize();

    //At this point we have the width and height of the texture
    //Now to get the offsets
    textureSize.x = textureSize.x / 3;
    textureSize.y = textureSize.y / 3;

    //Now we set the required blue jay to the player object
    player.setTextureRect(sf::IntRect(textureSize.x * 0, textureSize.y * 0, textureSize.x, textureSize.y));

    //Now we enter the game loop
    while(window.isOpen()){

        //create the event
        sf::Event event;

        //we poll the event
        while(window.pollEvent(event)){

            //check for the event type
            //Only one we care about is the close event
            switch(event.type){
                case sf::Event::Closed:

                    //we clear the window
                    window.clear();

                    //We close the window
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