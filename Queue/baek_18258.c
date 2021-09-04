#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#pragma warning(disable:4996) 
#pragma warning(disable:4477) 

/*
������ �����ϴ� ť�� ������ ����, �Է����� �־����� ����� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.

����� �� ���� �����̴�.

push X: ���� X�� ť�� �ִ� �����̴�.
pop: ť���� ���� �տ� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ť�� ����ִ� ������ ������ ����Ѵ�.
empty: ť�� ��������� 1, �ƴϸ� 0�� ����Ѵ�.
front: ť�� ���� �տ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
back: ť�� ���� �ڿ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.

ù° �ٿ� �־����� ����� �� N (1 �� N �� 2,000,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� ����� �ϳ��� �־�����. �־����� ������ 1���� ũ�ų� ����, 100,000���� �۰ų� ����. ������ �������� ���� ����� �־����� ���� ����.
*/

#define SUCCESS	1
#define FAIL	0

#define YES 1
#define NO 0

typedef int Data;

typedef struct _node
{
	Data data;
	struct _node *pNext;

} Node;

typedef struct _queue {
	Node *pFront;
	Node *pBack;
	int numdata;
} Queue;


void queue_init(Queue *pq) {
	pq->pBack = NULL;
	pq->pFront = NULL;
	pq->numdata = 0;
}

// empty: ť�� ��������� 1, �ƴϸ� 0�� ����Ѵ�.
int queue_is_empty(Queue *pq) {
	
	if (pq->pFront == NULL) return YES;
	
	return NO;
}

// push X: ���� X�� ť�� �ִ� �����̴�.
int queue_push(Queue *pq, Data data) {

	Node *pNewNode = (Node*)malloc(sizeof(Node));	
	pNewNode->data = data;
	pNewNode->pNext = NULL; 

	if (queue_is_empty(pq)) {
		pq->pBack = pNewNode;
		pq->pFront = pNewNode;
	}
	else {
		pq->pBack->pNext = pNewNode; 
		pq->pBack = pNewNode;
	}

	pq->numdata++;

	return SUCCESS;
}

// pop: ť���� ���� �տ� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
int queue_pop(Queue *pq, Data *pData) {

	if (queue_is_empty(pq) == YES) {
		printf("%d\n", -1);
		return 0;
	}

	if (pData != NULL)
		*pData = pq->pFront->data;

	Node *pCurNode = (Node*)malloc(sizeof(Node));
	pCurNode = pq->pFront;
	pq->pFront = pq->pFront->pNext;
	free(pCurNode);
	pq->numdata--;

	printf("%d\n", *pData);

	return SUCCESS;
} 

// size: ť�� ����ִ� ������ ������ ����Ѵ�.
int queue_size(Queue *pq) {
	printf("%d\n", pq->numdata);
	return 0;
}

// front: ť�� ���� �տ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
int queue_front(Queue *pq, Data *pData) {

	if (queue_is_empty(pq)) {
		printf("%d\n", -1);
		return 0;
	}

	if(pData != NULL)
		*pData = pq->pFront->data;

	printf("%d\n", *pData);

	return SUCCESS;
}

// back: ť�� ���� �ڿ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
int queue_back(Queue *pq, Data *pData) {

	if (queue_is_empty(pq)) {
		printf("%d\n", -1);
		return 0;
	}

	if (pData != NULL)
		*pData = pq->pBack->data;

	printf("%d\n", *pData);

	return SUCCESS;
}


int main() {

	Queue queue;
	Data data;

	queue_init(&queue);

	int N = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {

		char order[6] = { 0 };
		scanf("%s", order);

		if (strcmp(order, "push") == 0) {
			int num = 0;
			scanf("%d", &num);
			queue_push(&queue, num);
		}
		else if (strcmp(order, "pop") == 0) {
			queue_pop(&queue, &data);
		}
		else if (strcmp(order, "size") == 0) {
			queue_size(&queue);
		}
		else if (strcmp(order, "empty") == 0) {
			
			if (queue_is_empty(&queue)) {
				printf("%d\n", 1);
			}
			else {
				printf("%d\n", 0);
			}
		}
		else if (strcmp(order, "front") == 0) {
			queue_front(&queue, &data);
		}
		else if (strcmp(order, "back") == 0) {
			queue_back(&queue, &data);
		}

	}

	return 0;
} // �¾ҽ��ϴ� !! 