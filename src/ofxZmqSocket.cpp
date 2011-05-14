#include "ofxZmqSocket.h"

#include "ofxZmqConfig.h"

static zmq::context_t& ofxZmqContext()
{
	static zmq::context_t zmq_context(OFXZMQ_NUM_THREAD);
	return zmq_context;
}

ofxZmqSocket::ofxZmqSocket(int type) : socket(ofxZmqContext(), type)
{
	zmq::pollitem_t item;
	item.socket = socket;
	item.fd = 0;
	item.events = ZMQ_POLLIN;
	item.revents = 0;
	items[0] = item;
}

void ofxZmqSocket::connect(string addr)
{
	socket.connect(addr.c_str());
}

void ofxZmqSocket::bind(string addr)
{
	socket.bind(addr.c_str());
}

bool ofxZmqSocket::send(const vector<uint8_t> &data, bool more)
{
	zmq::message_t m(data.size());
	memcpy(m.data(), data.data(), data.size());
	return socket.send(m, more ? ZMQ_SNDMORE : 0) == 0;
}

void ofxZmqSocket::receive(vector<uint8_t> &data)
{
	int64_t more;
	size_t more_size = sizeof(more);
	
	data.clear();
	
	do
	{
		zmq::message_t m;
		socket.recv(&m);
		
		socket.getsockopt(ZMQ_RCVMORE, &more, &more_size);
		
		const int numBytes = m.size();
		const uint8_t *src = (uint8_t*)m.data();
		
		data.insert(data.end(), src, src + numBytes);
	}
	while (more);
}

void ofxZmqSocket::setIdentity(string data)
{
	socket.setsockopt(ZMQ_IDENTITY, data.data(), data.size());
}

bool ofxZmqSocket::hasWaitingMessage()
{
	return zmq::poll(items, 1, 0) > 0;
}

bool ofxZmqSocket::getNextMessage(vector<uint8_t> &data)
{
	if ((items[0].revents & ZMQ_POLLIN) == false) return false;
	
	receive(data);
	
	return true;
}
