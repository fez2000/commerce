#ifndef COMMANDES_H_INCLUDE
#define COMMANDES_H_INCLUDE
#include "commande.h"
    namespace commande{
        /* 
            @brief classe de base d'un commande permettant d'effectuer des operation elementaire sur un commande
            @methodes:
                -update: qui permet de chercher un commande un commande et de le mettre a jour
                -remove: qui permet de supprimer un commande 
                -create: qui permet de creer un nouveau commande
                -load: qui permet de charger un commande un commande a partir d'un fichier par defaut commande commande.txt
                -store: qui permet de specifier ou serons sauvegerder les cleints par defaut sur le fichier de load si pas specifier
        */
        class commande
        {
        private:
            /* data */
        public:
            commande(/* args */);
            ~commande();
            int create();
            int remove();
            int update();
            base find();
            int load();
            int store();
        };
    }
#endif