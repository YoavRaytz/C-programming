/*
 * Airline.c
 *
 *  Created on: 9 Dec 2020
 *      Author: yoav
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "generalFunctions.h"
#include "Flight.h"
#include "Airline.h"

int add(Airline* airline, const AirportManager* am)
{
	emptyBuffer();
	char* src;
	int ok;
	do
	{
		src = createDynStr("src IATA: ");
		if(!src)
			return 0;
		ok = IATAExist(am, src);
		if(ok == False)
		{
			printf("NOT FOUND\n");
		}

	}while(ok == False);

	char* dest;
	int isEqual;
	do
	{
		dest = createDynStr("dest IATA: ");
		if(!dest)
			return 0;
		ok = IATAExist(am, dest);
		isEqual =  strcmp(src, dest);

		if(ok == False)
			printf("NOT FOUND\n");

		if(isEqual == 0)
			printf("\nIATAs ARE EQUAL!!\n");



	}while((ok == False) || (isEqual == 0));

	addFlight(airline, src, dest);
	free(src);
	free(dest);
	return 1;
}


int createAirline(Airline* airline)
{
	puts("\nCreate your desire Airline company:");

	airline->name = createDynStr("Please enter the airline name:\n");
	airline->flightAmount = 0;
	airline-> flightsBoard = NULL;
	return 1;
}



int addFlight(Airline* airline, char* src, char* dest) //******
{
	airline -> flightsBoard = (Flight**)realloc(airline -> flightsBoard, sizeof(Flight*)*(airline->flightAmount + 1));
	*(airline -> flightsBoard + airline -> flightAmount) = createFlight(src, dest);
	airline -> flightAmount = airline->flightAmount + 1; //increase array by 1
	return 1;
}

void printAirline(const Airline* airline)
{
	int i;
	printf("Airline name: ");
	puts(airline->name);
	printf("has %d flights:\n", airline->flightAmount);
	for (i = 0; i < airline->flightAmount; i++)
	{
		printf("\nFlight %d/%d: \n", i+1, airline->flightAmount);
		printFlight(airline->flightsBoard[i]);
		puts("***");
	}
}

int getNumFlight(const Airline* airline, char* from , char* to)
{
	int i;
	int sum=0,res;
	for(i=0; i<airline->flightAmount; i++)
	{
		res = equalsData(airline->flightsBoard[i], from, to);
		if(res==1)
			sum++;
	}
	return sum;
}

void freeAirline(Airline* airline)
{
	free(airline->name);
	int i;
	for (i = 0; i < airline->flightAmount; i++)
	{
		freeFlight(airline->flightsBoard[i]);
	}

	free(airline->flightsBoard);

}

