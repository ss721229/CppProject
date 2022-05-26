#include "class.h"
#pragma warning(disable:4996)
using namespace std;

int checkInt(char str[], int sign) { // Only get number, not minus or char value.
	int flag;

	while (1) { 
		flag = 0;

		if (sign == 0)
			cout << "Enter the number of items: ";
		else if(sign == 1)
			cout << "Enter number: ";
		else if(sign == 2)
			cout << "Enter string length(less than or equal): ";
		else if(sign==3)
			cout << "Enter string length(more than or equal): ";

		cin >> str;

		for (int i = 0; i < strlen(str); i++)
			if (isdigit(str[i]) == 0)
				flag = 1;

		if (flag == 0 && str[0] != '0') // if str isn't number, user can show error and enter word again.
			return stoi(str);
		else
			cout << "Please enter the valid value." << endl;
	}
	
}
void backgroundTop() {
	cout << "\n\n\n\n";
}
void intro() { // show first
	system(" mode con: lines=40 cols=80 | title Find List");
	backgroundTop();

	cout << setw(45) << "Find List\n" << endl;
	cout << setw(64) << "This is a program that finds the list you want.\n" << endl;
	cout << setw(114) << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
	cout << setw(51) << "How to use this program" << endl;
	cout << setw(93) << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl << endl;
	cout << setw(36) << "1. Enter the list size" << endl << endl;
	cout << setw(28) << "2. Enter items" << endl << endl;
	cout << setw(47) << "3. Choose function and execute it" << endl << endl;
	cout << setw(67) << "Enter 1, user can save current list and exit program" << endl << endl;
	cout << setw(62) << "Enter 2, user can enter the wordand leave items" << endl;
	cout << setw(55) << "containing the word on the list" << endl << endl;
	cout << setw(63) << "Enter 3, user can enter the word and leave items" << endl;
	cout << setw(59) << "not containing the word on the list" << endl << endl;
	cout << setw(65) << "Enter 4, user can enter the number and leave items" << endl;
	cout << setw(65) << "whose string length is less than or equal" << endl << endl;
	cout << setw(65) << "Enter 5, user can enter the number and leave items" << endl;
	cout << setw(65) << "whose string length is more than or equal" << endl << endl;
	cout << setw(63) << "enter 6, user can show current list and continue" << endl;
	cout << setw(36) << "this program" << endl << endl;
	system("PAUSE");
	system("cls");
	backgroundTop();
}

void programFunc() {
	cout << setw(117) << "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖" << endl;
	cout << setw(15) << "弛" << setw(44) << "Enter the number you want to perform." << setw(8) << "弛" << endl;
	cout << setw(15) << "弛" << setw(49) << "1. You can exit program and save current list." << setw(3) << "弛" << endl;
	cout << setw(15) << "弛" << setw(42) << "2. Find items that contain enterd word." << setw(10) << "弛" << endl;
	cout << setw(15) << "弛" << setw(46) << "3. Find items that not contain enterd word." << setw(6) << "弛" << endl;
	cout << setw(15) << "弛" << setw(49) << "4. Find Items are less than or equal to number" << setw(3) << "弛" << endl;
	cout << setw(15) << "弛" << setw(49) << "5. Find Items are more than or equal to number" << setw(3) << "弛" << endl;
	cout << setw(15) << "弛" << setw(23) << "6. Show current list" << setw(29) << "弛" << endl;
	cout << setw(117) << "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;
}

//getUserWantList function
void getUserWantList::getdata(char inputData[]) {
	cout << "- ";
	gets_s(inputData, 50);
	data = new char[strlen(inputData) + 1];
	strcpy(data, inputData);
}

void getUserWantList::putdata() {
	if (data != NULL) {
		cout << "- " << data << endl;
	}
}
char* getUserWantList::returnDataStr() {
	return data;
}

void getUserWantList::dataFree() {
	delete[] data;
}

int getUserWantList::selectIncludeOrNot(char str[]) {
	int num = 0;
	programFunc();
	
	while (TRUE) {
		num = checkInt(str, 1);
		getchar();
		if (num != 1 && num != 2 && num != 3 && num != 4 && num != 5 && num != 6)
			cout << "Please enter the valid value." << endl;
		else
			break;
	}
	return num;
}

void getUserWantList::getIncludeWordList(char word[]) {
	int cntSameSpell = 0, checkWordFlag = 0;

	if (data != NULL) {
		for (int i = 0; i < strlen(data); i++) {
			for (int j = 0; j < strlen(word); j++)
				if (data[i + j] == word[j])
					cntSameSpell++;
			if (cntSameSpell == strlen(word))
				checkWordFlag = 1;
			cntSameSpell = 0;
		}
	}
	if (!checkWordFlag)
		data = NULL;

}

void getUserWantList::getNotIncludeWordList(char word[]) {
	int cntSameSpell = 0, checkWordFlag = 0;

	if (data != NULL) {
		for (int i = 0; i < strlen(data); i++) {
			for (int j = 0; j < strlen(word); j++)
				if (data[i + j] == word[j])
					cntSameSpell++;
			if (cntSameSpell == strlen(word))
				checkWordFlag = 1;
			cntSameSpell = 0;
		}
	}
	if (checkWordFlag)
		data = NULL;
}

void getUserWantList::getStrlenLessOrEqual(char word[], int numStrlen) {
	int cntStrlen = 0;

	if (data != NULL) {
		for (int i = 0; i < strlen(data); i++) {
			if (data[i] != NULL)
				cntStrlen++;
		}
		if (cntStrlen > numStrlen)
			data = NULL;
	}
}
void getUserWantList::getStrlenMoreOrEqual(char word[], int numStrlen) {
	int cntStrlen = 0;

	if (data != NULL) {
		for (int i = 0; i < strlen(data); i++) {
			if (data[i] != NULL)
				cntStrlen++;
		}
		if (cntStrlen < numStrlen)
			data = NULL;
	}
}
