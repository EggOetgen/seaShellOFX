#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

//    n = 512;
//    m = 96;
 
    n = 384;
    m = 80;
    
//    n = 256;
//    m = 48;

//    n = 128;
//    m = 32;
//    n = 64;
//    m = 16;
    
   
 
    gui.setup();
    gui.add(turns.setup("turns", 6 * TWO_PI, 0, 10 * TWO_PI));
    gui.add(D.setup("D", 1.f, 1.f, 1.f));
    gui.add(alpha.setup("alpha", 1.49f, 0, PI));
    gui.add(beta.setup("beta", .47f, -PI, PI));
    gui.add(A.setup("A", .0f, 0.f, 100.f));
   // gui.add(k.setup("k", .47f, 0.f, 2.f));
    gui.add(mu.setup("mu", 0.08f, 0.f, 6.283185f));
    gui.add(omega.setup("omega", -6.283185f, 0.f, 6.283185f));
    gui.add(phi.setup("phi", 2.6f, -PI, PI));
    gui.add(a.setup("a", 13.13f, 0.f, 50.f));
    gui.add(b.setup("b", 20.f, 0.f, 50.f));
    gui.add(L.setup("L", 5.f, 0.f, 5.f));
    gui.add(P.setup("P", 5.f, 0.f, 5.f));
    gui.add(W1.setup("W1", 5.f, -5.f, 5.f));
    gui.add(W2.setup("W2", .39f, -10.f, 10.f));
    gui.add(N.setup("N", 10, -10, 10));
//    gui.add(k.setup("k", .86f, 0.f, 10.f));

    pTurns = turns;
  
    shell.generate(n,m,D, turns, alpha, beta, A, mu, omega, phi, a, b, L, P, W1, W2, N);
    shell.generateMesh(n,m, turns);
 
   // light.setPosition(-100,-300,300);

    light.enable();
    
 
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
   shell.generate(n,m, D, turns, alpha, beta, A, mu, omega, phi, a, b, L, P, W1, W2, N);
    if(turns != pTurns){
        shell.generateMesh(n,m, turns);

    }else{    
    shell.updateMesh(n, m ,turns);
    }
   
}

//--------------------------------------------------------------
void ofApp::draw(){
   
    gui.draw();
   
    ofEnableDepthTest();
   
    light.enable();
        cam.begin();
            shell.draw(m);
        cam.end();
    light.disable();
    
    ofDisableDepthTest();
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
