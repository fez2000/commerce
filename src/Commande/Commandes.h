#ifndef COMMANDES_H_INCLUDES
#define COMMANDES_H_INCLUDES
#include "Commande.h"
#include "../Cellule/Cellule.h"
#include "../Liste/Liste.h"
#define FICHIERSTOCKC  "./BD/commande.txt"
#define FICHIERSTOCKTEMPC  "./BD/commande.temporaire.txt"
#define FICHIERSTOCKC  "./BD/commande.txt" 
#include <map>

    namespace Commande{
        /* 
            @brief classe de base d'un commande permettant d'effectuer des operation elementaire sur une commande
            @proprietes:
                -table: tableau qui lie d'id d'une commande et sa cellule;
                -maxNumeroGenerer: represente l'id de la prochaine de commande a creer
            @methodes:
                -modifier: qui permet de chercher une commande et de la mettre a jour
                -supprimer: qui permet de supprimer une commande    
                -creer: qui permet de creer une nouvelle commande
                -charger: charge les commandes a partir d'un fichier commande.txt par defaut
                -sauvegarder: qui permet de specifier ou serons sauvegerder les cleints par defaut sur le fichier de load si pas specifier
                -chercher: permet de chercher une commande par id
                -commandes_de: permet de recuperer les commandes d'un client
                -commandes_pour: permet de recuperer les commandes effectues sur un article donner
        */
        class Commande:public Liste<Base>
        {
        private:
            std::map<typeId, Cellule<Base> * > table;//map fonction de la lib map qui permet de creer les tableaux associatifs
            typeId maxNumeroGenerer;//plus grand id generer
            int sauvegarder();
            int charger();
        public:
            Commande(/* args */);
            typeId creer(unsigned long,unsigned long,unsigned long);
            int supprimer(typeId);
            int annuler(typeId);
            int lancer_livraison(typeId);
            int modifier(typeId,typeId,typeId,unsigned long,int);
            Cellule<Base>* chercher(typeId);
            Liste<Base> commandes_de(typeId);
            Liste<Base> commandes_encour_de(typeId);
            Liste<Base> commandes_pour(typeId);
            Liste<Base> commandes_livrer_pour(typeId );
            int charger(const char *);
            int sauvegarder(const char *);
            friend std::ostream& operator<<(std::ostream &, const Commande &);
            friend std::istream& operator>>(std::istream &is, Commande &b);   
        
        };
    };
#endif