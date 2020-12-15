/*
 * Flight.c
 *
 *  Created on: 9 Dec 2020
 *      Author: yoav
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Airport.h"
#include "generalFunctions.h"
#include "Date.h"
#include "Flight.h"
#include "AirportManager.h"


Flight* createFlight(char* src, char* dest)
{
	Flight* theFlight = malloc(sizeof(Flight));
	if(!theFlight)
	{
		printf("\nCant allocate memory for flight");
		return NULL;
	}
	strcpy(theFlight->from, src);
	theFlight->from[4] = '\0';
	strcpy(theFlight->to, dest);
	theFlight->to[4] = '\0';

	int hour;
	do{
		printf("Enter the hour of the flight: ");
		scanf("%d", &hour);
	}
	while (hour<0 || hour > 23);

	theFlight->hourOfDepart = hour;

	theFlight->date = malloc(sizeof(Date));
	if(!theFlight->date)
	{
		printf("\nCan't allocate memory for date\n");
		return NULL;
	}
	initDate(theFlight->date);

	return theFlight;
}

void printFlight(const Flight* f)
{
	printf("Flight details:\n");
	printf("Destination: %s", f->from);
	printf("\nto: %s", f->to);
	printf("\n");
	printf("Hour: %d ", f->hourOfDepart);
	printDate(f->date);


}

int equalsData(const Flight *f ,char* fromC, char* toC)
{
	if(strcmp(f->from , fromC)==0 && strcmp(f->to , toC)==0 )
		return 1;

	return 0;
}

void freeFlight(Flight* flight)
{
	free(flight->date);
}







