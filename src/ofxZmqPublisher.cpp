#include "ofxZmqPublisher.h"

ofxZmqPublisher::ofxZmqPublisher() : ofxZmqSocket(ZMQ_PUB)
{
}

void ofxZmqPublisher::bind(string addr)
{
	ofxZmqSocket::bind(addr);
}

void ofxZmqPublisher::connect(string addr)
{
	ofxZmqSocket::connect(addr);
}

bool ofxZmqPublisher::send(const void *data, size_t len, bool nonblocking, bool more)
{
	return ofxZmqSocket::send(data, len, nonblocking, more);
}

bool ofxZmqPublisher::send(void *data, size_t len, bool nonblocking, bool more)
{
	return ofxZmqSocket::send(data, len, nonblocking, more);
}

bool ofxZmqPublisher::send(const string& data, bool nonblocking, bool more)
{
	return ofxZmqSocket::send((const void*)data.data(), data.size(), nonblocking, more);
}

bool ofxZmqPublisher::send(const ofBuffer& data, bool nonblocking, bool more)
{
	return ofxZmqSocket::send(data, nonblocking, more);
}
