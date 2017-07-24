#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "shell.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    /*TAKEN FROM https://github.com/genekogan/SeashellGenerator */
    
       
    shell shell;
    
    ofLight light;
    
    ofEasyCam cam;
    int n, m;
    
   ofxIntSlider D;
    ofxFloatSlider turns;
    ofxFloatSlider alpha;
    ofxFloatSlider beta;
    ofxFloatSlider A;
    //ofxFloatSlider k;
    ofxFloatSlider mu;
    ofxFloatSlider omega;
    ofxFloatSlider phi;
    ofxFloatSlider a;
    ofxFloatSlider b;
    ofxFloatSlider L;
    ofxFloatSlider P;
    ofxFloatSlider W1;
    ofxFloatSlider W2;
    ofxIntSlider N;
    
    ofxPanel gui;

    float pTurns;







};
