/*
 * Airport.h
 *
 *  Created on: 8 Dec 2020
 *      Author: yoav
 */

#ifndef AIRPORT_H_
#define AIRPORT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//#include "AirportManager.h"
typedef struct {
	char *name; // air port name
	char * countryName; //country
	char IATA [3];
} Airport;

int initAirport(Airport * theAirport, char *iatasArray);//, AirportManager* am);
void printAirport(const Airport* airport);

char* getValidWord(char* word, int totalLength, int actulLength);
char* validAirportName(char* inputName);//, char* updateName);

int IATARules(char* iata, char *iatasArray);//, AirportManager* am);
int checkEqualAirports (Airport *airport1, Airport *airport2);
int checkAirportIATA(Airport *airport, char* iata);
int check2IATA(char iata1[], char iata2[]);
void freeAirport(Airport* theAirport);

#endif /* AIRPORT_H_ */

