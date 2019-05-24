#ifndef LIVRAISON_H_INCLUDE
#define LIVRAISON_H_INCLUDE
#include "../fonctions/fonctions.h"
    namespace Livraison{
        
        /* 
            @brief classe de base des livraisons permettant d'effectuer des operations elementaire sur une livraison
            @proprite: 
                -numero: identifant de la livraison
                -client: identifiant du cleint a livrer
                -article: identifiant de l'article livrer
                -quantite: quantite de l'article commander
            @methodes:
                -modifier: pour mettre a jour une livraison
                -ref_client: pour retourner la reference du client
                -ref_article: pour retourner la reference du l'article
                -nombre: retourne la quantite de l'article a livrer
                -ref: retourne l'identifiant de la livraison
        */
        class Base
        {
        private:
            typeId numero;
            typeId commande;
            typeId client;
            unsigned long quantite;
        public:
            Base(typeId,typeId,unsigned long, unsigned long);
            ~Base();
            Base();
            void modifier(typeId,typeId, unsigned long);
            typeId ref(void);
            typeId ref_commande(void);
            typeId ref_client(void); 
            unsigned long nombre(void);
            friend void affiche(Base);
            friend int operator== (Base,Base);
            friend int operator< (Base,Base);
            friend int operator<= (Base,Base);
            friend int operator> (Base,Base);
            Base & operator= (const Base &);
            friend std::ostream& operator<<(std::ostream &, const Base &);
            friend std::istream& operator>>(std::istream &, Base &);
        };
           
    }
#endif