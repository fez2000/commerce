#ifndef CLIENT_H_INCLUDE
#define CLIENT_H_INCLUDE

#include "../fonctions/fonctions.h" // Differentes fonction generique
#include <string>
#define MASCULIN "M"
#define FEMININ "F"

namespace Client{
    /* 
        @brief classe de base d'un client permettant d'effectuer des operations elementaire sur un client
        @methodes:
            -update: pour mettre a jour un client
            - 
    */
    class Base
    {
    private:
        unsigned long numeroClient;
        std::string nomClient;
        std::string prenomClient;
        std::string dateNaissance;
        std::string sexe;
    public:

        // constructeur
        Base(/* args */);
        Base(unsigned long, std::string, std::string, std::string, std::string);

        ~Base();
        
        bool tester_reference(unsigned long);
        int tester_nom(const char *);
        unsigned long get_numero(void);

        friend int operator== (Base,Base);
        friend int operator< (Base,Base);
        friend int operator<= (Base,Base);
        friend int operator> (Base,Base);
        friend int operator>= (Base,Base);
        Base & operator= (const Base &);

        friend std::ostream& operator<<(std::ostream &os, const Base &);
        friend std::istream& operator>>(std::istream &is, Base &);
    };
    
   
} // client
#endif