#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi ..�����޸�, ����, ���ڿ� ��ȯ
#include <string.h> //strcpy.. ���ڿ��Լ�. memcpy.. �޸𸮺� �Լ�
#pragma warning(disable:4996) // scnaf() �� ���� c�Լ��� ���۹���. 
#pragma warning(disable:4477) // unsigned <--> signed ���� warning ����

#define MAX 100050

#define SUCCESS 1
#define FAIL 0

#define GET_PARENT_IDX(idx) ((idx) >> 1) 
#define GET_LEFT_IDX(idx) ((idx) << 1) 
#define GET_RIGHT_IDX(idx) (((idx) << 1) + 1) 

#define COMP_ASC(d1, d2) ((d2)-(d1))  // ��������
#define COMP_DESC(d1, d2) ((d1)-(d2))  // ��������

/* Heap�� ������*/

typedef int HData;

typedef int fnPriorityComp(HData d1, HData d2);
// d1�� �켱������ ���ٸ� 0���� ū �� ���� 
// d2�� �켱������ ���ٸ� 0���� ���� �� ���� 
// d1 = d2�� 0����

typedef struct _time {

	int startTime;
	int endTime;

} Time;
// ������ ���� �ð� ����ؼ� �������.. Time�̶�� ����ü ������ ���� �迭 ��ü�� endTime�� Ű������ ���Ľ�Ű�� ���ݾ�?! ��� ������ �ϱ����.....������
// �̰� ���� �� ���θ� ���� ���ؼ� �׷����� ����

typedef struct _heap
{
	int numData; // ����ִ� �����Ͱ��� 
	Time *heapArr; // �����޸𸮷� ����

} Heap;

// ������
Heap *g_hp;

// �Լ� 
int getHighPriority(Heap *ph, int idx)
{
	if (GET_LEFT_IDX(idx) > ph->numData) return 0;
	if (GET_LEFT_IDX(idx) == ph->numData) return GET_LEFT_IDX(idx);
	if (COMP_ASC(ph->heapArr[GET_LEFT_IDX(idx)].endTime, ph->heapArr[GET_RIGHT_IDX(idx)].endTime) < 0) {
		idx = GET_RIGHT_IDX(idx);
	}
	else {
		idx = GET_LEFT_IDX(idx);
	}

	return idx;
}

void heap_init(Heap *ph, int len) {
	ph->numData = 0; 
	ph->heapArr = (Time*)malloc(sizeof(Time)*(len + 1));

	g_hp = ph; 
}

int heap_is_empty(Heap *ph) {
	if (ph->numData == 0) return SUCCESS;
	return FAIL;
}

void heap_insert(Heap *ph, Time arr) {

	int idx = ph->numData + 1;

	while (idx != 1) 
	{	
		if (COMP_ASC(arr.endTime, ph->heapArr[GET_PARENT_IDX(idx)].endTime) > 0) 
		{	
			ph->heapArr[idx] = ph->heapArr[GET_PARENT_IDX(idx)];
			idx = GET_PARENT_IDX(idx);
		}
		else
		{
			break;
		}
	}

	ph->heapArr[idx] = arr;
	ph->numData++;
}

// startTime���Ŀ� �Լ�
void start_heap_insert(Heap *ph, Time arr) {

	int idx = ph->numData + 1;
	while (idx != 1)
	{
		if (COMP_ASC(arr.startTime, ph->heapArr[GET_PARENT_IDX(idx)].startTime) > 0)
		{
			ph->heapArr[idx] = ph->heapArr[GET_PARENT_IDX(idx)];
			idx = GET_PARENT_IDX(idx);
		}
		else
		{
			break;
		}
	}

	ph->heapArr[idx] = arr;
	ph->numData++;
}

// ���� ������ ���� delete. ������ root���� �߻� 
Time heap_delete(Heap *ph) {

	Time rootData = ph->heapArr[1]; 
	Time lastElement = ph->heapArr[ph->numData];
	
	int idx = 1; 
	int childIdx;

	while (childIdx = getHighPriority(ph, idx))
	{
		if (COMP_ASC(lastElement.endTime, ph->heapArr[childIdx].endTime) >= 0) break;

		ph->heapArr[idx] = ph->heapArr[childIdx];
		idx = childIdx;
	}

	ph->heapArr[idx] = lastElement;
	ph->numData--;

	return rootData;
}

// startTime���Ŀ� �Լ�
Time start_heap_delete(Heap *ph) {

	Time rootData = ph->heapArr[1];
	Time lastElement = ph->heapArr[ph->numData];

	int idx = 1;
	int childIdx;

	while (childIdx = getHighPriority(ph, idx))
	{
		if (COMP_ASC(lastElement.startTime, ph->heapArr[childIdx].startTime) >= 0) break;

		ph->heapArr[idx] = ph->heapArr[childIdx];
		idx = childIdx;
	}

	ph->heapArr[idx] = lastElement;
	ph->numData--;

	return rootData;
}

