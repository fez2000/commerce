#include <iostream>
#include "fonctions.h"
#include <math.h>
#include <string.h>
#include <vector>
#include <fstream>
#include "../Client/Clients.h"
#include "../Article/Articles.h"


bool choix_non_valide(std::string choix, std::string listeValide ){
    long i = listeValide.size();
    while (--i>=0)
    {
        if(choix[0] == listeValide[i]){
            return false;
        }
    }
    return true;
};
long long de_string_pour_long_long(std::string s){
 long long num = 0;
 long long i = 0, N= s.size();

 while (i < N)
 {
     num = s[i]*i+num;
     i++;
 }
  return num;   
}
Client::Client gestionnaireClient;
Article::Article gestionnaireArticle;

/*
    Acceuil
*/
void acceuil(){
    // differentes variables a utiliser dans notre fonction
    std::string choixUtilisateur;
     do{

          // petit menu de presentation
          std::cout << "\t##########################################################################################\n";
          std::cout << "\t##-_-_-                                                                            -_-_-##\n";
          std::cout << "\t##                 BIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE                 ##\n";
          std::cout << "\t##                                                                                      ##\n";
          std::cout << "\t##                               %%%     %%%     %%%                                    ##\n";
          std::cout << "\t##                                %%%   %%%      %%%                                    ##\n";
          std::cout << "\t##                                  %%%%%        %%%                                    ##\n";
          std::cout << "\t##                                  %%%%%        %%%                                    ##\n";
          std::cout << "\t##                                %%%   %%%      %%%%%%%%%%                             ##\n";
          std::cout << "\t##                               %%%     %%%     %%%%%%%%%%                             ##\n";
          std::cout << "\t##                                                                                      ##\n";
          std::cout << "\t##                  ---------------------------------------------------                 ##\n";
          std::cout << "\t##                  ---------------------------------------------------                 ##\n";
          std::cout << "\t##                                                                                      ##\n";
          std::cout << "\t##                      Veuillez suivre à la lettre les consigne !                      ##\n";
          std::cout << "\t##                  ---------------------------------------------------                 ##\n";
          std::cout << "\t##  Tapez:                                                                              ##\n";
          std::cout << "\t##       1- Pour GESTIONS CLIENTS               2- Pour GESTIONS ARTICLES               ##\n";
          std::cout << "\t##       3- Pour GESTIONS COMMANDES             4- Pour GESTIONS LIVRAISONS             ##\n";
          std::cout << "\t##       5- Pour AUTRES FONCTIONS               0- QUITTER                              ##\n";
          std::cout << "\t##                                                                                      ##\n";
          std::cout << "\t##                                                                                      ##\n";
          std::cout << "\t##                    -------------------------------------------                       ##\n";
          std::cout << "\t##-_-_-                                                                            -_-_-##\n";
          std::cout << "\t##                                                                                      ##\n";

          std::cout << "\t## Entrer votre choix: \t";
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
          case '5': // a propos
               autre_fonction();
               break;

          default:
               std::cout << " choix non disponible \n";
          break;
     };
}

