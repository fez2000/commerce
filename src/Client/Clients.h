#ifndef CLIENTS_H_INCLUDE
#define CLIENTS_H_INCLUDE
#include "Client.h"
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
    class Client
    {
    private:
        /* data */
    public:
        Client(/* args */);
        ~Client();
        int create();
        int remove();
        int update();
        Base find();
        int load();
        int store();
    };
    
}
#endif