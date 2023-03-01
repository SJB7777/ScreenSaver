#include "ofApp_Lee.h"

//--------------------------------------------------------------
void ofApp_Lee::setup(){
	init(); // 값들 초기 상태로 바꿔주는 함수
}

//--------------------------------------------------------------
void ofApp_Lee::update(){

}

//--------------------------------------------------------------
void ofApp_Lee::draw(){
	if (sc_change == 0)
		screen_save(); // 화면보호기 1번 함수 호출
	else
		screen_save2(); // 화면보호기 2번 함수 호출
}

//--------------------------------------------------------------
void ofApp_Lee::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp_Lee::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp_Lee::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp_Lee::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp_Lee::mousePressed(int x, int y, int button){
	if (sc_change == 0) // 화면보호기 1번 진행중일 때, 마우스 클릭하면
		sc_change = 1; // sc_change 값 1로 수정
	else if (sc_change == 1)  // 화면보호기 2번 진행중일 때, 마우스 클릭하면
		sc_change = 0; // sc_change 값 0으로 수정
}

//--------------------------------------------------------------
void ofApp_Lee::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp_Lee::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp_Lee::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp_Lee::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp_Lee::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp_Lee::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp_Lee::screen_save() {
	ofSetBackgroundColor(0); // 배경화면 검은색

	xPos += xDir; // x축 기준 좌표 xDir 만큼 증가
	yPos += yDir; // y축 기준 좌표 yDir 만큼 증가
	rotate++; // 회전 정도 나타내는 rotate 값 1씩 증가

	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2); // ofGetWidth() / 2, ofGetHeight() / 2 을 원점으로 잡기
	ofRotateZDeg(rotate); // z축 방향으로 rotate 정도 만큼 회전
	ofRotateYDeg(rotate); // y축 방향으로 rotate 정도 만큼 회전
	ofRotateXDeg(rotate); // x축 방향으로 rotate 정도 만큼 회전

	if (xPos < ofGetWidth() / 4 || xPos > ofGetWidth() - 100) { // xPos 값이 ofGetWidth() / 4 보다 작거나 ofGetWidth() - 100 보다 커지면, xDIr에 -1 곱해서 xPos 값 줄이기(반대면 xPos 값 늘리기) + 색상 랜덤하게 변경
		xDir *= -1;
		r_random = ofRandom(10, 255); // RGB 중 R 값 10 ~ 255 사이의 랜덤한 값 할당
		g_random = ofRandom(10, 255); // RGB 중 G 값 10 ~ 255 사이의 랜덤한 값 할당
		b_random = ofRandom(10, 255); // RGB 중 B 값 10 ~ 255 사이의 랜덤한 값 할당
		ofSetColor(r_random, g_random, b_random); // 구의 색깔을 랜덤하게 설정
	}

	else if (yPos < ofGetHeight() / 4 || yPos > ofGetHeight() - 100) { // yPos 값이 ofGetHeight() / 4 보다 작거나 ofGetHeight() - 100 보다 커지면, yDIr에 -1 곱해서 yPos 값 줄이기(반대면 yPos 값 늘리기) + 색상 랜덤하게 변경
		yDir *= -1;
		r_random = ofRandom(10, 255); // RGB 중 R 값 10 ~ 255 사이의 랜덤한 값 할당
		g_random = ofRandom(10, 255); // RGB 중 G 값 10 ~ 255 사이의 랜덤한 값 할당
		b_random = ofRandom(10, 255); // RGB 중 B 값 10 ~ 255 사이의 랜덤한 값 할당
		ofSetColor(r_random, g_random, b_random); // 구의 색깔을 랜덤하게 설정
	}

	// 특정 좌표에 구체 그리기
	ofDrawSphere(100, 100, 100, 60);
	ofDrawSphere(xPos, 100, 100, 60);
	ofDrawSphere(100, yPos, 100, 60);
	ofDrawSphere(xPos, yPos, 100, 60);
	ofDrawSphere(200, 200, 200, 60);
	ofDrawSphere(400, 400, 400, 60);
}

void ofApp_Lee::screen_save2() {
	ofSetBackgroundColor(0); // 배경화면 검은색

	if (angle > 0.25 * PI) // 우측으로 pi/4 만큼 움직인 상황
		check = 1; // 양쪽 끝에 도달했는지 나타내는 변수 값인, check 변수 1로 수정
	if (angle < -0.25 * PI) // 좌측으로 pi/4 만큼 움직인 상황
		check = 0; // 양쪽 끝에 도달했는지 나타내는 변수 값인, check 변수 0으로 수정

	if (check == 0)
		angle += 0.007; // check 값이 0이면 angle이 0.007 씩 증가 = 우측으로 이동
	else if (check == 1)
		angle -= 0.007; // check 값이 1이면 angle이 0.007 씩 감소 = 좌측으로 이동

	ofSetColor(ofColor::springGreen); // 색깔 springGreen으로 설정

	// 진자 모형 그리기
	ofDrawRectangle(0, 0, ofGetWidth(), 200);
	ofDrawLine(500, 200, 500 + 100 * sin(angle), 430 + 100 * cos(angle));
	ofDrawCircle(500 + 100 * sin(angle), 430 + 100 * cos(angle), 50);
}

void ofApp_Lee::init() {
	xPos = ofGetWidth() / 2; // 구의 x좌표 기준 값을, 화면 너비 중간에 위치하도록 설정
	yPos = ofGetHeight() / 2; // 구의 y좌표 기준 값을, 화면 높이 중간에 위치하도록 설정
	xDir = 4; // x축 방향 움직이는 정도(속도)를 4로 설정
	yDir = 4; // y축 방향 움직이는 정도(속도)를 4로 설정
	sc_change = 0; // 화면보호기 1번이 먼저 실행되도록, sc_change 변수 값 0으로 설정
	check = 0; // 화면보호기 2번의 초기 진행과정에서, 진자 운동이 오른쪽으로 움직이게 하기 위해, check 변수 값 0으로 설정
}
