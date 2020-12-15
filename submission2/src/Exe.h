/*
 * exe.h
 *
 *  Created on: 11 Dec 2020
 *      Author: yoav
 */

#ifndef EXE_H_
#define EXE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//#include <conio.h>

//#include "AirportManager.h"

int addToirpormManager(AirportManager* am);
int addTotAirline(Airline* airline, const AirportManager* am);

void showMenu();




#endif /* EXE_H_ */