void autre_fonction(){
    // differentes variables a utiliser dans notre fonction
    std::string choixUtilisateur;
     do{

          // petit menu de presentation
          std::cout << "\t##########################################################################################\n";
          std::cout << "\t##-_-_-                                                                            -_-_-##\n";
          std::cout << "\t##                 BIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE                 ##\n";
          std::cout << "\t##                                                                                      ##\n";
          std::cout << "\t##                               %%%     %%%     %%%                                    ##\n";
          std::cout << "\t##                                %%%   %%%      %%%                                    ##\n";
          std::cout << "\t##                                  %%%%%        %%%                                    ##\n";
          std::cout << "\t##                                  %%%%%        %%%                                    ##\n";
          std::cout << "\t##                                %%%   %%%      %%%%%%%%%%                             ##\n";
          std::cout << "\t##                               %%%     %%%     %%%%%%%%%%                             ##\n";
          std::cout << "\t##                                                                                      ##\n";
          std::cout << "\t##                  ---------------------------------------------------                 ##\n";
          std::cout << "\t##                  ---------------------------------------------------                 ##\n";
          std::cout << "\t##                                                                                      ##\n";
          std::cout << "\t##                      Veuillez suivre à la lettre les consigne !                      ##\n";
          std::cout << "\t##                  ---------------------------------------------------                 ##\n";
          std::cout << "\t##  Tapez:                                                                              ##\n";
          std::cout << "\t##       1 - Pour Liste des articles achetes par un client                              ##\n";
          std::cout << "\t##       2 - Pour Liste des Clients d'un Article                                        ##\n";
          std::cout << "\t##       3 - Pour Liste des Commandes en Cours d'un Client                              ##\n";
          std::cout << "\t##       4 - Pour les Statistiques sur les Ventes d'un Article                          ##\n";
          std::cout << "\t##       5 - Pour Liste des articles avec Prix Unitaire                                 ##\n";
          std::cout << "\t##       6 - Pour Liste des Articles a Ravitailler                                      ##\n";
          std::cout << "\t##       7 - Pour Capital du SuperMarche XL                                             ##\n";
          std::cout << "\t##       8 - Pour Meilleur Client de XL                                                 ##\n";
          std::cout << "\t##                                                                                      ##\n";
          std::cout << "\t##       9 - Pour RETOUR                          0 - QUITTER LE PROGRAMME              ##\n";
          std::cout << "\t##                                                                                      ##\n";
          std::cout << "\t##                    -------------------------------------------                       ##\n";
          std::cout << "\t##-_-_-                                                                            -_-_-##\n";
          std::cout << "\t##                                                                                      ##\n";

          std::cout << "\t## Entrer votre choix: \t";
          std::cin >> choixUtilisateur;
          system("clear");

     } while (choixUtilisateur.c_str()[0] != '0' && choixUtilisateur.c_str()[0] != '1' && choixUtilisateur.c_str()[0] != '2' && choixUtilisateur.c_str()[0] != '3' && choixUtilisateur.c_str()[0] != '4' && choixUtilisateur.c_str()[0] != '5' && choixUtilisateur.c_str()[0] != '6' && choixUtilisateur.c_str()[0] != '7' && choixUtilisateur.c_str()[0] != '8' && choixUtilisateur.c_str()[0] != '9');


     switch (choixUtilisateur.c_str()[0]){
          case '0':
               system("exit");
               break;
          case '1': // Liste des articles achetes par un client
               
               break;
          case '2': // Liste des Clients d'un Article
                interface_liste_client_article();
               
               break;
          case '3': // Liste des Commandes en Cours d'un Client
               
               break;
          case '4': // les Statistiques sur les Ventes d'un Article
               
               break;
          case '5': // Liste des articles avec Prix Unitaire
               break;
          case '6': // Liste des Articles a Ravitailler 

               break;
          case '7': // Capital du SuperMarche XL
                interface_capital();
               break;
          case '8': // Meilleur Client de XL
                interface_meilleur_client();
               break;
          case '9': // retour
                acceuil();
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
    std::string choixUtilisateur;
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
            interface_modif_client();
            break;
        case '3': // fonction menu de recherche d'un client;
            interface_recherche_client();
            break;
        case '4': //fonction de supression d'un client;
            interface_suppression_client();
            break;
        case '5': // affichage client
            interface_liste_client();
            break;

    }
} // termine

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
            interface_creation_article();
            break;
        case '2': // fonction menu de modification d'un ARTICLE;
            interface_modif_article();
            break;
        case '3': // fonction menu de recherche d'un ARTICLE;
            interface_recherche_article();
            break;
        case '4': //fonction de supression d'un ARTICLE;
            interface_suppression_article();
            break;
        case '5': // Affichages des differents articles
            interface_liste_article();
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
    std::string choixUtilisateur;

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
    std::cout <<"\n";


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
   // fonction terminé

