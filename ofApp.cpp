#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(0);

	ofTrueTypeFont font;
	font.loadFont("fonts/Kazesawa-bold.ttf", 250, true, true, true);

	this->fbo.allocate(ofGetWidth(), ofGetHeight());
	this->fbo.begin();

	ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);

	ofBackground(255, 0);
	ofSetColor(255, 0, 0);
	font.drawString("R", font.stringWidth("R") * -1.5, font.stringHeight("R") * 0.5);
	ofSetColor(0, 255, 0);
	font.drawString("G", font.stringWidth("G") * -0.5, font.stringHeight("G") * 0.5);
	ofSetColor(0, 0, 255);
	font.drawString("B", font.stringWidth("B") *  0.5, font.stringHeight("B") * 0.5);

	this->fbo.end();

	this->shader.load("shader/shader.vert", "shader/shader.frag");
}
//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->shader.begin();
	this->shader.setUniform1f("time", ofGetElapsedTimef());
	this->shader.setUniform2f("resolution", ofGetWidth(), ofGetHeight());
	this->shader.setUniformTexture("tex", this->fbo.getTexture(), 1);

	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());

	this->shader.end();
}

//--------------------------------------------------------------
int main() {

	ofGLWindowSettings settings;
	settings.setGLVersion(3, 2);
	settings.setSize(720, 720);
	ofCreateWindow(settings);
	ofRunApp(new ofApp());
}