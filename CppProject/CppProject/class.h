#ifndef CLASS_H
#define CLASS_H

#include<string>
#include<iostream>
#include<iomanip>
#include<fstream>
#include<Windows.h>


void intro(); // Prints the program name and usage
void backgroundTop(); // check that input is numeric
void programFunc(); // Prints a description of the function
int checkInt(char str[], int sign);

class getUserWantList {
	char *data;
public:

	void getdata(char inputData[]); // Enter text and store it in Data using dynamic assignments
	void putdata(); // cout Data
	void dataFree(); // Data Free
	char* returnDataStr(); // Data return function to save to file, check if list is empty
	int selectIncludeOrNot(char str[]); // check that the user entered numbers 1 to 6

	void getIncludeWordList(char word[]); // Leave only items containing word strings
	void getNotIncludeWordList(char word[]); // Leave only items not containing word strings
	void getStrlenLessOrEqual(char word[], int numStrlen); // Leave only items with string length less than or equal to numStrlen
	void getStrlenMoreOrEqual(char word[], int numStrlen); // Leave only items with string length more than or equal to numStrlen

};

#endif

