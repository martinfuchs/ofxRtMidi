#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	midi.setup();
	ofAddListener(midi.floatEvent,this,&testApp::sliderEvent);
}

//--------------------------------------------------------------
void testApp::update(){
	midi.update();
}

void testApp::sliderEvent(ofxRtFloatValue & f){
	int port = 14;
	if(port==f.port) cout << f.value << endl;
}

//--------------------------------------------------------------
void testApp::draw(){

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	cout << midi.getFloatValue(4) << endl;
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}