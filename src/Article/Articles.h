#ifndef ARTICLES_H_INCLUDE
#define ARTICLES_H_INCLUDE
#include "Article.h"
#include "../Cellule/Cellule.h"
#include "../Liste/Liste.h"
#define FICAL  "./BD/atricle.txt"
#define FICAST  "./BD/atricle.temporaire.txt"
#define FICAS  "./BD/atricle.txt" 
#include <iostream>
#include <map>
    namespace Article{
        /* 
        @brief classe de gestion des  atricles permettant d'effectuer des operations sur un ensemble d'atricle
        @methodes:
            -update: qui permet de chercher un  atricle un   atricle et de le mettre a jour
            -remove: qui permet de supprimer un atricle 
            -create: qui permet de creer un nouveau atricle
            -load: qui permet de charger des atricles a partir d'un fichier par defaut atricle.txt
            -store: qui permet de specifier ou serons sauvegerder les cleints par defaut sur le fichier de load si pas specifier
        */
        class   Article: public Liste< Base >
        {
        private:
            std::map<unsigned long, Cellule<Base> * > table;
            unsigned long maxNumeroGenerer;
            int sauvegarder();
        public:
            Article();
            Article(const char *,const char *);
            ~Article();
            int creer(const char *, double, unsigned long,unsigned long);
            int supprimer(unsigned long);
            int mettre_a_jour(unsigned long,const char *, double, unsigned long,unsigned long );
            Cellule<Base>* chercher(const char *);
            Cellule<Base>* chercher(unsigned long);
            Cellule<Base>** critiques();
            int charger(const char *);
            int sauvegarder(const char *);
            static Article deserialiser(std::istream&);
            friend std::ostream& operator<<(std::ostream &os, const Article &b) {
        os << b.taille << ' ' <<b.maxNumeroGenerer ;
        Cellule<Base> * c = b.tete;
        while (c!=b.sentinelle)
        {
            std::cout << (*c) << std::endl;
            os << ' ' << (*c);
            c=c->get_next();
        }
        return os;
    };
            friend std::istream& operator>>(std::istream &is, Article &b){
    if (!is) return is;
   
    unsigned int taille,maxNumeroGenerer;
    if (is >> taille >> maxNumeroGenerer)
        b.taille = taille;
        b.maxNumeroGenerer = maxNumeroGenerer;
        b.tete = b.sentinelle = new Cellule<Base>;
        Cellule<Base> * c;
        while (taille >0 )
        {
            Base a;
            if(!(is >> a)) return is;
            c = new Cellule<Base>(a);
            b.ajouter_trie(c);
            taille--;
        }
        
    return is;
    };   
        };
    
    }
#endif