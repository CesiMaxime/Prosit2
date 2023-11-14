#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    string monFichier = "io/test.txt";
    string fromfile;
    ofstream fichier(monFichier, ios::out | ios::trunc);

    if (fichier) 
    {
        fichier << "Hello world!";
        fichier.close();
    }
    else
        cerr << "Erreur à l'ouverture" << endl;

    ifstream fichierIn(monFichier, ios::in);

    if (fichierIn)
    {
        fichierIn >> fromfile;
        fichierIn.close();

    }
    else
        cerr << "Erreur à l'ouverture" << endl;

    ofstream fichierO("io/write.txt", ios::out | ios::trunc);

    if (fichierO)
    {
        fichierO << fromfile;
        fichierO.close();

    }
    else
        cerr << "Erreur à l'ouverture" << endl;
    return 0;
}