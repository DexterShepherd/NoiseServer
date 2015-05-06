//
//  wave.h
//  noiseServerV3_2
//
//  Created by Dexter Shepherd on 5/5/15.
//
//

#ifndef __noiseServerV3_2__wave__
#define __noiseServerV3_2__wave__

#include <stdio.h>
#include "ofMain.h"

class wave{
public:
    wave(float _x, float _y, float _width, float _inc, int _numPoints);
    void update();
    void draw();
    float getNoise(){return value/width;};
private:
    float x;
    float xOff;
    float y;
    float yOff;
    float width;
    float value;
    float theta;
    float inc;
    int numPoints;
    vector<float> history;
    int counter;
};
#endif /* defined(__noiseServerV3_2__wave__) */
