#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofRectangle rect(0, 0, 800, 1200);
    ofBeginSaveScreenAsSVG("topografia_generativa.svg", false, false, rect);

    // 1. Color de fondo solicitado: #23c6d4 -> RGB(35, 198, 212)
    ofBackground(35, 198, 212);

    ofNoFill();
    ofSetLineWidth(1.5);

    // Coordenadas de los centros u "focos" de las ondas
    int centrosX[] = { 300, 500, 250, 550, 400 };
    int centrosY[] = { 200, 450, 750, 900, 1050 };
    int numCentros = 5;

    // Definimos los 3 colores solicitados para las líneas en un arreglo de ofColor:
    // 1. #e0fcfc -> RGB(224, 252, 252)
    // 2. #459f9f -> RGB(69, 159, 159)
    // 3. #1b6969 -> RGB(27, 105, 105)
    ofColor paletaColores[3] = {
        ofColor(224, 252, 252),
        ofColor(69, 159, 159),
        ofColor(27, 105, 105)
    };

    // Bucle anidado para generar líneas concéntricas u onduladas alrededor de cada centro
    for (int c = 0; c < numCentros; c++) {
        float cx = centrosX[c];
        float cy = centrosY[c];

        int contadorAnillo = 0; // Para alternar los colores de la paleta en cada anillo

        for (int r = 20; r < 350; r += 15) {

            // Asignamos una tonalidad diferente de la paleta según el índice del anillo
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