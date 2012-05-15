#include "ofxZmqSubscriber.h"

ofxZmqSubscriber::ofxZmqSubscriber() : ofxZmqSocket(ZMQ_SUB)
{
}

void ofxZmqSubscriber::connect(string addr)
{
	setFilter(filter);
	ofxZmqSocket::connect(addr);
}

void ofxZmqSubscriber::receive(string &data)
{
	ofxZmqSocket::receive(data);
}

void ofxZmqSubscriber::receive(ofBuffer &data)
{
	ofxZmqSocket::receive(data);
}

bool ofxZmqSubscriber::hasWaitingMessage(long timeout_millis)
{
	return ofxZmqSocket::hasWaitingMessage(timeout_millis);
}

bool ofxZmqSubscriber::getNextMessage(string &data)
{
	return ofxZmqSocket::getNextMessage(data);
}

bool ofxZmqSubscriber::getNextMessage(ofBuffer &data)
{
	return ofxZmqSocket::getNextMessage(data);
}

void ofxZmqSubscriber::setFilter(string f)
{
	filter = f;
	socket.setsockopt(ZMQ_SUBSCRIBE, filter.data(), filter.size());
}
