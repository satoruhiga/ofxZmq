#pragma once

#include "ofMain.h"

#include "zmq.hpp"

class ofxZmqSocket
{

public:

	virtual ~ofxZmqSocket();

	void setIdentity(string data);
	string getIdentity();

	void setHighWaterMark(long maxQueueSize);
	long getHighWaterMark();

protected:

	zmq::socket_t socket;
	zmq::pollitem_t items[1];

	ofxZmqSocket(int type);

	void connect(string addr);
	void bind(string addr);

	bool send(const void *data, size_t len, bool nonblocking, bool more);
	bool send(void *data, size_t len, bool nonblocking, bool more);
	bool send(const string &data, bool nonblocking, bool more);
	void receive(string &data);

	bool hasWaitingMessage(long timeout_millis = 0);
	bool getNextMessage(string &data);

};