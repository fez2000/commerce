#include "Commandes.h"
#include <fstream>

namespace Commande{
    Commande::Commande()
    {
                //load
        maxNumeroGenerer = 1;
        taille = 0;
        charger();
    };
    /*
    @name: creer
    @brief: methode de la classe article qui permet de creer une nouvelle commande
    @params: 
        -client id du client qui passe la commande de type typeId
        -article id de l'article commander de type typeId
        -quantite quantite de l'article commander de type unsigned long 
    @return: l'id de la commande creer ou ERROR_CODE en cas d'erreur
    */
    typeId Commande::creer(typeId client,typeId article,unsigned long quantite){
        Base commande(maxNumeroGenerer,client,article,quantite,ENCOUR);  
        ajouter(new Cellule<Base>(commande));
        table.insert(std::pair<typeId,Cellule<Base> * >(maxNumeroGenerer,tete));
        maxNumeroGenerer++;
        if(sauvegarder() == ERROR_CODE){
            return ERROR_CODE;
        }
        return maxNumeroGenerer - 1;
    };
    int Commande::supprimer(typeId numero){
        Cellule<Base> * b = table[numero];
        if(!b)return 0;
        enlever(*b);
        table.erase(numero);
        return sauvegarder();
        
    };
    int Commande::modifier(typeId numero, typeId client,typeId article,unsigned long quantite,int etat){
        Base a(numero,client,article,quantite,etat);
        Cellule<Base> b(a);
        Cellule<Base>* e = chercher(numero);
        if(!e) return 0;
        if(e){
            (*e) = b;
        }
        return sauvegarder(); 
    };
    Liste<Base> Commande::commandes_de(typeId id){
        Liste<Base> t;
        Cellule<Base> * i;

        i=tete;
        while(i!=sentinelle){
            if(i->get().ref_client()==id){
               t.ajouter(new Cellule<Base>(i->get())); 
            }
        i = i->get_next();
        }
        return t;
    };
    Liste<Base> Commande::commandes_encour_de(typeId id){
        Liste<Base> t;
        Cellule<Base> * i,*j;

        i=tete;
        while(i!=sentinelle){
            if(i->get().ref_client()==id){

                if(ENCOUR == i->get().status()){
                    Base p = i->get();
                    j = new Cellule<Base>(p);
                    std::cout<< j->get().ref()<<std::endl;
                     t.ajouter(j);
                }
               
            }
        i = i->get_next();
        }
        return t;
    };
    Liste<Base> Commande::commandes_pour(typeId id){
        Liste<Base> t;
        Cellule<Base> * i;

        i=tete;
        while(i!=sentinelle){
            if(i->get().ref_article()==id){
                if(!i->get().est_annuler())
               t.ajouter(new Cellule<Base>(i->get())); 
            }
            i = i->get_next();
        }
        return t;
    };
    Cellule<Base> * Commande::chercher(typeId ref){
        return table[ref];
    };
    int Commande::sauvegarder(){
        std::ofstream fichier;
        fichier.exceptions ( std::ofstream::failbit | std::ofstream::badbit );
        try{
            fichier.open((FICHIERSTOCKTEMPC));
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
    std::istream& operator>>(std::istream &is, Commande &b){
        if (!is) return is;

        unsigned long taille;
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
    int Commande::lancer_livraison(typeId idCommade){
        Cellule<Base> * p = table[idCommade];
        if(p)p->get().en_cour();
        return sauvegarder();
    };
    int Commande::annuler(typeId id){
        Cellule<Base> * p = table[id];
        if(p)p->get().annuler();
        return sauvegarder();
    };
    int Commande::charger(){
        std::ifstream fichier;
        fichier.exceptions ( std::ifstream::failbit | std::ifstream::badbit );
        try{
            fichier.open(FICHIERSTOCKTEMPC);
            if(fichier){
                if(fichier.eof())return ERROR_CODE;
                if(fichier>>*this){
                fichier.close();    
                    return SUCCESS_CODE;
                }
                fichier.close();
            }
        }
        catch(std::ifstream::failure& ex){
            //std::cout <<ex.what()<< std::endl;
            return ERROR_CODE;
        }
        return SUCCESS_CODE;
    }
    std::ostream& operator<<(std::ostream &os, const Commande &b) {
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