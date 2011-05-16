#include "ofxZmqPublisher.h"

ofxZmqPublisher::ofxZmqPublisher() : ofxZmqSocket(ZMQ_PUB)
{
}

void ofxZmqPublisher::bind(string addr)
{
	ofxZmqSocket::bind(addr);
}

bool ofxZmqPublisher::send(const void *data, size_t len, bool more)
{
	ofxZmqSocket::send(data, len, more);
}

bool ofxZmqPublisher::send(void *data, size_t len, bool more)
{
	ofxZmqSocket::send(data, len, more);
}
