#include "ofApp.h"

#include <Windows.h>
#include <shellapi.h>

#pragma comment(lib, "Shell32.lib")


enum ApplicationStates {
	KIM,
	LEE,
	YONG
};

int ApplicationState = ApplicationStates::KIM;



//--------------------------------------------------------------
void ofApp::setup(){
	font.load("arial.ttf", 32);
	
	
	// Kim
	kim.setup();
	// Lee
	lee.setup();
	//Yong
	yong.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
	
	switch (ApplicationState) {
	case ApplicationStates::KIM:
		kim.update();
		
		break;
	case ApplicationStates::LEE:
		lee.update();
		
		break;
	case ApplicationStates::YONG:
		yong.update();
		
		break;

	}
	
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	switch (ApplicationState) {
	case ApplicationStates::KIM:
		kim.draw();
		
		break;
	case ApplicationStates::LEE:
		lee.draw();
		
		break;
	case ApplicationStates::YONG:
		yong.draw();
		
		break;

	}
	
	
	
	
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
	switch (key) {
	case OF_KEY_RIGHT:
		ApplicationState = (ApplicationState + 1) % 3;
		break;
	case OF_KEY_LEFT:
		ApplicationState = (ApplicationState + 2) % 3;
		break;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	switch (ApplicationState) {
	case ApplicationStates::KIM:
		kim.mouseDragged(x, y, button);
		break;
	case ApplicationStates::LEE:
		
		break;
	case ApplicationStates::YONG:
		break;

	}
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	switch (ApplicationState) {
	case ApplicationStates::KIM:
		kim.mousePressed(x, y, button);
		break;
	case ApplicationStates::LEE:
		lee.mousePressed(x, y, button);
		break;
	case ApplicationStates::YONG:
		break;

	}
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
