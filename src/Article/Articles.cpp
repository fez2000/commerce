#include "Articles.h"
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>

namespace Article{
    

    
    Article::Article()
    {

        //load
        maxNumeroGenerer = 1;
        taille = 0;
        charger();
    }
    
    typeId Article::creer(const char * nom, double prix, unsigned long quantite,unsigned long seuil){
        std::string b(nom);
        Base article(maxNumeroGenerer,b,prix,quantite,seuil);
         
        
         Cellule<Base>* c;
        c = new Cellule<Base>(article);
        ajouter_trie(c);
         
        table.insert(std::pair<typeId,Cellule<Base> * >(maxNumeroGenerer,c));
        maxNumeroGenerer ++;
        //store
        
        if(sauvegarder() == ERROR_CODE){
            return ERROR_CODE;
        }else{
            return SUCCESS_CODE;
        };
    };

    int Article::supprimer(typeId id){
        Cellule<Base> * b = table[id];
        if(!b)return 0;
        enlever(*b);
        table.erase(id);
        return sauvegarder();
    };
    int Article::mettre_a_jour(typeId ref,const char * nom, double prix, unsigned long quantite,unsigned long seuil){
        Base a (ref,nom,prix,quantite,seuil);
        Cellule<Base> b(a);
        Cellule<Base>* e = chercher(ref);
        if(e){
            (*e) = b;
        }
        return sauvegarder(); 
    };
    long double Article::capital(){
        long double total = 0;
                Cellule<Base> * b = tete;
        while ( b != sentinelle)
        {
            total += b->get().get_prix()*b->get().get_quantite();
            b = b->get_next();
        }
        return total;
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
    Cellule<Base> * Article::chercher(typeId ref){
        return table[ref];
    };

    int Article::sauvegarder(){
        std::ofstream fichier;
        fichier.exceptions ( std::ofstream::failbit | std::ofstream::badbit );
        try{
            fichier.open(FICAST);
            if(fichier){
                fichier << *this;
                fichier.close();
                std::cout << "\t##########################################################################################\n";
                std::cout << "\t##                                                                                      ##\n"; 
                std::cout << "\t##                          Operation effectuer avec SUCCES !                           ##\n";
                std::cout << "\t##                                                                                      ##\n";
                std::cout << "\t##########################################################################################\n";
                
            }   
        }
        catch(std::ofstream::failure& ex){
            return ERROR_CODE;
        } 
        return SUCCESS_CODE;
    }
    
    Liste<Base> Article::critiques(){
        Liste<Base> t;
        Cellule<Base> * i;

        i=tete;
        while(i!=sentinelle){
            if(i->get().a_ravitailler()){
               t.ajouter(new Cellule<Base>(i->get())); 
            }
            i = i->get_next();
        }
        return t;
    };
    Liste<Base> Article::liste_ayant_nom(const char * nomArticle){
        Liste<Base> l;
        Cellule<Base> * i;
        i=tete;
        while(i!=sentinelle){
            
            if( i->get().get_libelle().find(nomArticle) <i->get().get_libelle().length() ){
               l.ajouter(new Cellule<Base>(i->get())); 
            }
           i = i->get_next(); 
        }
        return l;
    };
    int Article::charger(){
        std::ifstream fichier;
        fichier.exceptions ( std::ifstream::failbit | std::ifstream::badbit );
        try{
            fichier.open(FICAST);
            if(fichier){
                if(fichier.eof())return 0;
                if(fichier>>*this){
                fichier.close();    
                return 1;
                }
                fichier.close();
            }

        }
        catch(std::ifstream::failure& ex){
            //std::cout << strerror( errno ) << std::endl;
            return ERROR_CODE;
        }
        return SUCCESS_CODE;
    }
    std::ostream& operator<<(std::ostream &os, const Article &b) {
        os << b.taille << ' ' <<b.maxNumeroGenerer ;
        Cellule<Base> * c = b.tete;
        while (c!=b.sentinelle)
        {
            os << '\n' << (*c);
            c=c->get_next();
        }
        return os;
    };
    std::istream& operator>>(std::istream &is, Article &b){
        if (!is) return is;
    
        unsigned int taille;
        typeId maxNumeroGenerer;
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
                b.table.insert(std::pair<typeId,Cellule<Base> * >(a.get_reference(),c));
                taille--;
            }
            
            
        }    
        return is;
    };
}