#include <iostream>
#include "fonctions.h"
#include <math.h>
#include <string.h>
#include <vector>
#include <fstream>
#include "../Client/Clients.h"

Client::Client gestionnaireClient;

/*
    Acceuil
*/
std::string choixUtilisateur;
void acceuil(){
    int i = charger("fr");
    // differentes variables a utiliser dans notre fonction
    
     do{
          std::cout << get("menu");
          std::cin >> choixUtilisateur;
          system("clear");

     } while (choixUtilisateur.c_str()[0] != '0' && choixUtilisateur.c_str()[0] != '1' && choixUtilisateur.c_str()[0] != '2' && choixUtilisateur.c_str()[0] != '3' && choixUtilisateur.c_str()[0] != '4' && choixUtilisateur.c_str()[0] != '5');


     switch (choixUtilisateur.c_str()[0]){
          case '0':
               system("exit");
               break;
          case '1': // gestion client
               menu_general_client();
               break;
          case '2':
               // gestion article
               menu_general_article();
               break;
          case '3':
               // gestion commande
               menu_general_commande();
               break;
          case '4':
               // gestion livraison
               menu_general_livraison();
               break;
          case '5':
               // a propos
               break;

          default:
               std::cout << " choix non disponible \n";
          break;
     };
}

/*
    Fonction de gestion du menu client
*/

void menu_general_client(){
    
    do
    {
    
        std::cout << "\t##########################################################################################\n";
        std::cout << "\t##-_-_-                                                                            -_-_-##\n";
        std::cout << "\t##               BIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL                ##\n";
        std::cout << "\t##                -----------------------------------------------------                 ##\n";
        std::cout << "\t##                                                                                      ##\n";
        std::cout << "\t##                          ------------------------------                              ##\n";
        std::cout << "\t##                         |     GESTION DES CLIENTS      |                             ##\n";
        std::cout << "\t##                          ------------------------------                              ##\n";
        std::cout << "\t##                                                                                      ##\n";
        std::cout << "\t##                     Veuillez suivre à la lettre les consigne !                       ##\n";
        std::cout << "\t##                       --------------------------------------                         ##\n";
        std::cout << "\t##-_-_-  Appuyez sur:                                                              -_-_-##\n";
        std::cout << "\t##                                                                                      ##\n";
        std::cout << "\t##     - 1 pour Enregistrer un nouveau client       - 3 pour Rechercher un client       ##\n";
        std::cout << "\t##                                                                                      ##\n";
        std::cout << "\t##     - 2 pour la Modification d'un client         - 4 pour Supprimer un client        ##\n";
        std::cout << "\t##                                                                                      ##\n";
        std::cout << "\t##     - 5 pour afficher les CLIENTS                - 0 pour Menu principal             ##\n";
        std::cout << "\t##                                                                                      ##\n";
        std::cout << "\t##         ----------------------------------------------------------------             ##\n";

        std::cout << "\t## Entrer votre choix: \t";
        std::cin >> choixUtilisateur;
        system("clear");
    
    }while(choixUtilisateur.c_str()[0] != '0' && choixUtilisateur.c_str()[0] != '1' && choixUtilisateur.c_str()[0] != '2' && choixUtilisateur.c_str()[0] != '3' && choixUtilisateur.c_str()[0] != '4'&& choixUtilisateur.c_str()[0] != '5');

    switch(choixUtilisateur.c_str()[0]){

        case '0': // fonction de retour au menu principal;
            acceuil();
            break;
        case '1': // creation d'un nouveau client;
            interface_creation_client();
            break;
        case '2': // fonction menu de modification d'un client;
            break;
        case '3': // fonction menu de recherche d'un client;
            break;
        case '4': //fonction de supression d'un client;
            break;
        case '5':
            // affichage client
            break;

    }
}

