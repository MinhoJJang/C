#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#pragma warning(disable:4996) 
#pragma warning(disable:4477) 
#define MAX_LENGTH 10005
#define SIZE 2750

char fibo[MAX_LENGTH][SIZE];

// ���� Ư���� �迭�� ��´�. �̶� ������ �迭�� 0��° �Ǻ���ġ ���� arr[0]�� ���, 1��° ���� arr[1]�� ���...�̷�������..!
int sizeArr(int N) {

	if (N == 0) {
		return 0;
	}

	int cnt = 0;
	int i = 0;

	if (N == 200) {

	}

	while (fibo[N][i] != '\0') {
		i++;
		cnt++;
	}

	return cnt-1;
}

char fn(int N, int FirstN) {

	char isTen[SIZE][1] = { 0 };

	if (N == 0) {
		fibo[N][0] = '0';
	}
	else if (N == 1) {
		fibo[N][0] = '1';
	}
	else {

		
		int lengthCount = 0;

		// ���Ϸ��� ���ڿ��� �����ľ�. 
		int lengthOfArr1 = sizeArr(N - 1);
		int lengthOfArr2 = sizeArr(N - 2);
		// Arr1 >= Arr2 
		int save = lengthOfArr1;

		// ���̰� �� �� �迭�� 0��°�� �����ϰ� �� �ڿ��� ���� �� ����
		// ������ ���� 5+8 = 13�̷� �����..?
		while (lengthOfArr1>=0) {
							
			int check = 0;
			
			if (lengthOfArr2 >= 0) {
			
				check = fibo[N - 1][lengthOfArr1] + fibo[N - 2][lengthOfArr2] + isTen[lengthCount][0] - '0' - '0';
			}
			else {
				check = fibo[N - 1][lengthOfArr1] + isTen[lengthCount][0] - '0';
			}
			
			if (isTen[lengthCount][0] == '1') {
				check -= '0';
			}

			// ���� ���� 10�� ���� ������
			if (check < 10) {
				fibo[N][lengthOfArr1+1] = check + '0' ;
			}
			// 10�� ������ 
			else {
				// ���� �ڸ����� ���Ҵµ� ������ �� �� �ڸ����� �þ��...?
				isTen[lengthCount + 1][0] = '1'; // ���� ���� 10���ڸ��� �÷��ְ�
				fibo[N][lengthOfArr1 + 1] = check - 10 + '0';
				
			}


			lengthOfArr1--;
			lengthOfArr2--;

			lengthCount++;

			

		}

		// ���� ������ �ڸ����� ����, ����� �ڸ����� 1 �þ�ٸ�
		if (lengthOfArr1 == -1 && isTen[lengthCount][0] == '1') {
			fibo[N][0] = '1';
		}
		// ���� ���� ���� ���� �ڸ����� ������ �ʾҴٸ�
		else {
			int k = 0;
			while (k <= save) {
				fibo[N][k] = fibo[N][k + 1];
				k++;
			}
			fibo[N][k] = '\0';
		}
	}

	if (N == FirstN) {
		return 0;
	}

	return fn(N + 1, FirstN);
}

int main() {

	int N;
	
	scanf("%d", &N);
	fn(0, N);

	int i = 0;
	while(fibo[N][i] != 0){ 
		printf("%c", fibo[N][i]);
		i++;
	}

	return 0;
}
// 200�ʰ����� �����ϰ� �״µ� �� ������
// �ƴ� ���� �����Ϸ������� �Ǵµ� ??????????�������� 