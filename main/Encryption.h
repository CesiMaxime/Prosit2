#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#ifndef ENCRYPTION_H
#define ENCRYPTION_H
class Encryption
{
protected:
	static bool crypt;
	static bool type3;
	static string fileName;
	static string newFileName;

public:
	bool getCrypt();
	void setCrypt(bool crypt);

	bool getType3();
	void setType3(bool type3);

	string getFileName();
	void setFileName(string fileName);

	string getNewFileName();
	void setNewFileName(string newFileName);

	Encryption();

	virtual void cryptage() = 0;

};

#endif