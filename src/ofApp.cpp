#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofRectangle rect(0, 0, 800, 1200);
    ofBeginSaveScreenAsSVG("topografia_generativa.svg", false, false, rect);

    ofBackground(255);
    ofNoFill();
    ofSetLineWidth(1.5);
    ofSetColor(50, 70, 120);

    int centrosX[] = { 300, 500, 250, 550, 400 };
    int centrosY[] = { 200, 450, 750, 900, 1050 };
    int numCentros = 5;

    for (int c = 0; c < numCentros; c++) {
        float cx = centrosX[c];
        float cy = centrosY[c];

        for (int r = 20; r < 350; r += 15) {
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

    ofEndSaveScreenAsSVG();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

}

//--------------------------------------------------------------
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