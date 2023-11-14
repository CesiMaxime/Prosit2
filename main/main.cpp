#include <fstream>
#include <iostream>
#include <string>
#include "Cesar.h"
using namespace std;

int main()
{
    char command;
    int decalage;

    Cesar instanceCesar;
    cout << "voulez vous crypter ou decrypter votre fichier ? (c, d) \n";
    cin >> command;
    if (command == 'c') {
        instanceCesar.setCrypt(0);
        cout << "Cryptage";
    }
    else if (command == 'd') {
        instanceCesar.setCrypt(1);
    }
    else {
        cout << "Reponse invalide : " << command << "\n";
    }
    cout << "Quelle est la clef de votre cryptage ?";
    cin >> decalage;
    instanceCesar.setDecalage(decalage);

    cout << instanceCesar.getFileName();
    instanceCesar.cryptage();

}