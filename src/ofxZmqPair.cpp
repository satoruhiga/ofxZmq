#include "ofxZmqPair.h"

ofxZmqPair::ofxZmqPair() : ofxZmqSocket(ZMQ_PAIR)
{
}

void ofxZmqPair::connect(string addr)
{
	ofxZmqSocket::connect(addr);
}

void ofxZmqPair::bind(string addr)
{
	ofxZmqSocket::bind(addr);
}

bool ofxZmqPair::send(const void *data, size_t len, bool nonblocking, bool more)
{
	return ofxZmqSocket::send(data, len, nonblocking, more);
}

bool ofxZmqPair::send(void *data, size_t len, bool nonblocking, bool more)
{
	return ofxZmqSocket::send(data, len, nonblocking, more);
}

bool ofxZmqPair::send(const string &data, bool nonblocking, bool more)
{
	return ofxZmqSocket::send((const void*)data.data(), data.size(), nonblocking, more);
}

void ofxZmqPair::receive(string &data)
{
	return ofxZmqSocket::receive(data);
}

bool ofxZmqPair::hasWaitingMessage(long timeout_millis)
{
	return ofxZmqSocket::hasWaitingMessage(timeout_millis);
}

bool ofxZmqPair::getNextMessage(string &data)
{
	return ofxZmqSocket::getNextMessage(data);
}
