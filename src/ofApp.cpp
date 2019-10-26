#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    
    bSendSerialMessage = true;
    ofBackground(255);
    
    font.load("DIN.otf", 24);
    
    serial.listDevices();

    vector <ofSerialDeviceInfo> deviceList = serial.getDeviceList();
    
    long baud = 9600;
    serial.setup(2, baud); //open the first device

	memset(inByte, 0, 2);

    nBytesRead = 0;
    memset(onOff, 0, 8);

	pow.load("sounds/pow.wav");
	angel.load("sounds/angel.wav");
	horses.load("sounds/horses.wav");
	twelfth.load("sounds/twelfth.wav");
	blue.load("sounds/blue.wav"); 
	dilemma.load("sounds/dilemma.wav");
	germinal.load("sounds/germinal.wav");
	iran.load("sounds/iran.wav");
	sitti.load("sounds/sitti.wav");



	pow.setMultiPlay(false);
	angel.setMultiPlay(false);
	horses.setMultiPlay(false);
	twelfth.setMultiPlay(false);
	blue.setMultiPlay(false);
	dilemma.setMultiPlay(false);
	germinal.setMultiPlay(false);
	iran.setMultiPlay(false);
	sitti.setMultiPlay(false);

}

//--------------------------------------------------------------
void ofApp::update(){
    
   
    // (1) write the letter "!" to serial -
    // this will tell the arduino we ready to get data:
    if(bSendSerialMessage){
        serial.writeByte('!');
        bSendSerialMessage = false;
    }
    
    // (2) read
    // we try to read 2 bytes
    
    // clear our variables
    nBytesRead  = 0;
    long nRead	= 0;  // a temp variable to keep count per read
	memset(inByte, 0, 2);
    
  
	while ((nRead = serial.readBytes(inByte, 2)) > 0) {
        nBytesRead = nRead;
    };
    
    //if we have got everything
    if ( nBytesRead == 2){


        // turn our byte back into two int's
	 
		onOff[9] = inByte[1] & 0x01;
		onOff[8] = inByte[1] >> 1;

		onOff[7] = inByte[0] & 0x01;
		onOff[6] = inByte[0] >> 1;
		onOff[5] = inByte[0] >> 2;
		onOff[4] = inByte[0] >> 3;
		onOff[3] = inByte[0] >> 4;
		onOff[2] = inByte[0] >> 5;
        onOff[1] = inByte[0] >> 6;
        onOff[0] = inByte[0] >> 7; 

        
        bSendSerialMessage = true;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){


    if (onOff[0] == 1 && !pow.isPlaying()){
		pow.play();
		//noVolumeChange
		cout << "pow" << endl;
		pow.setPan(-1.0f);
    } 

	if (onOff[1] == 1 && !angel.isPlaying()){
	
		angel.play();
		angel.setVolume(0.2f);
		cout << "angel" << endl;
		angel.setPan(-1.0f);
    }

	if (onOff[2] == 1 && !horses.isPlaying()) {
		horses.play();
		horses.setVolume(0.5f);
		cout << "horses" << endl;
		horses.setPan(-1.0f);
	} 
	

	if (onOff[3] == 1 && !twelfth.isPlaying()) {
		twelfth.play();
		twelfth.setVolume(0.6f);
		cout << "twelfth" << endl;
		twelfth.setPan(-1.0f);
	}

	if (onOff[4] == 1 && !blue.isPlaying()) {
		blue.play();
		blue.setVolume(0.6f);
		cout << "blue" << endl;
		blue.setPan(-1.0f);
	}

	if (onOff[5] == 1 && !dilemma.isPlaying()) {
		dilemma.play();
		dilemma.setVolume(0.6f);
		cout << "dilemma" << endl;
		dilemma.setPan(1.0f);
	}

	if (onOff[6] == 1 && !germinal.isPlaying()) {
		germinal.play();
		germinal.setVolume(0.6f);
		cout << "germinal" << endl;
		germinal.setPan(1.0f);
	}

	if (onOff[7] == 1 && !iran.isPlaying()) {
		iran.play();
		iran.setVolume(0.7f);
		cout << "iran" << endl;
		iran.setPan(1.0f);
	}

	if (onOff[8] == 1 && !sitti.isPlaying()) {
		sitti.play();
		sitti.setVolume(0.8f);
		cout << "sitti" << endl;
		sitti.setPan(1.0f);
	}

	if (onOff[9] == 1){
		angel.stop();
		horses.stop();
		blue.stop();
		twelfth.stop();
		dilemma.stop();
		germinal.stop();
		iran.stop();
		sitti.stop();
		pow.stop();
		cout << "reset" << endl;
		

		for (int i = 0; i < 10; i++) {
			onOff[i] = 0;
		}
		
	}  



}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
