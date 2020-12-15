#ifndef FLIGHT_H_
#define FLIGHT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Airport.h"
#include "generalFunctions.h"
#include "Date.h"
#include "Flight.h"

typedef struct {
	char from[4];
	char to[4];
	int hourOfDepart;
	Date *date;

} Flight;

Flight* createFlight(char* src, char* dest);
void printFlight(const Flight* f);
int  equalsData(const Flight* f, char* fromC, char* toC);
void freeFlight(Flight* flight);
#endif
