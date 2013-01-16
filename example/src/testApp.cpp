#include "testApp.h"

#include "ofxZmq.h"

ofxZmqSubscriber subscriber;
ofxZmqPublisher publisher;

//--------------------------------------------------------------
void testApp::setup()
{
	// start server
	publisher.bind("tcp://*:9999");
	
	// start client
	subscriber.connect("tcp://localhost:9999");
}

//--------------------------------------------------------------
void testApp::update()
{
	while (subscriber.hasWaitingMessage())
	{
		ofBuffer data;
		subscriber.getNextMessage(data);
		
		cout << "received data: " << data << endl;
	}
}

//--------------------------------------------------------------
void testApp::draw()
{
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
	if (!publisher.send("this is a test"))
	{
		cout << "send failed" << endl;
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y)
{

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h)
{

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo)
{

}
