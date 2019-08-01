#include <SFML/Graphics.hpp>

class Animation{
    public:
        
        //Constructor
        Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
        
        //Destructor
        ~Animation();

        //Rect we want to use to display the image
        sf::IntRect uvRect;

        //Update function
        //deltaTime difference between time frames
        void Update(int row, float deltaTime);
    
    private:

        //This variable stores the amount of images in a texture
        //We use Vector2u because image indices will always be unsigned
        sf::Vector2u imageCount;

        //We need the current image
        sf::Vector2u currentImage;

        //Next variables control the speed of the animation
        float totalTime;

        //Time taken to switch image
        float switchTime;
};