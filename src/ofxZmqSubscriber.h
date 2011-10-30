#pragma once

#include "ofMain.h"
#include "ofxZmq.h"

class ofxZmqSubscriber : public ofxZmqSocket
{
public:
	
	ofxZmqSubscriber();
	
	void connect(string addr);
	void setFilter(string filter);

	void receive(string &data);
	
	bool hasWaitingMessage(long timeout_millis = 0);
	bool getNextMessage(string &data);

private:
	
	string filter;
	
};
