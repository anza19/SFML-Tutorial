//In this lecture we will learn how to open a window

#include <SFML/Graphics.hpp>

int main(){

    //Here we are rendering the window in video mode
    //For videomode we need to give two parameters, the dimensions of the screen and the name
    //We can also give the style of the window
    sf::RenderWindow window(sf::VideoMode(512, 512),"The Screen's Name", sf::Style::Close | sf::Style::Resize);

    //Need a game loop
    while(window.isOpen()){

        //Create an event
        sf::Event event;
        while(window.pollEvent(event)){

            //check if need to close the event
            if(event.type == sf::Event::Closed){
                //clear and close the window
                window.clear();
                window.close();
            }
        }        
    }
}   