#ifndef CLASS_H
#define CLASS_H

class getUserWantList {
	char *data;
public:
	void intro();
	void getdata(char inputData[]);
	void putdata();
	void dataFree();
	int selectIncludeOrNot();

	void getIncludeWordList(char word[]);
	void getNotIncludeWordList(char word[]);
};




#endif