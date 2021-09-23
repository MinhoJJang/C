#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#pragma warning(disable:4996) 
#pragma warning(disable:4477) 

/*https://www.acmicpc.net/problem/2231
� �ڿ��� N�� ���� ��, �� �ڿ��� N�� �������� N�� N�� �̷�� �� �ڸ����� ���� �ǹ��Ѵ�. � �ڿ��� M�� �������� N�� ���, M�� N�� �����ڶ� �Ѵ�. ���� ���, 245�� �������� 256(=245+2+4+5)�� �ȴ�. ���� 245�� 256�� �����ڰ� �ȴ�. ����, � �ڿ����� ��쿡�� �����ڰ� ���� ���� �ִ�. �ݴ��, �����ڰ� ���� ���� �ڿ����� ���� �� �ִ�.

�ڿ��� N�� �־����� ��, N�� ���� ���� �����ڸ� ���س��� ���α׷��� �ۼ��Ͻÿ�.
*/

// �Էµ� ���� N�̸� N�� 1�� ���� �� �������� ���ؼ� �� ���� ���� N�̸� ����

int fn(int N, int FirstN) {

	int sum = 0;
	int basic = N;
	int rest;

	do {

		rest = basic % 10;
		basic = basic / 10;
		sum += rest;

	} while (basic != 0);

	if (FirstN == sum + N) {
		return N;
	}

	if (N == FirstN+1) {
		return 0;
	}

	return fn(N + 1, FirstN);
}

int main() {

	int N;
	scanf("%d", &N);
	printf("%d", fn( 1, N));

	return 0;
}