#include "ofxZmqRequest.h"

ofxZmqRequest::ofxZmqRequest() : ofxZmqSocket(ZMQ_REQ)
{
}

void ofxZmqRequest::connect(string addr)
{
	ofxZmqSocket::connect(addr);
}

void ofxZmqRequest::send(const vector<uint8_t> &data, bool more)
{
	ofxZmqSocket::send(data, more);
}

void ofxZmqRequest::receive(vector<uint8_t> &data)
{
	ofxZmqSocket::receive(data);
}

bool ofxZmqRequest::hasWaitingMessage()
{
	return ofxZmqSocket::hasWaitingMessage();
}

bool ofxZmqRequest::getNextMessage(vector<uint8_t> &data)
{
	return getNextMessage(data);
}
