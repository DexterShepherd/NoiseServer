//
//  wave.cpp
//  noiseServerV3_2
//
//  Created by Dexter Shepherd on 5/5/15.
//
//

#include "wave.h"

wave::wave(float _x, float _y, float _width, float _inc, int _numPoints){
    x = _x;
    y = _y;
    width = _width;
    value = 0.0;
    theta = ofRandom(0, 10);
    inc = _inc;
    history.assign(ofGetHeight(), 1);
    
    counter = 0;
}

void wave::update(){
    value = ofNoise(theta)*width;
    theta+=inc;
    history[0] = value;
    for(int i = ofGetHeight(); i > 0; i--){
        history[i] = history[i-1];
    }
}

void wave::draw(){
    ofPushMatrix();
    ofTranslate(x, y);
    
    for(int i = 0; i < ofGetHeight(); i++){
        ofSetColor(255);
        ofRect(history[i], i, 1, 5);
    }
    for(int i = 0; i < 10; i++){
        ofSetColor(ofMap(history[i*(ofGetHeight()/10)], 0, width, 0, 255), 100);
        ofRect(0, i*(ofGetHeight()/10), width, ofGetHeight()/10);
    }
    
    ofPopMatrix();
}