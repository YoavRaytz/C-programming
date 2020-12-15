/*
 * Airline.h
 *
 *  Created on: 9 Dec 2020
 *      Author: yoav
 */

#ifndef AIRLINE_H_
#define AIRLINE_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Airline.h"
#include "AirportManager.h"

typedef struct {

	char* name;
	Flight ** flightsBoard; // air port name
	int flightAmount;
} Airline;

int createAirline(Airline* airline);
int addFlight(Airline* airline, char src[], char dest[]);
void printAirline(const Airline* airline);
int add(Airline* airline, const AirportManager* am);
int getNumFlight(const Airline* airline, char* from , char* to);
void freeAirline(Airline* airline);

#endif /* AIRLINE_H_ */
