#include <iostream>
#include <cstring>
#include "PlaneFunctions.h"
#include "Structs.h"

using namespace std;

int main()
{
	Plane Planes[N]{
		{"Air", 4444, Widebody, {12, 20}, {12, 4, 1999, 12, 55}, {13, 4, 1999, 20, 07}, "Praga" },
		{"Corn", 5555, Regional, {0, 50}, {21, 3, 2000, 14, 35}, {21, 3, 2000, 19, 30}, "London"},
		{"Water", 3333, Local, {1, 6}, {13, 11, 2010, 20, 05}, {14, 11, 2010, 21, 30}, "Minsk"},
		{"Parrot", 1111, Narrowbody, {20, 0}, {5, 3, 2005, 10, 35}, {5, 3, 2005, 19, 30}, "Riga"},
		{"Dove", 2222, Local, {0, 4}, {14, 11, 2020, 15, 30}, {14, 11, 2020, 16, 30}, "Berlin"},
	};

	/*for (size_t i = 0; i < 5; i++)
	{
		InputData(Planes[i]);
	}*/
	
	AddPlane(Planes);
	PrintPlane(Planes[4]);
	DeletePlane(Planes, 4);
	PrintPlanes(Planes, CurrentArraySize(Planes));

	SortSideNumber(Planes, CurrentArraySize(Planes));

	for (size_t i = 0; i < CurrentArraySize(Planes); i++)
	{
		PrintPlane(Planes[i]);
	}
	cout << "***** \t ***** \t ***** \t ******" << endl;

	SortDestination(Planes, CurrentArraySize(Planes));

	for (size_t i = 0; i < CurrentArraySize(Planes); i++)
	{
		PrintPlane(Planes[i]);
	}

	system("pause");
	return 0;
}