#ifndef COMMANDE_H_INCLUDE
#define COMMANDE_H_INCLUDE
#include "../fonctions/fonctions.h"
    namespace Commande{
        enum Etat {ENCOUR,LIVRER,ANNULER};
        /* 
            @brief classe de base des commandes permettant d'effectuer des operations elementaire sur une commande
            @proprites: 
                -numero: identifiant d'une commande
                -client: identifiant du client qui a passer la commande
                -etat: staus d'une commade en cour ou bien livrer
                -article: identifiant de l'article commander
                -quantite: quantite de l'article commander
                
            @methodes:
                -est_livrer: permet de savoir si une commande a deja ete livrer
                -modifier: pour mettre a jour une commande
                -livrer: permet de specifier qu'un article a ete livrer
                -plus_livrer: permet de rentrer a l'etat ENCOUR en cas d'erreur de manipulation 
                -ref_client: retourne la reference du client
                -ref_article: retourne la reference de l'article
                -nombre: retourne la quantite de l'article commander
                -ref: retourne la reference de la commande
        */
        class Base
        {
        private:
            typeId numero;
            typeId client;
            typeId article;
            int etat;
            unsigned long quantite;
        public:
            Base(typeId,typeId,typeId, unsigned long, int);
            ~Base();
            Base();
            void modifier(typeId,typeId, unsigned long,int);
            bool est_livrer();
            void livrer();
            void annuler();
            int status(void);
            typeId ref(void);
            typeId ref_client(void);
            typeId ref_article(void);
            unsigned long nombre(void);    
            friend int operator== (Base,Base);
            friend int operator< (Base,Base);
            friend int operator<= (Base,Base);
            friend int operator> (Base,Base);
            Base & operator= (const Base &);
            friend std::ostream& operator<<(std::ostream &os, const Base &b);
            friend std::istream& operator>>(std::istream &is, Base &b);
        };
           
    }
#endif