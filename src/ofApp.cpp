#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
   // ofSetBackgroundAuto(false);
    ofBackground(0);
    numClients = 10;
    waves = new wave*[numClients];
    for(int i = 0; i < numClients; i++){
       waves[i] = new wave((i * ofGetWidth()/numClients), 0, ofGetWidth()/numClients, 0.08, 100);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    updateWave();
}

//--------------------------------------------------------------
void ofApp::draw(){
    drawWave();
}

void ofApp::updateWave(){
    for(int i = 0; i < numClients; i++){
        waves[i]->update();
    }
}

void ofApp::drawWave(){
    for(int i = 0; i < numClients; i++){
        waves[i]->draw();
    }
}

