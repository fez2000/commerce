#include "Livraisons.h"
#include <fstream>

namespace Livraison{
    Livraison::Livraison()
    {
                //load
        maxNumeroGenerer = 1;
        taille = 0;
        charger();
    };
    int Livraison::creer(unsigned long client,unsigned long article,unsigned long quantite){
        Base commande(maxNumeroGenerer,client,article,quantite);  
        ajouter(new Cellule<Base>(commande));
        table.insert(std::pair<unsigned long,Cellule<Base> * >(maxNumeroGenerer,tete));
        maxNumeroGenerer++;
        sauvegarder();
        return 1;
    };
    int Livraison::supprimer(unsigned long numero){
        Cellule<Base> * b = table[numero];
        if(!b)return 0;
        enlever(*b);
        table.erase(numero);
        sauvegarder();
        return 1;
    };
    int Livraison::modifier(unsigned long numero, unsigned long client,unsigned long article,unsigned long quantite,int etat){
        Base a(numero,client,article,quantite);
        Cellule<Base> b(a);
        Cellule<Base>* e = chercher(numero);
        if(!e) return 0;
        if(e){
            (*e) = b;
        }
        sauvegarder(); 
        return 1;
    };
    Liste<Base> Livraison::livraisons_de(unsigned long id){
        Liste<Base> t;
        Cellule<Base> * i;

        i=tete;
        while(i!=sentinelle){
            if(i->get().ref_client()==id){
               t.ajouter(new Cellule<Base>(i->get())); 
            }
        }
        return t;
    };
    Liste<Base> Livraison::livraisons_pour(unsigned long id){
        Liste<Base> t;
        Cellule<Base> * i;

        i=tete;
        while(i!=sentinelle){
            if(i->get().ref_article()==id){
               t.ajouter(new Cellule<Base>(i->get())); 
            }
        }
        return t;
    };
    Cellule<Base> * Livraison::chercher(unsigned long ref){
        Cellule<Base> * b = tete;
        
        return table[ref];
    };
    int Livraison::sauvegarder(){
        std::ofstream fichier(FICHIERSTOCKTEMPL);
        if(fichier){
            fichier << *this;
            fichier.close();
            std::cout << "sauvegarder\n";
        }else{
            std::cout << "erreur d'ouverture\n";
            return -1;
        }    
        return 1;
    }
    std::istream& operator>>(std::istream &is, Livraison &b){
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
                b.table.insert(std::pair<unsigned long,Cellule<Base> * >(a.ref(),c));
                taille--;
            }
            
            
        }    
        return is;
    };
    int Livraison::charger(){
        std::ifstream fichier(FICHIERSTOCKTEMPL);
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
    std::ostream& operator<<(std::ostream &os, const Livraison &b) {
                os << b.taille << ' ' <<b.maxNumeroGenerer ;
                Cellule<Base> * c = b.tete;
                while (c!=b.sentinelle)
                {
                    os << ' ' << (*c);
                    c=c->get_next();
                }
                return os;
            };
}