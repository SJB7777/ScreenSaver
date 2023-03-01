#pragma once

#include "ofMain.h"


class Particle {
public:
	Particle();
	void setup();
	void update(float dt);
	void draw();

	ofPoint pos;
	ofPoint vel;
	float time;
	float lifeTime;
	bool live;
};

class Params {
public:
	
	void setup();
	void update();
	ofPoint eCenter;
	float eRad;
	float velRad;
	float lifeTime;

	float rotate;
	float force;
	float spinning;
	float friction;
};

extern Params param;



class ofApp_Yong : public ofBaseApp{

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
		

		vector<Particle> p;
		ofFbo fbo;
		float history;
		float time0;
		float bornRate;
		float bornCount;

};
