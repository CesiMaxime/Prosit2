#pragma once
#include "Encryption.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#ifndef XOR_H
#define XOR_H

class Xor : public Encryption
{
private:
	string clef;

public:

	string getClef();
	void setClef(string tclef);

	Xor();
	Xor(string tclef);

	void cryptage();
};
#endif