#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#pragma warning(disable:4996) 
#pragma warning(disable:4477) 

/*

������
C - D - B - A - E
1 - 2 - 3 - 4 - 5
Ű
C - A - B - D - E
1 - 2 - 3 - 4 - 5

���� �����԰� ū ���� ���� �迭 �ε����� ������ ��� 1�� �־��ְ� ,
A�� A���� ���ؼ� ���� �迭�� �ٽ� �ְ�, �ּڰ��� ã�Ƽ� �װź��� �ٽ� ����� �ִ´�. 
*/

int FindBigWeight(int NumberOfPeople, int weight[]) {

	// �����Ը� �迭�� ū ������� �����ϰ�, �� ����� ��ȣ�� ���������� 2���� �迭�� �ִ´�.

	// �ƴ���, ���Ʈ�����ϱ� �����ϰ� ���ϴ°ǰ�????

	// 












}

int FindBigHeight();

int main() {

	int NumberofPeople;
	int weight[55] = { 0 };
	int height[55] = { 0 };
	int MostHeavyWeight = 0;
	int MostTallHeight = 0;
	int index = 0;
	
	int Answer[55] = { 0 };

	scanf("%d", &NumberofPeople);

	for (index = 0; index < NumberofPeople; index++) {
		scanf("%d %d", &weight[index], &height[index]);
	}

	for (index = 0; index < NumberofPeople; index++) {

		MostHeavyWeight = weight[index];
		MostTallHeight = height[index];

		int CountBiggerPersonThanMe = 0;

		for (int CompareIndex = 0; CompareIndex < NumberofPeople; CompareIndex++) {
			if (MostHeavyWeight < weight[CompareIndex] && MostTallHeight < height[CompareIndex]) {
				CountBiggerPersonThanMe++;
			}
		}

		Answer[index] = CountBiggerPersonThanMe + 1;
		
	}

	for (int i = 0; i < NumberofPeople; i++) {
		printf("%d ", Answer[i]);
	}

	return 0;
}