#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#ifndef XOR_H
#define XOR_H

class Xor
{
private:
	bool crypt;
	bool type3;
	string clef;
	string fileName;
	string newFileName;

public:
	bool getCrypt();
	void setCrypt(bool crypt);

	bool getType3();
	void setType3(bool type3);

	string getClef();
	void setClef(string decalage);

	string getFileName();
	void setFileName(string fileName);

	string getNewFileName();
	void setNewFileName(string newFileName);

	Xor();
	Xor(bool crypt, string decalage, string fileName, string newFileName);

	void cryptage();
};
#endif