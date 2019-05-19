#include "Livraison.h"

namespace Livraison{
    Base::Base()
    {
        this->quantite = 0;
    };
    Base::Base(  typeId numero,typeId commande,typeId client,unsigned long quantite)
    {
        this->numero = numero;
        this->commande = commande;
        this->client = client;
        this->quantite = quantite;
       
    }
    void Base::modifier(typeId commande,typeId client,unsigned long quantite){
        this->commande = commande;
        this->client = client;
        this->quantite = quantite;
    };
 
     
    typeId Base::ref_client(){
        return client;
    };
    typeId Base::ref_commande(){
        return commande;
    };
    unsigned long Base::nombre(){
        return quantite;
    };
    typeId Base::ref(void){
        return numero;
    };
    Base::~Base()
    {
    };
    Base& Base::operator=(const Base& is){
        if(&is != this){
            numero = is.numero;
            commande = is.commande;
            client = is.client;
            quantite = is.quantite;
        }
        return * this;
    }
    int operator==(Base b1,Base b2){
        return b1.numero == b2.numero;
    }
    int operator<(Base b1,Base b2){
        return b1.numero < b2.numero;
    }
    int operator>(Base b1,Base b2){
        return b1.numero > b2.numero;
    }
    int operator<=(Base b1,Base b2){
        return b1.numero<=b2.numero;
    }
    std::ostream& operator<<(std::ostream &os, const Base &b) {
        
        return os << ' ' <<b.numero<< ' ' <<  b.commande  << ' ' << b.client << ' ' << b.quantite;
    }
    std::istream& operator>>(std::istream &is, Base &b){
       
    std::string nom;    
    if (!is) return is;
    is >> b.numero >> b.commande >> b.client  >> b.quantite;
        
    return is;
    }
}