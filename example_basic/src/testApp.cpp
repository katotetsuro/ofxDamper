#include "testApp.h"

vector<float> fsmoothed, fraw;
vector<ofVec2f> vsmoothed, vraw;
const int m = 10;

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(15);
    floatDamper.setup(m);
    vecDamper.setup(m);
}

//--------------------------------------------------------------
void testApp::update(){
    if (ofRandom(1) > 0.2) {
        float v = sin(ofGetElapsedTimef()) + ofNoise(ofGetElapsedTimef()*10);
        floatDamper.add(v);
        fraw.push_back(v);
        fsmoothed.push_back(floatDamper.get());
        if (fraw.size() == 50) {
            fraw.erase(fraw.begin());
            fsmoothed.erase(fsmoothed.begin());
        }
        
        ofVec2f vec(ofVec2f(v*cos(ofGetElapsedTimef()), v*sin(ofGetElapsedTimef())));
        vecDamper.add(vec);
        vraw.push_back(vec);
        vsmoothed.push_back(vecDamper.get());
    } else {
        floatDamper.removeOldest();
        vecDamper.removeOldest();
    }
    
    ofSetWindowTitle(ofToString(ofGetFrameRate(), 2));
}

//--------------------------------------------------------------
void testApp::draw(){
    ofNoFill();
    ofBeginShape();
    for (int i=0; i<fraw.size(); ++i) {
        ofVertex(i*20, fraw[i]*100 + ofGetHeight()/2);
    }
    ofEndShape();
    
    ofPushStyle();
    ofSetColor(0);
    ofBeginShape();
    for (int i=0; i<fraw.size(); ++i) {
        ofVertex(i*20, fsmoothed[i] * 100 + ofGetHeight()/2);
    }
    ofEndShape();
    ofPopStyle();
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
