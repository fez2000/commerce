#include "Articles.h"
#include "stdlib.h"
#include <iostream>
#include <fstream>

namespace Article{


    std::istream& operator>>(std::istream &is,Cellule<Base> &b){
        if (!is) return is;
        Base valeur;
        if (is >> valeur)
        b = Cellule<Base>{valeur};
        return is;
    };
    Article::Article(const char * fichier_chargement = FICAL,const char * fichier_sauvegarde = FICAS)
    {
        //load
        maxNumeroGenerer = 0;
    }
    Article::Article()
    {
        maxNumeroGenerer = 0;
        taille = 0;
        tete = sentinelle  = 0;
    }
    Article::~Article()
    {
    }
    int Article::creer(const char * nom, double prix, unsigned long quantite,unsigned long seuil){
        std::string b(nom);
        Base a(maxNumeroGenerer,b,prix,quantite,seuil);
         
        
         Cellule<Base>* c;
        c = new Cellule<Base>(a);
        ajouter_trie(c);
        std::cout << *this->tete;
         
        table.insert(std::pair<unsigned long,Cellule<Base> * >(maxNumeroGenerer,c));
        maxNumeroGenerer ++;
        //store
        
        sauvegarder();
        return 1;
    };

    int Article::supprimer(unsigned long h){
        Cellule<Base> * b = tete;
        while (!b->get().tester_reference(h) || b != sentinelle)
        {
            b = b->get_next();
        }
        if(b != sentinelle){
            enlever(*b);
            table.erase(h);
        }
        sauvegarder();
        return 1;
    };
    int Article::mettre_a_jour(unsigned long ref,const char * nom, double prix, unsigned long quantite,unsigned long seuil){
        Base a (ref,nom,prix,quantite,seuil);
        Cellule<Base> b(a);
        Cellule<Base>* e = chercher(ref);
        if(e){
            (*e) = b;
        }
        sauvegarder(); 
        return 1;
    };
    Cellule<Base> * Article::chercher(const char * lib){
        Cellule<Base> * b = tete;
        while (!b->get().tester_libelle(lib) || b != sentinelle)
        {
            b = b->get_next();
        }
        if(b != sentinelle){
            return b;
        }
        return NULL;
    };
    Cellule<Base> * Article::chercher(unsigned long ref){
        Cellule<Base> * b = tete;
        
        return table[ref];
    };
    int Article::sauvegarder(){
        
    std::ofstream fichier(FICAST);
    if(fichier){
        fichier << *this;
        fichier.close();
        std::cout << "sauvegarder\n";
    }else{
        std::cout << "erreur d'ouverture\n";
    }
     
    return 1;
    }

    
    
}