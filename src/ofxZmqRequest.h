#pragma once

#include "ofMain.h"
#include "ofxZmq.h"

class ofxZmqRequest : public ofxZmqSocket
{
public:
	
	ofxZmqRequest();
	
	void connect(string addr);
	
	void send(const void *data, size_t len, bool nonblocking = false, bool more = false);
	void send(void *data, size_t len, bool nonblocking = false, bool more = false);
	void receive(vector<uint8_t> &data);
	
	bool hasWaitingMessage(long timeout = 0);
	bool getNextMessage(vector<uint8_t> &data);
	
};
