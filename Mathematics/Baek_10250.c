#include <stdio.h> //ǥ�� �������� 
#pragma warning(disable:4996) //scanf()�� ANSI C�Լ� ���� �޼��� ����

/*
https://www.acmicpc.net/problem/10250
*/

int main() {

	int H = 0; //ȣ�� ����
	int W = 0; //ȣ�� ���� �� ����
	int N = 0; // N��° �մ�
	int Test,t;
	int ans[999];

	scanf("%d", &Test);

	for (t = 0; t < Test; t++) {

		scanf("%d%d%d", &H,&W,&N);

		int Y = N % H; //�մ� H��� ���� ���ȣ�� ���. 101,201,301,...
		//�� ȣ���� ������ �˷��ִ� ��
		int X = N / H + 1; //���ȣ

		if (Y != 0) {
			ans[t] = 100 * Y + X;
		}
		else {
			int ex = X - 1;
			ans[t] = 100 * H + ex;
			
		}
		H, W, N = 0;
	}
	
	for (t = 0; t < Test; t++) {
		printf("%d\n", ans[t]);
	}

	return 0;
} //�¾ҽ��ϴ�!!