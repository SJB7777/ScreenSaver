#include "ofMain.h"

class screen_saver_lee{

	public:
		void init(); // ���� �ʱ� ���·� �ٲ��ִ� �Լ�
	
		//screen_saver01 �Լ�,����
		void screen_save(); // ȭ�麸ȣ�� 1�� �Լ�
		int xDir, yDir, xPos, yPos; // ���� x���� �ӵ�, y���� �ӵ�, x��ǥ, y��ǥ ��Ÿ���� ����
		int r_random, g_random, b_random, bw_random; // RGB, BW ����ǥ ��������, ������ ���� ��Ÿ���� ���� ���� 
		float rotate; // x��, y��, z�� �������� ȸ���ϴ� ������ ��Ÿ���� ����

		//screen_saver02 �Լ�, ����
		void screen_save2(); // ȭ�麸ȣ�� 2�� �Լ�
		float angle = 0; // ���� � �����ϱ� ����, ���� ����
		int check; // ���� ��� ǥ���� ��, ���� ���� �����߰�, ���� �ݴ� �������� �������� ��Ÿ���� ����

		int sc_change; // ȭ�麸ȣ�� ��ü ����
};