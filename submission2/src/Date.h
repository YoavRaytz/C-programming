/*
 * Date.h
 *
 *  Created on: 8 Dec 2020
 *      Author: yoav
 */

#ifndef DATE_H_
#define DATE_H_

typedef struct
{
    int yyyy;
    int mm;
    int dd;
} Date;

int isValidDate(int day, int month, int year);


int initDate(Date* date);
void printDate(const Date* date);

#endif /* DATE_H_ */
