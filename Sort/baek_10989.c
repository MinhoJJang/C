#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi ..�����޸�, ����, ���ڿ� ��ȯ
#include <string.h> //strcpy.. ���ڿ��Լ�. memcpy.. �޸𸮺� �Լ�
#pragma warning(disable:4996) // scnaf() �� ���� c�Լ��� ���۹���. 
#pragma warning(disable:4477) // unsigned <--> signed ���� warning ���� 

#define MAX 10002
int arr[MAX] = { 0 };

void printArr(int N) {

	// �Էµ� ���� �ڿ����̹Ƿ� 
	int idx = 1;
	int k;
	
	for (k = arr[idx]; idx < MAX; idx++) {
		
		for (int i = 0; i < k; i++) {
			printf("%d\n", idx);
		}

		k = arr[idx + 1];
	}

}

void inputData(int N) {
	int idx;
	for (int i = 0; i < N; i++) {
		scanf("%d", &idx);
		arr[idx]++;
	}
}

int main() {

	int N;
	scanf("%d", &N);
	inputData(N);
	printArr(N);

	return 0;
} // �޸��ʰ�????? 

// 1. �Է����������� �ʰ� Ǫ�� ��
// 2. �ԷµǴ� ������ ������ 10000�� ���̹Ƿ�, �̰��� �̿�
// ����?

// �迭 arr[10005] = {0};�� �����, �Էµ� ���ڰ� i�� arr[i]++�ǵ��� ������.

// �¾ҽ��ϴ�!! 