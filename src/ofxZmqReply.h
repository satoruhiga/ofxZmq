#pragma once

#include "ofMain.h"
#include "ofxZmq.h"

class ofxZmqReply : public ofxZmqSocket
{
public:
	
	ofxZmqReply();
	
	void bind(string addr);
	
	void send(void *data, size_t len, bool more = false);
	void receive(vector<uint8_t> &data);
	
	bool hasWaitingMessage();
	bool getNextMessage(vector<uint8_t> &data);
	
};
