#include "ofxZmqRequest.h"

ofxZmqRequest::ofxZmqRequest() : ofxZmqSocket(ZMQ_REQ)
{
}

void ofxZmqRequest::connect(string addr)
{
	ofxZmqSocket::connect(addr);
}

bool ofxZmqRequest::send(const void *data, size_t len, bool nonblocking, bool more)
{
	return ofxZmqSocket::send(data, len, nonblocking, more);
}

bool ofxZmqRequest::send(void *data, size_t len, bool nonblocking, bool more)
{
	return ofxZmqSocket::send(data, len, nonblocking, more);
}

bool ofxZmqRequest::send(const string &data, bool nonblocking, bool more)
{
	return ofxZmqSocket::send((const void*)data.data(), data.size(), nonblocking, more);
}

bool ofxZmqRequest::send(const ofBuffer &data, bool nonblocking, bool more)
{
	return ofxZmqSocket::send(data, nonblocking, more);
}

void ofxZmqRequest::receive(string &data)
{
	ofxZmqSocket::receive(data);
}

void ofxZmqRequest::receive(ofBuffer &data)
{
	ofxZmqSocket::receive(data);
}

bool ofxZmqRequest::hasWaitingMessage(long timeout_millis)
{
	return ofxZmqSocket::hasWaitingMessage(timeout_millis);
}

bool ofxZmqRequest::getNextMessage(string &data)
{
	return ofxZmqSocket::getNextMessage(data);
}

bool ofxZmqRequest::getNextMessage(ofBuffer &data)
{
	return ofxZmqSocket::getNextMessage(data);
}
