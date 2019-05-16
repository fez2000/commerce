#ifndef LIVRAISON_H_INCLUDE
#define LIVRAISON_H_INCLUDE
#include <fstream>
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
            unsigned long numero;
            unsigned long client;
            unsigned long article;
            unsigned long quantite;
        public:
            Base(unsigned long,unsigned long,unsigned long, unsigned long);
            ~Base();
            Base();
            void modifier(unsigned long,unsigned long, unsigned long,int);
            unsigned long ref_client(void);
            unsigned long ref_article(void);
            unsigned long nombre(void);
            unsigned long ref(void);
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