#include "testApp.h"
#include "SequentialMode.h"
#include "OpenMpMode.h"

testApp::testApp(void)
{
	SYSTEM_INFO sysinfo;
	GetSystemInfo( &sysinfo );
	int i =  sysinfo.dwNumberOfProcessors;
}

testApp::~testApp(void)
{

}

void testApp::setup(){
	stateMachine.addState(new OpenMpMode());
	stateMachine.addState(new SequentialMode());
	stateMachine.changeState(stateMachine.getSharedData().SEQUENTIAL);
}

//--------------------------------------------------------------
void testApp::update(){
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
}



//--------------------------------------------------------------
void testApp::keyPressed(int key){

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

