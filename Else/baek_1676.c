#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#pragma warning(disable:4996) 
#pragma warning(disable:4477) 

/*
N!���� �ڿ������� ó�� 0�� �ƴ� ���ڰ� ���� ������ 0�� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/

// �ڿ� 0�� ��������, 2�� 5�� 1���� �־�� �Ѵ�. �� ������ ����.

#define MAX 502
#define TWO 0
#define FIVE 1

int arr[MAX][2] = { 0 };
int totalTwo = 0;
int totalFive = 0;

void NumberOfTwoAndFive(int N) {

	while (N > 1) {
		int Test;

		// 2�� ����
		Test = N;
		while (Test % 2 == 0) {
			arr[N][TWO]++;
			Test /= 2;
		}

		// 5�� ����
		Test = N;
		while (Test % 5 == 0) {
			arr[N][FIVE]++;
			Test /= 5;
		}

		totalTwo += arr[N][TWO];
		totalFive += arr[N][FIVE];
		N--;
	}
}

int findZero() {
	if (totalFive > totalTwo) {
		return totalTwo;
	}
	return totalFive;
}

int main() {

	int N;
	scanf("%d", &N);
	
	NumberOfTwoAndFive(N);
	printf("%d", findZero());

	return 0;
}