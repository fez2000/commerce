#ifndef COMMANDES_H_INCLUDE
#define COMMANDES_H_INCLUDE
#include "Commande.h"
#include "../Cellule/Cellule.h"
#include "../Liste/Liste.h"
#define FICHIERSTOCKC  "./BD/commande.txt"
#define FICHIERSTOCKTEMPC  "./BD/commande.temporaire.txt"
#define FICHIERSTOCKC  "./BD/commande.txt" 
#include <iostream>
#include <map>
    namespace Commande{
        /* 
            @brief classe de base d'un commande permettant d'effectuer des operation elementaire sur un commande
            @methodes:
                -update: qui permet de chercher une commande et de la mettre a jour
                -remove: qui permet de supprimer un commande 
                -create: qui permet de creer une nouvelle commande
                -load: qui permet de charger une commande a partir d'un fichier par defaut commande commande.txt
                -store: qui permet de specifier ou serons sauvegerder les cleints par defaut sur le fichier de load si pas specifier
        */
        class Commande:Liste<Base>
        {
        private:
            std::map<unsigned long, Cellule<Base> * > table;//map fonction de la lib map qui permet de creer les tableaux associatifs
            unsigned long maxNumeroGenerer;//plus grand id generer
            int sauvegarder();
            int charger();
        public:
            Commande(/* args */);
            int creer(unsigned long,unsigned long,unsigned long);
            int supprimer(unsigned long);
            int modifier(unsigned long,unsigned long,unsigned long,unsigned long,int);
            Cellule<Base>* chercher(unsigned long);
            Liste<Base> commandes_de(unsigned long);
            int charger(const char *);
            int sauvegarder(const char *);
            friend std::ostream& operator<<(std::ostream &, const Commande &);
            friend std::istream& operator>>(std::istream &is, Commande &b);   
        
        };
    };
#endif