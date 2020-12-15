/*
 * generalFunctions.c
 *
 *  Created on: 8 Dec 2020
 *      Author: yoav
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Airport.h"
#include "generalFunctions.h"

#define MAX 255


char* createDynStr(const char* msg)
{
	char* defualtStr = NULL;
	int len, inpStr[MAX];
//	char *inpStr[MAX];
	printf("%s", msg);
	myGets(inpStr, sizeof(inpStr));
	len  = strlen(inpStr) + 1;
	defualtStr = (char*)malloc(len*sizeof(char));
	if(defualtStr != NULL)
	{
		strcpy(defualtStr, inpStr);
	}
	return defualtStr;


}

char* myGets(char * buf, size_t size)
{
	if(buf!= NULL && size>0)
	{
		if(fgets(buf, size, stdin))
		{
			buf[strcspn(buf, "\n")] = '\0';
			return  buf;
		}
		*buf = '\0';
	}
	return NULL;
}

int numOfWords(char * str)
{
	int len;
	char* temp = NULL;
	len  = strlen(str) + 1;
	temp = (char*)malloc(len*sizeof(char));
	strcpy(temp, str);

	int numOfWords = 0;
	char* word;


	word = strtok(temp, " ");
	while (word)
	{
		numOfWords++;
		word = strtok(NULL, " ");
	}
	free(temp);
	return numOfWords;

}

void append(char *s, char c)
{
    size_t len = strlen(s);
    s[len] = c;
    s[len + 1] = '\0';
}

void emptyBuffer()
{
	char ch;
	ch = getchar();
}
