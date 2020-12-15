/*
 * Date.c
 *
 *  Created on: 8 Dec 2020
 *      Author: yoav
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Date.h"


int isValidDate(int day, int month, int year)
{
    //check range of year,month and day
    if (year > 10000 || year < 0)
        return 0;
    if (month < 1 || month > 12)
        return 0;
    if (day < 1 || day > 31)
        return 0;
    if (month == 2)
		return (day <= 28);
    //handle months which has only 30 days
    if (month == 4 || month == 6 || month == 9 || month == 11)
        return (day <= 30);
    return 1;
}


int initDate(Date* date)
{
	int day, month, year;
	int status = 0;
	do
	{
	printf("Enter date in format (day/month/year): ");
	scanf("%d/%d/%d",&day, &month, &year);

	//check date validity
	status = isValidDate(day, month, year);
	if(status !=1)
		printf("Please enter a valid date!\n");
	}while(status !=1);

	date->dd = day;
	date->mm = month;
	date->yyyy = year;
	return 1;
}


void printDate(const Date* date)
{
	printf("\nDate: %02d/%02d/%d\n", date->dd, date->mm, date->yyyy);
}
