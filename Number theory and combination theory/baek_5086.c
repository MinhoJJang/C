#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#pragma warning(disable:4996) 
#pragma warning(disable:4477) 

/*
https://www.acmicpc.net/problem/5086
4 �� 3 = 12�̴�.

�� ���� ���� ������ ���� ����� �� �� �ִ�.

3�� 12�� ����̰�, 12�� 3�� ����̴�.

4�� 12�� ����̰�, 12�� 4�� ����̴�.

�� ���� �־����� ��, ���� 3���� �� � �������� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

ù ��° ���ڰ� �� ��° ������ ����̴�.
ù ��° ���ڰ� �� ��° ������ ����̴�.
ù ��° ���ڰ� �� ��° ������ ����� ��� ��� �ƴϴ�.
*/

#define FACTOR 1
#define MULTIPLE 2
#define NEITHER 3

int fn(int a, int b) {

	if (a%b == 0 && a > b) {
		return MULTIPLE;
	}
	else if (b > a && b%a == 0) {
		return FACTOR;
	}
	else {
		return NEITHER;
	}
}

int main() {

	int a;
	int b;

	int save;

	while (1) {
		scanf("%d %d", &a, &b);

		if (a == 0 && b == 0) {
			break;
		}

		save = fn(a, b);

		if (save == 1) {
			printf("factor\n");
		}
		else if (save == 2) {
			printf("multiple\n");
		}
		else {
			printf("neither\n");
		}
	}

	return 0;
} // �¾ҽ��ϴ�!! 