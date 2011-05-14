#include "ofxZmqRequest.h"

ofxZmqRequest::ofxZmqRequest() : ofxZmqSocket(ZMQ_REQ)
{
}

void ofxZmqRequest::connect(string addr)
{
	ofxZmqSocket::connect(addr);
}

void ofxZmqRequest::send(void *data, size_t len, bool more)
{
	ofxZmqSocket::send(data, len, more);
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
	return ofxZmqSocket::getNextMessage(data);
}
