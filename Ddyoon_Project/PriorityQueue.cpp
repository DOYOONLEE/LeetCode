#include<stdio.h>

#define MAX_SIZE 100

int heap[MAX_SIZE];
int heapSize = 0;

void heapInit(void) {
	heapSize = 0;
}

void Swap(int* from, int* to) {
	int temp = *from;
	*from = *to;
	*to = temp;
}

int push(int value) {
	if (heapSize + 1 > MAX_SIZE) {
		printf("queue is Full!!\n");
		return 0;
	}

	heap[heapSize] = value;

	int current = heapSize;
	// Priority ����

	// ���̳ʸ� ��ġ�� �켱���� ����.
	while (current > 0 && heap[current] < heap[(current - 1) / 2]) {
		Swap(&heap[current], &heap[current - 1 / 2]);
		current = (current - 1) / 2;
	}

	heapSize += 1;
	return 1;
}

int pop() {
	if (heapSize < 1) return -1;

	int priorityValue = heap[0];
	heapSize -= 1;

	heap[0] = heap[heapSize];

	int current = 0;

	// 0�� �� �� ���� ��������, �ٽ� ������ ���־�� �Ѵ�.
	while (current * 2 + 1 < heapSize) {
		int child;

		if (current * 2 + 2 == heapSize) child = current * 2 + 1;
		else child = heap[current * 2 + 1] < heap[current * 2 + 2] ? current * 2 + 1 : current * 2 + 2;

		if (heap[current] < heap[child]) break;

		Swap(&heap[current], &heap[child]);

		current = child;
	}
	return priorityValue;
}