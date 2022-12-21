//
//  particle.cpp
//  videorain
//
//  Created by Matt Comeione on 12/11/22.
//

#include "particle.hpp"

particle::particle(int startX, int startY, int hue){
    position = glm::vec2(startX, startY);
    // direction = glm::vec2(ofRandom(-2.0, 2.0), ofRandom(-2.0, 2.0));
    force = glm::vec2(0, 0.02);
    direction = force;
    size = ofRandom(32, 128);
    color.setHsb(hue, 255, 255);
    dot.load("dot.png");
    dead = false;
    dot.resize(size,size);
}

particle::particle(int startX, int startY, ofColor initColor, float initSize){
    position = glm::vec2(startX, startY);
    direction = glm::vec2(ofRandom(-1.0, 1.0), ofRandom(-1.0, 1.0));
    size = initSize;
    force = glm::vec2(0, 0.02);
    //direction = force;
    color = initColor;
    dot.load("dot.png");
    dead = false;
    dot.resize(size,size);
}

particle::~particle(){
    
}

void particle::update(){
    position += direction;
    direction += force;
    if(size > 1)
    {
        size -= 0.07;
    }
    float brightness = color.getBrightness();
    //float myHue = color.getHue();
    if(brightness > 1)
    {
        color.setBrightness(brightness -= 0.5);
        //color.setHue( myHue -= 0.5);
    }
    else
    {
        color.setBrightness(brightness = 0);
        dead = true;
    }
}

void particle::draw(){
    ofEnableAlphaBlending();
    ofBlendMode(OF_BLENDMODE_MULTIPLY);
    ofSetColor(color);
    dot.setAnchorPercent(0.5, 0.5);
    dot.draw(position, size, size);
    ofRectangle(position,size,size);
}