// modification client
void interface_modif_client(){
    // differentes variables a utiliser dans notre fonction
    std::string nom;
    std::string prenom;
    std::string date;
    std::string sexe;
    std::string choixUtilisateur;

    // petit menu de presentation
    std::cout << "\t##########################################################################################\n";
    std::cout << "\t##-_-_-                                                                            -_-_-##\n";
    std::cout << "\t##               BIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL                ##\n";
    std::cout << "\t##                ----------------------------------------------------                  ##\n";
    std::cout << "\t##                        ---------------------------------                             ##\n";
    std::cout << "\t##                       | MODIFICATION D'UN NOUVEAU CLIENT |                           ##\n";
    std::cout << "\t##                        ---------------------------------                             ##\n";
    std::cout << "\t##                                                                                      ##\n";
    std::cout << "\t##                    Veuillez suivre à la lettre les consigne !                        ##\n";
    std::cout << "\t##                      -------------------------------------                           ##\n";
    std::cout << "\t##-_-_-                                                                            -_-_-##\n";
    std::cout << "\t##                                                                                      ##\n";
    std::cout << "\t##         ----------------------------------------------------------------             ##\n";
      /*  // recuperation des informations du nouveau client
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
    std::cout <<"\n";

        */
    do{
        std::cout <<"\t Voulez-vous faire une nouvelle modification? \n";
        std::cout <<"\t 1 - pour OUI \n";
        std::cout <<"\t 0 - pour NOM \n";
        std::cin >> choixUtilisateur;
    } while (choixUtilisateur.c_str()[0] != '0' && choixUtilisateur.c_str()[0] != '1');

    switch (choixUtilisateur.c_str()[0]){
        case '0':
            system("clear");
            menu_general_client();
            break;
        case '1': 
            system("clear");
            interface_modif_client();
            break;
    }

};

// recherche client
void interface_recherche_client(){
    // differentes variables a utiliser dans notre fonction
    std::string choixUtilisateur;
    int id;
    std::string nomR;
    std::string ch;
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
    
    do{
        std::cout <<"\t Voulez-vous faire la recherche via ID ou via NOM? \n";
        std::cout <<"\t 1 - pour ID \n";
        std::cout <<"\t 2 - pour NON \n";
        std::cin >> choixUtilisateur;
    } while (choixUtilisateur.c_str()[0] != '1' && choixUtilisateur.c_str()[0] != '2');

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

    do{
        std::cout <<"\t Voulez-vous refaire une recherche? \n";
        std::cout <<"\t 1 - pour OUI \n";
        std::cout <<"\t 0 - pour Nom \n";
        std::cin >> ch;
    } while (ch.c_str()[0] != '0' && ch.c_str()[0] != '1');

    switch (ch.c_str()[0]){
        case '0':
            menu_general_client();
            break;
        case '1': 
            interface_recherche_client();
            break;
    }   
    system("clear"); 
};

// suppression client
void interface_suppression_client(){
    // differentes variables a utiliser dans notre fonction
    int id;
    std::string ch;

    // petit menu de presentation
    std::cout << "\t##########################################################################################\n";    
    std::cout << "\t##-_-_-                                                                            -_-_-##\n";
    std::cout << "\t##                 BIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL              ##\n";
    std::cout << "\t##                   ---------------------------------------------------                ##\n";
    std::cout << "\t##                           ---------------------------------                          ##\n";
    std::cout << "\t##                          |    SUPPRESSION D'UN CLIENT      |                         ##\n";
    std::cout << "\t##                            --------------------------------                          ##\n";
    std::cout << "\t##                                                                                      ##\n";
    std::cout << "\t##                      Veuillez suivre à la lettre les consigne !                      ##\n";
    std::cout << "\t##                               -----------------------                                ##\n";
    std::cout << "\t##-_-_-                                                                            -_-_-##\n";
    std::cout << "\t##                                                                                      ##\n";
    std::cout << "\t##         ----------------------------------------------------------------             ##\n";
    
        std::cout <<"\t Entrer l'ID du client a supprimer: \t";
        std::cin >> id;
        
        gestionnaireClient.supprimer_client(id);
        std::cout << "\n";    


    do{
        std::cout <<"\t Voulez-vous refaire une suppresion? \n";
        std::cout <<"\t 1 - pour OUI \n";
        std::cout <<"\t 0 - pour Nom \n\n";
        std::cout <<"\t Entrer votre choix: \t";
        std::cin >> ch;
        system("clear");
    } while (ch.c_str()[0] != '0' && ch.c_str()[0] != '1');

    switch (ch.c_str()[0]){
        case '0':
            menu_general_client();
            break;
        case '1': 
            interface_suppression_client();
            break;
    }   
    system("clear"); 
};// fonction terminé

