#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#pragma warning(disable:4996) 
#pragma warning(disable:4477) 

/*
1966

���� Deque�� ���� �տ� �ִ� ������ ���߿䵵���� Ȯ���Ѵ�.
������ ������ �� ���� �������� �߿䵵�� ���� ������ �ϳ��� �ִٸ�, �� ������ �μ����� �ʰ� Deque�� ���� �ڿ� ���ġ �Ѵ�. �׷��� �ʴٸ� �ٷ� �μ⸦ �Ѵ�.
���� ��� Deque�� 4���� ����(A B C D)�� �ְ�, �߿䵵�� 2 1 4 3 ��� C�� �μ��ϰ�, �������� D�� �μ��ϰ� A, B�� �μ��ϰ� �ȴ�.

�������� �� ����, ���� Deque�� �ִ� ������ ���� �߿䵵�� �־����� ��, � �� ������ �� ��°�� �μ�Ǵ��� �˾Ƴ��� ���̴�. ���� ��� ���� ������ C������ 1��°��, A������ 3��°�� �μ�ǰ� �ȴ�.

ù �ٿ� �׽�Ʈ���̽��� ���� �־�����. �� �׽�Ʈ���̽��� �� �ٷ� �̷���� �ִ�.

�׽�Ʈ���̽��� ù ��° �ٿ��� ������ ���� N(1 �� N �� 100)��, �� ��°�� �μ�Ǿ����� �ñ��� ������ ���� Deque���� �� ��°�� ���� �ִ����� ��Ÿ���� ���� M(0 �� M < N)�� �־�����. �̶� �� ������ 0��°��� ����. �� ��° �ٿ��� N�� ������ �߿䵵�� ���ʴ�� �־�����. �߿䵵�� 1 �̻� 9 ������ �����̰�, �߿䵵�� ���� ������ ���� �� ���� ���� �ִ�.

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
	Data IndexOfData;
} Node;

typedef struct _queue {
	Node *pFront;
	Node *pBack;
	Data NumberOfData;
	Data BigData;
} Queue;


void queue_init(Queue *pq) {
	pq->pBack = NULL;
	pq->pFront = NULL;
	pq->NumberOfData = 0;
	pq->BigData = 1;
}

int queue_is_empty(Queue *pq) {

	if (pq->pFront != NULL) { return NO; }

	return YES;
}

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

	pq->NumberOfData++;
	pNewNode->IndexOfData = (pq->NumberOfData -1);

	return SUCCESS;
}

int queue_MakeQueueCircle(Queue *pq) {

	if (queue_is_empty(pq) == YES) {
		return FAIL;
	}

	pq->pBack->pNext = pq->pFront;

	return SUCCESS;
}

int queue_SearchDataIndex(Queue *pq, Data IndexWantToKnow, Data NumberOfDocuments) {

	Node *CurrentNode = (Node*)malloc(sizeof(Node));
	Node *PointingBigNode = (Node*)malloc(sizeof(Node));
	Node *SearchNode = (Node*)malloc(sizeof(Node));
	Node *SearchingStartNode = (Node*)malloc(sizeof(Node));
	
	CurrentNode = pq->pFront;
	PointingBigNode = pq->pBack;

	pq->BigData = pq->pFront->data;
	
	while (CurrentNode->pNext->IndexOfData != pq->pFront->IndexOfData && pq->BigData != 9) {

		if (pq->BigData < CurrentNode->pNext->data) {
			pq->BigData = CurrentNode->pNext->data;
			PointingBigNode = CurrentNode;		
		}
		CurrentNode = CurrentNode->pNext;
	}

	int MostBigDataInQueue = PointingBigNode->pNext->data;
	int CheckBigDataCount = 0;

	SearchNode = PointingBigNode->pNext;

	for(int iteration=0; MostBigDataInQueue>0; iteration++) // �ǹ̾��� for�� ��� �׳� while()�� ���°� �������ϴ� 
	{
		if (SearchNode->data == MostBigDataInQueue) {

			CheckBigDataCount++;
			SearchingStartNode = SearchNode;

			if (SearchNode->IndexOfData == IndexWantToKnow) {
				
				return CheckBigDataCount;
			}
		}
	
		if (SearchNode->IndexOfData == PointingBigNode->IndexOfData) {
			MostBigDataInQueue--;
			SearchNode = SearchingStartNode;
			PointingBigNode = SearchingStartNode;
		}

		SearchNode = SearchNode->pNext;
	}

	free(CurrentNode);
	free(PointingBigNode);
	free(SearchNode);
	free(SearchingStartNode);
}

int main() {

	Queue q;

	int Testcase = 0;
	int NumberOfDocuments = 0;
	int IndexWeWant = 0;
	int ImportanceNumbers = 0;
	int Answer[1000] = { 0 };

	scanf("%d", &Testcase);

	for (int t = 0; t < Testcase; t++) {

		scanf("%d %d", &NumberOfDocuments, &IndexWeWant);

		queue_init(&q);
		
		for (int i = 0; i < NumberOfDocuments; i++) {
			scanf("%d", &ImportanceNumbers);
			queue_push(&q, ImportanceNumbers);
		}

		if (NumberOfDocuments == 1) {
			Answer[t] = 1;
		}

		else {
			queue_MakeQueueCircle(&q);
			Answer[t] = queue_SearchDataIndex(&q, IndexWeWant, NumberOfDocuments);
		}
	}

	for (int t = 0; t < Testcase; t++) {
		printf("%d\n", Answer[t]);
	}

	return 0;
} // �¾ҽ��ϴ�!! �� ��¥... �Ф� ��¥ ������� �ФФФ�
