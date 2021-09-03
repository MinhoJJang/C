#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi ..�����޸�, ����, ���ڿ� ��ȯ
#include <string.h> //strcpy.. ���ڿ��Լ�. memcpy.. �޸𸮺� �Լ�
#include <time.h> // clock .. �ð�, ��¥ �Լ�
#pragma warning(disable:4996) // scnaf() �� ���� c�Լ��� ���۹���. 
#pragma warning(disable:4477) // unsigned <--> signed ���� warning ���� 

/*
1���� n������ ���� ���ÿ� �־��ٰ� �̾� �þ�������ν�, �ϳ��� ������ ���� �� �ִ�. �̶�, ���ÿ� push�ϴ� ������ �ݵ�� ���������� ��Ű���� �Ѵٰ� ����. ������ ������ �־����� �� ������ �̿��� �� ������ ���� �� �ִ��� ������, �ִٸ� � ������ push�� pop ������ �����ؾ� �ϴ����� �˾Ƴ� �� �ִ�. �̸� ����ϴ� ���α׷��� �ۼ��϶�.

ù �ٿ� n (1 �� n �� 100,000)�� �־�����. ��° �ٺ��� n���� �ٿ��� ������ �̷�� 1�̻� n������ ������ �ϳ��� ������� �־�����. ���� ���� ������ �� �� ������ ���� ����.

�Էµ� ������ ����� ���� �ʿ��� ������ �� �ٿ� �� ���� ����Ѵ�. push������ +��, pop ������ -�� ǥ���ϵ��� �Ѵ�. �Ұ����� ��� NO�� ����Ѵ�.

*/

// =========HEADER.H==========

#define SUCCESS 1
#define FAIL 0

typedef int Data;

typedef struct _node {
	Data data;
	struct _node *pNext;
} Node;

typedef struct _stack {
	Node *pTop;
	int numdata;
} Stack;

// =========HEADER.H==========


// ==========STACK.C===========
void stack_init(Stack *pStack) {
	pStack->pTop = NULL;
	pStack->numdata = 0;
}

int stack_push(Stack *pStack, Data data) {

	Node *pNewNode = (Node*)malloc(sizeof(Node));
	memset(pNewNode, 0, sizeof(Node));

	pNewNode->data = data;
	pNewNode->pNext = pStack->pTop;
	pStack->pTop = pNewNode;
	pStack->numdata++;

	return SUCCESS;
}

int stack_is_empty(Stack *pStack) {

	if (pStack->pTop == NULL) {
		return SUCCESS;
	}
	else {
		return FAIL;
	}
}


int stack_pop(Stack *pStack, Data *pData) {

	if (stack_is_empty(pStack)) {
		return FAIL;
	}

	Node *pCurrent = pStack->pTop;
	if (pData != NULL)
		*pData = pStack->pTop->data;

	pStack->pTop = pStack->pTop->pNext;

	free(pCurrent);

	pStack->numdata--;

	return SUCCESS;

}

int stack_size(Stack *pStack, Data *pData) {

	*pData = pStack->numdata;
	return SUCCESS;
}


int stack_top(Stack *pStack, Data *pData) {

	if (stack_is_empty(pStack)) {
		return FAIL;
	}

	if (pData != NULL)
		*pData = pStack->pTop->data;

	return SUCCESS;
}

int main() {

	int N;
	int num;
	
	char plus_min[500000] = { 0 }; 
	// ù��° ���� ����. plus_min �� +�� -�� ��� �迭�̴ϱ�, N�� �ִ���� 100000���� ��� �ι�� ���ƾ� �Ѵ�. 
	int plma = 0; // plus_min�迭 = �ø� �迭
	int k = 1;

	Stack stack;
	Data data;

	scanf("%d", &N); // ù�ٿ� �Է¹޴� ���� N
	stack_init(&stack); 

	for (int i = 0; i < N; i++) {

		scanf("%d", &num);

		if (i > 0 && !stack_is_empty(&stack)) { 
			stack_top(&stack, &data);	
			if (data > num) {
				printf("NO");
				return 0;
			}
			else if (data == num) // �������. ���� data = num �̶� == �̶� �򰥸��� ����...
			{
				stack_pop(&stack, &data);
				plus_min[plma] = '-';
				plma++;
				continue;
			}
		}

		do {
			stack_push(&stack, k);

			plus_min[plma] = '+'; 
			plma++;
			
			k++;

			stack_top(&stack, &data);
		} while (data < num); // stack�� num �������� ��

		// top �� �ִ� data = num �� ���¿���
		stack_pop(&stack, &data);
		plus_min[plma] = '-'; 
		plma++;
	}

	
	for (int t = 0; t < plma; t++) {
		printf("%c\n", plus_min[t]);
	}

	return 0;
} // �¾ҽ��ϴ�!! 