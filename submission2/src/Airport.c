
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Airport.h"
#include "AirportManager.h"
#include "generalFunctions.h"


char* getValidWord(char* word, int totalLength, int actulLength)
{
	int len;
	char* temp = NULL, *newWord;
	len  = strlen(word) + 1;
	temp = (char*)malloc(len*sizeof(char));
	if(!temp)
	{
		printf("\nCan't allocate memory for the name");
		return NULL;
	}

	newWord = (char*)calloc(len, sizeof(char));
	if(!newWord)
	{
		printf("\nCan't allocate memory for the name");
		return NULL;
	}
	*newWord = '\0';
	strcpy(temp, word);
	char ch;
	int i;
	if(strlen(temp)%2 == 0)
	{
		for(i=0; i<len; i++)
		{
			if(i%2 == 0)
				ch = toupper(temp[i]);
			else
				ch = tolower(temp[i]);

			append(newWord, ch);
		}
		return newWord;
	}
	else
	{
		ch = temp[0]; //get the first letter
		if(actulLength == totalLength && totalLength > 1)
			ch = tolower(ch);
		else
			ch = toupper(ch);
		temp[0] = ch;
	}

	return temp;


}
char* validAirportName(char* inputName)//, char* updateName)
{
	int len, NOW;
	char* temp = NULL;
	len  = strlen(inputName) + 1;
	temp = (char*)malloc(len*sizeof(char));
	strcpy(temp, inputName);

	char* delimiters = " ";
	char* words;
	int actul = 0;
	char* tempWord;

	NOW = numOfWords(temp); //NOW - Num Of Words


	len = len + NOW - 1; //for each word above the first one we have to add 1 space

	inputName = realloc(inputName, len);
	if(!inputName)
	{
		printf("\nCan't aloocate memory\n");
		return NULL;
	}

	words = strtok(temp, delimiters);
	int prev=0;
	while (words != NULL)
	{
		actul++;
		tempWord = getValidWord(words, NOW, actul);

		if(NOW > 1 && actul < NOW) //add double space
		{
			tempWord = realloc(tempWord, strlen(tempWord)+3); // add 2 spaces and \0 total 3 chars
			if(!tempWord)
			{
				printf("\nCant aloocate memeory\n");
				return NULL;
			}
			strcat(tempWord, "  \0");
		}

		strcpy(inputName+prev, tempWord);
		prev = prev + strlen(tempWord);
		words = strtok(NULL, delimiters);
	}
	free(temp);
	free(tempWord);
	return inputName;
}
int IATARules(char* iata, char *iatasArray)//, AirportManager* am)
{
	if(!iata)
		return 0;
	if(strlen(iata) !=3)
		return 0;
	int i;
	for (i = 0; iata[i] != '\0'; i++) {
		if(isupper(iata[i]) == 0)
			return 0;
	}

	for(i=0; i< strlen(iatasArray); i+=3)
	{
	   char string_3l[4] = {'\0'};
	   strncpy(string_3l, iatasArray+i, 3);
	   if(strcmp(iata, string_3l) == 0)
	   {
		   printf("\nAlreadt exist!!!");
		   return 0;
	   }

	}
	return 1;
}
void printAirport(const Airport* airport)
{
	printf("\nAirport name is: %s,\ncountry Name: %s\n", airport->name, airport->countryName);
	printf("IATA: %s", airport->IATA);
}


int initAirport(Airport* theAirport, char *iatasArray)
{

	theAirport->name = createDynStr("Airport name: ");
	if(!theAirport->name) //allocation did not work
		return 0;
	theAirport->name = validAirportName(theAirport->name);

	theAirport->countryName = createDynStr("Airport countryName: ");
	if(!theAirport->countryName) //allocation did not work
		return 0;
	char* iata;
	do
	{
		iata = createDynStr("Airport IATA: [3 upper case letters only!] ");

	}while(IATARules(iata, iatasArray)!=1);

	strcpy(theAirport->IATA, iata);
	if(!theAirport->IATA) //allocation did not work
		return 0;

	return 1;
}

int checkEqualAirports (Airport *airport1, Airport *airport2)
{
	return check2IATA(airport1->IATA, airport2->IATA);
}

int checkAirportIATA( Airport *airport, char iata[])
{
	return check2IATA(airport->IATA, iata);
}

int check2IATA(char iata1[], char iata2[])
{
	int result;
	result = strcmp(iata1, iata2);
	if(result == 0)
		return 1;
	return 0;
}

void freeAirport(Airport* theAirport)
{
	free(theAirport->name);
	free(theAirport->countryName);


}

