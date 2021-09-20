#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi ..�����޸�, ����, ���ڿ� ��ȯ
#include <string.h> //strcpy.. ���ڿ��Լ�. memcpy.. �޸𸮺� �Լ�
#pragma warning(disable:4996) // scnaf() �� ���� c�Լ��� ���۹���. 
#pragma warning(disable:4477) // unsigned <--> signed ���� warning ���� 
#include <math.h>

#ifndef __HEAP_H__
#define __HEAP_H__

/*
https://www.acmicpc.net/problem/1037
��� A�� N�� ��¥ ����� �Ƿ���, N�� A�� ����̰�, A�� 1�� N�� �ƴϾ�� �Ѵ�. � �� N�� ��¥ ����� ��� �־��� ��, N�� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

ù° �ٿ� N�� ��¥ ����� ������ �־�����. �� ������ 50���� �۰ų� ���� �ڿ����̴�. ��° �ٿ��� N�� ��¥ ����� �־�����. 1,000,000���� �۰ų� ����, 2���� ũ�ų� ���� �ڿ����̰�, �ߺ����� �ʴ´�.
*/

/* Heap�� ������*/

typedef int HData;

typedef int fnPriorityComp(HData d1, HData d2);
// d1�� �켱������ ���ٸ� 0���� ū �� ���� 
// d2�� �켱������ ���ٸ� 0���� ���� �� ���� 
// d1 = d2�� 0����

typedef struct _heap
{
	int numData; // ����ִ� �����Ͱ��� 
	HData *heapArr; // �����޸𸮷� ����
	fnPriorityComp *comp; // �켱���� ���Լ� 

} Heap;

/* Heap�� ����*/

// �� �ʱ�ȭ
void heap_init(Heap *ph, int len);
void heap_destroy(Heap *ph);

// ���� ����ִ���? 
int heap_is_empty(Heap *ph);

// ���� ������ �߰� insert
void heap_insert(Heap *ph, HData data);

// ���� ������ ���� delete
HData heap_delete(Heap *ph);

// ������
Heap *g_hp;
void HeapSort(int arr[], int n);

#endif

#define SUCCESS 1
#define FAIL 0

#define GET_PARENT_IDX(idx) ((idx) >> 1) 
#define GET_LEFT_IDX(idx) ((idx) << 1) 
#define GET_RIGHT_IDX(idx) (((idx) << 1) + 1) 

#define COMP_ASC(d1, d2) ((d2)-(d1)) 
#define COMP_DESC(d1, d2) ((d1)-(d2)) 

int getHighPriority(Heap *ph, int idx)
{
	if (GET_LEFT_IDX(idx) > ph->numData) return 0;
	if (GET_LEFT_IDX(idx) == ph->numData) return GET_LEFT_IDX(idx);
	if (COMP_ASC(ph->heapArr[GET_LEFT_IDX(idx)], ph->heapArr[GET_RIGHT_IDX(idx)]) < 0) {
		idx = GET_RIGHT_IDX(idx);
	}
	else {
		idx = GET_LEFT_IDX(idx);
	}

	return idx;
}

void heap_init(Heap *ph, int len) {
	ph->numData = 0;
	ph->heapArr = (int*)malloc(sizeof(int)*(len + 1));

	g_hp = ph;
}

int heap_is_empty(Heap *ph) {
	if (ph->numData == 0) return SUCCESS;
	return FAIL;
}

void heap_insert(Heap *ph, HData data) {

	int idx = ph->numData + 1;

	while (idx != 1)
	{
		if (COMP_ASC(data, ph->heapArr[GET_PARENT_IDX(idx)]) > 0)
		{
			ph->heapArr[idx] = ph->heapArr[GET_PARENT_IDX(idx)];
			idx = GET_PARENT_IDX(idx);
		}
		else
		{
			break;
		}
	}

	ph->heapArr[idx] = data;
	ph->numData++;
}

// ���� ������ ���� delete. ������ root���� �߻� 
HData heap_delete(Heap *ph) {

	HData rootData = ph->heapArr[1];
	HData lastElem = ph->heapArr[ph->numData];

	int idx = 1;
	int childIdx;

	while (childIdx = getHighPriority(ph, idx))
	{
		if (COMP_ASC(lastElem, ph->heapArr[childIdx]) >= 0) break;

		ph->heapArr[idx] = ph->heapArr[childIdx];

		idx = childIdx;
	}
	ph->heapArr[idx] = lastElem;
	ph->numData--;

	return rootData;
}

void HeapSort(int arr[], int n)
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

#define MAX 100

int numArr[MAX] = { 0 };

int main() {

	Heap hp;

	int numberofNum;
	
	scanf("%d", &numberofNum);

	for (int i = 0; i < numberofNum; i++) {
		scanf("%d", &numArr[i]);
	}

	if (numberofNum > 1) {
		heap_init(&hp, numberofNum);
		HeapSort(numArr, numberofNum);
		printf("%d", numArr[0] * numArr[numberofNum - 1]);
	}
	else {
		long t = (long)pow(numArr[0], 2);
		printf("%ld", t);
	}

	return 0;
} // �¾ҽ��ϴ