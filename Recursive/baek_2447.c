#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#pragma warning(disable:4996) 
#pragma warning(disable:4477) 
#pragma warning(disable:4828) 

#include <math.h>
/*
https://www.acmicpc.net/problem/2447
����
������� �������� ���� ��� ����. N�� 3�� �ŵ�����(3, 9, 27, ...)�̶�� �� ��, ũ�� N�� ������ N��N ���簢�� ����̴�.

ũ�� 3�� ������ ����� ������ �ְ�, ����� ������ ��� ĭ�� ���� �ϳ��� �ִ� �����̴�.

***
* *
***
N�� 3���� Ŭ ���, ũ�� N�� ������ �������� ä���� ����� (N/3)��(N/3) ���簢���� ũ�� N/3�� �������� �ѷ��� �����̴�. ���� ��� ũ�� 27�� ������ ���� ��� 1�� ����.

�Է�
ù° �ٿ� N�� �־�����. N�� 3�� �ŵ������̴�. �� � ���� k�� ���� N=3k�̸�, �̶� 1 �� k < 8�̴�.

���
*/

#define MAX 10000
#define SUPER_MAX 531500

char save[SUPER_MAX];
// In C, if the array becomes too large, it must be declared as a global variable.

int printarr(int N, char(*board)[MAX]) {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%c", board[i][j]);
		}
		printf("\n");
	}

	return 0;
}

int fnStar(int N, char(*board)[MAX], int FirstN) {

	// Start with N = 3;
	// FirstN is Input number

	int Center = N / 3; 
	// Center = 1/3 of N 
	// Because I have to put it in 3x3

	if (N == 3) {

		// create star
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				board[i][j] = '*';
			}
		}

		// delete star
		for (int i = Center; i < Center * 2; i++) {
			for (int j = Center; j < Center * 2; j++) {
				board[i][j] = ' ';
			}
		}
	}

	else {

		// Put everything on the existing board 
		// in a one-dimensional arrangement one by one. 
		int idx = 0;

		for (int i = 0; i < Center; i++) {
			for (int j = 0; j < Center; j++) {
				save[idx++] = board[i][j];
			}
		}

		// create star
		int x = 0;
		int y = 0;

		while (x != N) {
			idx = 0;
			for (int i = x; i < x + Center; i++) {
				for (int j = y; j < y + Center; j++) {
					board[i][j] = save[idx++];
				}
			}
			if (y == Center * 2) {
				y = 0;
				x = x + Center;
			}
			else {
				y = y + Center;
			}
		}

		// delete star 
		for (int i = Center; i < 2 * Center; i++) {
			for (int j = Center; j < 2 * Center; j++) {
				board[i][j] = ' ';
			}
		}
	}

	if (N == FirstN) {
		return printarr(N, board);
	}

	return fnStar(N * 3, board, FirstN);
}

char board[MAX][MAX];

int main() {

	int N;
	scanf("%d", &N);
	fnStar(3, board, N);

	return 0;
} // �¾ҽ��ϴ�!