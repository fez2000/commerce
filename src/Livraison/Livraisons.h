#ifndef COMMANDES_H_INCLUDE
#define COMMANDES_H_INCLUDE
#include "Livraison.h"
#include "../Cellule/Cellule.h"
#include "../Liste/Liste.h"
#define FICHIERSTOCKL  "./BD/livraison.txt"
#define FICHIERSTOCKTEMPL  "./BD/livraison.temporaire.txt"
#define FICHIERSTOCKL  "./BD/livraison.txt" 
#include <map>
    namespace Livraison{
        /* 
            @brief classe de base d'une Livraison permettant d'effectuer des operation elementaire sur une Livraison
                        @proprietes:
                -table: tableau qui lie d'id d'une commande et sa cellule;
                -maxNumeroGenerer: represente l'id de la prochaine de Livraison a creer
            @methodes:
                -update: qui permet de chercher une Livraison et de la mettre a jour
                -remove: qui permet de supprimer un commande 
                -create: qui permet de creer une nouvelle commande
                -load: qui permet de charger une commande a partir d'un fichier par defaut commande commande.txt
                -store: qui permet de specifier ou serons sauvegerder les cleints par defaut sur le fichier de load si pas specifier
        */
        class Livraison:public Liste<Base>
        {
        private:
            std::map<typeId, Cellule<Base> * > table;//map fonction de la lib map qui permet de creer les tableaux associatifs
            typeId maxNumeroGenerer;//plus grand id generer
            int sauvegarder();
            int charger();
        public:
            Livraison(/* args */);
            typeId creer(typeId,typeId,unsigned long);
            int supprimer(typeId);
            int modifier(typeId,typeId,typeId,unsigned long);
            Cellule<Base>* chercher(typeId);
            Liste<Base> livraisons_de(typeId);
            Cellule<Base> * livraisons_apropos(typeId);
            int charger(const char *);
            int sauvegarder(const char *);
            friend std::ostream& operator<<(std::ostream &, const Livraison &);
            friend std::istream& operator>>(std::istream &, Livraison &);   
        
        };
    };
#endif