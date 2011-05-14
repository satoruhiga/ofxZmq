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

void ofxZmqPair::send(void *data, size_t len, bool more)
{
	ofxZmqSocket::send(data, len, more);
}

void ofxZmqPair::receive(vector<uint8_t> &data)
{
	return ofxZmqSocket::receive(data);
}

bool ofxZmqPair::hasWaitingMessage()
{
	return ofxZmqSocket::hasWaitingMessage();
}

bool ofxZmqPair::getNextMessage(vector<uint8_t> &data)
{
	return ofxZmqSocket::getNextMessage(data);
}
