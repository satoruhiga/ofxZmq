#pragma once

#include "ofMain.h"
#include "ofxZmq.h"

class ofxZmqPublisher : public ofxZmqSocket
{
public:
	
	ofxZmqPublisher();
	
	void bind(string addr);
	
	bool send(const void *data, size_t len, bool nonblocking = false, bool more = false);
	bool send(void *data, size_t len, bool nonblocking = false, bool more = false);
	
};
