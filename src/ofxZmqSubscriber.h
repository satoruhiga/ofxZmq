#pragma once

#include "ofMain.h"
#include "ofxZmq.h"

class ofxZmqSubscriber
{
public:
	
	ofxZmqSubscriber();
	
	void addConnectAddress(string addr);
	vector<string> listConnectAddress();
	void dumpConnectAddress();
	
	void setFilter(string filter);
	
	bool hasWaitingData();
	bool getNextMessage(vector<uint8_t> &container);
	
protected:
	
	zmq::socket_t subscriber;
	zmq::pollitem_t items[1];
	
private:
	
	vector<string> connectAddress;
	string filter;
	
};
