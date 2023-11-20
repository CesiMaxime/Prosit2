#include "Encryption.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool Encryption::crypt = 0;
bool Encryption::type3 = 0;
string Encryption::fileName = "io/test1";
string Encryption::newFileName = "io/res";

bool Encryption::getCrypt() {
	return this->crypt;
}

void Encryption::setCrypt(bool crypt) {
	this->crypt = crypt;
}

bool Encryption::getType3() {
	return this->type3;
}

void Encryption::setType3(bool type3) {
	this->type3 = type3;
}

string Encryption::getFileName() {
	return this->fileName;
}

void Encryption::setFileName(string fileName) {
	this->fileName = fileName;
}

string Encryption::getNewFileName() {
	return this->newFileName;
}

void Encryption::setNewFileName(string newFileName) {
	this->newFileName = newFileName;
}

Encryption::Encryption() {

}