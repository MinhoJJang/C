#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#pragma warning(disable:4996) 
#pragma warning(disable:4477) 

/*
������ �����ϴ� ��(Deque)�� ������ ����, �Է����� �־����� ����� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.

����� �� ���� �����̴�.

push_front X: ���� X�� ���� �տ� �ִ´�.
push_back X: ���� X�� ���� �ڿ� �ִ´�.
pop_front: ���� ���� �տ� �ִ� ���� ����, �� ���� ����Ѵ�. ����, ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
pop_back: ���� ���� �ڿ� �ִ� ���� ����, �� ���� ����Ѵ�. ����, ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ���� ����ִ� ������ ������ ����Ѵ�.
empty: ���� ��������� 1��, �ƴϸ� 0�� ����Ѵ�.
front: ���� ���� �տ� �ִ� ������ ����Ѵ�. ���� ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
back: ���� ���� �ڿ� �ִ� ������ ����Ѵ�. ���� ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
*/

#define SUCCESS	1
#define FAIL	0

#define YES 1
#define NO 0

typedef int Data;

typedef struct _node
{
	Data data;
	struct _node *pNext_headFront;
	struct _node *pNext_headBack;
} Node;

typedef struct _deque {
	Node *pFront;
	Node *pBack;
	int numdata;
} Deque;

void queue_init(Deque *dq) {
	dq->pBack = NULL;
	dq->pFront = NULL;
	dq->numdata = 0;
}

// empty: ť�� ��������� 1, �ƴϸ� 0�� ����Ѵ�.
int queue_is_empty(Deque *dq) {

	if (dq->numdata == 0) {
		
		return YES;
	}
	
	return NO;
}

// push X: ���� X�� �տ� �ִ´� (Front�� �߰�)
int queue_push_front(Deque *dq, Data data) {

	Node *pNewNode = (Node*)malloc(sizeof(Node));
	pNewNode->data = data;
	pNewNode->pNext_headFront = NULL;
	pNewNode->pNext_headBack = NULL;

	if (queue_is_empty(dq)) {
		dq->pBack = pNewNode;
		dq->pFront = pNewNode;
		dq->pBack->pNext_headFront = dq->pFront;
		dq->pFront->pNext_headBack = dq->pBack;
	}
	else {
		dq->pFront->pNext_headFront = pNewNode;
		pNewNode->pNext_headBack = dq->pFront;
		dq->pFront = pNewNode;
	}

	dq->numdata++;

	return SUCCESS;
}

// ���� X�� ���� �ڿ� �ִ´� (Back�� �߰�)
int queue_push_back(Deque *dq, Data data) {

	Node *pNewNode = (Node*)malloc(sizeof(Node));
	pNewNode->data = data;
	pNewNode->pNext_headBack = NULL;
	pNewNode->pNext_headFront = NULL;

	if (queue_is_empty(dq)) {
		dq->pBack = pNewNode;
		dq->pFront = pNewNode;
		// ������� 
		dq->pBack->pNext_headFront = dq->pFront;
		dq->pFront->pNext_headBack = dq->pBack;
		// 1������ 
	}
	else {
		
		pNewNode->pNext_headFront = dq->pBack;
		dq->pBack->pNext_headBack = pNewNode;
		dq->pBack = pNewNode;
	}

	dq->numdata++;

	return SUCCESS;
}

// pop_front ������ ���� �տ� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
int queue_pop_front(Deque *dq, Data *pData) {

	if (dq->numdata == 0) {
		printf("%d\n", -1);
		return 0;
	}

	if (pData != NULL)
		*pData = dq->pFront->data;

	Node *pCurNode = (Node*)malloc(sizeof(Node));

	pCurNode = dq->pFront;
	dq->pFront = dq->pFront->pNext_headBack;
	free(pCurNode);
	// pop���� front�� ���������ġ�� ���ع����� ���߿� push�Ҷ� ������ ������ۿ�....

	dq->numdata--;

	printf("%d\n", *pData);

	return SUCCESS;
}

// pop_back ������ ���� �տ� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
int queue_pop_back(Deque *dq, Data *pData) {

	if (dq->numdata == 0) {
		printf("%d\n", -1);
		return 0;
	}

	if (pData != NULL)
		*pData = dq->pBack->data;

	Node *pCurNode = (Node*)malloc(sizeof(Node));

	pCurNode = dq->pBack;
	dq->pBack = dq->pBack->pNext_headFront;
	free(pCurNode);

	dq->numdata--;

	printf("%d\n", *pData);

	return SUCCESS;
}

// size: ť�� ����ִ� ������ ������ ����Ѵ�.
int queue_size(Deque *dq) {
	printf("%d\n", dq->numdata);
	return 0;
}

// front: ť�� ���� �տ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
int queue_front(Deque *dq, Data *pData) {

	if (queue_is_empty(dq) == YES) {
		printf("%d\n", -1);
		return 0;
	}

	if (pData != NULL)
		*pData = dq->pFront->data;

	printf("%d\n", *pData);

	return SUCCESS;
}

// back: ť�� ���� �ڿ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
int queue_back(Deque *dq, Data *pData) {

	if (queue_is_empty(dq) == YES) {
		printf("%d\n", -1);
		return 0;
	}

	if (pData != NULL)
		*pData = dq->pBack->data;

	printf("%d\n", *pData);

	return SUCCESS;
}


int main() {

	int NumberOfOrders = 0;

	Deque dq;
	Data data;

	queue_init(&dq);

	scanf("%d", &NumberOfOrders);
	
	for (int OrderCount = 0; OrderCount < NumberOfOrders; OrderCount++) {
		char Order[20] = { 0 };
		scanf("%s", Order);

		if (strcmp(Order, "push_back") == 0) {
			int PushNumber = 0;
			scanf("%d", &PushNumber);
			queue_push_back(&dq, PushNumber);
			continue;
		}
		else if (strcmp(Order, "push_front") == 0) {
			int PushNumber = 0;
			scanf("%d", &PushNumber);
			queue_push_front(&dq, PushNumber);
			continue;
		}
		else if (strcmp(Order, "pop_back") == 0) {
			queue_pop_back(&dq, &data);
			continue;
		}
		else if (strcmp(Order, "pop_front") == 0) {
			queue_pop_front(&dq, &data);
			continue;
		}
		else if (strcmp(Order, "size") == 0) {
			queue_size(&dq);
			continue;
		}
		else if (strcmp(Order, "empty") == 0) {
			printf("%d\n", queue_is_empty(&dq));
			continue;
		}
		else if (strcmp(Order, "front") == 0) {
			queue_front(&dq, &data);
			continue;
		}
		else if (strcmp(Order, "back") == 0) {
			queue_back(&dq, &data);		
			continue;
		}
	}
	return 0;
} // �¾ҽ��ϴ�. ��ȿ���� �����κ��� ���߿� ��¦ ��ġ�� ������ 