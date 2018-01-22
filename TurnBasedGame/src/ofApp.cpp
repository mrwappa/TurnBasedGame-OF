#include "ofApp.h"

InputHandler ofApp::Input;


//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowShape(ofGetScreenWidth(), ofGetScreenHeight());
	ofSetWindowPosition(0, 0);
}
//--------------------------------------------------------------
void ofApp::update(){

	Input.Update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	InputHandler::KeyPress[key] = true;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	InputHandler::KeyPress[key] = false;
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	InputHandler::MousePress[button] = true;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	InputHandler::MousePress[button] = false;
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
