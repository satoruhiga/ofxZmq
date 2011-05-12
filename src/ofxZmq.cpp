#include "ofxZmq.h"

static zmq::context_t *zmq_context = NULL;

zmq::context_t& ofxZmqContext()
{
	if (zmq_context == NULL)
	{
		zmq_context = new zmq::context_t(OFXZMQ_NUM_THREAD);
	}
	
	return *zmq_context;
}