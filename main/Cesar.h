#pragma once

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#ifndef CESAR_H
#define CESAR_H
class Cesar {

private:
	bool crypt;
	bool type3;
	int decalage;
	string fileName;
	string newFileName;

public:
	bool getCrypt();
	void setCrypt(bool crypt);

	bool getType3();
	void setType3(bool type3);

	int getDecalage();
	void setDecalage(int decalage);

	string getFileName();
	void setFileName(string fileName);

	string getNewFileName();
	void setNewFileName(string newFileName);

	Cesar();
	Cesar(bool crypt, int decalage, string fileName, string newFileName);

	void cryptage();
};

#endif
