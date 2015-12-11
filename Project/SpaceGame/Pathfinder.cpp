// Fill out your copyright notice in the Description page of Project Settings.

#include "SpaceGame.h"
#include "Pathfinder.h"

Pathfinder::Pathfinder()
{
	//minHeap = new MinHeap<int32, int32>();

	//minHeap->Enqueue(10, 209);
	//minHeap->Enqueue(50, 239);
	//minHeap->Enqueue(2, 207);

	////Något funkar inte helt här
	//minHeap->Dequeue();
	//minHeap->Enqueue(12, 276);
	//minHeap->Enqueue(1, 276);

	//// Figure out if it actually works or not?

	//GenerateProximityMatrix();
}

void Pathfinder::Initialize()
{
	//minHeap = new MinHeap<int32, int32>();

	GenerateProximityMatrix();
}

void Pathfinder::GenerateProximityMatrix()
{
	for (TObjectIterator<AStar> Itr; Itr; ++Itr)
	{
		//Itr->GetName();
		UE_LOG(LogTemp, Warning, TEXT("hej"));
	}
}

Pathfinder::~Pathfinder()
{
}

void Pathfinder::test()
{
	UE_LOG(LogTemp, Warning, TEXT("hej"));
}

