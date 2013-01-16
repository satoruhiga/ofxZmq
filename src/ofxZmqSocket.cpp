#include "ofxZmqSocket.h"

#include "ofxZmqConfig.h"

static zmq::context_t *ctx = NULL;

static zmq::context_t& ofxZmqContext()
{
	if (ctx == NULL)
	{
		ctx = new zmq::context_t(OFXZMQ_NUM_THREAD);
	}
	return *ctx;
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

ofxZmqSocket::~ofxZmqSocket()
{
}

void ofxZmqSocket::connect(string addr)
{
	socket.connect(addr.c_str());
}

void ofxZmqSocket::bind(string addr)
{
	socket.bind(addr.c_str());
}

bool ofxZmqSocket::send(const void *data, size_t len, bool nonblocking, bool more)
{
	zmq::message_t m(len);
	memcpy(m.data(), data, len);

	int flags = 0;
	
	if (more) flags |= ZMQ_SNDMORE;
	if (nonblocking) flags |= ZMQ_DONTWAIT;
	
	try
	{
		return socket.send(m, flags);
	}
	catch (zmq::error_t &e)
	{
		ofLog(OF_LOG_ERROR, "ofxZmqSocket::send: %s", e.what());
		return false;
	}
}

bool ofxZmqSocket::send(void *data, size_t len, bool nonblocking, bool more)
{
	return ofxZmqSocket::send((const void*)data, len, nonblocking, more);
}

bool ofxZmqSocket::send(const string &data, bool nonblocking, bool more)
{
	return ofxZmqSocket::send((const void*)data.data(), data.size(), nonblocking, more);
}

bool ofxZmqSocket::send(const ofBuffer &data, bool nonblocking, bool more)
{
	return ofxZmqSocket::send((const void*)data.getBinaryBuffer(), data.size(), nonblocking, more);
}


bool ofxZmqSocket::receive(string &data)
{
	int32_t more;
	size_t more_size = sizeof(more);
	
	data.clear();
	
	zmq::message_t m;
	socket.recv(&m);
	
	socket.getsockopt(ZMQ_RCVMORE, &more, &more_size);
	
	const int numBytes = m.size();
	const uint8_t *src = (uint8_t*)m.data();
	
	data.insert(data.end(), src, src + numBytes);

	return more;
}

bool ofxZmqSocket::receive(ofBuffer &data)
{
	int32_t more = 0;
	size_t more_size = sizeof(more);
	
	data.clear();
	
	stringstream ss;
	
	zmq::message_t m;
	socket.recv(&m);
	
	socket.getsockopt(ZMQ_RCVMORE, &more, &more_size);
	
	const int numBytes = m.size();
	const char *src = (const char*)m.data();
	
	ss.write(src, numBytes);
	
	data.set(ss);
	
	return more;
}


void ofxZmqSocket::setIdentity(string data)
{
	socket.setsockopt(ZMQ_IDENTITY, data.data(), data.size());
}

string ofxZmqSocket::getIdentity()
{
	char buf[255];
	size_t size = 0;
	socket.getsockopt(ZMQ_IDENTITY, buf, &size);
	return string(buf, buf + size);
}

void ofxZmqSocket::setHighWaterMark(long maxQueueSize)
{
	int32_t v = maxQueueSize;
	size_t size = sizeof(v);
	socket.setsockopt(ZMQ_SNDHWM, &v, size);
	socket.setsockopt(ZMQ_RCVHWM, &v, size);
}

long ofxZmqSocket::getHighWaterMark()
{
	int32_t v;
	size_t size = sizeof(v);
	socket.getsockopt(ZMQ_SNDHWM, &v, &size);
	return v;
}

bool ofxZmqSocket::hasWaitingMessage(long timeout_millis)
{
	return zmq::poll(items, 1, timeout_millis * 1000) > 0;
}

bool ofxZmqSocket::getNextMessage(string &data)
{
	if ((items[0].revents & ZMQ_POLLIN) == false) return false;
	return receive(data);
}

bool ofxZmqSocket::getNextMessage(ofBuffer &data)
{
	if ((items[0].revents & ZMQ_POLLIN) == false) return false;
	return receive(data);
}

