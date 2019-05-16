#include "Clients.h"
#include "stdlib.h"
#include <iostream>
#include <fstream>

namespace Client{

    Client::Client(){
        maxNumeroGenerer = 1; // initialisation des indentifiant des clients
        taille = 0;
        charger_client();
    }
    
    int Client::creer_client(const char * nomClient, const char * prenomClient, const char * dateN, const char * sexeC){

        std::string nom(nomClient);
        std::string prenom(prenomClient);
        std::string date(dateN);
        std::string sexe(sexeC);

        Base client(maxNumeroGenerer, nom, prenom, date, sexe);
         
        
        Cellule<Base>* celluleClient; // definition d'un pointeur vers une cellule client
        celluleClient = new Cellule<Base>(client);
        ajouter_trie(celluleClient);// fonction provenant du fichier liste
        std::cout << *this->tete;
         
        tableClient.insert(std::pair<unsigned long,Cellule<Base> * >(maxNumeroGenerer,celluleClient));
        maxNumeroGenerer ++;
        
        sauvegarder_client();
        return 1;
    }

    int Client::sauvegarder_client(){
        
        std::ofstream fichier(FSTOCKAGE_T);
        if(fichier){
            fichier << *this;
            fichier.close();
            std::cout << "sauvegarder\n";
        }else{
            std::cout << "erreur d'ouverture\n";
        }
     
        return 1;
    };

    int Client::supprimer_client(unsigned long val){
        Cellule<Base> * b = tete;
        std::cout <<"debut while\n";
        while (!b->get().tester_reference(val) && b != sentinelle)
        {
        std::cout << b->get();
        std::cout <<"\n";

            b = b->get_next();
        }
        std::cout <<"fin while\n";
        if(b != sentinelle){
            enlever(*b);
            tableClient.erase(val);
        }
        std::cout <<"if\n";
        sauvegarder_client();
        return 1;
    };

    int Client::mettre_a_jour_client(unsigned long num, const char * nomClient, const char * prenomClient, const char * date, const char * sexe){
        Base client (num,nomClient,prenomClient,date,sexe);
        Cellule<Base> cellule(client);
        Cellule<Base>* pointeurVersCel = chercher_client(num);
        if(pointeurVersCel){
            (*pointeurVersCel) = cellule;
        }
        sauvegarder_client(); 
        return 1;
    };
    /*
        methode de recherche d'un client 
        en fonction de son nom
    */
    Cellule<Base> * Client::chercher_client(const char * nom){
        Cellule<Base> * pointeVersCelClient = tete;
        while (pointeVersCelClient->get().tester_nom(nom) != 0 && pointeVersCelClient != sentinelle)
        {
            pointeVersCelClient = pointeVersCelClient->get_next();
        }
        if(pointeVersCelClient != sentinelle){
            return pointeVersCelClient;
        }
        return NULL;
    };
    Cellule<Base> * Client::chercher_client(unsigned long num){
        return tableClient[num];
    };  

    int Client::charger_client(){
        std::ifstream fichier(FSTOCKAGE_T);
        if(fichier){
            if(fichier.eof())return 0;
            if(fichier>>*this){
            fichier.close();    
            return 1;
            }
            fichier.close();
        }else{
            std::cout << "erreur d'ouverture\n";
        }

        return 0;
    }
    /*
        methode de serialisation des données
    */
    std::ostream& operator<<(std::ostream &fichierSortie, const Client &client) {
                fichierSortie << client.taille << ' ' <<client.maxNumeroGenerer ;
                Cellule<Base> * pointeurVersCelClient = client.tete;
                while (pointeurVersCelClient!=client.sentinelle)
                {
                    fichierSortie << ' ' << (*pointeurVersCelClient);
                    pointeurVersCelClient=pointeurVersCelClient->get_next();
                }
                return fichierSortie;
    };
    /*
        methode de deserialisation des
        données
    */

    std::istream& operator>>(std::istream &fichierALire, Client &client){
            if (!fichierALire) return fichierALire;
        
            unsigned int taille,maxNumeroGenerer;
            if (fichierALire >> taille >> maxNumeroGenerer){
                
                client.tete = client.sentinelle = new Cellule<Base>;
                Cellule<Base> * pointeurVersCelCient;
                Base  nouveauClient ;
                
                client.maxNumeroGenerer = maxNumeroGenerer;
                while (taille >0 )
                {
                    fichierALire >> nouveauClient;
                    pointeurVersCelCient = new Cellule<Base>(nouveauClient);
                    client.ajouter_trie(pointeurVersCelCient);
                    client.tableClient.insert(std::pair<unsigned long,Cellule<Base> * >(nouveauClient.get_numero(),pointeurVersCelCient));
                    taille--;
                }   
            }    
            return fichierALire;
        };

    Client::~Client()
    {
    }
}