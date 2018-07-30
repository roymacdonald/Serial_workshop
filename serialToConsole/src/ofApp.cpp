#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	
	
//	ofSetLogLevel(OF_LOG_VERBOSE);
		
	serial.listDevices();
	vector <ofSerialDeviceInfo> deviceList = serial.getDeviceList();
	
	// this should be set to whatever com port your serial device is connected to.
	// (ie, COM4 on a pc, /dev/tty.... on linux, /dev/tty... on a mac)
	// arduino users check in arduino app....
	int baud = 9600;
	serialOk = serial.setup(0, baud); //open the first device
	//serial.setup("COM4", baud); // windows example
	//serial.setup("/dev/tty.usbserial-A4001JEC", baud); // mac osx example
	//serial.setup("/dev/ttyUSB0", baud); //linux example
	
	//USE THE AnalogToSerialRaw arduino code for this example.
	
}

//--------------------------------------------------------------
void ofApp::update(){
	
	if(serialOk){
		while (serial.available() > 0) {
			int i1 = serial.readByte();
			if(i1 != OF_SERIAL_NO_DATA && i1 != OF_SERIAL_ERROR) {
//				cout << i1 << endl;
				if(i1 != '\n'){
					inputString += (unsigned char)i1;
				}else{
//					cout<< inputString << endl;
					vector<string> numbers = ofSplitString(inputString, ",");
					ints.resize(numbers.size());
					for(int i =0; i < numbers.size(); i++){
						ints[i] = ofToInt(numbers[i]);
					}
					cout << ofToString(ints) << endl;

					
					inputString = "";
				}
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	ofSetColor(0);
	if(ints.size()){
	float w = ofGetWidth() / ints.size();
	for(int i = 0; i < ints.size(); i++){
		ofDrawRectangle(i*w, 0,w, ofMap(ints[i], 0, 1023, 0, ofGetHeight()));
	}
	}
}
