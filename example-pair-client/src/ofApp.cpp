#include "ofApp.h"


ofxZmqPair client;

//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetLogLevel(OF_LOG_VERBOSE);
	// start server
	client.bind("tcp://*:9999");
	
	// start client
	client.connect("tcp://rpi3.local:9999");
}

//--------------------------------------------------------------
void ofApp::update()
{
	while (client.hasWaitingMessage())
	{
		ofBuffer data;
		client.getNextMessage(data);
		
        ofLog() << "client RECEIVED: " << data;
	}
}

//--------------------------------------------------------------
void ofApp::draw()
{
    
    if(client.isConnected())
    {
        if(ofGetFrameNum() % 100 == 0)
        {
            string message  = "Hello From client: " + ofToString(ofGetFrameNum());
            if (!client.send(message))
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
