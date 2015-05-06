#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "wave.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
        void updateWave();
    void sendNoise();
    void drawWave();
    int numClients;
    wave** waves;
    ofxOscSender OscOut;
};
