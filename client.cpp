#include <fstream>

#include "client.h"

namespace client{
using namespace std;

    client::Base(int num_client, char nom_client, char prenom_client, char date_naiss_client, char sexe):
        num_client(numero_client), nom_client(nom_client), prenom_client(prenom_client), date_naiss_client(date_naiss_client), sexe(sexe)
    {
        ofstream fichier("BD/CLIENT/dico_client.txt", ios::out | ios::trunc);  //déclaration du flux et ouverture du fichier
        
        if(fichier){  // si l'ouverture a réussi

            // enregistrement des donnees
            fichier << "Client numero: " << num_client << endl;
            fichier << "Noms: " << nom_client << endl;
            fichier << "Prenom: " << prenom_client << endl;
            fichier << "Date de naissance: " << date_naiss_client << endl;
            fichier << "Sexe: " << sexe << endl;
            fichier << "\n";
 
            fichier.close();  // fermeture du fichier
                }/*
                else{// sinon, on affiche ce message d'erreur
                        cout << "Erreur à l'ouverture !" << endl;
                } */
    }
    
    Base::~Base()
    {
    }
} // client
}
    