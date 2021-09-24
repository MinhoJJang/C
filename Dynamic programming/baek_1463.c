#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#pragma warning(disable:4996) 
#pragma warning(disable:4477) 

/*https://www.acmicpc.net/problem/1463
���� X�� ����� �� �ִ� ������ ������ ���� �� ���� �̴�.

X�� 3���� ������ ��������, 3���� ������.
X�� 2�� ������ ��������, 2�� ������.
1�� ����.
���� N�� �־����� ��, ���� ���� ���� �� ���� ������ ����ؼ� 1�� ������� �Ѵ�. ������ ����ϴ� Ƚ���� �ּڰ��� ����Ͻÿ�.

ù° �ٿ� 1���� ũ�ų� ����, 10^6���� �۰ų� ���� ���� N�� �־�����.
*/
#define MAX 1000005
#define FINDMIN(IDX1, IDX2) IDX1 < IDX2 ? IDX1 : IDX2;

int arr[MAX];

int fn(int X) {

	switch (X)
	{
	case 1: 
		return 0;
		break;
	case 2: case 3:
		return 1;
		break;
	}

	if (arr[X] != 0) {
		return arr[X];
	}
	// X�� 3���� ������������ �׳� �׷��� �ؼ� �ٷ� ���Ѵ�.  
	if (X % 6 == 0) {
		arr[X] = FINDMIN(fn(X / 2) + 1, fn(X / 3) + 1);
	}
	else if (X % 3 == 0) {
		arr[X] = FINDMIN(fn(X - 1) + 1, fn(X / 3) + 1);	
	}
	else if (X % 2 == 0) {
		arr[X] = FINDMIN(fn(X - 1) + 1, fn(X / 2) + 1);
	}
	else {
		arr[X] = fn(X - 1) + 1;
	}

	return arr[X];
}


int main() {

	int N;
	scanf("%d", &N);

	printf("%d", fn(N));
	
	return 0;
} // �¾ҽ��ϴ�!
