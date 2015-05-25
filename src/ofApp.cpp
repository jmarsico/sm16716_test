#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	    //create the socket and bind to port 11999
	ofSetLogLevel(OF_LOG_VERBOSE);

	udpConnection.Create();
	udpConnection.Bind(11999);
	udpConnection.SetNonBlocking(true);

	//load config file
	    //load config.xml
    if(!config.loadFile(ofToDataPath("config.xml")))
    {
        ofLog() << "Failed to load config.xml";
    }

	int numPix = config.getValue("NUMLIGHTS", 20);
	ofLog() << "number of pixels to run: " << numPix;

	if(sm16716.init(numPix))
	{
		ofLog() << "main: init of sm16716 successful";
	} 
    
    blankCounter = 0;

    r = g = b = 0;

    colorState = 0;


}

//--------------------------------------------------------------
void ofApp::update(){
	

	
	if(colorState == 0)
	{
		r ++;
		g = 0;
		b = 0;
		if(r >= 255)
		{
			colorState = 1;
			r = 0;
		}
	}

	if(colorState == 1)
	{
		g ++;
		r = 0;
		b = 0;
		if(g >= 255)
		{
			colorState = 2;
			g = 0;
		}	
	}

	if(colorState == 2)
	{
		b++;
		r = 0;
		g = 0;
		if(b>= 255)
		{
			colorState = 3;
			b = 0;
		}
	}

	if(colorState = 3)
	{
		r++;
		g++;
		b++;

		if(b >= 255)
		{
			colorState = 0;
			r = 0;
			g = 0;
			b = 0;
		}
	}

	for(int i = 0; i < 420; i++)
	{
		sm16716.set_pixel_rgb(i, r, g, b );
	}

	ofLog() << "r: " << r << " g: " << g << " b: " << b;

	//once all of the pixels are set, send them out!
	sm16716.show();


	ofLogVerbose() << ofGetFrameRate();
	
}
		

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

