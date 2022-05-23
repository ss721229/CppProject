#include "class.h"
#pragma warning(disable:4996)
using namespace std;

int main() {
	// obj: saving list datas
	// inputData: word user enter(on the list)
	// word: word user enter(find items containing or not)
	// Nchar: variarion to check number, not word(translate int)
	// Nint: list number, num: function number, cntToCheckItemExist: after using function, check items exist on the list
	// ofstream: 
	getUserWantList* obj = NULL;
	char inputData[50], word[20], Nchar[5];
	int Nint, num = 0, numStrlen, cntToCheckItemExist = 0;
	ofstream listFile("test.txt");

	intro();

	Nint = checkInt(Nchar, 0); // enter list number and dynamic allocation
	getchar();
	cout << endl;
	obj = new getUserWantList[Nint];

	if (obj == NULL) {
		cout << "Error" << endl;
		return -1;
	}

	cout << "Enter your list ( number: " << Nint << " )" << endl;
	for (int i = 0; i < Nint; i++) // get list
		obj[i].getdata(inputData);

	while (num != 1) {
		num = obj->selectIncludeOrNot(Nchar);

		if (num == 1) { // put list and exit the program
			system("cls");
			backgroundTop();
			cout << endl << "Currnt list" << endl;
			for (int i = 0; i < Nint; i++)
				obj[i].putdata();

			//파일 저장
			if (!listFile) {
				cout << "File is not opened.";
				exit(-1);
			}
			for (int i = 0; i < Nint; i++)
				if (obj[i].returnDataStr() != NULL)
					listFile << obj[i].returnDataStr() << endl;

			listFile.close();


			for (int i = 0; i < Nint; i++) // free dynamic allocation
				obj[i].dataFree();
			delete[] obj;

			exit(0);
		}
		else if (num == 2) { // get a list containing entered word
			cout << "Enter contain word: ";
			cin >> word;
			for (int i = 0; i < Nint; i++)
				obj[i].getIncludeWordList(word);
		}
		else if (num == 3) { // get a list don't containing entered word
			cout << "Enter not contain word: ";
			cin >> word;
			for (int i = 0; i < Nint; i++)
				obj[i].getNotIncludeWordList(word);
		}
		else if (num == 4) {
			numStrlen = checkInt(Nchar, 2);
			for (int i = 0; i < Nint; i++)
				obj[i].getStrlenLessOrEqual(word, numStrlen);
		}
		else if (num == 5) {
			numStrlen = checkInt(Nchar, 3);
			for (int i = 0; i < Nint; i++)
				obj[i].getStrlenMoreOrEqual(word, numStrlen);
		}
		else { // num = 6, print current list
			system("cls");
			backgroundTop();
			cout << endl << "Currnt list" << endl;
			for (int i = 0; i < Nint; i++)
				obj[i].putdata();

		}
		cout << endl;
		system("PAUSE");
		system("cls");
		backgroundTop();

		if (num == 2 || num == 3 || num == 4 || num == 5) { // if there is no item, exit the program
			for (int i = 0; i < Nint; i++)
				if (obj[i].returnDataStr() != NULL)
					cntToCheckItemExist++;
			if (cntToCheckItemExist == 0) {
				system("cls");
				backgroundTop();
				cout << "Exit the program because the list is empty." << endl;
				exit(0);
			}
			cntToCheckItemExist = 0;
		}
	}
	return 0;
}