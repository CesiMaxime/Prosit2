#include "Cesar.h"
#include <iostream>
#include <string>
#include <fstream>
#include "Encryption.h"
using namespace std;

int Cesar::getDecalage() {
	return this->decalage;
}

void Cesar::setDecalage(int decalage) {
	this->decalage = decalage;
}


Cesar::Cesar() : Encryption(){
	this->decalage = 1;
}

Cesar::Cesar(int decalage){
	this->decalage = decalage;
}

//cette fonction a été écrite en partie par chat gpt-3.5
void Cesar::cryptage() {

    string fichierEntree;
    if (type3 && crypt) {
        fichierEntree = "io/transition.txt";
    }
    else {
        fichierEntree = this->fileName;
    }

    ifstream fichierEntreeStream(fichierEntree);

    if (!fichierEntreeStream.is_open()) {
        cerr << "Erreur lors de l'ouverture du fichier d'entrée." << endl;
        return;
    }

    string fichierSortie;
    // Sélection du fichier de sortie en fonction de type3
    if (type3 && !crypt) {
        fichierSortie = "io/transition.txt";
    }
    else {
        fichierSortie = this->newFileName;
    }

    // Ouverture du fichier de sortie
    ofstream fichierSortieStream(fichierSortie);

    if (!fichierSortieStream.is_open()) {
        cerr << "Erreur lors de l'ouverture du fichier de sortie." << endl;
        fichierEntreeStream.close();
        return;
    }

    // Chiffrement ou déchiffrement du texte caractère par caractère
    char caractere;
    while (fichierEntreeStream.get(caractere)) {
        if (isalpha(caractere)) {
            char base = (isupper(caractere)) ? 'A' : 'a';
            int decalageApplique = (crypt) ? decalage : -decalage;
            caractere = static_cast<char>((caractere - base + decalageApplique + 26) % 26 + base);
        }

        fichierSortieStream.put(caractere);
    }

    // Fermeture des fichiers
    fichierEntreeStream.close();
    fichierSortieStream.close();

    string action = (crypt) ? "Chiffrement" : "Déchiffrement";
    cout << action << "Success. Saved file :" << fichierSortie << endl;
}
