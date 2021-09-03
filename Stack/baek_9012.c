#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi ..�����޸�, ����, ���ڿ� ��ȯ
#include <string.h> //strcpy.. ���ڿ��Լ�. memcpy.. �޸𸮺� �Լ�
#pragma warning(disable:4996) // scnaf() �� ���� c�Լ��� ���۹���. 
#pragma warning(disable:4477) // unsigned <--> signed ���� warning ���� 

/*
��ȣ ���ڿ�(Parenthesis String, PS)�� �� ���� ��ȣ ��ȣ�� ��(�� �� ��)�� ������ �����Ǿ� �ִ� ���ڿ��̴�. �� �߿��� ��ȣ�� ����� �ٸ��� ������ ���ڿ��� �ùٸ� ��ȣ ���ڿ�(Valid PS, VPS)�̶�� �θ���. �� ���� ��ȣ ��ȣ�� �� ��( )�� ���ڿ��� �⺻ VPS �̶�� �θ���. ���� x �� VPS ��� �̰��� �ϳ��� ��ȣ�� ���� ���ο� ���ڿ� ��(x)���� VPS �� �ȴ�. �׸��� �� VPS x �� y�� ����(concatenation)��Ų ���ο� ���ڿ� xy�� VPS �� �ȴ�. ���� ��� ��(())()���� ��((()))�� �� VPS ������ ��(()(��, ��(())()))�� , �׸��� ��(()�� �� ��� VPS �� �ƴ� ���ڿ��̴�.

�������� �Է����� �־��� ��ȣ ���ڿ��� VPS ���� �ƴ����� �Ǵ��ؼ� �� ����� YES �� NO �� ��Ÿ����� �Ѵ�.

�Է� �����ʹ� ǥ�� �Է��� ����Ѵ�. �Է��� T���� �׽�Ʈ �����ͷ� �־�����. �Է��� ù ��° �ٿ��� �Է� �������� ���� ��Ÿ���� ���� T�� �־�����. �� �׽�Ʈ �������� ù° �ٿ��� ��ȣ ���ڿ��� �� �ٿ� �־�����. �ϳ��� ��ȣ ���ڿ��� ���̴� 2 �̻� 50 �����̴�.

����� ǥ�� ����� ����Ѵ�. ���� �Է� ��ȣ ���ڿ��� �ùٸ� ��ȣ ���ڿ�(VPS)�̸� ��YES��, �ƴϸ� ��NO���� �� �ٿ� �ϳ��� ���ʴ�� ����ؾ� �Ѵ�.
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

// ==========STACK.C==========
void stack_init(Stack *pStack) {
	pStack->pTop = NULL;
	pStack->numdata = 0;
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
	pStack->numdata++;

	return SUCCESS;
}

int stack_pop(Stack *pStack, Data *pData) {

	if (stack_is_empty(pStack) == SUCCESS) {
		return FAIL;
	}

	Node *pCurrent = pStack->pTop;

	if (pData != NULL) // �ſ��߿�!!! pData�� NULL�̸� ����Ǿ�� �ȵ�! 
		
		*pData = pStack->pTop->data;
		pStack->pTop = pStack->pTop->pNext;

		free(pCurrent);

		pStack->numdata--;

	return SUCCESS;
	
}

void stack_destroy(Stack *pStack)
{
	while (!stack_is_empty(pStack)) // ������ �� �����������
	{
		stack_pop(pStack, NULL); // ������ �� ����������� pop
	}
}

int stack_top(Stack *pStack, Data *pData) {

	if (stack_is_empty(pStack) == SUCCESS) {
		*pData = -1;
		return FAIL;
	}

	else {
		*pData = pStack->pTop->data;
		return SUCCESS;
	}
}

int stack_ans(int a) {
	if (a == 0) {
		printf("NO\n");
	}
	else {
		printf("YES\n");
	}
	return SUCCESS;
}

// ==========STACK.C==========

//�̰� �������� ��� �ذ��ұ�? 

// �ϴ� ���ڿ��� �ް�, ���ڿ����� ���ڸ� �ϳ��� stack�� ��´�. ���� ���ڿ��� pop �ϴµ�, (1. ���� top�� (�̸� �ٷ� NO return), (2. ���ڿ� �� ���� ������ Ȧ���̸� �ٷ� NO return). �׸��� pop �Ҷ� ')' �� ���� ã���� �״�,  ')' �� ã�� �� pop �ϰ� count �� 1�� �ø���. (�� ã�� ���� count �� 1�� ������. ������ �� ������ �����ϰ� count�� 0�̸� YES return

// ========STACKMAIN.C=========
int main() {

	int t, Testcase = 0; // �׽�Ʈ ������
	char PS[100] = { 0 }; // ���� Parenthesis String ���ڿ�
	int ans[10000] = { 0 }; // YES, NO���� ���� �迭. ���ڷ� ���� �ް� ���߿� ���ڰ��� ���� YES, NO����

	Stack stack;
	Data data;

	scanf("%d", &Testcase);

	for (t = 0; t < Testcase; t++) {

		stack_init(&stack); // ���� ����
		int count = 0;
		
		scanf("%s", PS);
		int len = strlen(PS);

		if (len % 2 != 0) {
			ans[t] = 0; // PS������ Ȧ���̸� �ٷ� NO����. 
			stack_destroy(&stack);
			continue; // �ٷ� ���� for������ �̵�
		}

		for (int i = 0; i < len; i++) {
			stack_push(&stack, PS[i]);
		}

		stack_top(&stack, &data);
		if (data == 40) {
			ans[t] = 0; // stack_top�� "(" �� �ٷ� NO����. 
			stack_destroy(&stack);
			continue; // �ٷ� ���� for������ �̵�
		}

		while (!stack_is_empty(&stack)) {
			stack_pop(&stack, &data);

			if (data == 41) {
				count++; // ')' �̸� ī��Ʈ ��
			}
			else {
				count--;
			}

			if (count < 0) {
				ans[t] = 0; // pop �ϴٰ� (�� �� ���� pop �Ǵ� ���� NO ����
				stack_destroy(&stack);
				break; // while�� Ż��
			}
		}

		if (count != 0) {
			ans[t] = 0; // �� �ߴµ� count�� 0���� ũ�� ¦�� �ȸ����ϱ� NO ����
			stack_destroy(&stack);
			continue; // for ������ �ٷ� �̵� 
		}
		else {
			ans[t] = 1; // YES ����
			stack_destroy(&stack);
		}
	}

	for (int k = 0; k < Testcase; k++) {
		stack_ans(ans[k]);
	}

	return 0;
} // �¾ҽ��ϴ�!
// ========STACKMAIN.C=========