void interface_liste_client(){
    // differentes variables a utiliser dans notre fonction
    std::string ch;

    // petit menu de presentation
    std::cout << "\t##########################################################################################\n";    
    std::cout << "\t##-_-_-                                                                            -_-_-##\n";
    std::cout << "\t##                 BIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL              ##\n";
    std::cout << "\t##                   ---------------------------------------------------                ##\n";
    std::cout << "\t##                           ---------------------------------                          ##\n";
    std::cout << "\t##                          |        LISTE DES CLIENTS        |                         ##\n";
    std::cout << "\t##                            --------------------------------                          ##\n";
    std::cout << "\t##                                                                                      ##\n";
    std::cout << "\t##-_-_-                                                                            -_-_-##\n";
    std::cout << "\t##         -----------------------------------------------------------------            ##\n";
    
        
        // Fonction qui affiche la liste des client
        std::cout << "\n";    


    do{
        std::cout <<"\t Tapez: \n";
        std::cout <<"\t      1 - pour RETOUR AU MENU CLIENT \n";
        std::cout <<"\t      0 - pour RETOUR AU MENU PRINCIPAL \n\n";
        std::cout <<"\t Entrer votre choix: \t";
        std::cin >> ch;
        system("clear");
    } while (ch.c_str()[0] != '0' && ch.c_str()[0] != '1');

    switch (ch.c_str()[0]){
        case '0':
            system("clear");
            menu_general_client();
            break;
        case '1':
            system("clear");
            acceuil();
            break;
    }   
};

// fin des fontions associer au menu client

// debut des fonctions associer au menu Article

void interface_creation_article(){
    // differentes variables a utiliser dans notre fonction
    std::string nomArticle;
    double prixArticle;
    unsigned long quantite;
    unsigned long seuil;
    std::string choixUtilisateur;

    // petit menu de presentation
    std::cout << "\t##########################################################################################\n";
    std::cout << "\t##-_-_-                                                                            -_-_-##\n";
    std::cout << "\t##               BIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL                ##\n";
    std::cout << "\t##                ----------------------------------------------------                  ##\n";
    std::cout << "\t##                          ------------------------------                              ##\n";
    std::cout << "\t##                         |    CREATION DES ARTICLES     |                             ##\n";
    std::cout << "\t##                          ------------------------------                              ##\n";
    std::cout << "\t##                                                                                      ##\n";
    std::cout << "\t##                    Veuillez suivre à la lettre les consigne !                        ##\n";
    std::cout << "\t##                      -------------------------------------                           ##\n";
    std::cout << "\t##-_-_-                                                                            -_-_-##\n";
    std::cout << "\t##                                                                                      ##\n";
    std::cout << "\t##         ----------------------------------------------------------------             ##\n";
        // recuperation des informations du nouveau client
        std::cout << "\t Entrer le libelle de l'Article :\t";
        std::cin >>nomArticle;
        std::cout << "\t Entrer le Prix Unitaire de l'Article :\t";
        std::cin >> prixArticle;
        std::cout << "\t Entrer la Quantite en Stock :\t";
        std::cin >> quantite;
        std::cout << "\t Entrer le Seuil Critique de l'Article :\t";
        std::cin >> seuil;
    // Enregistrement de notre client
    gestionnaireArticle.creer(nomArticle.c_str(), prixArticle, quantite, seuil);
    std::cout <<"\n";


    do{
        std::cout <<"\t Voulez-vous refaire un enregistrement? \n";
        std::cout <<"\t 1 - pour OUI \n";
        std::cout <<"\t 0 - pour NOM \n";
        std::cout <<"\t Votre choix: \t";
        std::cin >> choixUtilisateur;
    } while (choixUtilisateur.c_str()[0] != '0' && choixUtilisateur.c_str()[0] != '1');

    switch (choixUtilisateur.c_str()[0]){
        case '0':
            system("clear");
            menu_general_article();
            break;
        case '1': 
            system("clear");
            interface_creation_article();
            break;
    }

};// termine

