#include <iostream>
#include <string>
#include <fstream>
#include "Xor.h"

string Xor::getClef() {
	return this->clef;
}

void Xor::setClef(string tclef) {
	this->clef = clef;
}


Xor::Xor() {
	this->clef = "11111111";

}

Xor::Xor(string tclef) {
	this->clef = clef;
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