void HeapSort(Time arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		heap_insert(g_hp, arr[i]);
	}
	for (i = 0; i < n; i++)
	{
		arr[i] = heap_delete(g_hp);
	}
	// �׳� insert�ϰ� �״�� delete�ϸ� arr�� ���ĵ� ������� �����Ͱ� ���ð���.
}

// startTime���Ŀ� �Լ�
void newHeapSort(Time arr[], int n, int startP, int finishP)
{
	int i;
	for (i = startP; i <= finishP; i++)
	{
		start_heap_insert(g_hp, arr[i]);
	}
	for (i = startP; i <= finishP; i++)
	{
		arr[i] = start_heap_delete(g_hp);
	}
	// �׳� insert�ϰ� �״�� delete�ϸ� arr�� ���ĵ� ������� �����Ͱ� ���ð���.
}

// ����ü Ÿ���� �迭�� ���������� ����.
Time arr[MAX];

void putDataTime(int N) {

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &arr[i].startTime, &arr[i].endTime);
	}
}

void sortEndTime(int N) {
	Heap hp;
	heap_init(&hp, N);
	HeapSort(arr, N);
}

// ��������_>���� ������ �ð��� ���� ��, �����ϴ� �ð��� �����ؾ���. 
/*
������ �ð��� ���ٸ� -> ó�� y���� ������ ����. ���ķ� idx++��Ű�鼭 y ���� �������� ������ Ȯ��

1. ���ٸ� -> �� idx���� ���� �����ϰ�, �� �ڷ� ��� �����ϸ鼭 �ٸ� y���� ���ö����� ���� ã�´�. ���� y���� ���� x�� ���� heapsort��Ų��. �װ� ������ �ٸ� y���� ������ ������ idx�� �ھƳְ� �ٽ� ����.

2. �ٸ��ٸ� -> ������ �� y�� �ְ� �ٽ� ����

--> ���̻� ������ y�� ���� ������ ����
*/
void sortStartTimesIfEndTimeIsSame(int N) {

	// y���� �����ϴ� ����
	int storeCurrentEndTime;
	int endTimeIndex = 0;

	// �ϴ� �� ó���� endtime
	storeCurrentEndTime = arr[endTimeIndex].endTime;

	// ���̻� y�� ������ �� ���� ������ 
	while(endTimeIndex < N-1) {

		// �� ���� endtime�̶� ������ ���� 
		// ���� ������ 
		if (storeCurrentEndTime == arr[endTimeIndex + 1].endTime) {

			int startIndex = endTimeIndex; // ���� ��ġ �����ϰ� 
			int finishIndex; // ������ ��ġ�� ����

			int searchIndex = startIndex + 2; // ������ġ +2 ���� ���� 

			// ��� ���� endtime ����.. �ٸ� endtime�� �����ų�, N�� �Ǳ� �� ���� ����
			while (arr[searchIndex].endTime == storeCurrentEndTime && searchIndex < N) {
				searchIndex++;
			}
			// ���� searchIndex�� N-2�� �Ѿ�� �ʾҴٸ�, storeCurrentEndTime ���� �ٲ���
			if (searchIndex <= N - 2) {
				storeCurrentEndTime = arr[searchIndex].endTime;
			}

			finishIndex = searchIndex - 1; // ������ ��ġ�� ��ġ-1��
			endTimeIndex = searchIndex; // endTime��ġ �ٲ���

			// startTime�� startindex���� finish���� ����
			Heap startHeap;
			heap_init(&startHeap, finishIndex - startIndex + 1);
			newHeapSort(arr, finishIndex - startIndex + 1, startIndex, finishIndex);
		}
		// �ٸ��� 
		else {
			storeCurrentEndTime = arr[endTimeIndex + 1].endTime;
			endTimeIndex++;
		}
	}
}

int findMaxNumberOfMeeting(int N) {

	int meetCount = 0;
	int idx = 0;

	int saveLastEndTime;

	// �� ó�� ȸ�Ǵ� ������ �� ����. 
	saveLastEndTime = arr[idx].endTime;
	meetCount++;
	idx++;

	// ���̻� ã�� �� �ִ� ȸ�ǰ� ����������
	while (idx != N) {

		// ���� �� ���� ȸ���� ���۽ð��� �� ȸ���� ������ �ð����� ���ų� ũ�ٸ�
		if (arr[idx].startTime >= saveLastEndTime) {
			meetCount++;
			saveLastEndTime = arr[idx].endTime;
		}

		idx++;
	}

	return meetCount;
}

// �׽�Ʈ��
void testPrint(int N) {
	for (int i = 0; i < N; i++) {
		printf("%d %d\n", arr[i].startTime, arr[i].endTime);
	}
}

int main() {

	int N;
	scanf("%d", &N);
	
	putDataTime(N);
	sortEndTime(N);
	sortStartTimesIfEndTimeIsSame(N);
	
	printf("%d", findMaxNumberOfMeeting(N));

	return 0;
} 

// �¾ҽ��ϴ�!!!!
// �̰� �ǹ� 2���??? �ƴ� ��?
// 2���� �����ϴ¹� ��� ������ ���� ���� 
