#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
	void draw();
	ofSerial serial;
	bool serialOk = false;
		
	string inputString;
	vector<int> ints;
};
