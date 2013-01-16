#include "ofxZmqReply.h"

ofxZmqReply::ofxZmqReply() : ofxZmqSocket(ZMQ_REP)
{
}

void ofxZmqReply::bind(string addr)
{
	ofxZmqSocket::bind(addr);
}

bool ofxZmqReply::send(const void *data, size_t len, bool nonblocking, bool more)
{
	return ofxZmqSocket::send(data, len, nonblocking, more);
}

bool ofxZmqReply::send(void *data, size_t len, bool nonblocking, bool more)
{
	return ofxZmqSocket::send(data, len, nonblocking, more);
}

bool ofxZmqReply::send(const string &data, bool nonblocking, bool more)
{
	return ofxZmqSocket::send((const void*)data.data(), data.size(), nonblocking, more);
}

bool ofxZmqReply::send(const ofBuffer &data, bool nonblocking, bool more)
{
	return ofxZmqSocket::send(data, nonblocking, more);
}

bool ofxZmqReply::receive(string &data)
{
	return ofxZmqSocket::receive(data);
}

bool ofxZmqReply::receive(ofBuffer &data)
{
	return ofxZmqSocket::receive(data);
}

bool ofxZmqReply::hasWaitingMessage(long timeout_millis)
{
	return ofxZmqSocket::hasWaitingMessage(timeout_millis);
}

bool ofxZmqReply::getNextMessage(string &data)
{
	return ofxZmqSocket::getNextMessage(data);
}

bool ofxZmqReply::getNextMessage(ofBuffer &data)
{
	return ofxZmqSocket::getNextMessage(data);
}
