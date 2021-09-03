#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi ..�����޸�, ����, ���ڿ� ��ȯ
#include <string.h> //strcpy.. ���ڿ��Լ�. memcpy.. �޸𸮺� �Լ�
#pragma warning(disable:4996) // scnaf() �� ���� c�Լ��� ���۹���. 
#pragma warning(disable:4477) // unsigned <--> signed ���� warning ���� 

#define SUCCESS 1
#define FAIL 0
/*
���ڴ� ���� ����̴� ���Ƹ� ȸ���� �غ��ϱ� ���ؼ� ��θ� �����ϴ� ���̴�.

�����̴� ����̸� ���ͼ� ���� �����ϴ� ���ε�, �ּ��ϰԵ� �׻� ���ž��� �����̴� ���� �Ǽ��� �߸� �θ��� ��� ġ�� �Ͼ�����.

�����̴� �߸��� ���� �θ� ������ 0�� ���ļ�, ���� �ֱٿ� ����̰� �� ���� ����� ��Ų��.

����̴� �̷��� ��� ���� �޾� ���� �� �� ���� ���� �˰� �;� �Ѵ�. ����̸� ��������!

ù ��° �ٿ� ���� K�� �־�����. (1 �� K �� 100,000)

���� K���� �ٿ� ������ 1���� �־�����. ������ 0���� 1,000,000 ������ ���� ������, ������ "0" �� ��쿡�� ���� �ֱٿ� �� ���� �����, �ƴ� ��� �ش� ���� ����.

������ "0"�� ��쿡 ���� �� �ִ� ���� ������ ������ �� �ִ�.

����̰� ���������� ���� �� ���� ���� ����Ѵ�. ���������� ��� ���� ���� 231-1���� �۰ų� ���� �����̴�.
*/

// ����ұ�? �ϴ� ���ڸ� �Է��Ҷ����� �ڵ����� push��Ű��, (scanf�Ἥ) 0�� �Է¹��� ��� push��Ű�� �ʰ� pop��Ű�� �ȴ�. 

// �ϴ� ���� �ʱ�ȭ �Լ�, push, pop 3���� ����ҵ� 


// =========HEADER.H==========

typedef int Data;

typedef struct _node {
	Data data;
	struct _node *pNext;
} Node;

typedef struct _stack {
	Node *pTop;
	//int numdata;
} Stack;

// =========HEADER.H==========

// ==========STACK.C==========
void stack_init(Stack *pStack) {
	pStack->pTop = NULL;
	//pStack->numdata = 0;
}

int stack_is_empty(Stack *pStack) {
	if (pStack->pTop == NULL) {
		return SUCCESS;
	}
	else {
		return FAIL;
	}
}

int stack_push(Stack *pStack, Data data) {

	Node *pNewNode = (Node*)malloc(sizeof(Node));
	memset(pNewNode, 0, sizeof(Node));

	pNewNode->data = data;
	pNewNode->pNext = pStack->pTop;
	pStack->pTop = pNewNode;
	//pStack->numdata++;

	return SUCCESS;
}

int stack_pop(Stack *pStack, Data *pData) {

	if (stack_is_empty(pStack) == SUCCESS) {
		return FAIL;
	}

	{
		Node *pCurrent = pStack->pTop;

		*pData = pStack->pTop->data;
		pStack->pTop = pStack->pTop->pNext;

		free(pCurrent);

		//pStack->numdata--;

		return SUCCESS;
	}
}
// ==========STACK.C==========


// ========STACKMAIN.C=========
int main() {

	int K; // ���� K
	int ans[100001] = { 0 };
	int num= 0;
	int answer = 0;
	int j = 0;
	
	Stack stack;
	Data data;

	stack_init(&stack);

	scanf("%d", &K);

	for (int i = 0; i < K; i++) {

		scanf("%d", &num); // ���� �ޱ�
		if (num == 0) {
			stack_pop(&stack, &data);
		}
		else {
			stack_push(&stack, num);
		}
	}
	
	while (!stack_is_empty(&stack)) {
		stack_pop(&stack, &data);
		ans[j] = data;
		j++;
	}

	for (int k = 0; k < j; k++) {
		answer += ans[k];
	}
	
	printf("%d", answer);

	return 0;
} // �¾ҽ��ϴ� ! 
// =========STACKMAIN.C=========