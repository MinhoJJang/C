#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#pragma warning(disable:4996) 
#pragma warning(disable:4477) 

/*
���� ó���ϴ� ���� ����п��� ����� �߿��� ���̴�. ����п��� N���� ���� ��ǥ�ϴ� �⺻ ��谪���� ������ ���� �͵��� �ִ�. ��, N�� Ȧ����� ��������.

������ : N���� ������ ���� N���� ���� ��
�߾Ӱ� : N���� ������ �����ϴ� ������ �������� ��� �� �߾ӿ� ��ġ�ϴ� ��
�ֺ� : N���� ���� �� ���� ���� ��Ÿ���� ��
���� : N���� ���� �� �ִ񰪰� �ּڰ��� ����
N���� ���� �־����� ��, �� ���� �⺻ ��谪�� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

���������� arr[4002] = {0}; �� ����� �迭���� �� ���� ������ ��´�. 

���-> �Է¹����� ���ÿ� sum += x �׳��ϸ�ǰ�

�߾Ӱ�-> arr[idx] ���� ���ϴٰ� N/2�Ѵ¼��� �� idx���

�ֺ�-> arr[idx]�� �������� �����ϰ� �ֺ� ã��

���� -> ������ ������ �߿��� �� ó���� �� �� idx���� �� 
*/

// -4000 ~ +4000
#define MAX 8005
#define ABSOLUTE 4000

int arr[MAX] = { 0 };

double sum = 0;
double arithmetic_mean = 0;

int median_value = 0;
// N�� Ȧ���̹Ƿ�, �߾Ӱ��� N/2��°�� �ִ� ���̴�. 

int common_value = 0;
int maxRange = 0;

void inputData(int N) {
	int idx;
	for (int i = 0; i < N; i++) {
		scanf("%d", &idx);
		// �ּ� -4000, �ִ� 4000�� ���� �Էµ�. 
		// �� arr�� idx+4000��°�� ���� ���� ���� 
		// ���� 0�� �ԷµǸ� arr[4000]�� 0�� ������ ���°�
		// -4000�� �ԷµǸ� arr[0]�� ������ ���
		arr[idx+ABSOLUTE]++;
		sum += idx;
	}
}

// �Ҽ��� �Ʒ� ù° �ڸ����� �ݿø��� ���
void printArithmeticMean(int N) {

	arithmetic_mean = sum / N;

	printf("%.0f\n", arithmetic_mean);
}

void printMedianValue(int N) {

	int count = 0;
	int aim = N / 2 + 1;
	int currentIdx = 0;

	while (count < aim) {
		count += arr[currentIdx++];	
	}

	// ���� ���� idx-4000
	median_value = currentIdx - ABSOLUTE - 1;
	printf("%d\n", median_value);
}

#define INITIALIZE 0
#define FINDFIRST 1
#define FINDSECOND 2

void printCommonValue() {

	int flag; // �ϴ� ���� ū ���� ã���� flag�� �� ���� ����� �迭�� idx���� �����Ѵ�.
	int identify = INITIALIZE; // �ֺ��� ã�� ������ ���� �� ����
	int maxNum = 0;

	for (int idx = 0; idx < MAX; idx++) {

		// ���� �ֺ󰪺��� �� ū ���� ã����
		if (maxNum < arr[idx]) {
			maxNum = arr[idx];
			flag = idx;

			// ù��°�� ã�� �ֺ��̶�� �ǹ̷�.. 
			identify = FINDFIRST;
		}
		// ���� �ֺ󰪰� ���� ����, �ֺ��� 0�� �ƴҰ��
		else if (maxNum == arr[idx] && maxNum != 0) {
			// �̰� �ι�°�� ã�� �ֺ��̸� ���� �����Ѵ�. 
			if (identify == FINDFIRST) {
				flag = idx;
				identify = FINDSECOND;
			}
		}
	}

	common_value = flag - ABSOLUTE;
	printf("%d\n", common_value);
}

void printMaxRange() {

	int low = -1;
	int high = -1;
	int lowIdx = 0;
	int highIdx = MAX-1;

	while (low == -1) {
		if (arr[lowIdx] != 0) {
			low = lowIdx;
		}
		lowIdx++;
	}

	while (high == -1) {
		if (arr[highIdx] != 0) {
			high = highIdx;
		}
		highIdx--;
	}

	maxRange = high - low;

	printf("%d\n", maxRange);
}

int main() {

	int N;
	scanf("%d", &N);

	inputData(N);
	printArithmeticMean(N);
	printMedianValue(N);
	printCommonValue();
	printMaxRange();

	return 0;
} // �¾ҽ��ϴ�! 