void interface_suppression_article(){
    // differentes variables a utiliser dans notre fonction
    int id;
    std::string ch;

    // petit menu de presentation
    std::cout << "\t##########################################################################################\n";    
    std::cout << "\t##-_-_-                                                                            -_-_-##\n";
    std::cout << "\t##                 BIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL              ##\n";
    std::cout << "\t##                   ---------------------------------------------------                ##\n";
    std::cout << "\t##                           ---------------------------------                          ##\n";
    std::cout << "\t##                          |    SUPPRESSION D'UN ARTICLE     |                         ##\n";
    std::cout << "\t##                            --------------------------------                          ##\n";
    std::cout << "\t##                                                                                      ##\n";
    std::cout << "\t##                      Veuillez suivre à la lettre les consigne !                      ##\n";
    std::cout << "\t##                               -----------------------                                ##\n";
    std::cout << "\t##-_-_-                                                                            -_-_-##\n";
    std::cout << "\t##                                                                                      ##\n";
    std::cout << "\t##         ----------------------------------------------------------------             ##\n";
    
        std::cout <<"\t Entrer l'ID de l'Article a supprimer: \t";
        std::cin >> id;
        
        gestionnaireArticle.supprimer(id);
        std::cout << "\n";    


    do{
        std::cout <<"\t Voulez-vous refaire une suppresion? \n";
        std::cout <<"\t 1 - pour OUI \n";
        std::cout <<"\t 0 - pour Nom \n\n";
        std::cout <<"\t Entrer votre choix: \t";
        std::cin >> ch;
        system("clear");
    } while (ch.c_str()[0] != '0' && ch.c_str()[0] != '1');

    switch (ch.c_str()[0]){
        case '0':
            menu_general_article();
            break;
        case '1': 
            interface_suppression_article();
            break;
    }   
    system("clear"); 
};// fonction terminé

void interface_liste_article(){
    // differentes variables a utiliser dans notre fonction
    std::string ch;

    // petit menu de presentation
    std::cout << "\t##########################################################################################\n";    
    std::cout << "\t##-_-_-                                                                            -_-_-##\n";
    std::cout << "\t##                 BIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL              ##\n";
    std::cout << "\t##                   ---------------------------------------------------                ##\n";
    std::cout << "\t##                           ---------------------------------                          ##\n";
    std::cout << "\t##                          |        LISTE DES ARTICLES       |                         ##\n";
    std::cout << "\t##                            --------------------------------                          ##\n";
    std::cout << "\t##                                                                                      ##\n";
    std::cout << "\t##-_-_-                                                                            -_-_-##\n";
    std::cout << "\t##         -----------------------------------------------------------------            ##\n";
    
        
        // Fonction qui affiche la liste des client
        std::cout << "\n";    


    do{
        std::cout <<"\t Tapez: \n";
        std::cout <<"\t      1 - pour RETOUR AU MENU DES ARTICLES \n";
        std::cout <<"\t      0 - pour RETOUR AU MENU PRINCIPAL \n\n";
        std::cout <<"\t Entrer votre choix: \t";
        std::cin >> ch;
        system("clear");
    } while (ch.c_str()[0] != '0' && ch.c_str()[0] != '1');

    switch (ch.c_str()[0]){
        case '0':
            system("clear");
            menu_general_article();
            break;
        case '1':
            system("clear");
            acceuil();
            break;
    }   
};

void interface_recherche_article(){
    // differentes variables a utiliser dans notre fonction
    std::string choixUtilisateur;
    int id;
    std::string nomR;
    std::string ch;
    // petit menu de presentation
    std::cout << "\t##########################################################################################\n";    
    std::cout << "\t##-_-_-                                                                            -_-_-##\n";
    std::cout << "\t##                 BIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL              ##\n";
    std::cout << "\t##                   ---------------------------------------------------                ##\n";
    std::cout << "\t##                           ---------------------------------                          ##\n";
    std::cout << "\t##                          |      RECHERCHE D'UN ARTICLE      |                        ##\n";
    std::cout << "\t##                            --------------------------------                          ##\n";
    std::cout << "\t##                                                                                      ##\n";
    std::cout << "\t##                      Veuillez suivre à la lettre les consigne !                      ##\n";
    std::cout << "\t##                               -----------------------                                ##\n";
    std::cout << "\t##-_-_-                                                                            -_-_-##\n";
    std::cout << "\t##                                                                                      ##\n";
    std::cout << "\t##         ----------------------------------------------------------------             ##\n";
    
    do{
        std::cout <<"\t Voulez-vous faire la recherche via ID ou via LIBELLE? \n";
        std::cout <<"\t 1 - pour ID \n";
        std::cout <<"\t 2 - pour LIBELLE \n";
        std::cin >> choixUtilisateur;
    } while (choixUtilisateur.c_str()[0] != '1' && choixUtilisateur.c_str()[0] != '2');

    switch (choixUtilisateur.c_str()[0]){
        case '1': // recherche via id
            std::cout <<"\t Entrer l'ID \t";
            std::cin >> id;
            gestionnaireArticle.chercher(id);
            break;
        case '2': // recherche via nom
            std::cout <<"\t Entrer le LIBELLE \t";
            std::cin >> nomR;
            gestionnaireArticle.chercher(nomR.c_str());
            break;
    };

    do{
        std::cout <<"\t Voulez-vous refaire une recherche? \n";
        std::cout <<"\t 1 - pour OUI \n";
        std::cout <<"\t 0 - pour Nom \n";
        std::cout <<"\t Entrer votre choix \t";

        std::cin >> ch;
    } while (ch.c_str()[0] != '0' && ch.c_str()[0] != '1');

    switch (ch.c_str()[0]){
        case '0':
            system("clear");
            menu_general_article();
            break;
        case '1': 
            system("clear");
            interface_recherche_article();
            break;
    }   
    system("clear"); 
};

