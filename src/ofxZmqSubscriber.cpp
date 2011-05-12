#include "ofxZmqSubscriber.h"

ofxZmqSubscriber::ofxZmqSubscriber() : subscriber(ofxZmqContext(), ZMQ_SUB)
{
	zmq::pollitem_t item;
	item.socket = subscriber;
	item.fd = 0;
	item.events = ZMQ_POLLIN;
	item.revents = 0;
	items[0] = item;
	
	connectAddress.clear();
	setFilter("");
}

void ofxZmqSubscriber::addConnectAddress(string addr)
{
	if (find(connectAddress.begin(), connectAddress.end(), addr) != connectAddress.end())
	{
		ofLog(OF_LOG_WARNING, "%s is already binded.", addr.c_str());
		return;
	}
	
	connectAddress.push_back(addr);
	
	subscriber.connect(addr.c_str());
}

vector<string> ofxZmqSubscriber::listConnectAddress()
{
	return connectAddress;
}

void ofxZmqSubscriber::dumpConnectAddress()
{
	cout << "===" << endl;
	for (int i = 0; i < connectAddress.size(); i++)
	{
		cout << connectAddress[i] << endl;
	}
	cout << "===" << endl;
}

void ofxZmqSubscriber::setFilter(string f)
{
	filter = f;
	subscriber.setsockopt(ZMQ_SUBSCRIBE, filter.data(), filter.size());
}

bool ofxZmqSubscriber::hasWaitingData()
{
	return zmq::poll(items, 1, 0) > 0;
}

bool ofxZmqSubscriber::getNextMessage(vector<uint8_t> &container)
{
	if ((items[0].revents & ZMQ_POLLIN) == false) return false;

	int64_t more;
	size_t more_size = sizeof(more);

	do
	{
		zmq::message_t m;
		subscriber.recv(&m);
		
		subscriber.getsockopt(ZMQ_RCVMORE, &more, &more_size);
		
		const int numBytes = m.size();
		const uint8_t *src = (uint8_t*)m.data();
		
		container.clear();
		container.insert(container.end(), src, src + numBytes);
	}
	while (more);
	
	return true;
}
