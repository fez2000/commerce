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
    
    typeId Client::creer_client(const char * nomClient, const char * prenomClient, Date::Date date, const char * sexeC){

        std::string nom(nomClient);
        std::string prenom(prenomClient);
        std::string sexe(sexeC);

        Base client(maxNumeroGenerer, nom, prenom, date, sexe);
         
        
        Cellule<Base>* celluleClient; // definition d'un pointeur vers une cellule client
        celluleClient = new Cellule<Base>(client);
        ajouter_trie(celluleClient);// fonction provenant du fichier liste
        std::cout <<"\n";
        std::cout <<"\n";
        std::cout <<"\n";
         
        tableClient.insert(std::pair<typeId,Cellule<Base> * >(maxNumeroGenerer,celluleClient));
        maxNumeroGenerer ++;
        
        if(sauvegarder_client() == ERROR_CODE){
            return ERROR_CODE;
        };
        return maxNumeroGenerer - 1;
    }
    Liste<Base> Client::liste_ayant_nom(const char * nomArticle){
        Liste<Base> l;
        Cellule<Base> * i;
        
        i=tete;
        while(i!=sentinelle){
            std::string nom(i->get().get_nom());
            if( nom.find(nomArticle) <nom.length() ){
               l.ajouter(new Cellule<Base>(i->get())); 
            }
            i = i->get_next();
        }
        return l;
    };
    int Client::sauvegarder_client(){
        
        std::ofstream fichier;
        fichier.exceptions ( std::ofstream::failbit | std::ofstream::badbit );
        try{
            fichier.open(FSTOCKAGE_T);
            if(fichier){
                fichier << *this;
                fichier.close();
                std::cout <<"\n";
                std::cout << "\t\033[33;1m##----------------------------------------------------------------------------------------------------------##\n";
                std::cout << "\t##\033[33;0m                                   \033[36;1mOperation effectuer avec SUCCES !\033[36;0m                                      \033[33;1m##\n";
                std::cout << "\t##----------------------------------------------------------------------------------------------------------##\033[33;0m\n"; 
            }
        }
        catch(std::ofstream::failure& ex){
            return ERROR_CODE;
        } 
        return SUCCESS_CODE;
    };
/*
    fonction de suppression d'un client dans notre
    liste de client
*/
    int Client::supprimer_client(typeId val){
        Cellule<Base> * b = tete;
        while (!b->get().tester_reference(val) && b != sentinelle)
        {
        //std::cout << b->get();
        std::cout <<"\n";

            b = b->get_next();
        }
        if(b != sentinelle){
            enlever(*b);
            tableClient.erase(val);
        }
        return sauvegarder_client();
    };

    int Client::mettre_a_jour_client(typeId num, const char * nomClient, const char * prenomClient, Date::Date date, const char * sexe){
        Base client (num,nomClient,prenomClient,date,sexe);
        Cellule<Base> cellule(client);
        Cellule<Base>* pointeurVersCel = chercher_client(num);
        if(pointeurVersCel){
            (*pointeurVersCel) = cellule;
        }
        trier();
        return sauvegarder_client(); 
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
    Cellule<Base> * Client::chercher_client(typeId num){
        return tableClient[num];
    };  

    int Client::charger_client(){
        std::ifstream fichier;
        fichier.exceptions ( std::ifstream::failbit | std::ifstream::badbit );
        try{
            fichier.open((FSTOCKAGE_T));
            if(fichier){
                if(fichier.eof())return 0;
                if(fichier>>*this){
                fichier.close();    
                return SUCCESS_CODE;
                }
                fichier.close();
            }
        }
        catch(std::ifstream::failure& ex){
            //std::cout << strerror( errno ) << std::endl;
            return ERROR_CODE;
        }
        return SUCCESS_CODE;
    }
    /*
        methode de serialisation des données
    */
    std::ostream& operator<<(std::ostream &fichierSortie, const Client &client) {
                fichierSortie << client.taille << ' ' <<client.maxNumeroGenerer ;
                Cellule<Base> * pointeurVersCelClient = client.tete;
                while (pointeurVersCelClient!=client.sentinelle)
                {
                    fichierSortie << '\n' << (*pointeurVersCelClient);
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
    
        unsigned int taille;
        typeId maxNumeroGenerer;
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
                client.tableClient.insert(std::pair<typeId,Cellule<Base> * >(nouveauClient.get_numero(),pointeurVersCelCient));
                taille--;
            }   
        }    
        return fichierALire;
    };

    Client::~Client()
    {
    }
}