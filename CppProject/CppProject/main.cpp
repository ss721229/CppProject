#include<iostream>
#include "class.h"
#pragma warning(disable:4996)
using namespace std;

int main() {
	getUserWantList* obj = NULL;
	char inputData[50], word[20];
	int N, num = 1;

	cout << "Enter list's count: ";
	cin >> N;
	getchar();
	cout << endl;
	obj = new getUserWantList[N];

	if (obj == NULL) {
		cout << "Error" << endl;
		return -1;
	}

	cout << "Enter your list" << endl;
	for (int i = 0; i < N; i++) // get list
		obj[i].getdata(inputData);



	while (num != 0) {
		num = obj->selectIncludeOrNot();
		if (num == 0) {
			cout << endl << "Currnt list" << endl;
			for (int i = 0; i < N; i++)
				obj[i].putdata();
		}
		else if (num == 1) {
			cout << "Enter contain word: ";
			cin >> word;
			for (int i = 0; i < N; i++)
				obj[i].getIncludeWordList(word);
		}
		else { // num = 2
			cout << "Enter not contain word: ";
			cin >> word;
			for (int i = 0; i < N; i++)
				obj[i].getNotIncludeWordList(word);
		}
	}






	for (int i = 0; i < N; i++) // free dynamic allocation
		obj[i].dataFree();
	delete[] obj;

	return 0;
}