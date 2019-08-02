//Simple window

#include <SFML/Graphics.hpp>

//doremone is about 70 by 90
//window dimensions
#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 800

int main(){

    //create a simple window
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Simple Window", sf::Style::Default);

    //loading a simple texture from the file system
    sf::Texture texture;

    //usng sf::IntRect we can extract a small subsection of the sprite sheet if we want.
    texture.loadFromFile("doremon.png", sf::IntRect(0, 0, 70, 90));

    //we can create a sprite from a texture
    sf::Sprite sprite;
    
    sprite.setTexture(texture);
    //now we run the program as long as the window is open
    while(window.isOpen()){

        //check all the events that are triggered since the last frame
        sf::Event event;

        //poll the event
        while(window.pollEvent(event)){
                    
            //check if close event is closed
            if(event.type == sf::Event::Closed){
                
                //clear and close the screen
                window.clear();
                window.close();
            }

        }

        //clear the frame to remove garbage
        //Elaboration: we always clear before we draw and display
        //So that we remove the contents of the previous frame from the window
        window.clear();

        //normally here is where we would call draw()
        //draw() draws the contents of the function to a hidden buffer
        window.draw(sprite);

        //display 
        //display displays the content from the hidden buffer to the window
        window.display();
    }

    return EXIT_SUCCESS;
}