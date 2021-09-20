#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#pragma warning(disable:4996) 
#pragma warning(disable:4477) 

/*
https://www.acmicpc.net/problem/1934

�� �ڿ��� A�� B�� ���ؼ�, A�� ����̸鼭 B�� ����� �ڿ����� A�� B�� �������� �Ѵ�. �̷� ����� �߿��� ���� ���� ���� �ּҰ������� �Ѵ�. ���� ���, 6�� 15�� ������� 30, 60, 90���� ������, �ּ� ������� 30�̴�.

�� �ڿ��� A�� B�� �־����� ��, A�� B�� �ּҰ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

ù° �ٿ� �׽�Ʈ ���̽��� ���� T(1 �� T �� 1,000)�� �־�����. ��° �ٺ��� T���� �ٿ� ���ļ� A�� B�� �־�����. (1 �� A, B �� 45,000)

��Ŭ���� ȣ���� -> a>b�ϋ� a�� b�� ���� �������� r�̶� ����. ���� b�� r�� ���� �������� r1�̶� ����. r�� r1���� ���� �������� ... �ؼ� �������� 0�� �� ���� ���� ���� �ٷ� �ּҰ����. 
*/

int ansArr[1005] = { 0 };

// �ּҰ���� ���ϱ�
int findGCM(int a, int b) {

	// x>y
	int x = (a > b) ? a : b;
	int y = a + b - x;

	int rest = x % y;
	if (rest == 0) {
		return y;
	}
	
	return findGCM(y, rest);
}

int findLCM(int a, int b) {

	return a * b / findGCM(a, b);
}

int setAns(int Testcase) {

	int a;
	int b;

	for (int i = 0; i < Testcase; i++) {
		scanf("%d%d", &a, &b);
		ansArr[i] = findLCM(a, b);
	}

	for (int i = 0; i < Testcase; i++) {
		printf("%d\n", ansArr[i]);
	}
}

int main() {

	int Testcase;
	scanf("%d", &Testcase);
	
	setAns(Testcase);

	return 0;
}