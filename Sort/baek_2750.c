#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#pragma warning(disable:4996) 
#pragma warning(disable:4477) 

/*
https://www.acmicpc.net/problem/2750

N���� ���� �־����� ��, �̸� ������������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/


// �ܼ��ϰ� 1��2��, 2��3��, 3��4�� �̷��� ���Ͽ� n-1��n�� ���� �����ϴ°� 1����Ŭ. �׷��� ����Ŭ�� �ݺ��Ѵ�. 
void BubbleSort(int arr[], int n) // ���� ����
{
	int i, j;
	int temp;

	// cycle ȸ�� Ƚ��
	for (i = 0; i < n - 1; i++) {

		// ��Ƚ��
		for (j = 0; j < (n - i) - 1; j++) {

			// 1. ������ �ΰ� �� 
			if (arr[j] > arr[j + 1]) // 2. ũ�Ⱑ �ݴ���.. <<��>>
			{
				temp = arr[j];		 // <<�̵�>> �� ����Ŭ�� �ִ� (n-i)-1�� �߻� (�׳� �� for���� j�ִ�ġ��ŭ �߻��Ѵٴ� �Ҹ���)
				arr[j] = arr[j + 1]; // <<�̵�>>
				arr[j + 1] = temp;  // <<�̵�>>
			}
		}
	}
}

// 1���� 2��~n������ �����鼭 ���� ���� ���� ��ġ�� �ٲ�. �׷��� '����'������. ���� ���� ���� '����'�ϴϱ�
void SelectionSort(int arr[], int n) {

	int i, j;
	int temp;

	for (i = 0; i < n - 1; i++) // �� ����Ŭ Ƚ�� = n- 1��
	{
		int index = i;

		for (j = i + 1; j < n; j++)
			// �� arr[i] �� arr[i+1]~arr[n-1]����
		{
			if (arr[index] > arr[j]) {
				// arr[index]������ '��' �������� ã�ƾ��ϴϱ� if ���ǽ��� ������ ���� �� �´�. ���� ó���� arr[i] > arr[j] ��� �Ἥ ������ �����. 
				//<<��>>
				index = j;
			}
		}

		if (index != i)
		{
			temp = arr[i];			 // <<�̵�>> 1����Ŭ�� ���ƾ� 1��. 
			arr[i] = arr[index];	 // <<�̵�>>
			arr[index] = temp;		 // <<�̵�>>
		}
	}
}

// n���� ������ �߿��� �տ������� i�� ��ŭ�� �����Ѵ�. ���� ����� �������İ� ����ϳ� �ڿ������� ���Ľ����Ѵٴ� ��, ���ĵ� �������� break�ȴٴ� ������ ���̰� ����. 
void InsertionSort(int arr[], int n)
{
	int i, j;
	int insData; // ������ �ӽ� ������

	for (i = 1; i < n; i++) {

		insData = arr[i];

		for (j = i - 1; j >= 0; j--) {
			if (insData < arr[j]) { // ��
				arr[j + 1] = arr[j];	  // <<�̵�>>
				// �ٷ� �ٷ� �� �ٲ��־����
				// P.S. �׳� ��ġ�� ã�°� �� ������ ������? ���� �ٲٴ°ͺ���..? 
				// ������ ��ġ�� ã�Ƶ� �ڸ��̵��ؾ��ϳ�..
			}
			else {
				break;
			}
		}
		arr[j + 1] = insData;  // <<�̵�>> 1����Ŭ�� 1��
	}
}

#define MAX 1005
int arr[MAX];

void printArr(int N) {
	for (int i = 0; i < N; i++) {
		printf("%d\n", arr[i]);
	}
}

void inputData(int N) {
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
}

int main() {

	int N;
	scanf("%d", &N);

	inputData(N);
	//InsertionSort(arr, N);
	//BubbleSort(arr, N);
	SelectionSort(arr, N);
	printArr(N);



	return 0;
}