#include "ofxZmqSubscriber.h"

ofxZmqSubscriber::ofxZmqSubscriber() : ofxZmqSocket(ZMQ_SUB)
{
}

void ofxZmqSubscriber::connect(string addr)
{
	ofxZmqSocket::connect(addr);
}

void ofxZmqSubscriber::receive(vector<uint8_t> &data)
{
	ofxZmqSocket::receive(data);
}

bool ofxZmqSubscriber::hasWaitingMessage()
{
	return ofxZmqSocket::hasWaitingMessage();
}

bool ofxZmqSubscriber::getNextMessage(vector<uint8_t> &data)
{
	return ofxZmqSocket::getNextMessage(data);
}

void ofxZmqSubscriber::setFilter(string f)
{
	filter = f;
	socket.setsockopt(ZMQ_SUBSCRIBE, filter.data(), filter.size());
}
