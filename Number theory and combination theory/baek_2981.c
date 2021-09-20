#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <math.h>
#pragma warning(disable:4996) 
#pragma warning(disable:4477) 

#define SUCCESS 1
#define FAIL 0

typedef int HData;

typedef int fnPriorityComp(HData d1, HData d2);
// �� �����͸� ���� � ���� ũ�ų� ������ �˾Ƴ��� �Լ�-�� Ÿ���� �����Ѱ���.. 
// d1�� �켱������ ���ٸ� 0���� ū �� ���� 
// d2�� �켱������ ���ٸ� 0���� ���� �� ���� 
// d1 = d2�� 0����

typedef struct _heap
{
	int numData; // ����ִ� �����Ͱ��� 
	HData *heapArr; // �����޸𸮷� ����
	fnPriorityComp *comp; // �켱���� ���Լ� 
	// �Լ�Ÿ�� ������ comp
} Heap;

// ������
Heap *g_hp;

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

#define MAX 500
#define SUPERMAX 6000

void findM(int NumberofNum, int minimumOfDifference, int numArr[MAX]) {

	int DivisorIdx = 0;
	int DivisorArr[MAX] = { 0 };
	int answerArr[MAX] = { 0 };
	double rootOfLowestDiff = sqrt(minimumOfDifference);

	// �ּ����� ��� ������ �� �����̴�. 
	for (int divisor = 1; divisor <= rootOfLowestDiff; divisor++) {
		// ���� ���� �ּڰ��� �����ٺ��� ���� ���� lowDiff�� ����� ���� �����Ѵ�. �̶� 1���� �ϹǷ� ���߿� 1�� ����ߵ�
		if (minimumOfDifference % divisor == 0) {
			DivisorArr[DivisorIdx] = divisor;
			DivisorIdx++;
			if (minimumOfDifference / divisor != divisor) {
				DivisorArr[DivisorIdx] = minimumOfDifference / divisor;
				DivisorIdx++;
			}
		}
	}
	
	Heap heap;
	heap_init(&heap, DivisorIdx);
	HeapSort(DivisorArr, DivisorIdx);
	// ������� ��� �������� �����ϰ�

	int ansIndex = 0;

	// ������� ������ �迭�� �ִ� ������ 1�� �ε������� ���ʷ� �ִ´�.
	for (int sortedDivisorArrIdx = 1; sortedDivisorArrIdx<DivisorIdx; sortedDivisorArrIdx++) {

		int newDivisor = DivisorArr[sortedDivisorArrIdx];
		int numArrIdx = 0;
		int rest = 0;

		for (numArrIdx = 0; numArrIdx < NumberofNum; numArrIdx++) {

			if (numArrIdx == 0) {
				rest = numArr[numArrIdx] % newDivisor;
			}
			else if (rest != numArr[numArrIdx] % newDivisor) {
				break;
			}
		}

		if (numArrIdx == NumberofNum) {
			answerArr[ansIndex] = newDivisor;
			ansIndex++;
		}
	}

	for (int j = 0; j < ansIndex; j++) {
		printf("%d ", answerArr[j]);
	}
}

//int makeItPositiveNumber(int a) {
//
//	if (a < 0) {
//		a = -a;
//	}
//
//	return a;
//}

int main() {

	int NumberofNum;
	scanf("%d", &NumberofNum);

	int numArr[MAX] = { 0 };
	int DifferenceBetweenNumbersArr[SUPERMAX] = { 0 };

	for (int i = 0; i < NumberofNum; i++) {
		scanf("%d", &numArr[i]);
	}

	int DifferenceIdx = 0;

	for (int i = 0; i < NumberofNum; i++) {
		for (int j = i+1; j < NumberofNum; j++) {
			if (numArr[i] - numArr[j] < 0) {
				DifferenceBetweenNumbersArr[DifferenceIdx] = numArr[j] - numArr[i];
			}
			else {
				DifferenceBetweenNumbersArr[DifferenceIdx] = numArr[i] - numArr[j];
			}
			// �ش��� �ٽ� ����Ʈ 
			// ��¥ �� �������� �̻��� �Լ� ȣ����������!!!!!!!!!!!!!!!!!!!!!!!!!
			// �Լ�ȣ�⿡ �ð��� ����Ƹ����� 
			DifferenceIdx++;
		}
	}

	Heap hp;
	heap_init(&hp, DifferenceIdx);
	HeapSort(DifferenceBetweenNumbersArr, DifferenceIdx);

	findM(NumberofNum, DifferenceBetweenNumbersArr[0], numArr);

	return 0;
} // �¾ҽ��ϴ�!!

// �ش��� �ٽ� ����Ʈ 
// ��¥ �� �������� �̻��� �Լ� ȣ����������!!!!!!!!!!!!!!!!!!!!!!!!!
// �Լ�ȣ�⿡ �ð��� ����Ƹ����� 
// ���� for�� �����°� ���ƺ��� ��ʸ������� �������Ѵ� ��鸸 ���¼��� �׳� �ð��ʰ