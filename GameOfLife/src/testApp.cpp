#include "testApp.h"
#include "SequentialMode.h"
#include "OpenMpMode.h"
#include "OpenCLMode.h"
#include "GLSLMode.h"



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
	ofEnableAlphaBlending();
	ofSetFrameRate( 500 );
	stateMachine.addState( new OpenMpMode() );
	stateMachine.addState( new SequentialMode() );
	stateMachine.addState( new OpenCLMode() );
	stateMachine.addState( new GLSLMode() );
	stateMachine.changeState( stateMachine.getSharedData().GLSL );
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

