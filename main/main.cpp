#include <fstream>
#include <iostream>
#include <string>
#include "Cesar.h"
#include "Xor.h"

int main()
{
    char command;
    int decalage;
    int typeCrypt;
    string clefXor;
    bool crypt = 0;

    Xor instanceXor;
    Cesar instanceCesar;

    instanceCesar.setType3(1);
    instanceXor.setType3(1);

    cout << "What type of encryption do you want? (1: Caesar, 2: Xor, 3: Double) \n";
    cin >> typeCrypt;

    cout << "Which file do you want to encrypt? Give the path if its not in this folder. \n";
    cin >> clefXor;
    instanceCesar.setFileName(clefXor);
    instanceXor.setFileName(clefXor);

    cout << "What name do you want for your encrypted file? Give the path if its not in this folder.\n";
    cin >> clefXor;
    instanceXor.setNewFileName(clefXor);
    instanceCesar.setNewFileName(clefXor);

    
    cout << "Do you want to encrypt or decrypt your file? (c, d)\n";
    cin >> command;
    if (command == 'c') {
        crypt = 0;
        instanceCesar.setCrypt(0);
        instanceXor.setCrypt(0);
        cout << "Cryptage";
    }
    else if (command == 'd') {
        crypt = 1;
        instanceCesar.setCrypt(1);
        instanceXor.setCrypt(1);
    }
    else {
        cout << "Invalid command: " << command << "\n";
    }

    if (typeCrypt == 1 || typeCrypt == 3) {
        cout << "What is the key for your Caesar encryption?";
        cin >> decalage;
        instanceCesar.setDecalage(decalage);
    }

    if (typeCrypt == 2 || typeCrypt == 3) {
        cout << "What is the key for your Xor encryption? 8 characteres)";

        cin >> clefXor;

        if (clefXor.size() == 8) {
            instanceXor.setClef(clefXor);
        }
        else {
            cout << "Incorrect Key, we will use the default one: 11111111";
        }

    }

    if (typeCrypt == 1) {
        instanceCesar.cryptage();
    }
    else if(typeCrypt == 2) {
        instanceXor.cryptage();
    }
    else if (typeCrypt == 3){
        if (crypt == 0) {
            instanceCesar.cryptage();
            instanceXor.cryptage();
        }
        else if (crypt == 1) {
            instanceXor.cryptage();
            instanceCesar.cryptage();
        }
        else {
            cout << "error";
        }
    }
    else {
        cout << "error";
    }
    

}