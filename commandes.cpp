#ifndef COMMANDES_H_INCLUDE
#define COMMANDES_H_INCLUDE
#include "commande.h"
    namespace commande{
        /* 
            @brief classe de base d'un commande permettant d'effectuer des operation elementaire sur un commande
            @methodes:
                -update: qui permet de chercher une commande et de la mettre a jour
                -remove: qui permet de supprimer un commande 
                -create: qui permet de creer une nouvelle commande
                -load: qui permet de charger une commande a partir d'un fichier par defaut commande commande.txt
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
            int find();
            int load();
            int store();
        };
    }
#endif