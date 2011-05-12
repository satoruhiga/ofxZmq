#pragma once

#define OFXZMQ_NUM_THREAD 1

#include "zmq.hpp"

#include "ofxZmqSubscriber.h"
#include "ofxZmqPublisher.h"

zmq::context_t& ofxZmqContext();
