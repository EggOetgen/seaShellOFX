//
//  shell.hpp
//  seashellOFX
//
//  Created by Edmund Oetgen on 18/07/2017.
//
//

#pragma once

#include "ofMain.h"

class shell{
    
public:
    void generate(int n, int m, int D, float turns, float alpha, float beta, float A, float k, float mu, float omega, float phi, float a, float b, float L, float P, float W1, float W2, int N);
    void generateMesh(int n, int m, float turns);
    void draw(int m);
    void updateMesh(int n, int m, float turns);
    
    
    /*TAKEN FROM https://github.com/genekogan/SeashellGenerator */
    
//    // spiral parameters
//    int D = 1; //varying this stretches and compresses along an axis orthoganal to the "A" parameter
//    float turns = 6 * TWO_PI;
//    
//    float alpha = 1.49;
//    float beta = .47;
//    float A = 0;
//    float k = 0.86; // test variable for rate of growth
//    
//    // ellipse orientation parameters
//    float mu = .08; // angle given in radians
//    float omega = .01; // angle given in radians
//    float phi = 2.6; //rotation of elipse about normal axis, angle given in radians
//    
//    // ellipsoid parameters
//    float a = 13.13; //elipse radii
//    float b = 20; //elipse radii
//    
//    // surface parameters
//    float L = 5;
//    float P = 5;
//    float W1 = 5;
//    float W2 = .39;
//    int N = 10;
//
//    // spiral parameters
//    int D = 1; //varying this stretches and compresses along an axis orthoganal to the "A" parameter
//    float turns = 6 * TWO_PI;
//    
//    float alpha = glm::radians(88.9);
//    float beta = glm::radians(4.f);
//    float A = 47;
//    float k = 0.86; // test variable for rate of growth
//    
//    // ellipse orientation parameters
//    float mu = glm::radians(1.f); // angle given in radians
//    float omega = glm::radians(-2.f); // angle given in radians
//    float phi = glm::radians(55.f); //rotation of elipse about normal axis, angle given in radians
//    
//    // ellipsoid parameters
//    float a = 1.3; //elipse radii
//    float b = 1.5; //elipse radii
//    
//    // surface parameters
//    float L = 0;
//    float P = 0;
//    float W1 = 0;
//    float W2 = 0;
//    int N = 0;
//    
    
    vector<ofPoint> spiral;
    vector<vector<ofPoint>> shell;
    vector<ofPoint> vertices;

    
    ofVboMesh shellMesh;
};