// acceuil Article
void menu_general_article(){
    std::string choixUtilisateur;
    do
    {
    
        std::cout << "\t##########################################################################################\n";
        std::cout << "\t##-_-_-                                                                            -_-_-##\n";
        std::cout << "\t##               BIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL                ##\n";
        std::cout << "\t##                -----------------------------------------------------                 ##\n";
        std::cout << "\t##                                                                                      ##\n";
        std::cout << "\t##                          ------------------------------                              ##\n";
        std::cout << "\t##                         |     GESTION DES ARTICLES      |                             ##\n";
        std::cout << "\t##                          ------------------------------                              ##\n";
        std::cout << "\t##                                                                                      ##\n";
        std::cout << "\t##                     Veuillez suivre à la lettre les consigne !                       ##\n";
        std::cout << "\t##                       --------------------------------------                         ##\n";
        std::cout << "\t##-_-_-  Appuyez sur:                                                              -_-_-##\n";
        std::cout << "\t##                                                                                      ##\n";
        std::cout << "\t##     - 1 pour Enregistrer un nouveau ARTICLE       - 3 pour Rechercher un ARTICLE     ##\n";
        std::cout << "\t##                                                                                      ##\n";
        std::cout << "\t##     - 2 pour la Modification d'un ARTICLE         - 4 pour Supprimer un ARTICLE      ##\n";
        std::cout << "\t##                                                                                      ##\n";
        std::cout << "\t##     - 5 pour la liste des ARTICLES                - 0 pour Menu principal            ##\n";
        std::cout << "\t##                                                                                      ##\n";
        std::cout << "\t##         ----------------------------------------------------------------             ##\n";

        std::cout << "\t## Entrer votre choix: \t";
        std::cin >> choixUtilisateur;
        system("clear");
    }
    while(choixUtilisateur.c_str()[0] != '0' && choixUtilisateur.c_str()[0] != '1' && choixUtilisateur.c_str()[0] != '2' && choixUtilisateur.c_str()[0] != '3' && choixUtilisateur.c_str()[0] != '4'&& choixUtilisateur.c_str()[0] != '5');

    switch(choixUtilisateur.c_str()[0]){

        case '0': // fonction de retour au menu principal;
            acceuil();
            break;
        case '1': // creation d'un ARTICLE;
            
            break;
        case '2': // fonction menu de modification d'un ARTICLE;
            break;
        case '3': // fonction menu de recherche d'un ARTICLE;
            break;
        case '4': //fonction de supression d'un ARTICLE;
            break;
        case '5': // Affichages des differents articles
            break;

    }
}

// acceuil commande
void menu_general_commande(){
    std::string choixUtilisateur;
    do
    {
    
        std::cout << "\t##########################################################################################\n";
        std::cout << "\t##-_-_-                                                                            -_-_-##\n";
        std::cout << "\t##               BIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL                ##\n";
        std::cout << "\t##                -----------------------------------------------------                 ##\n";
        std::cout << "\t##                                                                                      ##\n";
        std::cout << "\t##                          ------------------------------                              ##\n";
        std::cout << "\t##                         |     GESTION DES COMMANDES    |                             ##\n";
        std::cout << "\t##                          ------------------------------                              ##\n";
        std::cout << "\t##                                                                                      ##\n";
        std::cout << "\t##                     Veuillez suivre à la lettre les consigne !                       ##\n";
        std::cout << "\t##                       --------------------------------------                         ##\n";
        std::cout << "\t##-_-_-  Appuyez sur:                                                              -_-_-##\n";
        std::cout << "\t##                                                                                      ##\n";
        std::cout << "\t##     - 1 pour Enregistrer une nouvel COMMANDE    - 3 pour Rechercher une COMMANDE     ##\n";
        std::cout << "\t##                                                                                      ##\n";
        std::cout << "\t##     - 2 pour la Modification d'une COMMANDE     - 4 pour Supprimer une COMMANDE      ##\n";
        std::cout << "\t##                                                                                      ##\n";
        std::cout << "\t##     - 5 pour la liste des COMMANDES             - 0 pour Menu principal              ##\n";
        std::cout << "\t##                                                                                      ##\n";
        std::cout << "\t##         ----------------------------------------------------------------             ##\n";

        std::cout << "\t## Entrer votre choix: \t";
        std::cin >> choixUtilisateur;
        system("clear");
    }
    while(choixUtilisateur.c_str()[0] != '0' && choixUtilisateur.c_str()[0] != '1' && choixUtilisateur.c_str()[0] != '2' && choixUtilisateur.c_str()[0] != '3' && choixUtilisateur.c_str()[0] != '4'&& choixUtilisateur.c_str()[0] != '5');

    switch(choixUtilisateur.c_str()[0]){

        case '0': // fonction de retour au menu principal;
            acceuil();
            break;
        case '1': // creation d'une;
            
            break;
        case '2': // fonction menu de modification d'une commande;
            break;
        case '3': // fonction menu de recherche d'une cpmmande;
            break;
        case '4': //fonction de supression d'une commande;
            break;
        case '5': // Affichages des differentes commandes
            break;

    }
}

