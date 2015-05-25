#pragma once

#include "ofMain.h"
#include "wiringPi.h"
#include "wiringPiSPI.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <errno.h>
#include <math.h>
#include "ofMain.h"

#include "ofxNetwork.h"
#include "ofxSM16716.h"
#include "ofxXmlSettings.h"


class ofApp : public ofBaseApp{
public:
	void setup();
	void update();
	void draw();
	
	void keyPressed(int key);
	void keyReleased(int key);

	ofxSM16716 sm16716;

	ofxUDPManager udpConnection;

	int ID;

	int blankCounter;

	ofxXmlSettings config;

	int r, g, b;	

	int colorState;

};
