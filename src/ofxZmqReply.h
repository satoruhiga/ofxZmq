#pragma once

#include "ofMain.h"
#include "ofxZmq.h"

class ofxZmqReply : public ofxZmqSocket
{
public:
	
	ofxZmqReply();
	
	void bind(string addr);
	
	void send(const void *data, size_t len, bool nonblocking = false, bool more = false);
	void send(void *data, size_t len, bool nonblocking = false, bool more = false);
	bool send(const string &data, bool nonblocking = false, bool more = false);
	void receive(string &data);
	
	bool hasWaitingMessage(long timeout_millis = 0);
	bool getNextMessage(string &data);
	
};
