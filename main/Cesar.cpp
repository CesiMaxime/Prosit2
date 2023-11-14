#include "Cesar.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool Cesar::getCrypt() {
	return this->crypt;
}

void Cesar::setCrypt(bool crypt) {
	this->crypt = crypt;
}

bool Cesar::getType3() {
	return this->type3;
}

void Cesar::setType3(bool type3) {
	this->type3 = type3;
}

int Cesar::getDecalage() {
	return this->decalage;
}

void Cesar::setDecalage(int decalage) {
	this->decalage = decalage;
}

string Cesar::getFileName() {
	return this->fileName;
}

void Cesar::setFileName(string fileName) {
	this->fileName = fileName;
}

string Cesar::getNewFileName() {
	return this->newFileName;
}

void Cesar::setNewFileName(string newFileName) {
	this->newFileName = newFileName;
}

Cesar::Cesar() {
	this->crypt = 0;
    this->type3 = 0;
	this->decalage = 1;
	this->fileName = "io/test.txt";
	this->newFileName = "io/res.txt";

}

Cesar::Cesar(bool crypt, int decalage, string fileName, string newFileName) {
	this->crypt = crypt;
	this->decalage = decalage;
	this->fileName = fileName;
	this->newFileName = newFileName;
}

//cette fonction a été écrite en partie par chat gpt-3.5
void Cesar::cryptage() {
    // Ouverture du fichier d'entrée
    ifstream fichierEntree(fileName);

    if (!fichierEntree.is_open()) {
        cerr << "Erreur lors de l'ouverture du fichier d'entrée." << endl;
        return;
    }

    // Sélection du fichier de sortie en fonction de type3
    string fichierSortie = (type3) ? "io/transition.txt" : newFileName;

    // Ouverture du fichier de sortie
    ofstream fichierSortieStream(fichierSortie);

    if (!fichierSortieStream.is_open()) {
        cerr << "Erreur lors de l'ouverture du fichier de sortie." << endl;
        fichierEntree.close();
        return;
    }

    // Chiffrement ou déchiffrement du texte caractère par caractère
    char caractere;
    while (fichierEntree.get(caractere)) {
        if (isalpha(caractere)) {
            char base = (isupper(caractere)) ? 'A' : 'a';
            int decalageApplique = (crypt) ? decalage : -decalage;
            caractere = static_cast<char>((caractere - base + decalageApplique + 26) % 26 + base);
        }

        fichierSortieStream.put(caractere);
    }

    // Fermeture des fichiers
    fichierEntree.close();
    fichierSortieStream.close();

    string action = (crypt) ? "Chiffrement" : "Déchiffrement";
    cout << action << " terminé. Résultat sauvegardé dans " << fichierSortie << endl;
}