void interface_modif_article(){
    // differentes variables a utiliser dans notre fonction
    std::string nom;
    std::string prenom;
    std::string date;
    std::string sexe;
    std::string choixUtilisateur;

    // petit menu de presentation
    std::cout << "\t##########################################################################################\n";
    std::cout << "\t##-_-_-                                                                            -_-_-##\n";
    std::cout << "\t##               BIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL                ##\n";
    std::cout << "\t##                ----------------------------------------------------                  ##\n";
    std::cout << "\t##                        ---------------------------------                             ##\n";
    std::cout << "\t##                       |    MODIFICATION D'UN ARTICLE    |                            ##\n";
    std::cout << "\t##                        ---------------------------------                             ##\n";
    std::cout << "\t##                                                                                      ##\n";
    std::cout << "\t##                    Veuillez suivre à la lettre les consigne !                        ##\n";
    std::cout << "\t##                      -------------------------------------                           ##\n";
    std::cout << "\t##-_-_-                                                                            -_-_-##\n";
    std::cout << "\t##                                                                                      ##\n";
    std::cout << "\t##         ----------------------------------------------------------------             ##\n";
      /*  // recuperation des informations du nouveau client
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
    std::cout <<"\n";

        */
    do{
        std::cout <<"\t Voulez-vous faire une nouvelle modification? \n";
        std::cout <<"\t 1 - pour OUI \n";
        std::cout <<"\t 0 - pour NOM \n";
        std::cin >> choixUtilisateur;
    } while (choixUtilisateur.c_str()[0] != '0' && choixUtilisateur.c_str()[0] != '1');

    switch (choixUtilisateur.c_str()[0]){
        case '0':
            system("clear");
            menu_general_client();
            break;
        case '1': 
            system("clear");
            interface_modif_client();
            break;
    }

};

// fin des fonction associer au menu article

// debut des fonctions associer au second menu
void interface_meilleur_client(){
    // differentes variables a utiliser dans notre fonction
    std::string ch;

    // petit menu de presentation
    std::cout << "\t##########################################################################################\n";    
    std::cout << "\t##-_-_-                                                                            -_-_-##\n";
    std::cout << "\t##                 BIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL              ##\n";
    std::cout << "\t##                   ---------------------------------------------------                ##\n";
    std::cout << "\t##                           ---------------------------------                          ##\n";
    std::cout << "\t##                          |        MEILLEUR CLIENTS          |                        ##\n";
    std::cout << "\t##                            --------------------------------                          ##\n";
    std::cout << "\t##                                                                                      ##\n";
    std::cout << "\t##-_-_-                                                                            -_-_-##\n";
    std::cout << "\t##         -----------------------------------------------------------------            ##\n";
    
        
        // Fonction qui affiche la liste des client
        std::cout << "\n"; 
        std::cout << "\t Le meilleur client du SUPERMARCHE XL \n";
    std::cout << "\t##########################################################################################\n";    
    std::cout << "\t##                                                                                      ##\n";    
    std::cout << "\t##                                                                                      ##\n";    
    std::cout << "\t##                                                                                      ##\n";    
    std::cout << "\t##########################################################################################\n";    

    do{
        std::cout <<"\t Tapez: \n";
        std::cout <<"\t      1 - pour RETOUR AU MENU \n";
        std::cout <<"\t      0 - pour RETOUR AU MENU PRINCIPAL \n\n";
        std::cout <<"\t Entrer votre choix: \t";
        std::cin >> ch;
        system("clear");
    } while (ch.c_str()[0] != '0' && ch.c_str()[0] != '1');

    switch (ch.c_str()[0]){
        case '0':
            system("clear");
            autre_fonction();
            break;
        case '1':
            system("clear");
            acceuil();
            break;
    }   
};

