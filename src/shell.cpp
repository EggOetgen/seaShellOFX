//
//  shell.cpp
//  seashellOFX
//
//  Created by Edmund Oetgen on 18/07/2017.
//
//

#include "shell.hpp"

void shell::generate(int n, int m, int D, float turns, float alpha, float beta, float A, float k, float mu, float omega, float phi, float a, float b, float L, float P, float W1, float W2, int N)
{
   
    // adjust resolution of mesh for number of shell turns
    n = (int) ( n * turns / 10.0);
    
    spiral.clear();
    shell.clear();
    
    spiral.resize(n);
    shell.resize(n);
    
    for (int i = 0; i < n; i++){
        shell[i].resize(m);
    }
    
    // Get vertices for the shell
    for (int i = 0; i < n; i++)
    {
        // Generate main spiral
        float theta = ofMap(i, 0, n, 0, turns);
        float rad = exp( theta * cos(alpha) / sin(alpha) );
        
        float x =  A * rad * sin(beta) * cos(theta) * D;
        float y =  A * rad * sin(beta) * sin(theta);
        float z = -A * rad * cos(beta);
        
        spiral[i] = ofPoint(x, y, z);
        
        // Generate ellipse around each point of spiral
        for (int j = 0; j < m; j++)
        {
            float s = ofMap(j, 0, m, 0, TWO_PI);
            float r2 = pow( pow(cos(s)/a,2) + pow(sin(s)/b,2), -0.5 );
            
            // add surface manipulations
            float surfrad = 0;
            if (W1==0 || W2==0 || N==0) surfrad = 0;
            else {
                float lt = (TWO_PI / N) * ( N*theta / TWO_PI - int(N*theta / TWO_PI) );
                surfrad = L * exp( -( pow(2*(s-P)/W1, 2) + pow(2*lt/W2, 2) ) );
            }
            r2 += surfrad;
            
            x = cos(s + phi) * cos(theta + omega) * r2 * rad * D;   // here  rad - 1 closes the opening of the curve at the origin
            y = cos(s + phi) * sin(theta + omega) * r2 * rad;
            z = sin(s + phi)                      * r2 * rad;
            
            // adjust orientation of the
            x -= sin(mu) * sin(s + phi) * sin(theta + omega) * r2;
            y += sin(mu) * sin(s + phi) * cos(theta + omega) * r2;
            z *= cos(mu);
            
            shell[i][j] = spiral[i] + ofPoint(x, y, z);
        }
    }
}

void shell::generateMesh(int n, int m, float turns)
{
   
    // adjust resolution of mesh for number of shell turns
 //   n = (int) (n * turns / 20.0);
    n = (int) (n * turns / 20.0);

    
    // vertices
   // float[][] vertices = new float[ n * m ][3];
       //vertices.resize(n*m);
  
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int pos = i + n * j;
            vertices.push_back(shell[i][j]);
            
                   }
    }
    
    shellMesh.clear();
    for (int i = 0; i < vertices.size(); i++) {
        shellMesh.addVertex(vertices[i]);
        shellMesh.addColor(ofFloatColor(ofMap(i, 0.f, vertices.size(),0.f,1.f)));
    }

    //the following thanks to jake sparrow hunter
    for (int i = m ; i < vertices.size(); i++) {
        if (i < vertices.size() && i != m){
            //TRI1
            //this point
            shellMesh.addIndex(i);
            //to previous point
            shellMesh.addIndex(i-1);
            //to this point on the previous ring
            shellMesh.addIndex(i-m);
            
            //TRI2
            //the previous point
           shellMesh.addIndex(i-1);
            //to the previous point on the previous ring
            shellMesh.addIndex(i-m-1);
            //to one after that
            shellMesh.addIndex(i-m);
        }
       // SPECIAL CASES
        
//       // first case
//        else if (i == m){
//            //TRI1
//            //this point
//            shellMesh.addIndex(i);
//            //to previous point
//            shellMesh.addIndex(i-1);
//            //to this point on the previous ring
//            shellMesh.addIndex(i-m);
//        }
////        //last case
//        else if (i == vertices.size()){
//            //TRI2
//            //the previous point
//            shellMesh.addIndex(i-1);
//            //to the previous point on the previous ring
//            shellMesh.addIndex(i-m-1);
//            //to one after that
//            shellMesh.addIndex(i-m);
//        }
    }
 
