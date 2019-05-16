#include "Article.h"
#include <iostream>
namespace Article{

    Base::Base(unsigned long reference,std::string libelle,unsigned long prix,unsigned long quantite,unsigned long seuil)
    {
        this->reference = reference;
        this->libelle = libelle;
        this->prix = prix;
        this->quantite = quantite;
        this->seuil = seuil;  
    };
    Base::Base()
    {
        this->reference = 0;
        this->prix = 0;
        this->quantite = 0;
        this->seuil = 0;
    };
    Base::~Base()
    {
    };
    unsigned long Base::get_reference(void){
        return reference;
    };
    Base* Base::fixer_prix(unsigned long prix){
        this->prix = prix;
        return this;
    };
    Base* Base::fixer_quantite(unsigned long quantite){
        this->quantite = quantite;
        return this;
    };
    Base* Base::ajouter_quantite( long quantite){
        this->quantite += quantite;
        return this;
    };
    bool Base::a_ravitailler(){
        return quantite <= seuil;
    };
    bool Base::tester_reference(unsigned long ref){
        return reference == ref;
    };
    int Base::tester_libelle(const char * lib){
        return libelle.compare(lib);
    };
    long Base::tester_quantite(unsigned long q){
        return quantite - q;
    }
    Base& Base::operator=(const Base& is){
        if(&is != this){
            prix = is.prix;
            quantite = is.quantite;
            reference = is.reference;
            seuil = is.seuil;
            libelle = is.libelle;
        }
        return * this;
    }
    int operator==(Base b1,Base b2){
        return b1.libelle.compare(b2.libelle.c_str()) == 0;
    }
    int operator<(Base b1,Base b2){
        return b1.libelle.compare(b2.libelle.c_str()) < 0;
    }
    int operator>(Base b1,Base b2){
        return b1.libelle.compare(b2.libelle.c_str()) > 0;
    }
    int operator<=(Base b1,Base b2){
        return b1.libelle.compare(b2.libelle.c_str()) <= 0;
    }
    std::ostream& operator<<(std::ostream &os, const Base &b) {
        serialiser(os,b.libelle);
        return os << ' ' <<b.prix  << ' ' << b.quantite << ' ' << b.reference << ' ' << b.seuil;
    }
    std::istream& operator>>(std::istream &is, Base &b){

        std::string nom;    
        if (!is) return is;
        if (!deserialiser(is, nom)) return is;
        b.libelle = nom;
        if (is >> b.prix >> b.quantite >> b.reference >> b.seuil)
        
        return is;
    }
};