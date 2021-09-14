#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#pragma warning(disable:4996) 
#pragma warning(disable:4477) 

/*
 ������ �ű�� ������ġ�� ������ ¦������ Ȧ�������� ���� �޶���. 

 ������ Ȧ������ 1-3 ����
 ¦���� 1-2 ����

 ������ ù ������ �����ϰ�, �׻� ���� �� �ִ� ���� �߿��� ���� ���� �� ���� �ö󰡾� �Ѵ�. 



*/
#define MAX 1050000


int fnTotal(int N) {

	if (N == 1 || N == 0) {
		return 1;
	}
	else {
		return (fnTotal(N - 1) * 2) + 1;
	}
}


void printarr(int N, int(*arr)[2]) {

	int total = fnTotal(N);

	for (int i = 0; i < total; i++) {

		printf("%d %d \n", arr[i][0], arr[i][1]);
	}

}

int copyArr[MAX][2];
int newArr[MAX][2];

int fn(int N, int arr[][2], int firstN) {

	// newarr1�� arr���� �����ؾ���. 

	int total = fnTotal(N - 1);
	for (int i = 0; i < total; i++) {

		copyArr[i][0] = arr[i][0];
		copyArr[i][1] = arr[i][1];
	}

	int idx = 0;


	// �ϴ� �� ó���� 1-2���� 1-3���� �˾ƾ� ��
	if (idx == 0) { 

		newArr[idx][0] = 1;

		if (N % 2 == 1) {
			newArr[idx][1] = 3;
		}
		else {
			newArr[idx][1] = 2;
		}

		idx++;
	}


	if (N == 1) {
		return fn(N + 1, newArr, firstN);
	}
	else	if(N>1){

		// ���� �迭�� �ִ� ������ ���� �� �迭�� �Ű��ش�. 
		// �� �迭�� ������ fnTotal���� ��������. 

		for (int i = total-1; i >= 0; i--) {
			newArr[i * 2 + 1][0] = copyArr[i][0];
			newArr[i * 2 + 1][1] = copyArr[i][1];
		}

		// ���� ���� ���� �� ù��°�� ���� �־��ش�. 
		newArr[2][0] = newArr[0][1];
		newArr[2][1] = newArr[1][1];

		int j = 4;
		int newtotal = fnTotal(N);
		// �̰� �ι�° �迭�� 2-3�̳� 3-2�̳Ŀ� ���� �޶���
		if (newArr[2][0] == 2) {

			
			while (j < newtotal) {

				newArr[j][0] = newArr[j-2][1];
				newArr[j][1] = newArr[j][0] + 1;
				
				if (newArr[j][1] == 4) {
					newArr[j][1] = 1;
				}

				j = j + 2;
			}
		}
		else {
			while (j < newtotal) {

				newArr[j][0] = newArr[j - 2][1];
				newArr[j][1] = newArr[j][0] -1;

				if (newArr[j][1] == 0) {
					newArr[j][1] = 3;
				}

				j = j + 2;
			}
		}
	}
	if (N == firstN) {
		printarr(N, newArr);
		return 0;
	}
	return fn(N + 1, newArr, firstN);
	
}



int main() {

	int N;
	scanf("%d", &N);

	printf("%d\n", fnTotal(N));

	if (N == 1) {
		printf("1 3");
	}
	else {
		fn(1, copyArr, N);
	}


	return 0;
}