void menu_general_livraison(){
    std::string choixUtilisateur;
    do
    {
    
        std::cout << "\t##########################################################################################\n";
        std::cout << "\t##-_-_-                                                                            -_-_-##\n";
        std::cout << "\t##               BIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL                ##\n";
        std::cout << "\t##                -----------------------------------------------------                 ##\n";
        std::cout << "\t##                                                                                      ##\n";
        std::cout << "\t##                          ------------------------------                              ##\n";
        std::cout << "\t##                         |     GESTION DES LIVRAISON    |                             ##\n";
        std::cout << "\t##                          ------------------------------                              ##\n";
        std::cout << "\t##                                                                                      ##\n";
        std::cout << "\t##                     Veuillez suivre à la lettre les consigne !                       ##\n";
        std::cout << "\t##                       --------------------------------------                         ##\n";
        std::cout << "\t##-_-_-  Appuyez sur:                                                              -_-_-##\n";
        std::cout << "\t##                                                                                      ##\n";
        std::cout << "\t##     - 1 pour Enregistrer une LIVRAISON    - 3 pour Rechercher une LIVRAISON          ##\n";
        std::cout << "\t##                                                                                      ##\n";
        std::cout << "\t##     - 2 pour la Modification d'une LIVRAISON   - 4 pour Supprimer une LIVRAISON      ##\n";
        std::cout << "\t##                                                                                      ##\n";
        std::cout << "\t##     - 5 pour la liste des LIVRAISONS            - 0 pour Menu principal              ##\n";
        std::cout << "\t##                                                                                      ##\n";
        std::cout << "\t##         ----------------------------------------------------------------             ##\n";

        std::cout << "\t## Entrer votre choix: \t";
        std::cin >> choixUtilisateur;
        system("clear");
    }
    while(choixUtilisateur.c_str()[0] != '0' && choixUtilisateur.c_str()[0] != '1' && choixUtilisateur.c_str()[0] != '2' && choixUtilisateur.c_str()[0] != '3' && choixUtilisateur.c_str()[0] != '4'&& choixUtilisateur.c_str()[0] != '5');


    switch(choixUtilisateur.c_str()[0]){

        case '0': // fonction de retour au menu principal;
            acceuil();
            break;
        case '1': // creation d'une LIVRAISON;
            
            break;
        case '2': // fonction menu de modification d'une LIVRAISON;
            break;
        case '3': // fonction menu de recherche d'une LIVRAISON;
            break;
        case '4': //fonction de supression d'une LIVRAISON;
            break;
        case '5': // Affichages des differentes LIVRAISON
            break;

    }
}

/*
    Cette fonction nous permet d'avoir une interface
    propre pour l'enregistrement de nos nouveau client
*/
void interface_creation_client(){
    // differentes variables a utiliser dans notre fonction
    std::string nom;
    std::string prenom;
    std::string date;
    std::string sexe;

    // petit menu de presentation
    std::cout << "\t##########################################################################################\n";
    std::cout << "\t##-_-_-                                                                            -_-_-##\n";
    std::cout << "\t##               BIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL                ##\n";
    std::cout << "\t##                ----------------------------------------------------                  ##\n";
    std::cout << "\t##                          ------------------------------                              ##\n";
    std::cout << "\t##                         | CREATION D'UN NOUVEAU CLIENT |                             ##\n";
    std::cout << "\t##                          ------------------------------                              ##\n";
    std::cout << "\t##                                                                                      ##\n";
    std::cout << "\t##                    Veuillez suivre à la lettre les consigne !                        ##\n";
    std::cout << "\t##                      -------------------------------------                           ##\n";
    std::cout << "\t##-_-_-                                                                            -_-_-##\n";
    std::cout << "\t##                                                                                      ##\n";
    std::cout << "\t##         ----------------------------------------------------------------             ##\n";
        // recuperation des informations du nouveau client
        std::cout << "\t Entrer NOM Client :\t";
        std::cin >>nom;
        std::cout << "\t Entrer PRENOM Client :\t";
        std::cin >> prenom;
        std::cout << "\t Entrer DATE NAISSANCE Client(JJ/MM/AAAA) :\t";
        std::cin >> date;
        std::cout << "\t Entrer SEXE Client(M/F) :\t";
        std::cin >> sexe;
    // Enregistrement de notre client
    gestionnaireClient.creer_client(nom.c_str(), prenom.c_str(), date.c_str(), sexe.c_str());

    std::string choixUtilisateur;
    do{
        std::cout <<"\t Voulez-vous refaire un enregistrement? \n";
        std::cout <<"\t 1 - pour OUI \n";
        std::cout <<"\t 0 - pour Nom \n";
        std::cin >> choixUtilisateur;
    } while (choixUtilisateur.c_str()[0] != '0' && choixUtilisateur.c_str()[0] != '1');

    switch (choixUtilisateur.c_str()[0]){
        case '0':
            system("clear");
            menu_general_client();
            break;
        case '1': 
            system("clear");
            interface_creation_client();
            break;
    }

}; // fin de notre fonction d'enregistrement de nouveau client

