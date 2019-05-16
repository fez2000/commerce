#include "Articles.h"
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
    Article::Article()
    {

        //load
        maxNumeroGenerer = 1;
        taille = 0;
        charger();
    }


    int Article::creer(const char * nom, double prix, unsigned long quantite,unsigned long seuil){
        std::string b(nom);
        Base article(maxNumeroGenerer,b,prix,quantite,seuil);
         
        
         Cellule<Base>* c;
        c = new Cellule<Base>(article);
        ajouter_trie(c);
        //std::cout << *this->tete;
         
        table.insert(std::pair<unsigned long,Cellule<Base> * >(maxNumeroGenerer,c));
        maxNumeroGenerer ++;
        //store
        
        sauvegarder();
        return 1;
    };

    int Article::supprimer(unsigned long id){
        Cellule<Base> * b = table[id];
        if(!b)return 0;
        enlever(*b);
        table.erase(id);
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
        while (b->get().tester_libelle(lib) !=0 && b != sentinelle)
        {
            b = b->get_next();
        }
        if(b != sentinelle){
            return b;
        }
        return NULL;
    };
    Cellule<Base> * Article::chercher(unsigned long ref){
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
    Liste<Base> Article::critiques(){
        Liste<Base> t;
        Cellule<Base> * i;

        i=tete;
        while(i!=sentinelle){
            if(i->get().a_ravitailler()){
               t.ajouter(new Cellule<Base>(i->get())); 
            }
        }
        return t;
    };
    int Article::charger(){
        std::ifstream fichier(FICAST);
        if(fichier){
            if(fichier.eof())return 0;
            if(fichier>>*this){
            fichier.close();    
            return 1;
            }
            fichier.close();
        }else{
            std::cout << "erreur d'ouverture\n";
        }

        return 0;
    }
    std::ostream& operator<<(std::ostream &os, const Article &b) {
                os << b.taille << ' ' <<b.maxNumeroGenerer ;
                Cellule<Base> * c = b.tete;
                while (c!=b.sentinelle)
                {
                    os << ' ' << (*c);
                    c=c->get_next();
                }
                return os;
    };
    std::istream& operator>>(std::istream &is, Article &b){
            if (!is) return is;
        
            unsigned int taille,maxNumeroGenerer;
            if (is >> taille >> maxNumeroGenerer){
                
                b.tete = b.sentinelle = new Cellule<Base>;
                Cellule<Base> * c;
                Base  a ;
                
                b.maxNumeroGenerer = maxNumeroGenerer;
                while (taille >0 )
                {
                    is >> a;
                    c = new Cellule<Base>(a);
                    b.ajouter_trie(c);
                    b.table.insert(std::pair<unsigned long,Cellule<Base> * >(a.get_reference(),c));
                    taille--;
                }
               
                
            }    
            return is;
        };
}