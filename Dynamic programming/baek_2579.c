#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#pragma warning(disable:4996) 
#pragma warning(disable:4477) 
#define MAX 310

int maxSum[MAX];
int stair[MAX];

//��ܰ� �Է��Լ�
void inputNum(int N) {
	for (int i = 1; i < N+1; i++) {
		scanf("%d", &stair[i]);
	}
}

// N��° ��ܱ����� �ִ��� ���ϴ� �Լ�
int fn(int N) {

	if (N == 1) {
		maxSum[N] = stair[N];
	}
	else if (N == 2) {
		maxSum[N] = stair[N] + stair[N-1];
	}
	else if (N == 3) {
		maxSum[N] = (stair[N - 2] >= stair[N - 1]) ? stair[N - 2] + stair[N] : stair[N - 1] + stair[N];
	}
	// N�� 3�ʰ��̰� maxSum���� �𸣸�..
	else if( maxSum[N] == 0){
		maxSum[N] = (fn(N - 2) > fn(N - 3) + stair[N - 1]) ? maxSum[N - 2] + stair[N] : maxSum[N - 3] + stair[N - 1] + stair[N];
	}
	// ??? ��°�� ������ �ٲ�µ� ���� �ٸ���?

	return maxSum[N];
}


int main() {

	int N;
	scanf("%d", &N);

	inputNum(N);
	printf("%d", fn(N));

	return 0;
}

// �̹����� ��¥ ���Ը��ڴ�^^ 