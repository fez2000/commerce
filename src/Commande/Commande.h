#ifndef COMMANDE_H_INCLUDE
#define COMMANDE_H_INCLUDE
#include <fstream>
    namespace Commande{
        enum Etat {ENCOUR,LIVRER};
        /* 
            @brief classe de base des commandes permettant d'effectuer des operations elementaire sur une commande
            @methodes:
            -update: pour mettre a jour un article
        */
        class Base
        {
        private:
            unsigned long numero;
            unsigned long client;
            int etat;
            unsigned long article;
            unsigned long quantite;
        public:
            Base(unsigned long,unsigned long,unsigned long, unsigned long, int);
            ~Base();
            Base();
            void modifier(unsigned long,unsigned long, unsigned long,int);
            bool est_livrer();
            void mettre_etat(int);
            unsigned long ref_client(void);
            unsigned long ref_article(void);
            unsigned long nombre(void);
            unsigned long ref(void);
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