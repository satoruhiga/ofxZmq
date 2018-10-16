#include "ofApp.h"


ofxZmqPair connection;

//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetLogLevel(OF_LOG_VERBOSE);
	// start server
	connection.bind("tcp://*:9999");
	
	// start client
	connection.connect("tcp://localhost:9999");
}

//--------------------------------------------------------------
void ofApp::update()
{
	while (connection.hasWaitingMessage())
	{
		ofBuffer data;
		connection.getNextMessage(data);
		
        ofLog() << "RECEIVED: " << data;
	}
}

//--------------------------------------------------------------
void ofApp::draw()
{
    
    if(connection.isConnected())
    {
        if(ofGetFrameNum() % 100 == 0)
        {
            string message  = "Hello";
            if (!connection.send(message))
            {
                ofLogError() << "SEND FAILED message: " << message;
            }else
            {
                ofLog() << "SENT message: " << message;
                
            }
        }
    }else
    {
        ofLog() << "NOT CONNECTED";
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	
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
