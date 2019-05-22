#ifndef ARTICLE_H_INCLUDE
#define ARTICLE_H_INCLUDE
#include <fstream>
#include <string>
#include "../fonctions/fonctions.h"
    namespace   Article
{
    /* 
        @brief classe de base d'un  atricle permettant d'effectuer des operations elementaire sur un atricle
        @proprietes:
            -refernce: identifiant d'un article
            -libelle: nom de l'article
            -prix: prix d'un article
            -quantite: quantite de l'article disponible
            -seuil: la quatite a partir de laquelle un article est critique 
        @methodes:
            -fixer_prix: pour mettre a jour le prix d'un  atricle
            -fixer_quantite: pour mettre a jour la quantite  d'atricle disponible
            -ajouter_quantite: pour augmenter une quantite d'atricle
            -a_ravitailler: teste la quantite d'article disponible est en dessous de seuil
            -tester_libelle: permet de comparer le libelle avec une chaine retourne 0 si egale 
            -tester_quantite: permet de comparer deux quantites
    */
    class Base
    {
    private:
        typeId reference; 
        std::string libelle; 
        double prix; 
        unsigned long quantite;  
        unsigned long seuil; 
    public:
        Base();
        Base(typeId,std::string,unsigned long,unsigned long,unsigned long);
        ~Base();
        Base* fixer_prix(unsigned long);
        Base* fixer_quantite(unsigned long);
        Base* ajouter_quantite(long);
        bool a_ravitailler(void);
        bool tester_reference(typeId);
        int tester_libelle(const char *);
        typeId get_reference(void);
        double get_prix(void);
        unsigned long get_quantite(void);
        long tester_quantite(unsigned long);
        friend void affiche(Base);
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