void interface_capital(){
    // differentes variables a utiliser dans notre fonction
    std::string ch;
    long double capital;

    // petit menu de presentation
    std::cout << "\t##########################################################################################\n";    
    std::cout << "\t##-_-_-                                                                            -_-_-##\n";
    std::cout << "\t##                 BIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL              ##\n";
    std::cout << "\t##                   ---------------------------------------------------                ##\n";
    std::cout << "\t##                           ---------------------------------                          ##\n";
    std::cout << "\t##                          |              CAPITAL            |                         ##\n";
    std::cout << "\t##                            --------------------------------                          ##\n";
    std::cout << "\t##                                                                                      ##\n";
    std::cout << "\t##-_-_-                                                                            -_-_-##\n";
    std::cout << "\t##         -----------------------------------------------------------------            ##\n";
    
        
        
        capital = gestionnaireArticle.capital();
        std::cout << "\n"; 
        std::cout << "\t Le CAPITAL du SUPERMARCHE XL \n";
    std::cout << "\t##########################################################################################\n";    
    std::cout << "\t##                                                                                      ##\n";    
    std::cout << "\t\t" << capital <<"\n";    
    std::cout << "\t##                                                                                      ##\n";    
    std::cout << "\t##########################################################################################\n";    

    do{
        std::cout <<"\t Tapez: \n";
        std::cout <<"\t      1 - pour RETOUR AU MENU \n";
        std::cout <<"\t      0 - pour RETOUR AU MENU PRINCIPAL \n\n";
        std::cout <<"\t Entrer votre choix: \t";
        std::cin >> ch;
        system("clear");
    } while (ch.c_str()[0] != '0' && ch.c_str()[0] != '1');

    switch (ch.c_str()[0]){
        case '0':
            system("clear");
            autre_fonction();
            break;
        case '1':
            system("clear");
            acceuil();
            break;
    }   
};// terminer

void interface_liste_client_article(){
    // differentes variables a utiliser dans notre fonction
    std::string ch;

    // petit menu de presentation
    std::cout << "\t##########################################################################################\n";    
    std::cout << "\t##-_-_-                                                                            -_-_-##\n";
    std::cout << "\t##                 BIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL              ##\n";
    std::cout << "\t##                   ---------------------------------------------------                ##\n";
    std::cout << "\t##                           ---------------------------------                          ##\n";
    std::cout << "\t##                          |   LISTE CLIENTS D'UN ARTICLE     |                        ##\n";
    std::cout << "\t##                            --------------------------------                          ##\n";
    std::cout << "\t##                                                                                      ##\n";
    std::cout << "\t##-_-_-                                                                            -_-_-##\n";
    std::cout << "\t##         -----------------------------------------------------------------            ##\n";
    
        
        // Fonction qui affiche la liste des client
        std::cout << "\n"; 
        std::cout << "\t Le meilleur client du SUPERMARCHE XL \n";
    std::cout << "\t##########################################################################################\n";    
    std::cout << "\t##                                                                                      ##\n";    
    std::cout << "\t##                                                                                      ##\n";    
    std::cout << "\t##                                                                                      ##\n";    
    std::cout << "\t##########################################################################################\n";    

    do{
        std::cout <<"\t Tapez: \n";
        std::cout <<"\t      1 - pour RETOUR AU MENU \n";
        std::cout <<"\t      0 - pour RETOUR AU MENU PRINCIPAL \n\n";
        std::cout <<"\t Entrer votre choix: \t";
        std::cin >> ch;
        system("clear");
    } while (ch.c_str()[0] != '0' && ch.c_str()[0] != '1');

    switch (ch.c_str()[0]){
        case '0':
            system("clear");
            autre_fonction();
            break;
        case '1':
            system("clear");
            acceuil();
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

