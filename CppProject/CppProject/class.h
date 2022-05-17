#ifndef CLASS_H
#define CLASS_H

#include<string>
#include<iostream>
#include<iomanip>
#include<Windows.h>

class getUserWantList {
	char *data;
public:

	void getdata(char inputData[]);
	void putdata();
	void dataFree();
	int selectIncludeOrNot(char str[]);

	void getIncludeWordList(char word[]);
	void getNotIncludeWordList(char word[]);


};

void intro();
void backgroundTop();
int checkInt(char str[], int sign);


#endif