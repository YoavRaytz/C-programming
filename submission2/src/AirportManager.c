/*
 * AirportManager.c
 *
 *  Created on: 8 Dec 2020
 *      Author: yoav
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Airport.h"
#include "AirportManager.h"
#include "generalFunctions.h"

int IATAExist(const AirportManager* am, char* iata)
{
	int i;
	for(i=0; i<am->size; i++)
	{
		if(strcmp(iata, (am -> allAirports + i) -> IATA) == 0)
			return True;
	}
	return False;
}

Airport* getAirportFromIATA(const AirportManager* am, char* iata)
{
	int i;
	for(i=0; i<am->size; i++)
	{
		if(strcmp(iata, (am -> allAirports + i) -> IATA) == 0)
			return am -> allAirports + i;
	}
	return NULL;
}


char* getiatasArray(AirportManager* am)
{
	char* iatas;
	iatas = malloc(am->size*3);
	int i;
	for(i=0; i<am->size; i++)
	{
		strcpy(iatas+i*3, (am->allAirports + i)->IATA);
		//		iatas = iatas + i*3;
		//		(am->allAirports + i)->IATA;
	}
	iatas[strlen(iatas)+1] = '\0';
	return iatas;
}

int initAirportManager(AirportManager* am)
{

	am->size = 0;
	int numOfAirports=0;
	printf("Please enter how many airport you would like to add: \n");
	scanf("%d",&numOfAirports);
	getchar(); //clean the \n

	am->maxSize = numOfAirports;
	am->allAirports = (Airport*)malloc(numOfAirports*sizeof(Airport));;
	if(!am -> allAirports)
	{
		printf("Something went wrong, can't allocate space for Airports");
		return 0;
	}
	return 1;
}

int addAirport(AirportManager* am, char *iatasArray)
{
	int res;
	//empty buffer from 'enter' char
//	char tav;
//	tav = getchar();
	emptyBuffer();
	if(am->size < am->maxSize)
	{
		printf("\nyou can add %d more airports\n", am->maxSize - am->size);
		res = initAirport(am -> allAirports + am -> size, iatasArray);
		if(res == True)
		{
			res = 1;
			am -> size = am->size + 1; //increase array by 1
		}
		return res;
	}
	printf("can't add any more");
	return 0;
}

void printAirportManager(const AirportManager* am)
{
	int i;
	for(i=0; i<am->size; i++)
	{
		printf("\nAirport %d/%d:", i+1, am->size);
		printAirport(am->allAirports + i);
		puts("\n***");
	}
}

void freeAirportManager(AirportManager* theAirportManager)
{
	int i;

	for (i = 0; i < theAirportManager->size; i++)
		freeAirport(theAirportManager->allAirports + i);

	free(theAirportManager->allAirports);
}
