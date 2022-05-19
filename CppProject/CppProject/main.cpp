#include "class.h"
#pragma warning(disable:4996)
using namespace std;

int main() {
	// obj: saving list datas
	// inputData: word user enter(on the list)
	// word: word user enter(find items containing or not)
	// Nchar: variarion to check number, not word(translate int)
	// Nint: list number, num: function number
	getUserWantList* obj = NULL; 
	char inputData[50], word[20], Nchar[5]; 
	int Nint, num = 0; 

	intro();

	Nint = checkInt(Nchar, 0); // enter list number and dynamic allocation
	getchar();
	cout << endl;
	obj = new getUserWantList[Nint];

	if (obj == NULL) {
		cout << "Error" << endl;
		return -1;
	}

	cout << "Enter your list ( number: " << Nint <<" )" << endl;
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
		else { // num = 4, print current list
			system("cls");
			backgroundTop();
			cout << endl << "Currnt list" << endl;
			for (int i = 0; i < Nint; i++)
				obj[i].putdata();

			cout << endl;
			system("PAUSE");
			system("cls");
			backgroundTop();
		}
	}

	return 0;
}