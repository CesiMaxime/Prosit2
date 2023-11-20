#pragma once
#include "Encryption.h"
using namespace std;
#include <iostream>
#include <string>
#include <fstream>


#ifndef CESAR_H
#define CESAR_H
class Cesar : public Encryption {

private:
	int decalage;

public:

	int getDecalage();
	void setDecalage(int decalage);

	Cesar();
	Cesar(int decalage);

	void cryptage();
};

#endif
