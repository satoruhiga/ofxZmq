#include "ofApp.h"


ofxZmqSubscriber subscriber;
ofxZmqPublisher publisher;

//--------------------------------------------------------------
void ofApp::setup()
{
	// start server
	publisher.bind("tcp://*:9999");
	
	// start client
	subscriber.connect("tcp://localhost:9999");
}

//--------------------------------------------------------------
void ofApp::update()
{
	while (subscriber.hasWaitingMessage())
	{
		ofBuffer data;
		subscriber.getNextMessage(data);
		
		cout << "received data: " << data << endl;
	}
}

//--------------------------------------------------------------
void ofApp::draw()
{
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	if (!publisher.send("this is a test"))
	{
		cout << "send failed" << endl;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{

}
