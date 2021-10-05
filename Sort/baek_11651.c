#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#pragma warning(disable:4996) 
#pragma warning(disable:4477) 

#define X 0
#define Y 1
#define MAX 100005

/*
����ü Ÿ���� �迭���� �� �迭�� �����ϴ� Ű�� �ٲٴ� ����
*/

typedef struct _coordinate {
	int x;
	int y;
} cord;

cord inputArr[MAX] = { 0 };

// == QuickSort ==

// �迭 �ΰ��� �ٲٱ�
void Swap(cord arr[], int idx1, int idx2)
{
	cord temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

// �迭 ���� ���� �ɰ��� (�ɰ� index ����)
int Partition(cord arr[], int left, int right) {

	int pivot = arr[left].y; // �ǹ��� ��ġ�� ���� ����! (��)
	int low = left + 1; // low �� �ǹ� �����ʿ��� ���� (index)
	int high = right; // high �� right ���� ���� (index)

	// 
	while (low <= high) {
		//low ���� �̵�, pivot ���� ū ���� ����������
		while (arr[low].y <= pivot && low <= high) {
			low++;
		}

		// high ���� �̵�, pivot ���� ���� ���� ����������!
		// �����־��� (high�ε� low�� ������)
		while (arr[high].y >= pivot && high >= (left + 1)) {
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
void QuickSort(cord arr[], int left, int right)
{
	if (left <= right)
	{
		int pivot = Partition(arr, left, right); // pivot ���ϰ�, �ѷ��ɰ�
		QuickSort(arr, left, pivot - 1); // pivot ���ʿ����� ������
		QuickSort(arr, pivot + 1, right); // pivot �����ʿ�����������
	}
}

void QuickSortMain(cord arr[], int n)
{
	QuickSort(arr, 0, n - 1);
}

// ==== 
void QuickSort_X(cord arr[], int left, int right)
{
	if (left <= right)
	{
		int pivot = Partition_X(arr, left, right); // pivot ���ϰ�, �ѷ��ɰ�
		QuickSort_X(arr, left, pivot - 1); // pivot ���ʿ����� ������
		QuickSort_X(arr, pivot + 1, right); // pivot �����ʿ�����������
	}
}

void QuickSortMain_X(cord arr[], int start, int end)
{
	QuickSort_X(arr, start, end);
}

int Partition_X(cord arr[], int left, int right) {

	int pivot = arr[left].x; // �ǹ��� ��ġ�� ���� ����! (��)
	int low = left + 1; // low �� �ǹ� �����ʿ��� ���� (index)
	int high = right; // high �� right ���� ���� (index)

	// 
	while (low <= high) {
		//low ���� �̵�, pivot ���� ū ���� ����������
		while (arr[low].x <= pivot && low <= high) {
			low++;
		}

		// high ���� �̵�, pivot ���� ���� ���� ����������!
		// �����־��� (high�ε� low�� ������)
		while (arr[high].x >= pivot && high >= (left + 1)) {
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
// ==Additional Method==

// y���� ������ x��ǥ�� �����ؾ� �ϴϱ� 
void x_cord_sort(int N) {
	for (int i = 0; i < N - 1; i++) {
		// ���� i��° y���� i+1���� y���� ������ ���� ����.
		if (inputArr[i].y == inputArr[i + 1].y) {
			int startIdx = i; // ������ġ 
			int tempIdx = i + 1; // �ӽ���ġ����
			// i+1���� �� y���� ���� ��ǥ�� �ִ��� �˻� 
			while (inputArr[tempIdx].y == inputArr[tempIdx + 1].y) {
				tempIdx++;
			}
			int endIdx = tempIdx; // �� ã������ ������ ��ġ�� ����
			i = endIdx; // endIdx�������� �ٽ� ã���� �ǹǷ�

			// ���� �����Ѵ�.
			QuickSortMain_X(inputArr, startIdx, endIdx);
		}
	}
}

void setData(int N) {
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &inputArr[i].x, &inputArr[i].y);
	}
}

void printData(int N) {
	for (int i = 0; i < N; i++) {
		printf("%d %d\n", inputArr[i].x, inputArr[i].y);
	}
}

int main() {

	int N;
	scanf("%d", &N);

	setData(N);
	QuickSortMain(inputArr, N);

	// �̻����� �迭���� y���� ������ �ִ��� ���� 
	x_cord_sort(N);

	printData(N);

	return 0;
} // �¾ҽ��ϴ�! 

// 11650�̶� �Ȱ��������� �׳