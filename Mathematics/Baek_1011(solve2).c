#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#pragma warning(disable:4996) 
#pragma warning(disable:4477) 
#include <math.h>
/*

*/

#define MAX 3000

int main() {

	long start, end, range, temp;
	int Test, t;

	// ������ y-x�� �߿��ѰŴϱ�, �� ������ �迭�� ������ 

	scanf("%d", &Test);

	long ans[MAX] = { 0 };

	for (t = 0; t < Test; t++) {

		scanf("%d%d", &start, &end);

		range = end - start;
		temp = sqrt(range);
	
		while (1) {
			if (range - temp * temp <= 0) {
				break;
			}
			temp++;
		}

		if (range > temp*temp - temp) {
			ans[t] = 2 * temp - 1;
		}
		else {
			ans[t] = 2 * temp - 2;
		}
	}

	for (t = 0; t < Test; t++) {
		printf("%d\n", ans[t]);
	}

	return 0;
} 

// int ���� �ð��ʰ�����... long���� �ٲٴ� �ٷ� ����� 
// temp�������� int������ �ʰ��ع����� ���� while����..�ʹ����̵��Ե� 