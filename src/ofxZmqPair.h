#pragma once

#include "ofMain.h"
#include "ofxZmq.h"

class ofxZmqPair : public ofxZmqSocket
{
public:
	
	ofxZmqPair();
	
	void connect(string addr);
	void bind(string addr);

	void send(const vector<uint8_t> &data, bool more = false);
	void receive(vector<uint8_t> &data);
	
	bool hasWaitingMessage();
	bool getNextMessage(vector<uint8_t> &data);
	
};
