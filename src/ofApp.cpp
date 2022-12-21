#include "ofApp.h"
#include "camrain.hpp"

//--------------------------------------------------------------
void ofApp::setup(){
 //   fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
    cr.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
    cr.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
//    fbo.begin();
    cr.draw();
//    fbo.end();
    //ofSetColor(0);
//    fbo.draw(0,0,ofGetWidth(), ofGetHeight());
    ofSetColor(255);
    ofDrawBitmapString(ofToString( ofGetFrameRate()), 10,10);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