void interface_recherche_client(){
    // differentes variables a utiliser dans notre fonction
    std::string nom;
    std::string prenom;
    std::string date;
    std::string sexe;

    // petit menu de presentation
    std::cout << "\t##########################################################################################\n";    
    std::cout << "\t##-_-_-                                                                            -_-_-##\n";
    std::cout << "\t##                 BIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL              ##\n";
    std::cout << "\t##                   ---------------------------------------------------                ##\n";
    std::cout << "\t##                           ---------------------------------                          ##\n";
    std::cout << "\t##                          |      RECHERCHE D'UN CLIENT      |                        ##\n";
    std::cout << "\t##                            --------------------------------                         ##\n";
    std::cout << "\t##                                                                                      ##\n";
    std::cout << "\t##                      Veuillez suivre à la lettre les consigne !                      ##\n";
    std::cout << "\t##                               -----------------------                                ##\n";
    std::cout << "\t##-_-_-                                                                            -_-_-##\n";
    std::cout << "\t##                                                                                      ##\n";
    std::cout << "\t##         ----------------------------------------------------------------             ##\n";
    
        std::string choixUtilisateur;
    do{
        std::cout <<"\t Voulez-vous faire la recherche via ID ou via NOM? \n";
        std::cout <<"\t 1 - pour ID \n";
        std::cout <<"\t 2 - pour NON \n";
    } while (choixUtilisateur.c_str()[0] != '1' && choixUtilisateur.c_str()[0] != '2');
    int id;
    std::string nomR;
    switch (choixUtilisateur.c_str()[0]){
        case '1': // recherche via id
        std::cout <<"\t Entrer l'ID \t";
        std::cin >> id;
        gestionnaireClient.chercher_client(id);
            break;
        case '2': // recherche via nom
            std::cout <<"\t Entrer le NOM \t";
            std::cin >> nomR;
            gestionnaireClient.chercher_client(nomR.c_str());
            break;
    };

        std::string ch;
    do{
        std::cout <<"\t Voulez-vous refaire une recherche? \n";
        std::cout <<"\t 1 - pour OUI \n";
        std::cout <<"\t 0 - pour Nom \n";
    } while (choixUtilisateur.c_str()[0] != '0' && choixUtilisateur.c_str()[0] != '1');
    int choixF;
    choixF = int(choixUtilisateur.c_str()[0]);

    switch (choixF){
        case 0:
            interface_recherche_client();
            break;
        case 1: 
            interface_creation_client();
            break;
    }    
};

bool est_premier(long p){
    if(p <= 1){
        return false;
    }
    int i = 2;
    long g = sqrtf(p);
    while (i <= g)
    {
        if(p%i == 0){
            return false;
        }
        i++;
    }
    return true;
}
long prochain_nb_premier(long p){
    while (!est_premier(++p));
    return p;
}
bool is_affirmatif(const char * choix){
    int i =0;
    std::vector<const char *> Choix;
    Choix.push_back("OUI");
    Choix.push_back("O");
    Choix.push_back("YES");
    Choix.push_back("Y");
    Choix.push_back("oui");
    Choix.push_back("o");
    Choix.push_back("yes");
    Choix.push_back("y");
    while ( i < 8 )
    {
        if(strcmp(choix,Choix[i]) == 0){
            return true;
        }
        i++;
    }
    return false;
};
std::ostream& serialiser(std::ostream &os, const std::string &s) {
    return os << '\"' << s << '\"';
}
std::istream& deserialiser(std::istream &is, std::string &s) {
   if (!is) return is;
   char c;
   if (is>>c && c != '\"') { 
      is.putback(c);
      // mettre is en état d'erreur
      return is;
   }
   std::string temp;
   while(is>>c && c != '\"')
      temp += c;
   if (is) // ou if ( == '\"') au choix
      s = temp;
   return is;
};
    /*
    @brief cat_many cat str argument in to one string 
    @params nbCh number of char * passed 
    @return a string resulting of concatanation off all char * parsed
    */
std::string cat_many(int nbCh, ...){
    va_list liste ;
    va_start (liste , nbCh) ;
    int i;
    std::string reslut;
    for (i=1 ; i<=nbCh ; i++)
    { 
        std::string tampon = va_arg (liste, char *) ;
        reslut += tampon;
        
    }
    va_end(liste);
    
    return reslut;
}

