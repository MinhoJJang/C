#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <math.h>
#pragma warning(disable:4996) 
#pragma warning(disable:4477) 
#define DIGIT_NUM 10

// https://www.acmicpc.net/problem/1436

int main() {

	int index;
	scanf("%d", &index);
	
	int count = 0; // ���ڿ����� 666�� ã���� +1
	int num = 665; //  num�� 1�� �ø��� comp_idx�� �ְ� ���ڿ� ���Ұ���
	
	while (index != count) {

		char comp_idx[DIGIT_NUM] = { 0 }; // ���� �ڸ��� 
		num++;
		sprintf(comp_idx, "%d", num);

		char *findit = strstr(comp_idx, "666");
		if (findit) {
			count++;
		}
	}

	printf("%d", num);

	return 0;
}