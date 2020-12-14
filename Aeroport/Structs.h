#pragma once

enum AircraftClass
{
	None,
	Widebody,
	Narrowbody,
	Regional,
	Local
};

struct Passengers
{
	int	businesCapacity;
	int	economyCapacity;
};

struct Time
{
	unsigned short Day;
	unsigned short Month;
	unsigned short Year;
	unsigned short Hour;
	unsigned short Minute;
};

struct Plane
{
	char name[25];
	int sideNumber;
	AircraftClass airclass;
	Passengers Passenger;
	Time departureTime;
	Time landingTime;
	char destination[30];
};