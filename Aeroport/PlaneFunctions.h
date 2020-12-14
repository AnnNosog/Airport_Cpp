#pragma once

#include "Structs.h"

#define N 10

void InputData(Plane &plane);
void InputTime(Time &time);
void PrintTime(Time time);
void PrintPlane(Plane plane);
int CurrentArraySize(Plane planes[], int size = N);
void PrintPlanes(Plane planes[], int size = N);
void AddPlane(Plane planes[], int size = N);
void DeletePlane(Plane planes[], int numberDelete, int size = N);
void NullLastStruct(Plane planes[], int size = N);
void SortName(Plane planes[], int size = N);
void SortSideNumber(Plane planes[], int size = N);
void SortEconomyCapacity(Plane planes[], int size = N);
void SortDestination(Plane planes[], int size = N);
