#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#pragma warning(disable:4996) 
#pragma warning(disable:4477) 


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

// 1. ť �ʱ�ȭ 
void queue_init(Queue *pq) {
	pq->pBack = NULL;
	pq->pFront = NULL;
	pq->numdata = 0;
}

// 2. ť�� �ڷᰡ ����ִ°�?
int queue_is_empty(Queue *pq) {
	if (pq->pFront == NULL) {
		return YES;
	}
	return NO;
}

// 3. ť�� �ڷ� �ֱ� 
int queue_enq(Queue *pq, Data data) {

	// (1) �ϴ� �����͸� ������� ��带 ������. 
	Node *pNewNode = (Node*)malloc(sizeof(Node)); // �����͸� malloc�� �޸� �Ҵ��ϴ°�..

	// (2) �� ��忡 �����͸� �־��ش�. 
	pNewNode->data = data;
	pNewNode->pNext = NULL; // ��ģ�� 1) pNewNode�� �ʱ�ȭ���Ѿ��ϴϱ� NULL�� �ʱ�ȭ�����ش�. 

	// (3) ���� ť�� �ڷᰡ ���� ���, pBack, pFront�� ���ÿ� pNewNode�� ����Ű�� �����. 
	if (queue_is_empty(pq) == YES) {
		pq->pBack = pNewNode;
		pq->pFront = pNewNode;
	}

	// (4) ť�� 1�� �̻� �����Ͱ� �ִ� ���, ���� ���� ���� pBack�� ��ġ�ϰ�, pFront�� �״�� �����Ѵ�. 
	else {
		pq->pBack->pNext = pNewNode; // ��ģ�� 2) front�� �״�� �����Ƿ��� ��ǻ� ���������� �ȵ�. ���� back�� �ִ� ����� ���� ��尡 ���ο� back�� ��ġ�ϴ� ���̹Ƿ� stack�� ����ϰ� back�� ����������. 
		pq->pBack = pNewNode;
	}
	pq->numdata++;

	return SUCCESS;
}

// 4. ť���� �ڷ���� 
int queue_deq(Queue *pq, Data *pData) {

	// �ϴ� ���� �ڷᰡ �ִ������� ���캻��. 
	if (queue_is_empty(pq) == YES) {
		return FAIL;
	}

	// ��ģ�� 3) pData�� NULL�� �Ǹ� �ȵǴϱ�..
	if (pData != NULL)
		// (1) front data�� *pData�� ����.
		*pData = pq->pFront->data;

	// (2) ���� front��带 ���� ���ο� ��带 ����������. 
	Node *pCurNode = (Node*)malloc(sizeof(Node));

	// (3) front Node �� pCurNode �� �ű��
	pCurNode = pq->pFront;

	// (4) front��ġ�� �������ְ�
	pq->pFront = pq->pFront->pNext;

	// (5) pCurNode�� free���ְ� NumberOfData-- ���ش�.
	free(pCurNode);
	pq->numdata--;

	return SUCCESS;
} 

// 5. ť���� �ڷ� �̸�����
int queue_peek(Queue *pq, Data *pData) {

	if (queue_is_empty(pq) == YES) {
		return FAIL;
	}

	if (pData != NULL)
		*pData = pq->pFront->data;

	return SUCCESS;
}

int queue_size(Queue *pq) {
	return pq->numdata;
}


/*

1 = 1
1 2 = 2
1 2 3 = 2 3 = 3 2 = 2
1 2 3 4 = 2 3 4 = 3 4 2 = 4 2 = 2 4 = 4
1 2 3 4 5 = 2 3 4 5 = 3 4 5 2 = 4 5 2 = 5 2 4 = 2 4 = 4 2 = 2

���� ���� front���� pop 1��, 2���ϰ� 2��°���� 2���� �����͸� �ٽ� back�� push���ִ� ť 

*/

int main() {

	Queue q;
	Data data;

	queue_init(&q);

	int N = 0;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		queue_enq(&q, i);
	}

	// q : N, N-1, ... , 3, 2, 1
	//    back					front

	// ���� 1: �Է°����� 1���϶��� ī�带 �������� �ȵȴ�. 
	if (N == 1) {
		printf("%d", 1);
		return 0;
	}

	while (queue_size(&q) != 1) {

		// �� �� ī�带 ������.
		queue_deq(&q, &data); 

		// ���� ���� ī�� �����Ͱ��� �����´�. 
		queue_peek(&q, &data); 
		int peekData = data;

		queue_deq(&q, &data);
		queue_enq(&q, peekData);
	}

	queue_peek(&q, &data);
	printf("%d", data);

	return 0;
} // �¾ҽ��ϴ�!!