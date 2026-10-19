#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofRectangle rect(0, 0, 800, 1200);
    ofBeginSaveScreenAsSVG("WATER.svg", false, false, rect);

    ofBackground(35, 198, 212);

    ofNoFill();
    ofSetLineWidth(1.5);

    int centrosX[] = { 300, 500, 250, 550, 400 };
    int centrosY[] = { 200, 450, 750, 900, 1050 };
    int numCentros = 5;

        ofColor paletaColores[3] = {
        ofColor(224, 252, 252), // #e0fcfc
        ofColor(69, 159, 159),  // #459f9f
        ofColor(27, 105, 105)   // #1b6969
    };

    for (int c = 0; c < numCentros; c++) {
        float cx = centrosX[c];
        float cy = centrosY[c];

        int contadorAnillo = 0;

        for (int r = 20; r < 350; r += 15) {

            ofSetColor(paletaColores[contadorAnillo % 3]);
            contadorAnillo++;

            ofPolyline onda;

            for (int angle = 0; angle < 360; angle += 5) {
                float rad = ofDegToRad(angle);
                float deformacion = ofSignedNoise(cx * 0.01, cy * 0.01, r * 0.02, angle * 0.05) * 25.0;
                float radioActual = r + deformacion;

                float x = cx + cos(rad) * radioActual;
                float y = cy + sin(rad) * radioActual;

                onda.addVertex(x, y);
            }

            onda.close();
            onda.draw();
        }
    }

    ofSetColor(255);

    for (int i = 0; i < 200; i++) {
        float gotaX = ofRandom(0, 800);
        float gotaY = ofRandom(0, 1200);
        float radioGota = ofRandom(1.0, 3.5); 

        ofDrawCircle(gotaX, gotaY, radioGota);
    }

    ofEndSaveScreenAsSVG();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

}

void ofApp::keyPressed(int key) {}
void ofApp::keyReleased(int key) {}
void ofApp::mouseMoved(int x, int y) {}
void ofApp::mouseDragged(int x, int y, int button) {}
void ofApp::mousePressed(int x, int y, int button) {}
void ofApp::mouseReleased(int x, int y, int button) {}
void ofApp::mouseEntered(int x, int y) {}
void ofApp::mouseExited(int x, int y) {}
void ofApp::windowResized(int w, int h) {}
void ofApp::gotMessage(ofMessage msg) {}
void ofApp::dragEvent(ofDragInfo dragInfo) {}