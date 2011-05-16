#pragma once

#include "ofMain.h"
#include "ofxZmq.h"

class ofxZmqSubscriber : public ofxZmqSocket
{
public:
	
	ofxZmqSubscriber();
	
	void connect(string addr);
	void setFilter(string filter);

	void receive(vector<uint8_t> &data);
	
	bool hasWaitingMessage(long timeout_millis = 0);
	bool getNextMessage(vector<uint8_t> &data);

private:
	
	string filter;
	
};
