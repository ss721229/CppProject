#include "class.h"
#pragma warning(disable:4996)
using namespace std;

int main() {
	getUserWantList* obj = NULL;
	char inputData[50], word[20], Nchar[5];
	int Nint, num = 0;

	intro();


	Nint = checkInt(Nchar, 0);
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
		if (num == 1) {
			cout << endl << "Currnt list" << endl;
			for (int i = 0; i < Nint; i++)
				obj[i].putdata();
		}
		else if (num == 2) {
			cout << "Enter contain word: ";
			cin >> word;
			for (int i = 0; i < Nint; i++)
				obj[i].getIncludeWordList(word);
		}
		else if (num == 3) { // num = 2
			cout << "Enter not contain word: ";
			cin >> word;
			for (int i = 0; i < Nint; i++)
				obj[i].getNotIncludeWordList(word);
		}
		else { // num = 4
			system("cls");
			cout << endl << "Currnt list" << endl;
			for (int i = 0; i < Nint; i++)
				obj[i].putdata();
			cout << endl;
			system("PAUSE");
			system("cls");
		}
	}



	for (int i = 0; i < Nint; i++) // free dynamic allocation
		obj[i].dataFree();
	delete[] obj;

	return 0;
}