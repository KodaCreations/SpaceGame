// Fill out your copyright notice in the Description page of Project Settings.
#include "MinHeap.h"
#pragma once

/**
 * 
 */
class SPACEGAME_API Pathfinder
{
public:
	Pathfinder();
	~Pathfinder();
private:
	MinHeap<int32, int32>* minHeap;
};
