#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#pragma warning(disable:4996) 
#pragma warning(disable:4477) 

/*
���� �ް�, 10���� ���� �������� ��� �迭�� �ִ´�. �׸��� �� �迭�� �����ϸ� ��.. �� ���� 
*/
void BubbleSort(int arr[], int n) 
{
	int i, j;
	int temp;

	for (i = 0; i < n - 1; i++) {
		
		for (j = 0; j < (n - i) - 1; j++) {

			if (arr[j] > arr[j + 1]) 
			{
				temp = arr[j];		
				arr[j] = arr[j + 1]; 
				arr[j + 1] = temp;
			}
		}
	}
}

int main() {

	long N;
	scanf("%d", &N);

	int arr[11] = { 0 };
	int currentNum = N;
	int idx = 0;

	while (currentNum != 0) {
		arr[idx] = currentNum % 10;
		currentNum -= arr[idx];
		currentNum /= 10;
		idx++;
	}
	
	BubbleSort(arr, idx);

	for (int i = idx - 1; i >= 0; i--) {
		printf("%d", arr[i]);
	}

	return 0;
} // �¾ҽ��ϴ