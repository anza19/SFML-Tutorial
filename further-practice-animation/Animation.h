#include <SFML/Graphics.hpp>

class Animation{
    public:
        
        Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
        ~Animation();

        //This variable will hold the image that we want to perform animation on
        //InRect that will store the image for animation
        sf::IntRect uvRect;

        //Update function, that updates the next image we want to show
        void Update(int row, float deltaTime); 

    private:
        
        //This variable will have the number of images in a sprite sheet in it
        sf::Vector2u imageCount;

        //This variable will have the current image in it
        sf::Vector2u currentImage;

        //This variable holds the time since we changed image
        float totalTime;

        //This variable holds the time since we switched between images in a spritesheet
        float switchTime;
};