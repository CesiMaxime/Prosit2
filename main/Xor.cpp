#include <iostream>
#include <string>
#include <fstream>
#include "Xor.h"


bool Xor::getCrypt() {
	return this->crypt;
}

void Xor::setCrypt(bool crypt) {
	this->crypt = crypt;
}

bool Xor::getType3() {
	return this->type3;
}

void Xor::setType3(bool type3) {
	this->type3 = type3;
}

string Xor::getClef() {
	return this->clef;
}

void Xor::setClef(string clef) {
	this->clef = clef;
}

string Xor::getFileName() {
	return this->fileName;
}

void Xor::setFileName(string fileName) {
	this->fileName = fileName;
}

string Xor::getNewFileName() {
	return this->newFileName;
}

void Xor::setNewFileName(string newFileName) {
	this->newFileName = newFileName;
}

Xor::Xor() {
	this->crypt = 0;
	this->type3 = 0;
	this->clef = "11111111";
	this->fileName = "io/test.txt";
	this->newFileName = "io/res.txt";

}

Xor::Xor(bool crypt, string clef, string fileName, string newFileName) {
	this->crypt = crypt;
	this->clef = clef;
	this->fileName = fileName;
	this->newFileName = newFileName;
}

void Xor::cryptage() {
    // Ouverture du fichier d'entrée
    string fichierEntree;
    string fichierSortie;

    if (type3 && !crypt) {
        fichierEntree = "io/transition.txt";
    }
    else {
        fichierEntree = this->fileName;
    }

    if (type3 && crypt) {
        fichierSortie = "io/transition.txt";
    }
    else {
        fichierSortie = this->newFileName;
    }


    ifstream fichierEntreeStream(fichierEntree, ios::binary);

    if (!fichierEntreeStream.is_open()) {
        cerr << "Erreur lors de l'ouverture du fichier d'entrée." << endl;
        return;
    }

    // Ouverture du fichier de sortie
    ofstream fichierSortieStream(fichierSortie, ios::binary);

    if (!fichierSortieStream.is_open()) {
        cerr << "Erreur lors de l'ouverture du fichier de sortie." << endl;
        fichierEntreeStream.close();
        return;
    }

    // Taille de la clé
    const size_t tailleClef = 8; // Taille fixe de 8 bits

    // Chiffrement XOR caractère par caractère
    char caractere;
    size_t indexClef = 0;

    while (fichierEntreeStream.get(caractere)) {
        // Appliquer le XOR uniquement aux caractères imprimables
        if (isprint(caractere)) {
            caractere ^= clef[indexClef];
            indexClef = (indexClef + 1) % tailleClef;
        }

        fichierSortieStream.put(caractere);
    }

    // Fermeture des fichiers
    fichierEntreeStream.close();
    fichierSortieStream.close();

    cout << "Success. Saved file :" << fichierSortie << endl;
}