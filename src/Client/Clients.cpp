#include "Clients.h"
#include "stdlib.h"
#include <iostream>
#include <fstream>

namespace Client{
    Client::Client(/* args */)
    {
    }
    
    int Client::creer_client(const char * nomClient, const char * prenomClient, const char * sexe){

        std::string nom(nomClient);
        std::string prenom(prenomClient);

        Base client(maxNumeroGenerer, nom, prenom, sexe);
         
        
        Cellule<Base>* celluleClient;
        celluleClient = new Cellule<Base>(client);
        ajouter_trie(celluleClient);
        std::cout << *this->tete;
         
        tableClient.insert(std::pair<unsigned long,Cellule<Base> * >(maxNumeroGenerer,celluleClient));
        maxNumeroGenerer ++;
        //store
        
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
        while (!b->get().tester_reference(val) || b != sentinelle)
        {
            b = b->get_next();
        }
        if(b != sentinelle){
            enlever(*b);
            tableClient.erase(val);
        }
        sauvegarder_client();
        return 1;
    };

        int Client::mettre_a_jour_client(const char * nomClient, const char * prenomClient, const char * sexe){
        Base a (ref,nom,prix,quantite,seuil);
        Cellule<Base> b(a);
        Cellule<Base>* e = chercher(ref);
        if(e){
            (*e) = b;
        }
        sauvegarder(); 
        return 1;
    };

    Client::~Client()
    {
    }
}