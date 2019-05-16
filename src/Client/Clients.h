#ifndef CLIENTS_H_INCLUDE
#define CLIENTS_H_INCLUDE
#include "Client.h"
#include "../Cellule/Cellule.h"
#include "../Liste/Liste.h"
#define FLECTURE  "./BD/dico_client.txt"
#define FSTOCKAGE_T  "./BD/dico_client.temporaire.txt"
#define FSTOCKAGE_D  "./BD/dico_client.txt" 
#include <iostream>
#include <map>
namespace Client{
    /* 
        @brief classe de base d'un client permettant d'effectuer des operation elementaire sur un client
        @methodes:
            -update: qui permet de chercher un client un client et de le mettre a jour
            -remove: qui permet de supprimer un client 
            -create: qui permet de creer un nouveau client
            -load: qui permet de charger un client un client a partir d'un fichier par defaut client client.txt
            -store: qui permet de specifier ou serons sauvegerder les cleints par defaut sur le fichier de load si pas specifier
    */
    class Client:public Liste <Base> //client herite des propriete de la classe Base

    {
    private:
        std::map<unsigned long, Cellule<Base> * > tableClient;// Cree un tableau associatif de clients
        unsigned long maxNumeroGenerer;
        int sauvegarder_client();

    public:
        Client(/* args */);
        ~Client();
        int creer_client(const char * nom_client, const char * prenom_client, const char * sexs);
        int supprimer_client(unsigned long);
        int mettre_a_jour_client(const char * nomClient, const char * prenomClient, const char * sexe);
        Base find();
        int charger_client();
        int sauvegarder_client(const char *);

        static Client deserialiser(std::istream&);

        friend std::ostream& operator<<(std::ostream &os, const Client &gestClient) {
            os << gestClient.taille << ' ' <<gestClient.maxNumeroGenerer ;
            Cellule<Base> * pointeurClient = gestClient.tete;
            while (pointeurClient != gestClient.sentinelle){
                std::cout << (*pointeurClient) << std::endl;
                os << ' ' << (*pointeurClient);
                pointeurClient = pointeurClient->get_next();
            }
            return os;
        };

        friend std::istream& operator>>(std::istream &is, Client &b){
        
        };
    };
    
}
#endif