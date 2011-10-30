#include "ofxZmqReply.h"

ofxZmqReply::ofxZmqReply() : ofxZmqSocket(ZMQ_REP)
{
}

void ofxZmqReply::bind(string addr)
{
	ofxZmqSocket::bind(addr);
}

void ofxZmqReply::send(const void *data, size_t len, bool nonblocking, bool more)
{
	ofxZmqSocket::send(data, len, nonblocking, more);
}

void ofxZmqReply::send(void *data, size_t len, bool nonblocking, bool more)
{
	ofxZmqSocket::send(data, len, nonblocking, more);
}

bool ofxZmqReply::send(const string &data, bool nonblocking, bool more)
{
	ofxZmqSocket::send((const void*)data.data(), data.size(), nonblocking, more);
}

void ofxZmqReply::receive(string &data)
{
	ofxZmqSocket::receive(data);
}

bool ofxZmqReply::hasWaitingMessage(long timeout_millis)
{
	return ofxZmqSocket::hasWaitingMessage(timeout_millis);
}

bool ofxZmqReply::getNextMessage(string &data)
{
	return ofxZmqSocket::getNextMessage(data);
}
