#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#pragma warning(disable:4996) 
#pragma warning(disable:4477) 

#define X 0
#define Y 1

int fn_x(int N, int(*arr)[2]) {

	// �⺻������ �� �־��ְ� 
	if (N == 0) {

		arr[N][X] = 1;
		return arr[N][X];
	}
	else if (N == 1) {

		arr[N][X] = 0;
		return arr[N][X];
	}

	// ���� ã������ arr�� N��° �迭�� �ƹ��� ���� ���ٸ� 
	if (arr[N][X] == 0) {

		arr[N][X] = fn_x(N - 1, arr) + fn_x(N - 2, arr);
		return arr[N][X];
		// �ٽ����� ����. arr�� fn_x(N, ~)���� ��������ν� �ٷιٷ� ��� ����ǵ��� ����. 	
	}
	// ���� �ִٸ�
	else {
		return arr[N][X];
	}
}

int fn_y(int N, int(*arr)[2]) {

	// �⺻������ �� �־��ְ� 
	if (N == 0) {

		arr[N][Y] = 0;
		return arr[N][Y];
	}
	else if (N == 1) {

		arr[N][Y] = 1;
		return arr[N][Y];
	}

	// ���� ã������ arr�� N��° �迭�� �ƹ��� ���� ���ٸ� 
	if (arr[N][Y] == 0) {

		arr[N][Y] = fn_y(N - 1, arr) + fn_y(N - 2, arr);
		return arr[N][Y];
		// ����Ǯ�̿� �ٽ����� ����. arr�� fn_y(N, ~)���� ��������ν� �ٷιٷ� ��� ����ǵ��� ����. 	

		// ó���� return fn_y(N - 1, arr) + fn_y(N - 2, arr); �ؼ� �ð��ʰ�����. 
	}
	// ���� �ִٸ�
	else {
		return arr[N][Y];
	}
}

void showArr(int Testcase, int(*arr)[2]) {

	for (int i = 0; i < Testcase; i++) {
		printf("%d %d\n", arr[i][0], arr[i][1]);
	}

}

int main() {

	int Testcase;
	int testArr1[100][2] = { 0 };
	int ansArr[100][2] = { 0 };
	int N;

	scanf("%d", &Testcase);

	for (int i = 0; i < Testcase; i++) {

		scanf("%d", &N);
		
		ansArr[i][0] = fn_x(N, testArr1);
		ansArr[i][1] = fn_y(N, testArr1);
	}

	showArr(Testcase, ansArr);

	return 0;
} // �¾ҽ��ϴ�! 