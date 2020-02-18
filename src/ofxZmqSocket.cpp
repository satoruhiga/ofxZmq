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
	item.socket = (void*)socket;
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

void ofxZmqSocket::disconnect(string addr)
{
	socket.disconnect(addr.c_str());
}

void ofxZmqSocket::unbind(string addr)
{
	socket.unbind(addr.c_str());
}

string ofxZmqSocket::getLastEndpoint() {
    char port[1024];
    size_t size = sizeof(port);
    socket.getsockopt(ZMQ_LAST_ENDPOINT, &port, &size);
    return std::string( port );
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


bool ofxZmqSocket::isConnected()
{
	return this->socket.connected();
}

void ofxZmqSocket::setHighWaterMark(long maxQueueSize)
{
	setReceiveHighWaterMark(maxQueueSize);
	setSendHighWaterMark(maxQueueSize);
}

void ofxZmqSocket::setSendHighWaterMark(long maxQueueSize)
{
	int32_t v = maxQueueSize;
	size_t size = sizeof(v);
	socket.setsockopt(ZMQ_SNDHWM, &v, size);
}

void ofxZmqSocket::setReceiveHighWaterMark(long maxQueueSize)
{
	int32_t v = maxQueueSize;
	size_t size = sizeof(v);
	socket.setsockopt(ZMQ_RCVHWM, &v, size);
}

long ofxZmqSocket::getHighWaterMark()
{
	return getSendHighWaterMark();
}

long ofxZmqSocket::getSendHighWaterMark()
{
	int32_t v;
	size_t size = sizeof(v);
	socket.getsockopt(ZMQ_SNDHWM, &v, &size);
	return v;
}

long ofxZmqSocket::getReceiveHighWaterMark()
{
	int32_t v;
	size_t size = sizeof(v);
	socket.getsockopt(ZMQ_RCVHWM, &v, &size);
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

