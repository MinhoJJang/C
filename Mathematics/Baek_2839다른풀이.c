#include <stdio.h> //ǥ�� �������� 
#pragma warning(disable:4996) //scanf()�� ANSI C�Լ� ���� �޼��� ����

/*

*/

int main() {

	//N���� 3�� ���鼭 �� ���� 5�� ����̸� �����ϱ�.
	int N = 0;
	int count = 0;
	scanf("%d", &N);

	if (N == 4) {
	    printf("%d", -1);
		return 0;
	}
	else if (N == 7) {
		printf("%d", -1);
		return 0;
	}
	else if (N % 5 == 0) {
		printf("%d", N / 5);
		return 0;
	}

	for (int i = 0; ; i++) {

		N = N - 3;

		if (N % 5 == 0) {
			printf("%d", (N / 5)+count+1);
			break;
		}
		else {
			count++;
		}
	}

	return 0;
} //end main()