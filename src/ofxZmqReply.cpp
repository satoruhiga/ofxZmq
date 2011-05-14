#include "ofxZmqReply.h"

ofxZmqReply::ofxZmqReply() : ofxZmqSocket(ZMQ_REP)
{
}

void ofxZmqReply::bind(string addr)
{
	ofxZmqSocket::bind(addr);
}

void ofxZmqReply::send(const vector<uint8_t> &data, bool more)
{
	ofxZmqSocket::send(data, more);
}

void ofxZmqReply::receive(vector<uint8_t> &data)
{
	ofxZmqSocket::receive(data);
}

bool ofxZmqReply::hasWaitingMessage()
{
	return ofxZmqSocket::hasWaitingMessage();
}

bool ofxZmqReply::getNextMessage(vector<uint8_t> &data)
{
	return getNextMessage(data);
}
