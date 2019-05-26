#include "Livraisons.h"
#include <fstream>
#include <stdlib.h>
namespace Livraison{
    Livraison::Livraison()
    {
                //load
        maxNumeroGenerer = 1;
        taille = 0;
        charger();
    };
    /*
    @name: creer
    @brief: methode de classe Livraison qui permet de creer une nouvelle livraison
    @params:
        -commande id de la commande 
        -client id du client a livre de type typeId
        -quantite quantite de l'article commander
    @return: l'id de la livraison ou ERROR_CODE en cas d'erreur
    */
    int Livraison::creer(typeId client,typeId article,unsigned long quantite){
        Base commande(maxNumeroGenerer,client,article,quantite);  
        ajouter(new Cellule<Base>(commande));
        table.insert(std::pair<typeId,Cellule<Base> * >(maxNumeroGenerer,tete));
        maxNumeroGenerer++;
        if(sauvegarder() == ERROR_CODE){
            return ERROR_CODE;
        };
        return SUCCESS_CODE;
    };
    int Livraison::supprimer(typeId numero){
        Cellule<Base> * b = table[numero];
        if(!b)return 0;
        enlever(*b);
        table.erase(numero);
        return sauvegarder();
    };
    int Livraison::modifier(typeId numero, typeId client,typeId article,unsigned long quantite){
        Base a(numero,client,article,quantite);
        Cellule<Base> b(a);
        Cellule<Base>* e = chercher(numero);
        if(!e) return 0;
        if(e){
            (*e) = b;
        }
        return sauvegarder(); 
    };
    Liste<Base> Livraison::livraisons_de(typeId id){
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
    /*
    @name: livraisons_apropos
    @brief methode de la classe livraison qui donne la livraison correspondant a une commande en cour
    @parmas: id qui est l'id de la commande
    @return: l'id de la livraison
    */
    Cellule<Base> *Livraison::livraisons_apropos(typeId id){
        Cellule<Base> * i;

        i=tete;
        while(i!=sentinelle){
            if(i->get().ref_commande()==id){
               return (new Cellule<Base>(i->get())); 
            }
        }
        return NULL;
    };
    Cellule<Base> * Livraison::chercher(typeId ref){        
        return table[ref];
    };
    int Livraison::sauvegarder(){
        std::ofstream fichier;
        fichier.exceptions ( std::ofstream::failbit | std::ofstream::badbit );
        try{
            fichier.open((FICHIERSTOCKTEMPL));
            if(fichier){
                fichier << *this;
                fichier.close();
                std::cout <<"\n";
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
    std::istream& operator>>(std::istream &is, Livraison &b){
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
                b.table.insert(std::pair<typeId,Cellule<Base> * >(a.ref(),c));
                taille--;
            }
            
            
        }    
        return is;
    };
    int Livraison::charger(){
        std::ifstream fichier;
        fichier.exceptions ( std::ifstream::failbit | std::ifstream::badbit );
        try{
            fichier.open((FICHIERSTOCKTEMPL));
            if(fichier){
                if(fichier.eof())return SUCCESS_CODE;
                if(fichier>>*this){
                fichier.close();    
                return SUCCESS_CODE;
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
    std::ostream& operator<<(std::ostream &os, const Livraison &b) {
        os << b.taille << ' ' <<b.maxNumeroGenerer ;
        Cellule<Base> * c = b.tete;
        while (c!=b.sentinelle)
        {
            os << '\n' << (*c);
            c=c->get_next();
        }
        return os;
    };
}