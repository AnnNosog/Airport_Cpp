#include <iostream>
#include <cstring>
#include "Structs.h"
#include "PlaneFunctions.h"

using namespace std;

void InputTime(Time &time)
{
	cout << "Day: ";
	cin >> time.Day;

	cout << "Month: ";
	cin >> time.Month;

	cout << "Year: ";
	cin >> time.Year;

	cout << "Hour: ";
	cin >> time.Hour;

	cout << "Minute: ";
	cin >> time.Minute;
}

void InputData(Plane &plane)
{
	cout << "Enter name: ";
	cin >> plane.name;

	cout << "Enter side number: ";
	cin >> plane.sideNumber;

	cout << "Enter airclass (1 - Widebody, 2 - Narrowbody, ";
	cout << "3 - Regional, 4 - Local): ";

	int temp;
	cin >> temp;
	plane.airclass = (AircraftClass)temp;


	cout << "Enter busines capacity: ";
	cin >> plane.Passenger.businesCapacity;

	cout << "Enter economy capacity: ";
	cin >> plane.Passenger.economyCapacity;

	cout << "Enter departure time: " << endl;

	InputTime(plane.departureTime);

	cout << "Enter landing time: " << endl;

	InputTime(plane.landingTime);

	cout << "Enter destination: ";
	cin >> plane.destination;

	cout << endl << " ******* \t ****** \t ******* \t *******" << endl;
}

void PrintTime(Time time)
{
	cout << "\tDay: " << time.Day << endl;
	cout << "\tMonth: " << time.Month << endl;
	cout << "\tYear: " << time.Year << endl;
	cout << "\tHour: " << time.Hour << endl;
	cout << "\tMinute: " << time.Minute << endl;
}

void PrintPlane(Plane plane)
{
	cout << "Name: " << plane.name << endl;
	cout << "Side number: " << plane.sideNumber << endl;
	cout << "Airclass: " << plane.airclass << endl;
	cout << "Busines capacity: " << plane.Passenger.businesCapacity << endl;
	cout << "Economy capacity: " << plane.Passenger.economyCapacity << endl;
	cout << "Departure time: " << endl;
	PrintTime(plane.departureTime);

	cout << "Landing time: " << endl;
	PrintTime(plane.landingTime);

	cout << "Destination: " << plane.destination << endl;
	cout << endl << endl;
}

int CurrentArraySize(Plane planes[], int size)
{
	int counter = 0;

	for (size_t i = 0; i < size; i++)
	{
		if (planes[i].sideNumber != 0)
		{
			counter++;
		}
	}

	return counter;
}

void PrintPlanes(Plane planes[], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << "Name: " << planes[i].name << endl;
		cout << "Side number: " << planes[i].sideNumber << endl;
		cout << "Destination: " << planes[i].destination << endl;
		cout << endl << " ******* \t ****** \t ******* " << endl << endl;
	}
}

void AddPlane(Plane planes[], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		if (planes[i].sideNumber == 0)
		{
			InputData(planes[i]);
			return;
		}
	}
}

void NullLastStruct(Plane planes[], int size)
{
	planes[size - 1].name[0] = '\0';
	planes[size - 1].sideNumber = 0;
	planes[size - 1].airclass = None;
	planes[size - 1].Passenger.businesCapacity = 0;
	planes[size - 1].Passenger.economyCapacity = 0;

	planes[size - 1].departureTime.Day = 0;
	planes[size - 1].departureTime.Hour = 0;
	planes[size - 1].departureTime.Minute = 0;
	planes[size - 1].departureTime.Month = 0;
	planes[size - 1].departureTime.Year = 0;

	planes[size - 1].landingTime.Day = 0;
	planes[size - 1].landingTime.Hour = 0;
	planes[size - 1].landingTime.Minute = 0;
	planes[size - 1].landingTime.Month = 0;
	planes[size - 1].landingTime.Year = 0;

	planes[size - 1].destination[0] = '\0';
}

void DeletePlane(Plane planes[], int numberDelete, int size)
{
	for (size_t i = numberDelete; i < size - 1; i++)
	{
		strcpy_s(planes[i].name, planes[i + 1].name);
		planes[i].sideNumber = planes[i + 1].sideNumber;
		planes[i].airclass = planes[i + 1].airclass;
		planes[i].Passenger.businesCapacity = planes[i + 1].Passenger.businesCapacity;
		planes[i].Passenger.economyCapacity = planes[i + 1].Passenger.economyCapacity;

		planes[i].departureTime.Day = planes[i + 1].departureTime.Day;
		planes[i].departureTime.Hour = planes[i + 1].departureTime.Hour;
		planes[i].departureTime.Minute = planes[i + 1].departureTime.Minute;
		planes[i].departureTime.Month = planes[i + 1].departureTime.Month;
		planes[i].departureTime.Year = planes[i + 1].departureTime.Year;

		planes[i].landingTime.Day = planes[i + 1].landingTime.Day;
		planes[i].landingTime.Hour = planes[i + 1].landingTime.Hour;
		planes[i].landingTime.Minute = planes[i + 1].landingTime.Minute;
		planes[i].landingTime.Month = planes[i + 1].landingTime.Month;
		planes[i].landingTime.Year = planes[i + 1].landingTime.Year;

		strcpy_s(planes[i].destination, planes[i + 1].destination);
	}

	NullLastStruct(planes, size);
}

void SortName(Plane planes[], int size)
{
	Plane temp;

	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = size - 1; j > i; j--)
		{
			if (strcmp(planes[j - 1].name, planes[j].name) > 0)
			{
				temp = planes[j - 1];
				planes[j - 1] = planes[j];
				planes[j] = temp;
			}
		}
	}
}

void SortSideNumber(Plane planes[], int size)
{
	Plane temp;

	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = size - 1; j > i; j--)
		{
			if (planes[j - 1].sideNumber > planes[j].sideNumber)
			{
				temp = planes[j - 1];
				planes[j - 1] = planes[j];
				planes[j] = temp;
			}
		}
	}
}

void SortEconomyCapacity(Plane planes[], int size)
{
	Plane temp;

	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = size - 1; j > i; j--)
		{
			if (planes[j - 1].Passenger.economyCapacity > planes[j].Passenger.economyCapacity)
			{
				temp = planes[j - 1];
				planes[j - 1] = planes[j];
				planes[j] = temp;
			}
		}
	}
}

void SortDestination(Plane planes[], int size)
{
	Plane temp;

	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = size - 1; j > i; j--)
		{
			if (strcmp(planes[j - 1].destination, planes[j].destination) > 0)
			{
				temp = planes[j - 1];
				planes[j - 1] = planes[j];
				planes[j] = temp;
			}
		}
	}
}