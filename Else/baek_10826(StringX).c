#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#pragma warning(disable:4996) 
#pragma warning(disable:4477) 
#define MAX 2500

int main() {

	int inputNum;	
	scanf("%d", &inputNum);

	short numArr_1[MAX] = { 0 };
	short numArr_2[MAX] = { 0};
	short fiboNumArr[MAX] = { 0 };

	numArr_2[0] = 1;

	if (inputNum == 1) { 
		printf("1"); 
		return 0; 
	}

	else if (inputNum == 0) { 
		printf("0"); 
		return 0; 
	}

	int currentSum, judgementNum;

	// �����ڸ��� 0��°�� ������ ����� ����� ���ϰ� �Ѵ�. ���߿� ����� ���� �ڿ������� ���
	for (int iterate = 2; iterate <= inputNum; iterate++) {

		// �տ��� ���ߴ� ���ڵ��� 10�̸��̸� -1, �̻��̸� 1�� ó��. 
		// if ���ǹ� �Ǵܿ� ���� judgementNum
		judgementNum = -1;

		for (int idx = 0; idx < MAX; idx++) {

			if (judgementNum == 1) {
				currentSum = numArr_1[idx] + numArr_2[idx] + 1;
			}
			else {
				currentSum = numArr_1[idx] + numArr_2[idx];
			}

			if (currentSum >= 10) {
				fiboNumArr[idx] = currentSum % 10;
				fiboNumArr[idx + 1] = 1;
				judgementNum = 1;
			}
			else {
				fiboNumArr[idx] = currentSum;
				judgementNum = -1;
			}
		}
		memcpy(numArr_1, numArr_2, sizeof(numArr_2));
		memcpy(numArr_2, fiboNumArr, sizeof(fiboNumArr));
	}

	for (int k = MAX-1; k >= 0; k--) {

		if (fiboNumArr[k] != 0) {
			for (int t = k; t >= 0; t--) {
				printf("%d", fiboNumArr[t]);
			}
			return 0;
		}
	}

}
