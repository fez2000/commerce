#include "Commande.h"

namespace Commande{
    Base::Base()
    {
        this->quantite = 0;
    };
    Base::Base(  typeId numero,typeId client,typeId article,unsigned long quantite, int etat = ENCOUR)
    {
        this->numero = numero;
        this->client = client;
        this->article = article;
        this->quantite = quantite;
        this->etat = etat;
    }
    void Base::modifier(typeId client,typeId article,unsigned long quantite,int etat){
       
        this->client = client;
        this->article = article;
        this->quantite = quantite;
        this->etat = etat;

    };
    bool Base::est_livrer(){
        return etat == TERMINER;
    };
    bool Base::est_annuler(){
        return etat == ANNULER;
    };
    Base Base::annuler(){
        this->etat = 3;
        return *this;
    }
    int Base::status(){
        return etat;
    }
    Base Base::livrer(){
        etat = TERMINER;
        return *this;
    }; 
    Base Base::en_cour(){
        etat = ENCOURLIVRAISON;
        return *this;
    };
    unsigned long Base::ref_client(){
        return client;
    };
    unsigned long Base::ref_article(){
        return article;
    };
    unsigned long Base::nombre(){
        return quantite;
    };
    unsigned long Base::ref(void){
        return numero;
    };
    Base::~Base()
    {
    };
    Base& Base::operator=(const Base& is){
        if(&is != this){
            numero = is.numero;
            client = is.client;
            etat = is.etat;
            article = is.article;
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
        
        return os << ' ' <<b.numero  << ' ' << b.client<< ' ' << b.etat << ' ' << b.article << ' ' << b.quantite;
    }
    std::istream& operator>>(std::istream &is, Base &b){
       
    std::string nom;    
    if (!is) return is;
    is >> b.numero >> b.client >> b.etat >> b.article >> b.quantite;
        
    return is;
    }
}