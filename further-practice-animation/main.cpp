
//In this file we will work with animation

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Animation.h"

#define SCREEN_WIDTH 512.0f
#define SCREEN_HEIGHT 512.0f

int main(){

    //render a window
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Simple Sprite Animation", sf::Style::Default);

    //make a simple rectangle on which we display texture on
    sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));

    //we set it an initial position
    player.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

    //create texture
    sf::Texture playerTexture;
    playerTexture.loadFromFile("goku.png");

    //set this texture to the rectangle we have rendered on the screen
    player.setTexture(&playerTexture);

    //we begin our animation here 
    //for image count we provide the number of sprites in the x direction
    //And the number of sprites in the y direction
    int row = 9;
    int col = 6;
    Animation animation(&playerTexture, sf::Vector2u(row,col), 0.5f);

    //define the delta time here
    float deltaTime = 0.0f;

    //clock to track the time that has passed
    sf::Clock clock;

    //enter game while loop
    while(window.isOpen()){

        //we get delta time to be the time elapsed
        deltaTime = clock.restart().asSeconds();

        //an event that will be polled
        sf::Event event;
        
        //poll the events, checking for the closed event specifically
        while(window.pollEvent(event)){
            
            //if closed event type, close it
            if(event.type == sf::Event::Closed){
                
                //clear and close the window
                window.clear();
                window.close();
            }
        }

        //update the animation

        //to change the row you want to see just change the row number in the update function call.
        animation.Update(0, deltaTime);

        //set the texture
        player.setTextureRect(animation.uvRect);

        //clear the window after every frame
        window.clear(sf::Color(150, 150, 150));

        //draw the player to the window
        window.draw(player);

        //display the window and its contents
        window.display();

    }

    return EXIT_SUCCESS;
}