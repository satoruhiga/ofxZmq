#include "ofxZmqPublisher.h"

ofxZmqPublisher::ofxZmqPublisher() : ofxZmqSocket(ZMQ_PUB)
{
}

void ofxZmqPublisher::bind(string addr)
{
	ofxZmqSocket::bind(addr);
}

bool ofxZmqPublisher::send(const vector<uint8_t> &data, bool more)
{
	ofxZmqSocket::send(data, more);
}
