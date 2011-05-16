#pragma once

#include "ofMain.h"

#include "zmq.hpp"

class ofxZmqSocket
{
	
	void setIdentity(string data);
	
protected:
	
	zmq::socket_t socket;
	zmq::pollitem_t items[1];

	ofxZmqSocket(int type);
	
	void connect(string addr);
	void bind(string addr);

	bool send(const void *data, size_t len, bool nonblocking, bool more);
	bool send(void *data, size_t len, bool nonblocking, bool more);
	void receive(vector<uint8_t> &data);

	bool hasWaitingMessage();
	bool getNextMessage(vector<uint8_t> &data);
	
};
