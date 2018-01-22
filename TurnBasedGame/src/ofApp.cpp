#include "ofApp.h"

bool ofApp::KeyPress[127];
int ofApp::Keys[127];

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){
	for (int i = 0; i < 127; i++)
	{
		Keys[i] = Keys[i] > 0 ? -1 : 0;
		if (KeyPress[i])
		{
			Keys[i] += 2;
		}
	}

	if (Keys['a'] == 2)
	{
		ofSetBackgroundColor(ofColor::white);
		std::cout << "1" << "\n";
	}
	else
	{
		ofSetBackgroundColor(ofColor::black);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	KeyPress[key] = true;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	KeyPress[key] = false;
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
