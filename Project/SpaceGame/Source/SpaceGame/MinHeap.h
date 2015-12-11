// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/**
 * 
 */
template <class TPriority, class TValue>
class SPACEGAME_API MinHeap
{
public:
	MinHeap();
	~MinHeap();
	void Enqueue(TPriority priority, TValue value);
	TValue Dequeue();
	int Count();
private:
	TArray<TKeyValuePair<TPriority, TValue>> heap;
	void Insert(TPriority priority, TValue value);
	void HeapifyFromEndToBeginning(int pos);
	void HeapifyFromBeginningToEnd(int pos);
	void DeleteRoot();
};

template<class TPriority, class TValue>
MinHeap<TPriority, TValue>::MinHeap()
{

}

template<class TPriority, class TValue>
MinHeap<TPriority, TValue>::~MinHeap()
{
}

template<class TPriority, class TValue>
void MinHeap<TPriority, TValue>::Enqueue(TPriority priority, TValue value)
{
	Insert(priority, value);
}

template<class TPriority, class TValue>
int MinHeap<TPriority, TValue>::Count()
{
	return heap.Num();
}

template<class TPriority, class TValue>
void MinHeap<TPriority, TValue>::Insert(TPriority priority, TValue value)
{
	heap.Add(TKeyValuePair<TPriority, TValue>(priority, value));
	HeapifyFromEndToBeginning(heap.Num() - 1);
}

template<class TPriority, class TValue>
void MinHeap<TPriority, TValue>::HeapifyFromEndToBeginning(int pos)
{
	if (pos >= heap.Num())
		return;

	// heap[i] have children heap[2*i + 1] and heap[2*i + 2] and parent heap[(i-1)/ 2];
	while (pos > 0)
	{
		int parentPos = (pos - 1) / 2;
		if (heap[parentPos].Key > heap[pos].Key)
		{
			Swap<TKeyValuePair<TPriority, TValue>>(heap[parentPos], heap[pos]);
			pos = parentPos;
		}
		else break;
	}
}

template<class TPriority, class TValue>
TValue MinHeap<TPriority, TValue>::Dequeue()
{
	if (heap.Num() == 0)
		return TValue();

	TValue result = heap[0].Value;
	DeleteRoot();
	return result;
}

template<class TPriority, class TValue>
void MinHeap<TPriority, TValue>::DeleteRoot()
{
	if (heap.Num() <= 1)
	{
		if (heap.Num() == 1)
			heap.RemoveAt(0);
		return;
	}

	heap[0] = heap[heap.Num() - 1];
	heap.RemoveAt(heap.Num() - 1);

	HeapifyFromBeginningToEnd(0);
}

template<class TPriority, class TValue>
void MinHeap<TPriority, TValue>::HeapifyFromBeginningToEnd(int pos)
{
	if (pos >= heap.Num())
		return;

	// heap[i] have children heap[2*i + 1] and heap[2*i + 2] and parent heap[(i-1)/ 2];
	while (true)
	{
		// on each iteration exchange element with its smallest child
		int smallest = pos;
		int left = 2 * pos + 1;
		int right = 2 * pos + 2;
		if (left < heap.Num() && heap[smallest].Key > heap[left].Key)
			smallest = left;
		if (right < heap.Num() && heap[smallest].Key > heap[right].Key)
			smallest = right;

		if (smallest != pos)
		{
			Swap<TKeyValuePair<TPriority, TValue>>(heap[smallest], heap[pos]);
			pos = smallest;
		}
		else break;
	}
}