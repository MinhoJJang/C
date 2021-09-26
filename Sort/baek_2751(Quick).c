#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi ..�����޸�, ����, ���ڿ� ��ȯ
#include <string.h> //strcpy.. ���ڿ��Լ�. memcpy.. �޸𸮺� �Լ�
#pragma warning(disable:4996) // scnaf() �� ���� c�Լ��� ���۹���. 
#pragma warning(disable:4477) // unsigned <--> signed ���� warning ���� 


/*
https://www.acmicpc.net/problem/2751
ù° �ٿ� ���� ���� N(1 �� N �� 1,000,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� ���� �־�����. �� ���� ������ 1,000,000���� �۰ų� ���� �����̴�. ���� �ߺ����� �ʴ´�.
*/

// �迭 �ΰ��� �ٲٱ�
void Swap(int arr[], int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

// �迭 ���� ���� �ɰ��� (�ɰ� index ����)
int Partition(int arr[], int left, int right) {

	int pivot = arr[left]; // �ǹ��� ��ġ�� ���� ����! (��)
	int low = left + 1; // low �� �ǹ� �����ʿ��� ���� (index)
	int high = right; // high �� right ���� ���� (index)

	// 
	while (low <= high) {
		//low ���� �̵�, pivot ���� ū ���� ����������
		while (arr[low] <= pivot && low <= high) {
			low++;
		}

		// high ���� �̵�, pivot ���� ���� ���� ����������!
		while (arr[high] >= pivot && high >= (left + 1)) {
			high--;
		}

		// low�� high�� ���߸�
		if (low <= high) // low, high�� �������� ���� ���¶�� Swap ����
			Swap(arr, low, high);
	}

	// pivot�� high�� ����Ű�� ���ȯ
	Swap(arr, left, high);

	return high; // �Ű��� �ǹ��� ��ġ���� ����
}

// ��������� ������ ����
void QuickSort(int arr[], int left, int right)
{
	if (left <= right)
	{
		int pivot = Partition(arr, left, right); // pivot ���ϰ�, �ѷ��ɰ�
		QuickSort(arr, left, pivot - 1); // pivot ���ʿ����� ������
		QuickSort(arr, pivot + 1, right); // pivot �����ʿ�����������
	}
}

#define MAX 1000005
int newArr[MAX];

void printArr(int N) {
	for (int i = 0; i < N; i++) {
		printf("%d\n", newArr[i]);
	}
}

void inputData(int N) {
	for (int i = 0; i < N; i++) {
		scanf("%d", &newArr[i]);
	}
}

int main() {

	int N;
	scanf("%d", &N);

	inputData(N);
	QuickSort(newArr, 0, N-1);
	printArr(N);

	return 0;
} // �ð��ʰ� 