//
//  camrain.hpp
//  videorain
//
//  Created by Matt Comeione on 12/11/22.
//

#ifndef camrain_hpp
#define camrain_hpp


#include "ofMain.h"
#include "particle.hpp"

class camrain{
public:
    void setup();
    void update();
    void draw();
    ofVideoGrabber webcam;
    vector<particle> particles;
    int camwidth;
    int camheight;
};


#endif /* camrain_hpp */
