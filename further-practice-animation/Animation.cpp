#include "Animation.h"

/*
The constructor is where we set the image count, switch time.
Also we compute the width and height for the offset we needed to display for the image
 */
Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime){
    
    this->imageCount = imageCount;
    this->switchTime = switchTime;
    totalTime = 0.0f;

    //starting current image we set to 0
    currentImage.x = 0;

    //We need to compute the offset we need to get the image we need
    uvRect.width = texture->getSize().x / (float)imageCount.x;

    uvRect.height = texture->getSize().y / (float)imageCount.y;
}

Animation::~Animation(){

}

void Animation::Update(int row, float deltaTime){

    //We set the y offset to be the row that we want to perform animation for
    currentImage.y = row;

    //Increment total time with delta time
    //Delta time is the time interval between changing frames
    totalTime += deltaTime;

    //when the totaltime exceeds the switch time which is the time between frame transition
    //we reduce totaltime by that switchtime to give a more smoother transition
    if(totalTime >= switchTime){
        totalTime -= switchTime;

        //we increment the x offset for currentImage to point to the next image
        currentImage.x++;

        //we also need to perform an additional check to see whether the x offset for current image we have is a sane value
        //basically that we haven't reached the end of the imageCount's x
        if(currentImage.x >= imageCount.x){

            //we reset everything
            currentImage.x = 0;
        }
    }

    //to fully display the image on the uvRect, we get the offset needed
    uvRect.left = currentImage.x * uvRect.width;
    uvRect.top = currentImage.y * uvRect.height;
}