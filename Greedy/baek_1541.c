#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#pragma warning(disable:4996) 
#pragma warning(disable:4477) 

/*

*/

int main() {

	char First_sentence[55];
	char Last_sentence[55];
	int FrontTotal = 0;
	int BackTotal = 0;

	gets(First_sentence);
	strcpy(Last_sentence, First_sentence);

	// 1.���� - �� ���� ���
	if (strchr(First_sentence, '-') == NULL) {
		
		char *FindAllNumbers = strtok(Last_sentence, "+-");

		while (FindAllNumbers != NULL) {
			BackTotal = BackTotal + atoi(FindAllNumbers);

			FindAllNumbers = strtok(NULL, "+-");
		}

		printf("%d", BackTotal);
		return 0;
	}


	// 2. ����  - �� ���� ��� 
	char *FindFrontMinus = strtok(First_sentence, "-");

	// ó������ ������ -�տ� ���� ã�� 
	char *FindFrontNumbers = strtok(FindFrontMinus, "+");
	while (FindFrontNumbers != NULL) {
		FrontTotal = FrontTotal + atoi(FindFrontNumbers);

		FindFrontNumbers = strtok(NULL, "+");
	}

	// ��ü ���� ã��
	char *FindAllNumbers = strtok(Last_sentence, "+-");

	while (FindAllNumbers != NULL) {
		BackTotal = BackTotal + atoi(FindAllNumbers);

		FindAllNumbers = strtok(NULL, "+-");
	}

	printf("%d", FrontTotal * 2 - BackTotal);

	return 0;
} // �¾ҽ��ϴ�!!