#pragma once

#include "ofMain.h"
#include "ofxZmq.h"

class ofxZmqRequest : public ofxZmqSocket
{
public:
	
	ofxZmqRequest();
	
	void connect(string addr);
	
	void send(const vector<uint8_t> &data, bool more = false);
	void receive(vector<uint8_t> &data);
	
	bool hasWaitingMessage();
	bool getNextMessage(vector<uint8_t> &data);
	
};
