#ifndef CLASS_H
#define CLASS_H

#include<string>
#include<iostream>
#include<iomanip>
#include<fstream>
#include<Windows.h>

class getUserWantList {
	char *data;
public:

	void getdata(char inputData[]);
	void putdata();
	void dataFree();
	char* saveListOnTheFile();
	int selectIncludeOrNot(char str[]);

	void getIncludeWordList(char word[]);
	void getNotIncludeWordList(char word[]);
	void getStrlenLessOrEqual(char word[], int numStrlen);
	void getStrlenMoreOrEqual(char word[], int numStrlen);

};

void intro();
void backgroundTop();
int checkInt(char str[], int sign);


#endif