#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetFrameRate(24);
    OscOut.setup("localhost", 8888);
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
    sendNoise();
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

void ofApp::sendNoise(){
    ofxOscMessage m;
    m.setAddress("/ripplesRaw");
    m.addIntArg(numClients);
    for(int i = 0; i < numClients; i++){
        m.addFloatArg(waves[i]->getNoise());
    }
    OscOut.sendMessage(m);
}
