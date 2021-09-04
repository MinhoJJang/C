#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#pragma warning(disable:4996) 
#pragma warning(disable:4477) 

/*
�似Ǫ�� ������ ������ ����.

1������ N������ N���� ����� ���� �̷�鼭 �ɾ��ְ�, ���� ���� K(�� N)�� �־�����. ���� ������� K��° ����� �����Ѵ�. �� ����� ���ŵǸ� ���� ������ �̷���� ���� ���� �� ������ ����� ������. �� ������ N���� ����� ��� ���ŵ� ������ ��ӵȴ�. ������ ������� ���ŵǴ� ������ (N, K)-�似Ǫ�� �����̶�� �Ѵ�. ���� ��� (7, 3)-�似Ǫ�� ������ <3, 6, 2, 7, 5, 1, 4>�̴�.

N�� K�� �־����� (N, K)-�似Ǫ�� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

ù° �ٿ� N�� K�� �� ĭ�� ���̿� �ΰ� ������� �־�����. (1 �� K �� N �� 1,000)
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

// ť�� �������� ����� �Լ�
int queue_MakeItCircle(Queue *pq) {

	if (queue_is_empty(pq) == YES) {
		return FAIL;
	}

	pq->pBack->pNext = pq->pFront;

	pq->pBack = NULL;

	return SUCCESS;
}

int queue_jump(Queue *pq, int jumptimes, Data *pData) {
	
	Node *CurrentNode = (Node*)malloc(sizeof(Node));

	Node *PopNode = (Node*)malloc(sizeof(Node));

	CurrentNode = pq->pFront; // ���� ��带 front���� ����Ѵ�. 

	// jumptimes�� 1�� �ƴ� ��� 
	// jumtimes�� 1�� ���� �׳� �Է��� ���� �״�� ����ϸ� �Ǵϱ� ���ܷ� �Ѵ�. 
	while (jumptimes-2 != 0) {
		CurrentNode = CurrentNode->pNext;
		jumptimes--;
	}

	// pop�� ����� �ٷ� ���� ��尡 currentnode�̴�.
	PopNode = CurrentNode->pNext;
	pq->pFront = PopNode->pNext;

	if (pData != NULL)
		*pData = PopNode->data;

	CurrentNode->pNext = pq->pFront;

	free(PopNode);
	pq->numdata--;

	return SUCCESS;
}

void queue_ans(int arr[], int NumberofPeople) {

	printf("<");

	for (int i = 0; i < NumberofPeople; i++) {
		if (i != NumberofPeople - 1) {
			printf("%d, ", arr[i]);
		}
		else {
			printf("%d", arr[i]);
		}
	}

	printf(">");
}


int main() {

	int NumberofPeople = 0;
	int DeleteNumber = 0;
	int Answer[1005] = { 0 };

	Queue q;
	Data data;

	scanf("%d %d", &NumberofPeople, &DeleteNumber);

	// NumberofPeople�� 1�� ���, 1 ���
	if (NumberofPeople == 1) {
		Answer[0] = 1;
		queue_ans(Answer, NumberofPeople);
		return 0;
	}

	// DeleteNumber�� 1�� ���, 1���� ���ʴ�� ���
	if (DeleteNumber == 1) {
		
		int num = 1;

		for (int person = 0; person < NumberofPeople; person++) {
			Answer[person] = num;
			num++;
		}

		queue_ans(Answer, NumberofPeople);
		return 0;
	}

	// DeleteNumber�� 1�� �ƴ� ���
	queue_init(&q);

	for (int person = 1; person <= NumberofPeople; person++) {
		queue_enq(&q, person);
	}

	queue_MakeItCircle(&q);

	for (int i = 0; i < NumberofPeople; i++) {
		queue_jump(&q, DeleteNumber, &data);
		Answer[i] = data;
	}

	queue_ans(Answer, NumberofPeople);

	return 0;
} // �¾ҽ��ϴ�! 