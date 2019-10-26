#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofTrueTypeFont		font;
    
    bool                bSendSerialMessage;			// a flag for sending serial
    unsigned char		inByte[2];				// data from serial, we will be trying to read 2
    long                 nBytesRead;					// how much did we read?
	long                 onOff[10];
    
    ofSerial            serial;

	ofSoundPlayer angel;
	ofSoundPlayer horses;
	ofSoundPlayer twelfth;
	ofSoundPlayer blue;
	ofSoundPlayer dilemma;
	ofSoundPlayer germinal;
	ofSoundPlayer iran;
	ofSoundPlayer sitti; 
	ofSoundPlayer pow;
	
};
