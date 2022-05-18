#include "class.h"
#pragma warning(disable:4996)
using namespace std;

int checkInt(char str[], int sign) {
	int flag;

	while (1) { // Only get number, not minus or char value.
		flag = 0;
		if (sign == 0)
			cout << "Enter list's count: ";
		else // sign = 1
			cout << "Enter number: ";
		cin >> str;
		for (int i = 0; i < strlen(str); i++)
			if (isdigit(str[i]) == 0)
				flag = 1;

		if (flag == 0 && str[0] != '0')
			return stoi(str);
		else
			cout << "Please enter the valid value." << endl;
	}
	return -1;
	
}
void backgroundTop() {
	cout << "\n\n\n\n";
	/*
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 | (11 << 4));
	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ";
	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ";
	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ";
	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ";
	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ";
	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | (0 << 4));
	*/
}
void intro() {
	system(" mode con: lines=40 cols=80 | title Find List");
	backgroundTop();

	cout << setw(44) << "Find List\n" << endl;
	cout << setw(63) << "This is a program that finds the list you want.\n" << endl;
	cout << setw(117) << "──────────────────────────────────────────────────" << endl;
	cout << setw(52) << "How to use this program" << endl;
	cout << setw(96) << "────────────────────────────────────" << endl << endl;
	cout << setw(38) << "1. Enter a list size" << endl << endl;
	cout << setw(33) << "2. Enter a list" << endl << endl;
	cout << setw(51) << "3. Choose function and execute it" << endl << endl;
	cout << setw(70) << "enter 1, user can show current listand exit program" << endl << endl;
	cout << setw(69) << "enter 2, user can enter the wordand leaves an item" << endl;
	cout << setw(59) << "containing the word on the list" << endl << endl;
	cout << setw(69) << "enter 3, user can enter the wordand leaves an item" << endl;
	cout << setw(66) << "don’t containing the word on the list" << endl << endl;
	cout << setw(66) << "enter 4, user can show current listand continue" << endl;
	cout << setw(40) << "this program" << endl << endl;
	system("PAUSE");
	system("cls");
	backgroundTop();
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
		cout <<"- " << data << endl;
	}
}

void getUserWantList::dataFree() {
	delete[] data;
}

int getUserWantList::selectIncludeOrNot(char str[]) {
	int num = 0;
	cout << setw(117) << "┌──────────────────────────────────────────────────┐" << endl;
	cout << setw(15) << "│" << setw(44) << "Enter the number you want to perform." << setw(8) << "│" << endl;
	cout << setw(15) << "│" << setw(49) << "1. You can exit program and show current list." << setw(3) << "│" << endl; // 나중에 파일에 저장하는 걸로 수정
	cout << setw(15) << "│" << setw(43) << "2. Finds items that contain enterd word." << setw(9) << "│" << endl;
	cout << setw(15) << "│" << setw(47) << "3. Finds items that not contain enterd word." << setw(5) << "│" << endl;
	cout << setw(15) << "│" << setw(23) << "4. Show current list" << setw(29) << "│" << endl;
	cout << setw(117) << "└──────────────────────────────────────────────────┘" << endl;


	
	while (TRUE) {
		num = checkInt(str, 1);
		if (num != 1 && num != 2 && num != 3 && num != 4)
			cout << "Please enter the valid value." << endl;
		else
			break;
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
