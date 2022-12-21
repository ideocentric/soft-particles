//
//  particle.hpp
//  videorain
//
//  Created by Matt Comeione on 12/11/22.
//

#ifndef particle_hpp
#define particle_hpp

#include "ofMain.h"

class particle{
public:
    ofColor color;
    ofImage dot;
    bool dead;
    float size;
    glm::vec2 force, position, direction;

    void update();
    void draw();
    
    particle(int x, int y, int hue);
    particle(int x, int y, ofColor color, float size);
    ~particle();
};

#endif /* particle_hpp */
