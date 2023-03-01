#pragma once

#include "ofMain.h"

class ofApp_Lee : public ofBaseApp{

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

		void init(); // 값들 초기 상태로 바꿔주는 함수

		//screen_saver01 함수,변수
		void screen_save(); // 화면보호기 1번 함수
		int xDir, yDir, xPos, yPos; // 구의 x방향 속도, y방향 속도, x좌표, y좌표 나타내는 변수
		int r_random, g_random, b_random, bw_random; // RGB, BW 색상표 기준으로, 랜덤한 색깔 나타내기 위한 변수 
		float rotate; // x축, y축, z축 기준으로 회전하는 정도를 나타내는 변수

		//screen_saver02 함수, 변수
		void screen_save2(); // 화면보호기 2번 함수
		float angle = 0; // 진자 운동 구현하기 위한, 각도 변수
		int check; // 진자 운동을 표현할 때, 양쪽 끝에 도달했고, 이제 반대 방향으로 가야함을 나타내는 변수

};

extern int ApplicationState;