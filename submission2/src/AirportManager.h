/*
 * AirportManager.h
 *
 *  Created on: 8 Dec 2020
 *      Author: yoav
 */

#ifndef AIRPORTMANAGER_H_
#define AIRPORTMANAGER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//#include "Airport.h"
#include "Airport.h"

typedef struct
{
	Airport* allAirports;
	int size;
	int maxSize;
} AirportManager;

int initAirportManager(AirportManager* am);
int addAirport(AirportManager* am, char *iatasArray);
void printAirportManager(const AirportManager* am);
char* getiatasArray(AirportManager* am);
Airport* getAirportFromIATA(const AirportManager* am, char* iata);
int IATAExist(const AirportManager* am, char* iata);
void freeAirportManager(AirportManager* theAirportManager);


#endif /* AIRPORTMANAGER_H_ */
