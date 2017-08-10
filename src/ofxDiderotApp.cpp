#include "ofxDiderotApp.h"

//--------------------------------------------------------------
void ofxDiderotApp::setup(){
    
	loadImages("SUP1/");

	index = 0;
	//ofSetRectMode(OF_RECTMODE_CENTER);
}

void ofxDiderotApp::loadImages(string path) {
	string imagesRoot = "../../../../../DiderotData/" + path;
	ofSetDataPathRoot(imagesRoot);

	imagePaths.clear();
	loader.clearPaths();
	imagePaths = loader.load(imagesRoot, "jpeg");
	cout << "We loaded " << imagePaths.size() << " images." << endl;
    
    string prefix = "../../";
    for(int i = 0; i < imagePaths.size(); i++) {
        string::size_type s = imagePaths[i].find(prefix);
        imagePaths[i].erase(s, prefix.length());
        //imagePaths[i].erase(prefix, prefix.length());
    }
    
    ofSetDataPathRoot("../../../data/");
    
	if (imagePaths.size() > 0) {
        bool loaded = image.load(imagePaths[0]);

	}
	else {
		cout << "ofxDidertoApp::loadImaegs [Error] Path: " + imagesRoot + " contained no jpeg files." << endl;
	}
    
}

//--------------------------------------------------------------
void ofxDiderotApp::update(){
	stepRight();
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
void ofxDiderotApp::stepLeft() {
	index--;
    if(index == -1)
        index = imagePaths.size()-1;
	cout << imagePaths[index] << endl;
	bool loaded = image.load(imagePaths[index]);
    cout<<"Loaded: "<<loaded<<endl;
    image.update();
}

//--------------------------------------------------------------
void ofxDiderotApp::stepRight() {
	index++;
	index %= imagePaths.size();
    cout << imagePaths[index] << endl;
	bool loaded = image.load(imagePaths[index]);
    cout<<"Loaded: "<<loaded<<endl;
    image.update();
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
		stepRight();
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
