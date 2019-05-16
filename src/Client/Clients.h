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

    class Client:public Liste <Base> //client herite des propriete de la classe Base

    {
    private:
        std::map<unsigned long, Cellule<Base> * > tableClient;// Cree un tableau associatif de clients
        unsigned long maxNumeroGenerer;
        int sauvegarder_client();
        int charger_client();

    public:
        Client();
        
        ~Client();
        int creer_client(const char *, const char *, const char * , const char *);
        int supprimer_client(unsigned long);
        int mettre_a_jour_client(unsigned long, const char *, const char * , const char *, const char * );
        Cellule<Base>* chercher_client(const char *);
        Cellule<Base>* chercher_client(unsigned long);
        int charger_client(const char *);
        int sauvegarder_client(const char *);

        friend std::ostream& operator<<(std::ostream &, const Client &); // serialisation de données

        friend std::istream& operator>>(std::istream &, Client &); //déserialisation de données
        
    };
    
};
#endif