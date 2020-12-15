/*
 * Exe.c
 *
 *  Created on: 11 Dec 2020
 *      Author: yoav
 */


#include "Airport.h"
#include "AirportManager.h"
#include "Flight.h"
#include "Airline.h"
#include "generalFunctions.h"
#include "Exe.h"



void showMenu()
{
	puts("1. Add airport to Airports manager");
	puts("2. Add flight to Airline company.");
	puts("3. Print all airports");
	puts("4. Print Airline details include all flights");
	puts("5. Count the flights number between to airports");
	puts("6. Exit");

}

int addToirpormManager(AirportManager* am)
{
	int res;
	char *iatasArray;
	int ok = 1;
	char tav;
	while (ok) {
		iatasArray = getiatasArray(am);
		res = addAirport(am, iatasArray);
		if(res == False)
		{
			printf("Something went wrong, can't enter Airport right now.");
			return 0;
		}

		printf("\nDo you want to enter anther Airport? y/n\n");
		do {
			tav = getchar();
		} while (isspace(tav));

		if (tav != 'y' && tav != 'Y')
		{
			ok=0;
		}
	}

	return 1;
}



int addTotAirline(Airline* airline, const AirportManager* am)
{
	int res;

	int ok = 1;
	char tav;
	while (ok) {
		res = add(airline, am);
		if(res == False)
		{
			puts("Something went wrong, can't adding Flight right now.");
			return 0;
		}
		else
			printf("\n");

		printf("Do you want to add a Flight? y/n\n");
		do {
			tav = getchar();
		} while (isspace(tav));

		if (tav != 'y' && tav != 'Y')
			ok = 0;


	}

	return 1;
}

