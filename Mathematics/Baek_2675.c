#include <stdio.h> //ǥ�� �������� 
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996) //scanf()�� ANSI C�Լ� ���� �޼��� ����

/*
���ڿ� S�� �Է¹��� �Ŀ�, �� ���ڸ� R�� �ݺ��� �� ���ڿ� P�� ���� �� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. ��, ù ��° ���ڸ� R�� �ݺ��ϰ�, �� ��° ���ڸ� R�� �ݺ��ϴ� ������ P�� ����� �ȴ�. S���� QR Code "alphanumeric" ���ڸ� ����ִ�.

QR Code "alphanumeric" ���ڴ� 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ\$%*+-./: �̴�.

ù° �ٿ� �׽�Ʈ ���̽��� ���� T(1 �� T �� 1,000)�� �־�����. �� �׽�Ʈ ���̽��� �ݺ� Ƚ�� R(1 �� R �� 8), ���ڿ� S�� �������� ���еǾ� �־�����. S�� ���̴� ��� 1�̸�, 20���ڸ� ���� �ʴ´�.
*/

int main() {

	int Test, t; // (1<= T <= 1000)
	int R; // �ݺ�Ƚ�� (1 <= R <= 8)
	char S[30] = { 0 }; // ���ڿ� ���� 1 <= S <= 20
	char Answer[1000000] = { 0 };

	scanf("%d", &Test);

	for (t = 0; t < Test; t++) {

		scanf("%d", &R);
		scanf("%s", S);
		int len = strlen(S);
		char Scpy[10] = { 0 }; 

		// �迭���� 8���� �ϸ� ��������
		// https://www.acmicpc.net/status?user_id=ahchjang&problem_id=2675&from_mine=1 ��Ÿ�� ���� ����

		char Newstr[200] = { 0 };

		for (int j = 0; j < len; j++) {
			for (int i = 0; i < R; i++) {
				Scpy[i] = S[j];
			}
			strcat(Newstr, Scpy);
		}	
		strcat(Answer, Newstr);
		strcat(Answer, "\n");
	}
	
		printf("%s", Answer);

	return 0;
} //�¾ҽ��ϴ�!