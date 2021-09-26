#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi ..�����޸�, ����, ���ڿ� ��ȯ
#include <string.h> //strcpy.. ���ڿ��Լ�. memcpy.. �޸𸮺� �Լ�
#pragma warning(disable:4996) // scnaf() �� ���� c�Լ��� ���۹���. 
#pragma warning(disable:4477) // unsigned <--> signed ���� warning ���� 

#define SUCCESS 1
#define FAIL 0

typedef int HData;

typedef int fnPriorityComp(HData d1, HData d2);

typedef struct _heap
{
	int numData; // ����ִ� �����Ͱ��� 
	HData *heapArr; // �����޸𸮷� ����
} Heap;

void heap_init(Heap *ph, int len); // ���ʱ�ȭ
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

// -----------------------------------------
// ��� �ε��� ��� ��ũ�� (���� ���)
#define GET_PARENT_IDX(idx) ((idx) >> 1) // idx/2 �������� shift����
// �Լ�ȣ���� �ƴ϶� �ش� �Լ��� �׳� ���Խ�Ŵ. �ð��� �̵�
#define GET_LEFT_IDX(idx) ((idx) << 1) // idx*2 = �������� 1ĭ
#define GET_RIGHT_IDX(idx) (((idx) << 1) + 1) // ��������ڰ� ��Ʈ�����ں��� �켱������ ũ�Ƿ� ��ȣ �����ֱ� 

// ���Լ� ��� ��ũ�� (���� up)
#define COMP_ASC(d1, d2) ((d2)-(d1)) // ��������
#define COMP_DESC(d1, d2) ((d1)-(d2)) // ��������

// idx�� �ڽĵ� �� �켱������ ���� �ڽ��� index�� ���� --> delete �� ��� 
int getHighPriority(Heap *ph, int idx)
{
	// �ڽĳ�尡 ���ٸ� 0���� 
	if (GET_LEFT_IDX(idx) > ph->numData) return 0;

	// �ڽĳ�尡 1����� (���� ��尡 ����)
	if (GET_LEFT_IDX(idx) == ph->numData) return GET_LEFT_IDX(idx);

	// �켱���� 
	if (COMP_ASC(ph->heapArr[GET_LEFT_IDX(idx)], ph->heapArr[GET_RIGHT_IDX(idx)]) < 0) {
		idx = GET_RIGHT_IDX(idx);
	}
	else {
		idx = GET_LEFT_IDX(idx);
	}

	return idx;

}

// �� �ʱ�ȭ
void heap_init(Heap *ph, int len) {
	ph->numData = 0; // ������(���)���� 0
	ph->heapArr = (int*)malloc(sizeof(int)*(len + 1));
	// complete binary tree�� �迭�� 1������ �����ϹǷ� 0���� ���� ����. �׷��� len+1��ŭ�� size�� �ʿ���. �̷��� �迭�� 1-based �迭�̶�� �θ�

	g_hp = ph; // �����Ŀ� �ʿ�

}

void heap_destroy(Heap *ph) {
	free(ph->heapArr);
	memset(ph, 0, sizeof(Heap));
}

// ���� ����ִ���? 
int heap_is_empty(Heap *ph) {
	if (ph->numData == 0) return SUCCESS;
	return FAIL;
}

// ���� ������ �߰� insert
void heap_insert(Heap *ph, HData data) {

	// ���� insert�Ǵ� �����ʹ� �� ������ ���� 
	int idx = ph->numData + 1;
	// ph->numData �� �����ִ� ��尳���̹Ƿ� ���� ���� ���� idx�� ��尳��+1��°�� �����Ѵ�. 
	// ���� �迭 �ε����� �迭�� 0���� �����ϴ� �Ͱ��� �ٸ��� 1���� �����Ѵ�. �׷��� �θ��ڽ��� �ε������� ���� �������� ���ԵǾ� ����� ���ϱ� ����

	// �Ʒ� while �� �����ϸ鼭 ���� INSERT�� data�� ��ġ�� idx�� ���� (���� �����ϴ°� �ƴ�. ���� ��ġ�� �����ϴ°�)
	while (idx != 1) // root (�ֻ���) �� �����Ҷ� ����
	{
		// �θ�� �켱���� �� 
		if (COMP_ASC(data, ph->heapArr[GET_PARENT_IDX(idx)]) > 0) // �θ𺸴� �켱������ ���ٸ�
		{
			// �θ� �������
			ph->heapArr[idx] = ph->heapArr[GET_PARENT_IDX(idx)];

			// idx �� �θ��� idx�� �̵� 
			idx = GET_PARENT_IDX(idx);

		}
		// ���� ���� ���� ��ȣ�� idx�� 
		else // �θ𺸴� �켱������ ���ų� ����.. ���⼭ while �������
		{
			break;
		}
	}

	// idx�� ������ �װ��� ���� INSERT�� data�� �� ��ġ 

	ph->heapArr[idx] = data;
	ph->numData++;

}

// ���� ������ ���� delete. ������ root���� �߻� 
HData heap_delete(Heap *ph) {

	// root�� ���ֱ� 
	HData rootData = ph->heapArr[1]; // �ε��� 1���� ��Ʈ ���, �̸� �����ϰ� ���� 

	// ������ ��尡 �ڸ����� ��ġ idx �� �����ؾ� �Ѵ� .
	// idx�� �����ɶ����� ������ ����� data�� ������ ���´�. 

	HData lastElem = ph->heapArr[ph->numData];
	// ����������� ���� �����س��� 

	int idx = 1; // ������ ��尡 �ϴ� root �ڸ��� ���� �ȴ�. 
	int childIdx;

	while (childIdx = getHighPriority(ph, idx))
		// �� ���Կ����� ��ü�� ������� ����. ������ �� ��ü�� �������. 
	{
		if (COMP_ASC(lastElem, ph->heapArr[childIdx]) >= 0) break;

		ph->heapArr[idx] = ph->heapArr[childIdx];

		idx = childIdx;
	}

	ph->heapArr[idx] = lastElem;
	//ph->heapArr[ph->numData] = NULL;
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

#define MAX 1000005
int arr[MAX];

void printArr(int N) {
	for (int i = 0; i < N; i++) {
		printf("%d\n", arr[i]);
	}
}

void inputData(int N) {
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
}

int main() {

	int N;
	scanf("%d", &N);

	Heap hp;
	inputData(N);
	heap_init(&hp, N);
	HeapSort(arr, N);
	printArr(N);

	return 0;
} // �¾ҽ��ϴ� 