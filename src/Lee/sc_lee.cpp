#include "sc_lee.h"

void screen_saver_lee::screen_save() {
	ofSetBackgroundColor(0); // ���ȭ�� ������

	xPos += xDir; // x�� ���� ��ǥ xDir ��ŭ ����
	yPos += yDir; // y�� ���� ��ǥ yDir ��ŭ ����
	rotate++; // ȸ�� ���� ��Ÿ���� rotate �� 1�� ����

	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2); // ofGetWidth() / 2, ofGetHeight() / 2 �� �������� ���
	ofRotateZDeg(rotate); // z�� �������� rotate ���� ��ŭ ȸ��
	ofRotateYDeg(rotate); // y�� �������� rotate ���� ��ŭ ȸ��
	ofRotateXDeg(rotate); // x�� �������� rotate ���� ��ŭ ȸ��

	if (xPos < ofGetWidth() / 4 || xPos > ofGetWidth() - 100) { // xPos ���� ofGetWidth() / 4 ���� �۰ų� ofGetWidth() - 100 ���� Ŀ����, xDIr�� -1 ���ؼ� xPos �� ���̱�(�ݴ�� xPos �� �ø���) + ���� �����ϰ� ����
		xDir *= -1;
		r_random = ofRandom(10, 255); // RGB �� R �� 10 ~ 255 ������ ������ �� �Ҵ�
		g_random = ofRandom(10, 255); // RGB �� G �� 10 ~ 255 ������ ������ �� �Ҵ�
		b_random = ofRandom(10, 255); // RGB �� B �� 10 ~ 255 ������ ������ �� �Ҵ�
		ofSetColor(r_random, g_random, b_random); // ���� ������ �����ϰ� ����
	}

	else if (yPos < ofGetHeight() / 4 || yPos > ofGetHeight() - 100) { // yPos ���� ofGetHeight() / 4 ���� �۰ų� ofGetHeight() - 100 ���� Ŀ����, yDIr�� -1 ���ؼ� yPos �� ���̱�(�ݴ�� yPos �� �ø���) + ���� �����ϰ� ����
		yDir *= -1;
		r_random = ofRandom(10, 255); // RGB �� R �� 10 ~ 255 ������ ������ �� �Ҵ�
		g_random = ofRandom(10, 255); // RGB �� G �� 10 ~ 255 ������ ������ �� �Ҵ�
		b_random = ofRandom(10, 255); // RGB �� B �� 10 ~ 255 ������ ������ �� �Ҵ�
		ofSetColor(r_random, g_random, b_random); // ���� ������ �����ϰ� ����
	}

	// Ư�� ��ǥ�� ��ü �׸���
	ofDrawSphere(100, 100, 100, 60);
	ofDrawSphere(xPos, 100, 100, 60);
	ofDrawSphere(100, yPos, 100, 60);
	ofDrawSphere(xPos, yPos, 100, 60);
	ofDrawSphere(200, 200, 200, 60);
	ofDrawSphere(400, 400, 400, 60);
}

void screen_saver_lee::screen_save2() {
	ofSetBackgroundColor(0); // ���ȭ�� ������

	if (angle > 0.25 * PI) // �������� pi/4 ��ŭ ������ ��Ȳ
		check = 1; // ���� ���� �����ߴ��� ��Ÿ���� ���� ����, check ���� 1�� ����
	if (angle < -0.25 * PI) // �������� pi/4 ��ŭ ������ ��Ȳ
		check = 0; // ���� ���� �����ߴ��� ��Ÿ���� ���� ����, check ���� 0���� ����

	if (check == 0)
		angle += 0.007; // check ���� 0�̸� angle�� 0.007 �� ���� = �������� �̵�
	else if (check == 1)
		angle -= 0.007; // check ���� 1�̸� angle�� 0.007 �� ���� = �������� �̵�

	ofSetColor(ofColor::springGreen); // ���� springGreen���� ����

	// ���� ���� �׸���
	ofDrawRectangle(0, 0, ofGetWidth(), 200);
	ofDrawLine(500, 200, 500 + 100 * sin(angle), 430 + 100 * cos(angle));
	ofDrawCircle(500 + 100 * sin(angle), 430 + 100 * cos(angle), 50);
}

void screen_saver_lee::init() {
	xPos = ofGetWidth() / 2; // ���� x��ǥ ���� ����, ȭ�� �ʺ� �߰��� ��ġ�ϵ��� ����
	yPos = ofGetHeight() / 2; // ���� y��ǥ ���� ����, ȭ�� ���� �߰��� ��ġ�ϵ��� ����
	xDir = 4; // x�� ���� �����̴� ����(�ӵ�)�� 4�� ����
	yDir = 4; // y�� ���� �����̴� ����(�ӵ�)�� 4�� ����
	sc_change = 0; // ȭ�麸ȣ�� 1���� ���� ����ǵ���, sc_change ���� �� 0���� ����
	check = 0; // ȭ�麸ȣ�� 2���� �ʱ� �����������, ���� ��� ���������� �����̰� �ϱ� ����, check ���� �� 0���� ����
}
