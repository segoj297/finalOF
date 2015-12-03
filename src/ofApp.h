#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    
    
    void SpoiledPressed(); //cat
    void GoodPressed(); //dog
    void SlipperyPressed(); //fish
    void ThousandEyesPressed(); //fly
    void XiongmaoPressed(); //panda
    void HandyPressed(); //squid
    void ShaggyPressed(); //goat
    
    
    ofVideoGrabber cam;
    ofxCv::ObjectFinder finder;
    ofImage spoiled;

    ofxPanel gui;
    
    
    ofxButton Spoiled;
    ofxButton Good;
    ofxButton Slippery;
    ofxButton ThousandEyes;
    ofxButton Xiongmao;
    ofxButton Handy;
    ofxButton Shaggy;
    
    
    
    
};
