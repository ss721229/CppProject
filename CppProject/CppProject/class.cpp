#include<iostream>
#include "class.h"
#pragma warning(disable:4996)
using namespace std;

//getUserWantList function
void getUserWantList::intro() {
	cout << "This is a program that finds the list you want" << endl;

}

void getUserWantList::getdata(char inputData[]) {
	gets_s(inputData, 50);
	data = new char[strlen(inputData) + 1];
	strcpy(data, inputData);
}

void getUserWantList::putdata() {
	if (data != NULL)
		cout << data << endl;
}

void getUserWantList::dataFree() {
	delete[] data;
}

int getUserWantList::selectIncludeOrNot() {
	int num;
	cout << "0. You can exit program and show current list" << endl; // 나중에 파일에 저장하는 걸로 수정
	cout << "1. Finds items that contain enterd word." << endl;
	cout << "2. Finds items that not contain enterd word." << endl;
	cin >> num;
	while (num != 0 && num != 1 && num != 2) {
		cout << "Enter correct number ( 0, 1, 2 )" << endl;
		cin >> num;
	}
	return num;
}


void getUserWantList::getIncludeWordList(char word[]) {
	int cntSameSpell = 0, checkWordFlag = 0;


	for (int i = 0; i < strlen(data); i++) {
		for (int j = 0; j < strlen(word); j++)
			if (data[i + j] == word[j])
				cntSameSpell++;

		if (cntSameSpell == strlen(word))
			checkWordFlag = 1;
		cntSameSpell = 0;
	}
	if (!checkWordFlag)
		data = NULL;

}


void getUserWantList::getNotIncludeWordList(char word[]) {
	int cntSameSpell = 0, checkWordFlag = 0;


	for (int i = 0; i < strlen(data); i++) {
		for (int j = 0; j < strlen(word); j++)
			if (data[i + j] == word[j])
				cntSameSpell++;

		if (cntSameSpell == strlen(word))
			checkWordFlag = 1;
		cntSameSpell = 0;
	}
	if (checkWordFlag)
		data = NULL;
}
