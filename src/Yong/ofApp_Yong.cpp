#include "ofApp_Yong.h"

Params param;

void Params::setup() {
	eCenter = ofPoint(ofGetWidth() / 2, ofGetHeight() / 2);
	

	eRad = 300;
	velRad = 0;
	lifeTime = 3.0;
	rotate = 500;
	force = -1000;
	spinning = 1000;
	friction = 0.05;
}

void Params::update() {
	eCenter = ofPoint(ofGetWidth() / 2, ofGetHeight() / 2);
	force = sin(ofGetElapsedTimef()/10)*1000;
}

Particle::Particle() {
	live = false;
}

ofPoint randomPointInCircle(float maxRad) {
	ofPoint pnt;
	float rad = ofRandom(0, maxRad);
	float angle = ofRandom(0, M_TWO_PI);
	pnt.x = cos(angle) * rad;
	pnt.y = sin(angle) * rad;
	return pnt;
}

void Particle::setup() {
	pos = param.eCenter + randomPointInCircle(param.eRad);
	vel = randomPointInCircle(param.velRad);
	time = 0;
	lifeTime = param.lifeTime;
	live = true;
}

void Particle::update(float dt) {
	if (live) {
		// Rotate vel
		vel.rotate(0, 0, param.rotate * dt);

		ofPoint acc;
		ofPoint delta = pos - param.eCenter;
		float len = delta.length();
		if (ofInRange(len, 0, param.eRad)) {
			delta.normalize();

			//Attraction/repulstion force
			acc += delta * param.force;

			//Spinning force
			acc.x += -delta.y * param.spinning;
			acc.y += delta.x * param.spinning;
		}
		vel += acc * dt;	//Euler method
		vel *= (1 - param.friction);	//Friction
		// Update pos
		pos += vel * dt;

		// Update time and check if particle should die
		time += dt;
		if (time >= lifeTime) {
			live = false; // Particle is now considered as died
		}
	}
}

void Particle::draw() {
	if (live) {
		// Compute size
		float size = ofMap(
			fabs(time - lifeTime / 2), 0, lifeTime / 2, 3, 1);
		// Compute color
		ofColor color = ofColor::red;
		float hue = ofMap(time, 0, lifeTime, 128, 255);
		color.setHue(hue);
		ofSetColor(color);

		ofCircle(pos, size);

	}
}



//--------------------------------------------------------------
void ofApp_Yong::setup(){
	ofSetFrameRate(60);

	//Allocate drawing buffer
	int w = ofGetWidth();
	int h = ofGetHeight();
	fbo.allocate(w, h, GL_RGB32F_ARB);

	//Fill buffer with white color
	fbo.begin();
	ofBackground(0, 0, 0);
	fbo.end();

	//Set up parameters
	param.setup();		//Global parameters

	time0 = ofGetElapsedTimef();

	bornCount = 0;

	history = 0.9;
	bornRate = 1500;

}

//--------------------------------------------------------------
void ofApp_Yong::update(){

	//Compute dt
	float time = ofGetElapsedTimef();
	float dt = ofClamp(time - time0, 0, 0.1);
	time0 = time;

	param.update();

	//If the particle is not active - active it
	int i = 0;
	while (i < p.size()) {
		if (!p[i].live) {
			p.erase(p.begin() + i);
		}
		else {
			i++;
		}
	}

	//Born new particles
	bornCount += dt * bornRate;		//Update bornCount value
	if (bornCount >= 1) {
		int bornN = int(bornCount);
		bornCount -= bornN;
		for (int i = 0; i < bornN; i++) {
			Particle newP;
			newP.setup();
			p.push_back(newP);
		}
	}

	//Update the particles
	for (int i = 0; i < p.size(); i++) {
		p[i].update(dt);
	}

}

//--------------------------------------------------------------
void ofApp_Yong::draw(){
	ofBackground(0, 0, 0);

	//1. Drawing to buffer
	fbo.begin();

	//Draw semi-transparent white rectangle
	//to slightly clearing a buffer (depends on history value)

	ofEnableAlphaBlending();	//Enable transparency

	float alpha = (1 - history) * 255;
	ofSetColor(0, 0, 0, alpha);
	ofFill();
	ofRect(0, 0, ofGetWidth(), ofGetHeight());

	ofDisableAlphaBlending();	//Disable transparency

	//Draw the particle
	ofFill();
	for (int i = 0; i < p.size(); i++) {
		p[i].draw();
	}

	fbo.end();

	//2. Draw buffer on the screen
	ofSetColor(255, 255, 255);
	fbo.draw(0, 0);

	
}

//--------------------------------------------------------------
void ofApp_Yong::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp_Yong::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp_Yong::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp_Yong::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp_Yong::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp_Yong::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp_Yong::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp_Yong::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp_Yong::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp_Yong::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp_Yong::dragEvent(ofDragInfo dragInfo){

}

