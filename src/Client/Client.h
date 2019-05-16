#ifndef CLIENT_H_INCLUDE
#define CLIENT_H_INCLUDE
namespace Client
{
    /* 
        @brief classe de base d'un client permettant d'effectuer des operations elementaire sur un client
        @methodes:
            -update: pour mettre a jour un client
            - 
    */
    class Base
    {
    private:
        int numeroClient;
        char nomClient;
        char prenomClient;
        char sexe;
    public:

        // constructeur
        Base(/* args */);
        Base(int numero_client, char nom_client);
        Base(int numero_client, char nom_client, char prenom_client, char sexe);
        ~Base();
        
        char modif_client(); // methode permettant la modification d'un client
        char recherche_client(); // methode de recherche d'un client
        bool supp_client(); // methode de suppression d'un client
        bool tester_reference(unsigned long);
    };
    
   
} // client
#endif