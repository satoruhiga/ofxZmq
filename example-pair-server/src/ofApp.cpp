#include "ofApp.h"


ofxZmqPair server;

//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetLogLevel(OF_LOG_VERBOSE);
    
	// start server
	server.bind("tcp://*:9999");

}

//--------------------------------------------------------------
void ofApp::update()
{
	while (server.hasWaitingMessage())
	{
		ofBuffer data;
		server.getNextMessage(data);
		
        ofLog() << "SERVER RECEIVED: " << data;
        
        if(server.isConnected())
        {
            string response  = "Hello From Server";
            if (!server.send(response))
            {
                ofLogError() << "SEND FAILED message: " << response;
            }else
            {
                ofLog() << "SENT message: " << response;
                
            }
        }else
        {
            ofLogError() << "SERVER NOT CONNECTED: " << data;

        }
        
	}
}

//--------------------------------------------------------------
void ofApp::draw()
{
    
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
