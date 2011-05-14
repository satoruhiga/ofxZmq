#pragma once

#include "ofMain.h"
#include "ofxZmq.h"

class ofxZmqPublisher : public ofxZmqSocket
{
public:
	
	ofxZmqPublisher();
	
	void bind(string addr);
	bool send(const vector<uint8_t> &data, bool more = false);
	
};
