#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#pragma warning(disable:4996) 
#pragma warning(disable:4477) 

//https://www.acmicpc.net/problem/10872
//����
//0���� ũ�ų� ���� ���� N�� �־�����.�̶�, N!�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
//
//�Է�
//ù° �ٿ� ���� N(0 �� N �� 12)�� �־�����.


int fn(int N) {

	if (N == 0) {
		return 1;
	}
	else {
		return N * fn(N - 1);
	}

}

int main() {

	int N;
	scanf("%d", &N);

	printf("%d", fn(N));


	return 0;
} // �¾ҽ��ϴ�!!