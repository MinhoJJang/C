#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <math.h>
#pragma warning(disable:4996) 
#pragma warning(disable:4477) 

#define INIT -1
#define NOTPRIME 0
/*
 �Ҽ� ã��
*/
int arr[101] = { 0 };

void putData(int N) {
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
}

int findPrimeNumber(int N) {
	
	int countPrime = 0;

	for (int i = 0; i < N; i++) {

		// ���� �־��� ���ڰ� �������̸� ������ �Ҽ��� �ƴϴϱ�.. ������ ���� ������ 1�� ���ҽ�Ű�鼭 ���������� �˻� 
		if (arr[i] != 1 && arr[i] != 2) {

			int squareRoot = sqrt(arr[i]);
			int flag = INIT;

			// 1�� �����ϰ� ������. 
			while (squareRoot > 1) {
				// ������ �������� �Ҽ��� �ƴ�
				if (arr[i] % squareRoot == 0) {
					flag = NOTPRIME;
					break;
				}
				squareRoot--;
			}

			// squareRoot�� 2���� ����������
			if (flag == INIT) {
				countPrime++;
			}
		}
		else if (arr[i] == 2) {
			countPrime++;
		}

	}

	return countPrime;
}

int main() {

	int N;
	scanf("%d", &N);

	putData(N);
	printf("%d", findPrimeNumber(N));

	return 0;
} // �¾ҽ��ϴ