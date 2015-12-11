// Fill out your copyright notice in the Description page of Project Settings.
#include "MinHeap.h"
#include "Star.h"
#pragma once

/**
 * 
 */
static class SPACEGAME_API Pathfinder
{
public:
	Pathfinder();
	~Pathfinder();
	static void test();

	UFUNCTION(BlueprintCallable, Category = "PathfinderFunctions")
	void Initialize();
private:
	//MinHeap<int32, int32>* minHeap;
	static TArray<AStar*> stars;
	static TArray<TArray<float>> proximityMatrix;

	static void GenerateProximityMatrix();
};
