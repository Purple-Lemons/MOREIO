/*
IF YOU HAVEN'T ALREADY DONE SO, PLEASE READ THE README
*/

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	state = 0;
	if (state == 0)
	{
		game = Game();
	}
	else if (state == 1)
	{
		tRec = TextRecognition();
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	if (state == 0)
	{
		game.calculate();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	if (state == 0)
	{
		game.draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (state == 0)
	{
		game.keyPressed(key);
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

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	game.mousePressed(x, y);
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
