#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi ..�����޸�, ����, ���ڿ� ��ȯ
#include <string.h> //strcpy.. ���ڿ��Լ�. memcpy.. �޸𸮺� �Լ�
#pragma warning(disable:4996) // scnaf() �� ���� c�Լ��� ���۹���. 
#pragma warning(disable:4477) // unsigned <--> signed ���� warning ���� 

// =========HEADER.H==========

#define SUCCESS 1
#define FAIL 0

#define YES 10
#define NO 5

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

void stack_destroy(Stack *pStack)
{
	while (!stack_is_empty(pStack)) // ������ �� �����������
	{
		stack_pop(pStack, NULL); // ������ �� ����������� pop
	}
}

int stack_ans(int a) {
	if (a == NO) {
		printf("no\n");
	}
	else {
		printf("yes\n");
	}
	return SUCCESS;
}
// ==========STACK.C===========


// ==========STACKMAIN.C===========
int main() {

	int ans[1000] = { 0 };
	int idx = 0; // �ݺ�Ƚ��
	Stack stack;
	Stack stack_new;
	Stack stack_new2;
	Stack check_stack; // ��ȣ�� pop�ɶ��� numdata�� �Է¹��� ���� ���� 
	Data data;
	char sentence[110] = { 0 };

	for (int i = 0; i < 1000; i++) { // '.'�Է¹��������� ��� for�� ����
	first:
		fgets(sentence, 110, stdin); // gets���� �ȵǳ�????
		int len = strlen(sentence); // ������� ������ ����

		if (sentence[0] == '.' && len == 2) {
			break; // '.' �ϳ��� �Է¹����� �Է� �����̹Ƿ� for�� Ż��
		}

		if (i > 0) {
			stack_destroy(&stack);
			stack_destroy(&stack_new);
			stack_destroy(&stack_new2);
			stack_destroy(&check_stack);
		}

		stack_init(&stack); // for�� �����Ҷ����� ���� ���� ����
		stack_init(&stack_new);
		stack_init(&stack_new2);
		stack_init(&check_stack);

		int PS1_1count = 0; // ')' ���� 
		int PS1_2count = 0; // '(' ���� 

		int PS2_1count = 0; // ']' ���� 
		int PS2_2count = 0; // '[' ���� 

		idx++; // ��üfor�� �ݺ�Ƚ��

		// ��ȣ�� stack�� �ֱ�. 
		for (int k = 0; k < len; k++) {
			if (sentence[k] == '(' || sentence[k] == ')' || sentence[k] == '[' || sentence[k] == ']') {
				stack_push(&stack, sentence[k]);
				stack_push(&stack_new, sentence[k]);
				stack_push(&stack_new2, sentence[k]);
			}
		}

		// ���� �󿡴� '(' �� ���� ���ڰ� �ƴ϶� 40�� ���� �ƽ�Ű�ڵ� ���ڷ� ���´�. 

		stack_size(&stack, &data);

		if (data == 0) { // ���� ���鸸 �ִ� ���ڿ��̸� yes ���� 
			ans[i] = YES;
			stack_ans(ans[i]);
			continue; // for������ �̵� 
		}
		if (data % 2 != 0) { // size���� Ȧ���� no����
			ans[i] = NO;
			stack_ans(ans[i]);
			continue; // for������ �̵� 
		}

		stack_top(&stack, &data);
		if (data == 40 || data == 91) {
			// asciicode ( = 40, ) = 41, [ = 91, ] = 93
			// stack_top�� '[' �̰ų� '(' �̸� �ٷ� no ����
			ans[i] = NO;
			stack_ans(ans[i]);
			continue;  // for������ �̵� 
		}

		while (!stack_is_empty(&stack)) { // ������ �� �����������
			stack_pop(&stack, &data);

			if (data == 41) {
				PS1_1count++; // ) ���� 
			}
			else if (data == 40) {
				PS1_2count++; // ( ���� 
			}
			else if (data == 93) {
				PS2_1count++; // ] ���� 
			}
			else if (data == 91) {
				PS2_2count++; // [ ���� 
			}

			if (PS1_1count - PS1_2count < 0 || PS2_1count - PS2_2count < 0) { // count ���� �ѹ��̶� ������ �Ǵ� ���� ¦�� ���� ���� �� ����
				ans[i] = NO;
				stack_ans(ans[i]);
				goto first;
			}
		}

		if (PS1_1count - PS1_2count > 0 || PS2_1count - PS2_2count > 0) {
			ans[i] = NO;
			stack_ans(ans[i]);
			continue;
		}

		if (PS1_1count - PS1_2count == 0 && PS2_1count - PS2_2count == 0) {

			int total = PS1_1count + PS1_2count + PS2_1count + PS2_2count;

			Data size_data;
			Data check_data; // check_stack���� pop�� data
			int check = 0; // ���̰� ���� ����
			int t = 0;

			if (PS1_1count > 0) {

				for (t = 0; t < total; t++) {

					stack_pop(&stack_new, &data);
					if (data == 41) { // ���� ) �̸�
						stack_size(&stack_new, &size_data); // pop�� ���¿��� stack �� ���� data
						stack_push(&check_stack, size_data); // �� data���� ���ο� check_stack�� push
					}
					else if (data == 40) { // ���� ( ������ ����
						stack_size(&stack_new, &size_data); // pop�� ���¿��� stack �� ���� data
						stack_pop(&check_stack, &check_data); // check_stack���� pop ���� check_data �̾Ƴ�
						check = check_data - size_data; // �̶� �ݵ�� check_data���� size_data���� �� ���� ����. 

						if (check % 2 == 0) { // �� ���̰� 2�� ����̸� �ݵ�� ��ȣ �ȿ� Ȧ������ ��ȣ�� �����Ƿ� �������� ���ڿ��� �ƴ� 
							ans[i] = NO;		
							break; // for�� Ż�� 
						}
						else {
							ans[i] = YES;
							continue;
						}
					}
				}
			}

			int test = i;
			int anstest[1000] = { 0 };

			stack_destroy(&check_stack);
			stack_init(&check_stack);
			check = 0;


			if (PS2_1count > 0) {
				for (t = 0; t < total; t++) {

					// �Ұ�ȣ �۵�����̶� �Ȱ��� 
					stack_pop(&stack_new2, &data);

					if (data == 93) { // ���� ] �̸�
						stack_size(&stack_new2, &size_data); // pop�� ���¿��� stack �� ���� size_data
						stack_push(&check_stack, size_data); // �� size_data���� ���ο� check_stack�� push
					}

					else if (data == 91) { // ���� [ ������ ����
						stack_size(&stack_new2, &size_data); // pop�� ���¿��� stack �� ���� size_data
						stack_pop(&check_stack, &check_data); // check_stack���� pop ���� check_data �̾Ƴ�
						check = check_data - size_data; // �̶� �ݵ�� check_data���� size_data���� �� ���� ����. 

						if (check % 2 == 0) { // �� ���̰� 2�� ����̸� �ݵ�� ��ȣ �ȿ� Ȧ������ ��ȣ�� �����Ƿ� �������� ���ڿ��� �ƴ� 
							anstest[test] = NO;
							break; // for�� Ż�� 
						}
						else {
							anstest[test] = YES;
							continue;
						}
					}
				}
			}

			if ((ans[i] == YES || ans[i] == 0)&& (anstest[test] == YES || anstest[test] == 0)) { // �Ѵ� yes�̸� yes.
				ans[i] = YES;
				stack_ans(ans[i]);
			}
			else {
				ans[i] = NO;
				stack_ans(ans[i]);
			}
		}

		//	stack_ans(ans[i]);
	}

	// ���� stack_ans �� ans[i]�� �Է� 
	//for (int j = 0; j < idx; j++) {
	//    stack_ans(ans[i]);
	//}

	return 0;
}