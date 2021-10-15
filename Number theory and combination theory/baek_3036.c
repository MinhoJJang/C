#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#pragma warning(disable:4996) 
#pragma warning(disable:4477) 

/*
����̴� â���� �� N���� �߰��ߴ�. ����̴� ������ ���� �տ� �ִ� ���� �ڿ� �ִ� ���� ���ϵ��� �ٴڿ� �������Ҵ�.

����̴� ù ��° ���� ������ �����߰�, ������ ���� ���� ���ư��ٴ� ����� �߰��ߴ�. ������ ���� ù ��° �� ���� ������ ���ư��⵵ �߰�, ������ ���ư��⵵ �ߴ�. �̷��� ���� ������ ���� ù ��° ���� �� ���� ������, ������ ���� �� ���� ������ �ñ�������.

���� �������� �־�����. �̶�, ù ��° ���� �� ���� ������, ������ ���� �� ���� ���ư����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/

/*
ù���� ���� ���ڷ� �ΰ�, �ڿ����� �и�� �ΰ� �� �м��� �ִ��� ����� ���� �� ���� 
*/
#define MAX 105
#define TRUE 1
#define FALSE 0

int arr[MAX] = { 0 };
int n;

// �����Ͱ� �ֱ� 
void putData() {

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
}

// ������ ���� 
int abs(int x) {
	if (x < 0) {
		return -x;
	}
	return x;
}

int printCurrentAnswer(int a, int b) {
	printf("%d/%d\n", a, b);
	return 0;
}

// ��� ã�� �Լ� 
// �̶� a�� �׻� arr[0] �̴�. 
int findAliquot(int a, int b) {

	int aliquot[MAX] = { 0 }; // ��������ϴ� �迭 
	int idx = 0; // �� �迭�� �ε��� 
	int flag = FALSE; // ������ �������� ������ FALSE, ������ �������� TRUE
	int mom = a; // �и�
	int son = b; // ���� 

	// 1. �� ���� ���� ������ ���Ѵ�. 
	int diff = abs(a - b);

	// ���� ���� ���̰� 0�� ���, ���� �׻� 1/1�̹Ƿ� 
	if (diff == 0) {
		return printCurrentAnswer(1, 1);
	}

	// 2. �� ������ ����� �迭�� �����Ѵ�. ����ϱ� i�� 2���� ����
	// ���ڰ� ũ�� Ư���ϰ� ã������ ������ 1000������ �׳� for�� ������ �����ϴٰ� �������� 
	for (int i = 2; i <= diff; i++) {
		if (diff % i == 0) {
			aliquot[idx++] = i;
		}
	}

	// 3. a,b�� ������ ������ ������ ����� ������...
	// - ���� ������ �������� ������, �׳� a,b�� �����Ѵ�. 
	// - ������ ��������, flag�� �����, �ϴ� for�� ������ �� ������ ���� �ٽ� �Լ��� ȣ���Ѵ�. �̶�, ���� Ȥ�� �и� 1�̸� �Լ�ȣ���� �����Ѵ�. 
	for (int i = 0; i < idx; i++) {
		if (mom % aliquot[i] == 0 && son % aliquot[i] == 0) {
			mom /= aliquot[i];
			son /= aliquot[i];
			if (mom == 1 || son == 1 || abs(mom - son) == 1) {
				break;
			}
			flag = TRUE;
		}
	}

	if (flag == FALSE) {
		return printCurrentAnswer(mom, son);
	}
	else {
		return findAliquot(mom, son);
	}
}

void printAns(int n) {

	int mother = arr[0];
	int sonidx = 1;

	while (sonidx != n) {
		// ans�� 0��° �ε����� ���ٰ� ġ��.. 
		// arr[0] / arr[1], arr[0] / arr[2] ... �̷���.. 

		// 1. �ϴ� ���� �и� ���̿� �����μ��� �ִ��� �˾ƾ� �Ѵ�. 
		// �Լ��� ������
		// �׸��� �ϴ� ���ڳ� �и� 1�̰ų� ���ڿ� �и��� ���� 1�̸� ������ ������ ���� �����Ƿ� �� ���� ���� 
		if (arr[0] == 1 || arr[sonidx] == 1 || abs(arr[0] - arr[sonidx]) == 1) {
			printCurrentAnswer(arr[0], arr[sonidx]);
		}
		else {
			findAliquot(arr[0], arr[sonidx]);
		}
		sonidx++;
	}
}

int main() {

	putData();
	printAns(n);

	return 0;
} // �¾ҽ��ϴ�!