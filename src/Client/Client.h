#ifndef CLIENT_H_INCLUDE
#define CLIENT_H_INCLUDE

#include "../Date/Date.h"

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
        typeId numeroClient;
        std::string nomClient;
        std::string prenomClient;
        Date::Date dateNaissance;
        std::string sexe;
    public:

        // constructeur
        Base(/* args */);
        Base(typeId, std::string, std::string, Date::Date, std::string);

        ~Base();
        
        bool tester_reference(typeId);
        int tester_nom(const char *);
        typeId get_numero(void);
        const char * get_nom();
        const char * get_prenom();
        const char * get_date();
        const char * get_sexe();

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