/*
 * generalFunctions.h
 *
 *  Created on: 8 Dec 2020
 *      Author: yoav
 */

#ifndef GENERALFUNCTIONS_H_
#define GENERALFUNCTIONS_H_
//#include <stddef.h>
typedef unsigned long size_t;

typedef enum {False, True} boolean;
void append(char *s, char c);
char* createDynStr(const char* msg);
char* myGets(char * buf, size_t size);
int numOfWords(char * str);
void emptyBuffer();



#endif /* GENERALFUNCTIONS_H_ */
