/*
 ============================================================================
 Name        : submission2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "Airport.h"
#include "generalFunctions.h"
#include "Date.h"
#include "AirportManager.h"
#include "Flight.h"
#include "Airline.h"
#include "Exe.h"

int main(void) {
	AirportManager am;
	Airline airline;
	int res;

	res = createAirline(&airline);
	res = initAirportManager(&am);
	int cont = 1, choice; //continue
	char *iata1, *iata2;

	while(cont)
	{
		showMenu();

		scanf("%d", &choice);
		switch (choice) {
			case 1:
				res = addToirpormManager(&am);
				break;
			case 2:
				res = addTotAirline(&airline, &am);
				break;
			case 3:
				printAirportManager(&am);
				break;
			case 4:
				printAirline(&airline);
				break;

			case 5:
				emptyBuffer();
				iata1=createDynStr("Enter iata1:");
				iata2=createDynStr("Enter iata2:");
				res=getNumFlight(&airline, iata1, iata2);
				printf("\nthere is %d flight from this Airport\n\n",res);

				break;
			case 6:
				printf("Bye Bye..");
				emptyBuffer();

				freeAirportManager(&am);
				freeAirline(&airline);
				cont = 0;
				break;

			default:
				printf("\nWRONG CHOICE\n");
				break;
		}
	}


	return EXIT_SUCCESS;
}
