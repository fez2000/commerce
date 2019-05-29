#include <fstream>
#include <iostream>
#include "Client.h"
#include "../Date/Date.h"
namespace Client{

    Base::Base(){
        this->numeroClient = 0;

    };

    Base::Base(typeId numero, std::string nom, std::string prenom, Date::Date date, std::string sexe){
        
        this->numeroClient = numero;
        this->nomClient = nom;
        this->prenomClient = prenom;
        this->dateNaissance = date;
        this->sexe = sexe;
    };

    /*
        Cette methode teste si le numero du client
        existe deja 
    */
    bool Base::tester_reference(typeId ref){
        return numeroClient == ref;
    };
    /*
        cette methode permet de retourner le 
        numero d'un client
    */

    typeId Base::get_numero(void){
        return numeroClient;
    };

    const char * Base::get_nom(){
        return nomClient.c_str();
    }

    const char * Base::get_prenom(){
        return prenomClient.c_str();
    }

    const char * Base::get_date(){
        std::cout << Date::Date::to_str( dateNaissance).c_str() << std::endl;
        return Date::Date::to_str( dateNaissance).c_str();
    }

    const char * Base::get_sexe(){
        return sexe.c_str();
    }

    
    /*
        cette methode permet de comparer
        un nom donné par l'utilisateur à
        un nom disponible en BD
    */
    int Base::tester_nom(const char * lib){
        return nomClient.compare(lib);
    };

    //  DEFINITION DES OPERATEUR

    /*
        1- Operateur d'affectation

        cette methode affecte les valeurs des propriétés
        de l'objet passer en paramètre a l'objet en cours
    */
    Base& Base::operator=(const Base& objetPasser){
        if(&objetPasser != this){
            numeroClient = objetPasser.numeroClient;
            nomClient = objetPasser.nomClient;
            prenomClient = objetPasser.prenomClient;
            dateNaissance = objetPasser.dateNaissance;
            sexe = objetPasser.sexe;
        }
        return * this;
    };
    /*
        2- Operateur d'egalite

        cette methode permet de tester si deux
        client sont identique
    */

    int operator==(Base client1,Base client2){
        return client1.nomClient.compare(client2.nomClient.c_str()) == 0;
    };

    /*
        2- Operateur de supperiorite

        cette methode permet de tester si un objet client1 
        est inferieur à un autre objet client2
    */
    int operator<(Base client1,Base client2){
        return client1.nomClient.compare(client2.nomClient.c_str()) < 0;
    };
    /*
        2- Operateur de supperiorite

        cette methode permet de tester si un objet 
        client1 est supperieur à un autre objet client2
    */
        int operator>(Base client1,Base client2){
        return client1.nomClient.compare(client2.nomClient.c_str()) > 0;
    };

    /*
        2- Operateur inferieur ou egal

        cette methode permet de tester si un objet 
        client1 est inferieur ou egal à un autre objet client2
    */

        int operator<=(Base client1,Base client2){
        return client1.nomClient.compare(client2.nomClient.c_str()) <= 0;
    };

    /*
        2- Operateur supperieur ou egal

        cette methode permet de tester si un objet 
        client1 est supperieur ou egal à un autre objet client2
    */
        int operator>=(Base client1,Base client2){
        return client1.nomClient.compare(client2.nomClient.c_str()) >= 0;
    }
    // FONCTION DE SERIALISATION ET DE DESERIALISATION
    /*
        nos fonction 
            serialiser()
            deserialiser()
        se trouve dans le fichier des fonctions 
    */
    std::ostream& operator<<(std::ostream &fichier, const Base &client) {
        serialiser(fichier,client.nomClient);
        fichier << ' ';
        serialiser(fichier,client.prenomClient);
        fichier << ' ';
        fichier << client.dateNaissance;
        fichier << ' ';
        serialiser(fichier,client.sexe);
        fichier << ' ';
        return  fichier << ' ' << client.numeroClient ;
    };
    std::istream& operator>>(std::istream &fichier, Base &client){

        std::string nom;    
        std::string prenom;
        Date::Date date;
        std::string sexe;
        if (!fichier) return fichier;

        if (!deserialiser(fichier, nom)) return fichier;
        client.nomClient = nom;
        if (!deserialiser(fichier, prenom)) return fichier;
        client.prenomClient = prenom;
        if (!(fichier >> date)) return fichier;
        client.dateNaissance = date;
        if (!deserialiser(fichier, sexe)) return fichier;
        client.sexe = sexe;
        fichier >> client.numeroClient;
        return fichier;
    };
    /*
        destructeur
    */

    Base::~Base()
    {

    }

} //client
