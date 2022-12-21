//
//  camrain.cpp
//  videorain
//
//  Created by Matt Comeione on 12/11/22.
//

#include "camrain.hpp"

void camrain::setup(){
    webcam.setup(320, 180);
    webcam.setDesiredFrameRate(15);
    camwidth = webcam.getWidth();
    camheight = webcam.getHeight();
}

//--------------------------------------------------------------
void camrain::update(){
    webcam.update();
    if(webcam.isFrameNew())
    {
        for (int i=0; i<particles.size(); i++)
        {
            particles[i].update();
        }

        // Clean up causes extreme slow down

    }
}

//--------------------------------------------------------------
void camrain::draw(){
    int grid = 16;
    for( int i = 0; i<camwidth; i+= grid)
    {
        for( int j = 0; j < camheight; j+= grid)
        {
            if(ofRandom(0, 1.0) >= 0.95)
            {
                ofColor color = webcam.getPixels().getColor(i,j);
                float brightness = color.getBrightness();
                int hue = color.getHue();
                //float radius = ofMap(brightness, 0, 255, 0, grid/2);
                float isize = ofMap(brightness, 0, 255, 16, 96);
                //ofSetColor(color);
                //ofDrawCircle(round(i*1.5),round(j*1.5), round(radius*1.5));
                particle newParticle( round(i*3), round(j*3), color, isize);
                particles.push_back(newParticle);
            }
        }
    }
    for(vector<particle>::iterator it = particles.begin(); it != particles.end();++it)
    {
        (*it).draw();
        if( (*it).dead)
        {
            it = particles.erase(it);
        }
    }

    //webcam.draw(0,0, 1920, 1080);
}
