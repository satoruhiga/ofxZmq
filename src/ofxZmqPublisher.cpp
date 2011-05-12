#include "ofxZmqPublisher.h"

ofxZmqPublisher::ofxZmqPublisher() : publisher(ofxZmqContext(), ZMQ_PUB)
{
	bindAddress.clear();
}

void ofxZmqPublisher::addBindAddress(string addr)
{
	if (find(bindAddress.begin(), bindAddress.end(), addr) != bindAddress.end())
	{
		ofLog(OF_LOG_WARNING, "%s is already binded.", addr.c_str());
		return;
	}
	
	bindAddress.push_back(addr);
	
	publisher.bind(addr.c_str());
}

vector<string> ofxZmqPublisher::listBindAddress()
{
	return bindAddress;
}

void ofxZmqPublisher::dumpBindAddress()
{
	cout << "===" << endl;
	for (int i = 0; i < bindAddress.size(); i++)
	{
		cout << bindAddress[i] << endl;
	}
	cout << "===" << endl;
}

bool ofxZmqPublisher::send(uint8_t *data, size_t len, bool more)
{
	zmq::message_t m(len);
	memcpy(m.data(), data, len);
	return publisher.send(m, more ? ZMQ_SNDMORE : 0) == 0;
}