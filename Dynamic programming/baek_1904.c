#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#pragma warning(disable:4996) 
#pragma warning(disable:4477) 

#define MAX 1005000

long arr[MAX];

long fn(int N) {

	if (N == 1 || N == 2) {
		arr[N] = N;	
	}
	else if (arr[N] == 0) {
		arr[N] = (fn(N - 2) + fn(N - 1)) % 15746;
	}
	return arr[N];

}

int main() {

	int N;
	scanf("%d", &N);

	printf("%d", fn(N));

	return 0;
} // �¾ҽ��ϴ�!!

/*
arr[N] = (fn(N - 2) + fn(N - 1)) % 15746;

�̷��Խ���ϴ� ����

(1 % 2) + (1 % 2) = 1 + 1 = 2

(1 + 1) % 2 = 0
*/