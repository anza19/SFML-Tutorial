#include "Animation.h"

Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime){

    //set image count, this is a reference to the current object
    this->imageCount = imageCount;
    this->switchTime = switchTime;
    totalTime = 0.0f;
    currentImage.x = 0;

    //Get offset of the specific image in the texture you need
    uvRect.width = texture->getSize().x / float(imageCount.x);
    uvRect.height = texture->getSize().y / float(imageCount.y);

}

Animation::~Animation(){

}

void Animation::Update(int row, float deltaTime){

    //set current image's y to row
    currentImage.y = row;

    //increment total time with delta time
    totalTime += deltaTime;

    if(totalTime >= switchTime){

        //smoother animation
        totalTime -= switchTime;

        //switch current image
        currentImage.x++;

        if(currentImage.x >= imageCount.x){
            currentImage.x = 0;
        }
    }

    //set left and top offset of uv
    uvRect.left = currentImage.x * uvRect.width;
    uvRect.top = currentImage.y * uvRect.height;

}