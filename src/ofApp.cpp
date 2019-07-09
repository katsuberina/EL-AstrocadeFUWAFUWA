#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255,255,255);
    
    // シリアル通信開始
    serial.setup("/dev/cu.usbmodem14611",9600);
}

//--------------------------------------------------------------
void ofApp::update(){

    nBytesRead = 0;
    int nRead = 0;
    char bytesRead[3];
    unsigned char bytesReturned[3];
    
    memset(bytesReturned, 0, 3);
    memset(bytesReadString, 0, 4);
    
    // シリアル通信で受け取ったデータを読み込む
    while ((nRead = (int)serial.readBytes(bytesReturned, 3)) > 0) {
                nBytesRead = nRead;
    };
    
    if (nBytesRead > 0) {
        memcpy(bytesReadString, bytesReturned, 3);
        string x = bytesReadString;
    }
    

    //fuwafuwa button
    if(ofToInt(bytesReadString) > fuwa_val  && trigger == false){
        start = ofGetElapsedTimeMillis();
    }
  
        if(ofGetElapsedTimeMillis() - start < trig_time && ofGetElapsedTimeMillis() > 1800 ){
            trigger = true;
            fuwa_state = 1;
        }else{
            fuwa_state = 0;
            trigger = false;
        }
    
    
    if( ofToInt(bytesReadString) < fuwa_val  && ofGetElapsedTimeMillis() - start >  trig_time ){
        fuwa_state = 0;
        trigger = false;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
   if(fuwa_state == 1){
       ofFill();        // draw "filled shapes"
       ofSetHexColor(0xCCCCCC);
       ofDrawCircle(512,384,80);
    }
        std::printf("value: %i\n", fuwa_state);
    
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


