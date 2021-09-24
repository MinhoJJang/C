#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#pragma warning(disable:4996) 
#pragma warning(disable:4477) 

/*https://www.acmicpc.net/problem/2798
������ ������ ���迡�� �� ī�忡�� ���� ������ ���� �ִ�. �� ����, ������ N���� ī�带 ��� ���ڰ� ���̵��� �ٴڿ� ���´�. �׷� �Ŀ� ������ ���� M�� ũ�� ��ģ��.

���� �÷��̾�� ���ѵ� �ð� �ȿ� N���� ī�� �߿��� 3���� ī�带 ���� �Ѵ�. ���� ���� �����̱� ������, �÷��̾ �� ī���� ���� M�� ���� �����鼭 M�� �ִ��� ������ ������ �Ѵ�.

N���� ī�忡 ���� �ִ� ���ڰ� �־����� ��, M�� ���� �����鼭 M�� �ִ��� ����� ī�� 3���� ���� ���� ����Ͻÿ�.
*/

#define MAXNUMBER_CARD	105
#define MAX_ABLE_NUMBEROFSUM 200000
#define FIND_ANSWER 0


int main() {

	int numberofCards;
	int sumYouWant;

	int numberWrittenOnCard[MAXNUMBER_CARD];

	scanf("%d %d", &numberofCards, &sumYouWant);

	for (int i = 0; i < numberofCards; i++) {
		scanf("%d", &numberWrittenOnCard[i]);
	}

	int first;
	int second; 
	int third;

	// 0 1 2 3 4 5

	int sumStorage[MAX_ABLE_NUMBEROFSUM] = { 0 };
	int minimumDifference = sumYouWant;
	int differenceInNumbers;

	int idx = 0;
	int i = 0;

	for (first = numberWrittenOnCard[i]; i < numberofCards - 2; i++) {
		
		int j = i + 1;

		for (second = numberWrittenOnCard[j]; j < numberofCards - 1; j++) {

			int k = j + 1;

			for (third = numberWrittenOnCard[k]; k < numberofCards; k++) {

				sumStorage[idx] = numberWrittenOnCard[i]+ numberWrittenOnCard[j]+ numberWrittenOnCard[k];
				differenceInNumbers = sumYouWant - sumStorage[idx];

				if (differenceInNumbers == 0) {
					printf("%d", sumYouWant - differenceInNumbers);
					return FIND_ANSWER;
				}
				else if (minimumDifference > differenceInNumbers && differenceInNumbers >= 0) {
					minimumDifference = differenceInNumbers;
				}

				idx++;
			}
		}
	}

	printf("%d", sumYouWant - minimumDifference);

	return 0;
}