#pragma once

#include "ofMain.h"
#include "wave.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
        void updateWave();
    void drawWave();
    int numClients;
    wave** waves;
};
