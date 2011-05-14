#include "ofxZmqPair.h"

ofxZmqPair::ofxZmqPair() : ofxZmqSocket(ZMQ_PAIR)
{
}

void ofxZmqPair::connect(string addr)
{
	ofxZmqPair::connect(addr);
}

void ofxZmqPair::bind(string addr)
{
	ofxZmqPair::bind(addr);
}

void ofxZmqPair::send(const vector<uint8_t> &data, bool more)
{
	ofxZmqPair::send(data, more);
}

void ofxZmqPair::receive(vector<uint8_t> &data)
{
	return ofxZmqPair::receive(data);
}

bool ofxZmqPair::hasWaitingMessage()
{
	return ofxZmqPair::hasWaitingMessage();
}

bool ofxZmqPair::getNextMessage(vector<uint8_t> &data)
{
	return ofxZmqPair::getNextMessage(data);
}
