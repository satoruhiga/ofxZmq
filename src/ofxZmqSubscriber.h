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
	void receive(ofBuffer &data);
	
	bool hasWaitingMessage(long timeout_millis = 0);
	bool getNextMessage(string &data);
	bool getNextMessage(ofBuffer &data);

private:
	
	string filter;
	
};
