#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi ..�����޸�, ����, ���ڿ� ��ȯ
#include <string.h> //strcpy.. ���ڿ��Լ�. memcpy.. �޸𸮺� �Լ�
#pragma warning(disable:4996) // scnaf() �� ���� c�Լ��� ���۹���. 
#pragma warning(disable:4477) // unsigned <--> signed ���� warning ���� 

/*
ũ�Ⱑ N�� ���� A = A1, A2, ..., AN�� �ִ�. ������ �� ���� Ai�� ���ؼ� ��ū�� NGE(i)�� ���Ϸ��� �Ѵ�. Ai�� ��ū���� �����ʿ� �����鼭 Ai���� ū �� �߿��� ���� ���ʿ� �ִ� ���� �ǹ��Ѵ�. �׷��� ���� ���� ��쿡 ��ū���� -1�̴�.

���� ���, A = [3, 5, 2, 7]�� ��� NGE(1) = 5, NGE(2) = 7, NGE(3) = 7, NGE(4) = -1�̴�. A = [9, 5, 4, 8]�� ��쿡�� NGE(1) = -1, NGE(2) = 8, NGE(3) = 8, NGE(4) = -1�̴�.

ù° �ٿ� ���� A�� ũ�� N (1 �� N �� 1,000,000)�� �־�����. ��°�� ���� A�� ���� A1, A2, ..., AN (1 �� Ai �� 1,000,000)�� �־�����.

�� N���� �� NGE(1), NGE(2), ..., NGE(N)�� �������� ������ ����Ѵ�.
*/

int arr[1000005] = { 0 };
// ���������� ����� �鸸�� �迭�� ���𰡴�

int main() {

	int N = 0;
	int idx = 0;
	int num = 0;

	scanf("%d", &N); // ���� A�� ũ�� 

	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		arr[i] = num;
	} // �迭�� �� ��� 

	for (int k = 0; k < N; k++) {
		for (int t = k + 1; t <= N; t++) {

			idx = arr[t] - arr[k];

			if (idx > 0) {
				arr[k] = arr[t];
				break;
			}
			if (t == N)
			{
				arr[k] = -1;
				break;
			}
		}

	}

	for (int s = 0; s < N; s++) {
		printf("%d ", arr[s]);
	}

	return 0;
} // �ð��ʰ� - 38%

// O(n^2) �̱� ������.. 