#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

void ofApp::setup() {
    ofSetVerticalSync(true);
    //ofToggleFullscreen();
    ofSetFrameRate(120);
    finder.setup("haarcascade_frontalface_default.xml");
    finder.setPreset(ObjectFinder::Fast);
    finder.getTracker().setSmoothingRate(.3);
    cam.setup(640*2,480*2);
    //sunglasses.load("sunglasses.png");
    
    ofEnableAlphaBlending();
    
    
    
    
    Spoiled.addListener(this, &ofApp::SpoiledPressed);
    Good.addListener(this, &ofApp::GoodPressed);
    Slippery.addListener(this, &ofApp::SlipperyPressed);
    ThousandEyes.addListener(this, &ofApp::ThousandEyesPressed);
    Xiongmao.addListener(this, &ofApp::XiongmaoPressed);
    Handy.addListener(this, &ofApp::HandyPressed);
    Shaggy.addListener(this, &ofApp::ShaggyPressed);
    
    
    gui.setup();
    gui.add(Spoiled.setup("Spoiled"));
    gui.add(Good.setup("Good"));
    gui.add(Slippery.setup("Slippery"));
    gui.add(ThousandEyes.setup("Thousand Eyes"));
    gui.add(Xiongmao.setup("Xiongmao"));
    gui.add(Handy.setup("Handy"));
    gui.add(Shaggy.setup("Shaggy"));

    
    
    
}

void ofApp::update() {
    cam.update();
    if(cam.isFrameNew()) {
        finder.update(cam);
    }
}

void ofApp::draw() {
    cam.draw(0, 0,1280,960);
    
    for(int i = 0; i < finder.size(); i++) {
        ofRectangle object = finder.getObjectSmoothed(i);
        spoiled.setAnchorPercent(.51, .3);
        float scaleAmount = 5 * object.width / spoiled.getWidth();
        ofPushMatrix();
        ofTranslate(object.x + object.width / 2., object.y + object.height * .42);
        ofScale(scaleAmount, scaleAmount);
        spoiled.draw(0, 0);
        ofPopMatrix();
        ofPushMatrix();
        ofTranslate(object.getPosition());
        ofDrawBitmapStringHighlight(ofToString(finder.getLabel(i)), 0, 0);
        ofDrawLine(ofVec2f(), toOf(finder.getVelocity(i)) * 10);
        ofPopMatrix();
    }
    gui.draw();
    
}


void ofApp::SpoiledPressed(){
    
    spoiled.load("newCat.png");
    

    
}

void ofApp::GoodPressed(){
    
    spoiled.load("newDog.png");
}


void ofApp::SlipperyPressed(){
    
    spoiled.load("newFish.png");
}

void ofApp::ThousandEyesPressed(){
    
    spoiled.load("newFly.png");
}

void ofApp::XiongmaoPressed(){
    
    spoiled.load("xiongMao.png");
}

void ofApp::HandyPressed(){
    
    spoiled.load("newSquid.png");
}

void ofApp::ShaggyPressed(){
    
    spoiled.load("newGoat.png");
}











