#include <stdio.h> //ǥ�� �������� 
#pragma warning(disable:4996) //scanf()�� ANSI C�Լ� ���� �޼��� ����

/*
https://www.acmicpc.net/problem/1011
�Է��� ù �ٿ��� �׽�Ʈ���̽��� ���� T�� �־�����. ������ �׽�Ʈ ���̽���
���� ���� ��ġ x �� ��ǥ ��ġ y �� ������ �־�����, x�� �׻� y���� ���� ����
���´�. (0 �� x < y < 2^31)
*/
			// ���� ��� ���̰� 9�� n=3���� break;
			// z�� (n-1)����< z <=n���� ����.
			// n������ 2n-1���� �̷���� ������ ������ ���̹Ƿ� 
			// z�� n���� - n < z �̸� 2n-1��, �ƴϸ� 2n-2��. 
			//16  17 18 19 20  21 22 23 24 25
			//7			8					9

int main() {

	int x, y, z;
	int Test,t;
	
	scanf("%d", &Test);

	int ans[100] = { 0 };

	for (t = 0; t < Test; t++) {

		scanf("%d%d", &x, &y);

		z = y - x;
		int n;

		for (n = 0; ; n++)
		{
			if (z - n * n <= 0) {
				break;
			}
		}			

		if (z > n*n - n) {
			ans[t] = 2 * n - 1;
		}
		else {
			ans[t] = 2 * n - 2;
		}

		x = 0;
		y = 0;
	}

	for (t = 0; t < Test; t++) {
		printf("%d\n", ans[t]);
	}

	return 0;
} //�ð��ʰ� 