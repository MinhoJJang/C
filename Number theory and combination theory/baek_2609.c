#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#pragma warning(disable:4996) 
#pragma warning(disable:4477) 

/*
�� ���� �ڿ����� �Է¹޾� �ִ� ������� �ּ� ������� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

ù° �ٿ��� �� ���� �ڿ����� �־�����. �� ���� 10,000������ �ڿ����̸� ���̿� �� ĭ�� ������ �־�����.
*/

/*
1. �ִ����� 

ū ���� a, ���� ���� b��� �ϸ�



2. �ּҰ����
�ִ������� ã������, �־��� ���� �ִ������� ������ �� ������ �ּҰ������ ���� ���� �ִ������� ���Ѵ�. 
*/

// greatest common measure = GCM
// least common multiple = LCM



// �ִ����� ã��
int fnGCM(int a, int b) {

	// a,b�߿� ū ���� 
	int big = (a > b) ? a : b;
	int small = a + b - big;

	int smallerOne = (small < big - small) ? small : big - small;

	int div = 2;
	int ans = 1;
	// ���� a,b ���� �ϳ��� 1�ΰ�� 
	if (a == 1 || b == 1) {
		ans *= 1;
	}
	// a == b�� ���
	if (a == b) {
		ans *= a;
	}
	else {
		while (div <= smallerOne) {
			if (a%div == 0 && b%div == 0) {
				ans *= div;
				a /= div;
				b /= div;
			}
			else {
				div++;
			}
		}
	}

	return ans;
}

// �ּҰ���� ã��
int fnLCM(int a, int b) {

	int gcm = fnGCM(a, b);
	
	int LCM_a = a / gcm;
	int LCM_b = b / gcm;

	int ans = LCM_a * LCM_b * gcm;

	return ans;
}

int main() {

	int a;
	int b;

	scanf("%d %d", &a, &b);

	printf("%d\n", fnGCM(a, b));
	printf("%d\n", fnLCM(a, b));

	return 0;
}