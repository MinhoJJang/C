#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi ..�����޸�, ����, ���ڿ� ��ȯ
#include <string.h> //strcpy.. ���ڿ��Լ�. memcpy.. �޸𸮺� �Լ�
#pragma warning(disable:4996) // scnaf() �� ���� c�Լ��� ���۹���. 
#pragma warning(disable:4477) // unsigned <--> signed ���� warning ���� 

/*
������ �����ϴ� ������ ������ ����, �Է����� �־����� ����� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.

����� �� �ټ� �����̴�.

push X: ���� X�� ���ÿ� �ִ� �����̴�.
pop: ���ÿ��� ���� ���� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ���ÿ� ����ִ� ������ ������ ����Ѵ�.
empty: ������ ��������� 1, �ƴϸ� 0�� ����Ѵ�.
top: ������ ���� ���� �ִ� ������ ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.

ù° �ٿ� �־����� ����� �� N (1 �� N �� 10,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� ����� �ϳ��� �־�����. �־����� ������ 1���� ũ�ų� ����, 100,000���� �۰ų� ����. ������ �������� ���� ����� �־����� ���� ����.

����ؾ��ϴ� ����� �־��� ������, �� �ٿ� �ϳ��� ����Ѵ�.
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
// ������ FAIL

int stack_pop(Stack *pStack, Data *pData) {

	if (stack_is_empty(pStack)==SUCCESS) {
		*pData = -1;
		return FAIL;
	}

	else {
		Node *pCurrent = pStack->pTop;

		*pData = pStack->pTop->data;
		pStack->pTop = pStack->pTop->pNext;

		free(pCurrent);

		pStack->numdata--;

		return SUCCESS;
	}
}

int stack_size(Stack *pStack, Data *pData) {
	
	*pData = pStack->numdata;
	return SUCCESS;
}


int stack_top(Stack *pStack, Data *pData) {

	if (stack_is_empty(pStack)==SUCCESS) {
		*pData = -1;
		return FAIL;
	}

	else {
		*pData = pStack->pTop->data;
		return SUCCESS;
	}
}
// ==========STACK.C===========


// ==========STACKMAIN.C===========
int main() {

	int order,N = 0; // ����� �� 

	Stack stack;
	Data data;
	int arr[10010] = { 0 };
	int NUMDATA = 0; // push ���� 

	stack_init(&stack);

	scanf("%d", &order);

	for (N = 0; N < order; N++) {

		char whatorder[10] = { 0 };
		int num = 0;
		
		scanf("%s", whatorder);

		if (strcmp(whatorder,"push")==0) {
			scanf("%d\n", &num);
			stack_push(&stack, num);
			NUMDATA++;
		}
		else if (strcmp(whatorder, "pop") == 0) {
			stack_pop(&stack, &data);
			arr[N- NUMDATA] = data;
		}
		else if (strcmp(whatorder, "size") == 0) {
			stack_size(&stack, &data);
			arr[N- NUMDATA] = data;
		}
		else if (strcmp(whatorder, "empty") == 0) {
			if (stack_is_empty(&stack) == 0) {
				arr[N- NUMDATA] = 0;
			}
			else {
				arr[N- NUMDATA] = 1;
			}
		}
		else if(strcmp(whatorder, "top") == 0) {
			stack_top(&stack, &data);
			arr[N -NUMDATA] = data;
		}
	}

	for (N = 0; N < order-NUMDATA; N++) {

		printf("%d\n", arr[N]);
	}

	return 0;
} // �¾ҽ��ϴ�!!!
// ==========STACKMAIN.C===========