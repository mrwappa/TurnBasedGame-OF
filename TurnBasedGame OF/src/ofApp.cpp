#include "ofApp.h"
#include "GameObject.h"
#include "Player.h"
InputHandler ofApp::Input;

ofImage image;
//--------------------------------------------------------------
void ofApp::setup() {
	ofSetWindowShape(ofGetScreenWidth(), ofGetScreenHeight());
	ofSetWindowPosition(0, 0);
	glEnable(GL_DEPTH);

	new Player(100, 100);
}
//--------------------------------------------------------------
void ofApp::update() {

	//INPUT
	Input.Update();

	//BEGIN UPDATE
	for (auto const &instance : GameObject::SuperList)
	{
		for (size_t i = 0; i < instance.second->Size(); i++)
		{
			//okej c++, du vägrar att kunna använda vanlig, acceptabel eller logisk syntax för index[] operatorer med maps, och därför måste jag uppenbarligen
			//göra något lika retarderat tillbaks för att få dig att funka...som att lägga till en FindAtIndex funktion som inte alls behövs eftersom jag har en
			//FUCKING INDEX OVERRIDE OPERATOR SOM SKA GÖRA DETTA JOBBET. MEN NEJ, DU VAR BARA TVUNGEN ATT SKITA NER ÖVER ALLT DET...kuksmaskare
			instance.second->FindAtIndex(i)->BeginUpdate();
		}
	}
	//UPDATE
	for (auto const &instance : GameObject::SuperList)
	{
		for (size_t i = 0; i < instance.second->Size(); i++)
		{
			instance.second->FindAtIndex(i)->Update();
		}
	}

	//END UPDATE
	for (auto const &instance : GameObject::SuperList)
	{
		for (size_t i = 0; i < instance.second->Size(); i++)
		{
			instance.second->FindAtIndex(i)->EndUpdate();
		}
	}
	if (InputHandler::ScrollWheel[1] == true)
	{
		ofSetBackgroundColor(ofColor::white);
		std::cout << "1" << "\n";
	}
	else
	{
		ofSetBackgroundColor(ofColor::black);
	}


	//SCROLL WHEEL RESET
	for (size_t i = 0; i < 2; i++)
	{
		InputHandler::ScrollWheel[i] = false;
	}

}

//--------------------------------------------------------------
void ofApp::draw() {
	//"DRAW"
	for (auto const &instance : GameObject::SuperList)
	{
		for (size_t i = 0; i < instance.second->Size(); i++)
		{
			instance.second->FindAtIndex(i)->Draw();
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

	if (key >= 65 and key <= 90)
	{
		InputHandler::KeyPress[key + 32] = true;
	}
	else if (key > 0)
	{
		InputHandler::KeyPress[key] = true;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {


	if (key >= 65 and key <= 90)
	{
		InputHandler::KeyPress[key + 32] = false;
	}
	else if (key > 0)
	{
		InputHandler::KeyPress[key] = false;
	}

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	InputHandler::MousePress[button] = true;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
	InputHandler::MousePress[button] = false;
}

void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY)
{
	InputHandler::ScrollWheel[0] = scrollY == 1 ? true : false;
	InputHandler::ScrollWheel[1] = scrollY == -1 ? true : false;
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
