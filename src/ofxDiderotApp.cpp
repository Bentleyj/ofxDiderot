#include "ofxDiderotApp.h"

bool comparePages(string a, string b) {
    string aCut = ofSplitString(a, ".")[0];
    aCut = ofSplitString(aCut, "/")[2];
    aCut = ofSplitString(aCut, "_")[0];
    if(ofSplitString(aCut, "F").size() > 1)
        aCut = ofSplitString(aCut, "F")[1];
    int an = ofToInt(aCut);
    string bCut = ofSplitString(b, ".")[0];
    bCut = ofSplitString(bCut, "/")[2];
    bCut = ofSplitString(bCut, "_")[0];
    if(ofSplitString(bCut, "F").size() > 1)
        bCut = ofSplitString(bCut, "F")[1];
    int bn = ofToInt(bCut);
    return an < bn;
}

//--------------------------------------------------------------
void ofxDiderotApp::setup(){
	index = 0;
}

//--------------------------------------------------------------
void ofxDiderotApp::loadImages(string path) {
	string imagesRoot = "GutenbergData/" + path;
	//ofSetDataPathRoot(imagesRoot);

	imagePaths.clear();
	loader.clearPaths();
	imagePaths = loader.load(imagesRoot);
	cout << "We loaded " << imagePaths.size() << " images." << endl;
    
   // std::sort(imagePaths.begin(), imagePaths.end(), comparePages);
        
	if (imagePaths.size() > 0) {
        bool loaded = image.load(imagePaths[0]);
	}
	else {
		cout << "ofxDidertoApp::loadImages [Error] Path: " + imagesRoot + " contained no jpeg files." << endl;
	}
    
}

//--------------------------------------------------------------
void ofxDiderotApp::update(){
//    stepRight();
}

//--------------------------------------------------------------
void ofxDiderotApp::draw(){
	ofPushMatrix();
	ofPushStyle();
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	image.draw(0, 0);
	ofPopStyle();
	ofPopMatrix();
}

//--------------------------------------------------------------
bool ofxDiderotApp::stepLeft() {
    bool loop = false;
	index--;
    if(index == -1) {
        index = imagePaths.size()-1;
        loop = true;
    }
	bool loaded = image.load(imagePaths[index]);
    return loop;
}

//--------------------------------------------------------------
bool ofxDiderotApp::stepRight(ofImage* img) {
    cout<<"stepped: ";
    bool loop = false;
	index++;
    if(index == imagePaths.size()) {
        index = 0;
        loop = true;
    }
    //cout<<imagePaths[index]<<endl;
	bool loaded = img->load(imagePaths[index]);
    cout<<loaded<<endl;
    return loop;
}

//--------------------------------------------------------------
void ofxDiderotApp::resetToBeginning() {
    index = 0;
    image.load(imagePaths[index]);
}

//--------------------------------------------------------------
void ofxDiderotApp::keyPressed(int key){
	if (key == OF_KEY_LEFT) {
		stepLeft();
	}
	else if (key == OF_KEY_RIGHT) {
//        stepRight();
	}
}

//--------------------------------------------------------------
void ofxDiderotApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofxDiderotApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofxDiderotApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofxDiderotApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofxDiderotApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofxDiderotApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofxDiderotApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofxDiderotApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofxDiderotApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofxDiderotApp::dragEvent(ofDragInfo dragInfo){ 

}