//    int index = 0;
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            vertices[index][0] = shell[i][j].x;
//            vertices[index][1] = shell[i][j].y;
//            vertices[index][2] = shell[i][j].z;
//            index++;
//        }
//    }
//    
//    // faces
//    index = 0;
//    int[][] faces = new int[ (n-1)*m ][4];
//    for (int j = 0; j < n-1; j++) {
//        for (int i = 0; i < m; i++) {
//            faces[index][0] = i + m * j;
//            faces[index][1] = (i + 1) % m + m * j;
//            faces[index][2] = (i + 1) % m + m * (j + 1);
//            faces[index][3] = i + m * (j + 1);
//            index++;
//        }
//    }
    
  
}

void shell::draw(int m){
    

 //  shellMesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
  //  shellMesh.drawWireframe();
//    ofPushMatrix();
//      ofTranslate(-50,0,0);
    shellMesh.draw();
//    ofPopMatrix();
//    ofPushMatrix();
//    ofTranslate(50,0,0);

//    for (int i = 0; i < shell.size(); i++){
//        for(int j = 0; j < shell[i].size(); j++){
//            
//            ofDrawSphere(shell[i][j], 0.5);
//    }
//    }
//    ofPopMatrix();
    
    //    for(int i = 0; i < shell.size(); i++){
//        for(int j = 0; j < shell[i].size(); j++){
//            ofDrawCircle(shell[i][j].x, shell[i][j].x, shell[i][j].x);
//            cout<<shell[i][j].x<<endl;
//        }
//    }
    
//    glBegin(GL_TRIANGLES);
//    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
//    //the following thanks to jake sparrow hunter
//    for (int i = m ; i <= vertices.size(); i++) {
//        if (i < vertices.size() && i != m){
//            //TRI1
//            //this point
//            glVertex3f(vertices[i].x, vertices[i].y, vertices[i].z);
//            //to previous point
//            glVertex3f(vertices[i-1].x, vertices[i-1].y, vertices[i-1].z);
//            //to this point on the previous ring
//            glVertex3f(vertices[i-m].x, vertices[i-m].y, vertices[i-m].z);
//            
//            //TRI2
//            //the previous point
//            glVertex3f(vertices[i-1].x, vertices[i-1].y, vertices[i-1].z);
//            //to the previous point on the previous ring
//            glVertex3f(vertices[i-m-1].x, vertices[i-m-1].y, vertices[i-m-1].z);
//            //to one after that
//            glVertex3f(vertices[i-m].x, vertices[i-m].y, vertices[i-m].z);
//        }
//        //SPECIAL CASES
//        
//        //first case
//        else if (i == m){
//            //TRI1
//            //this point
//            glVertex3f(vertices[i].x, vertices[i].y, vertices[i].z);
//            //to previous point
//            glVertex3f(vertices[i-1].x, vertices[i-1].y, vertices[i-1].z);
//            //to this point on the previous ring
//            glVertex3f(vertices[i-m].x, vertices[i-m].y, vertices[i-m].z);
//        }
//        //last case
//        else if (i == vertices.size()){
//            //TRI2
//            //the previous point
//            glVertex3f(vertices[i-1].x, vertices[i-1].y, vertices[i-1].z);
//            //to the previous point on the previous ring
//            glVertex3f(vertices[i-m-1].x, vertices[i-m-1].y, vertices[i-m-1].z);
//            //to one after that
//            glVertex3f(vertices[i-m].x, vertices[i-m].y, vertices[i-m].z);
//        }
//    }
//    
//    glEnd();
  

    
//     for (int i = 0 ; i <= vertices.size(); i++) {
//         ofDrawSphere(vertices[i], 2);
//     }
}

void shell::updateMesh(int n, int m, float turns){
//float time = ofGetElapsedTimef();
//    
//    for(int i = 0; i < shellMesh.getVertices().size(); i ++){
//    ofPoint p = shellMesh.getVertex(i);
//        float offset = ofNoise(i * 0.5, i*0.5, time)*ofRandom(-1,1);
//        float scale  = 1;
//        p.z += offset * scale;
//        
//
//        shellMesh.setVertex(i, p);
//    }
    
//    n = (int) (n * turns / 10.0);
//
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            int pos = i + n * j;
//            shellMesh.setVertex(pos, shell[i][j]);
//            vertices[pos] = shell[i][j];
//            
//        }
//    }
//    for (int i = 0; i < shell.size(); i++){
//        for(int j = 0; j < shell[i].size(); j++){
//        int pos = i + shell[i].size() * j;
//            shellMesh.setVertex(pos, shell[i][j]);
//            vertices[pos] = shell[i][j];
//        }
//    }
 
     n = (int) (n * turns / 20.0);
    vertices.clear();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int pos = i + n * j;
            vertices.push_back(shell[i][j]);
            
        }
    }

    for (int i = 0; i < vertices.size(); i++) {
        shellMesh.setVertex(i, vertices[i]);
    }
}

