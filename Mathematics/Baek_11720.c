#include <stdio.h> //ǥ�� �������� 
#pragma warning(disable:4996) //scanf()�� ANSI C�Լ� ���� �޼��� ����

/*
N���� ���ڰ� ���� ���� �����ִ�. �� ���ڸ� ��� ���ؼ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

ù° �ٿ� ������ ���� N (1 �� N �� 100)�� �־�����. ��° �ٿ� ���� N���� ������� �־�����.
*/

int main() {

	int MaxNum = 0;
	int total = 0;
	char num[100];

	scanf("%d", &MaxNum);
    scanf("%s", num);

	for (int i = 0; i < MaxNum; i++) {
		total += (num[i]-48);
	}
	
	printf("%d", total);

	return 0;
} //�¾ҽ��ϴ�!

