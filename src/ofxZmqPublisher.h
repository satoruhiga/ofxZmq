#pragma once

#include "ofMain.h"
#include "ofxZmq.h"

class ofxZmqPublisher
{
public:
	
	ofxZmqPublisher();
	
	void addBindAddress(string addr);
	vector<string> listBindAddress();
	void dumpBindAddress();
	
	bool send(uint8_t *data, size_t len, bool more = false);
	
	template<class T>
	bool send(vector<T> data, bool more = false)
	{
		return send((uint8_t*)&data[0], vector<T>::size_type * data.size(), more);
	}
	
protected:
	
	zmq::socket_t publisher;
	
private:
	
	vector<string> bindAddress;
	
};
