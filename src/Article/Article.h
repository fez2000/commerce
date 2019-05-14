#ifndef ARTICLE_H_INCLUDE
#define ARTICLE_H_INCLUDE
#include <fstream>
#include <string>
#include "../fonctions/fonctions.h"
    namespace   Article
{
    /* 
        @brief classe de base d'un  atricle permettant d'effectuer des operations elementaire sur un atricle
        @methodes:
            -update: pour mettre a jour un  atricle
    */
    class Base
    {
    private:
        unsigned long reference; 
        std::string libelle; 
        double prix; 
        unsigned long quantite;  
        unsigned long seuil; 
    public:
        Base();
        Base(unsigned long,std::string,unsigned long,unsigned long,unsigned long);
        ~Base();
        Base* fixer_prix(unsigned long);
        Base* fixer_quantite(unsigned long);
        Base* ajouter_quantite(long);
        bool a_ravitailler(void);
        bool tester_reference(unsigned long);
        int tester_libelle(const char *);
        long tester_quantite(unsigned long);
        friend int operator== (Base,Base);
        friend int operator< (Base,Base);
        friend int operator<= (Base,Base);
        friend int operator> (Base,Base);
        Base & operator= (const Base &);
        friend std::ostream& operator<<(std::ostream &os, const Base &b);
        friend std::istream& operator>>(std::istream &is, Base &b);
    };
    
} //    atricle

#endif