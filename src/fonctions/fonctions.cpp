#include <iostream>
#include "fonctions.h"
#include <math.h>
#include <string.h>
#include <vector>
#include <fstream>
#include "../Client/Clients.h"
#include "../Article/Articles.h"
#include "../Commande/Commandes.h"
#include "../Livraison/Livraisons.h"
#include "../relations/relations.h"


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
Commande::Commande gestionnaireCommande;
Livraison::Livraison gestionnaireLivraison;


/*
    Acceuil
*/
void acceuil(){
    // differentes variables a utiliser dans notre fonction
    std::string choixUtilisateur;
     do{

          // petit menu de presentation
        std::cout << "\t##############################################################################################################\n";              
        std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
        std::cout << "\t##                           BIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE                           ##\n";
        std::cout << "\t##                                                                                                          ##\n";
        std::cout << "\t##                          ---------------------------------------------------                             ##\n";
        std::cout << "\t##                          ---------------------------------------------------                             ##\n";
        std::cout << "\t##                                         %%%     %%%     %%%                                              ##\n";
        std::cout << "\t##                                          %%%   %%%      %%%                                              ##\n";
        std::cout << "\t##                                            %%%%%        %%%                                              ##\n";
        std::cout << "\t##                                            %%%%%        %%%                                              ##\n";
        std::cout << "\t##                                          %%%   %%%      %%%%%%%%%%                                       ##\n";
        std::cout << "\t##                                         %%%     %%%     %%%%%%%%%%                                       ##\n";
        std::cout << "\t##                          ---------------------------------------------------                             ##\n";
        std::cout << "\t##                          ---------------------------------------------------                             ##\n";
        std::cout << "\t##                              Veuillez suivre à la lettre les consigne !                                  ##\n";
        std::cout << "\t##                          ---------------------------------------------------                             ##\n";
        std::cout << "\t##      Tapez:                                                                                              ##\n";
        std::cout << "\t##          1- Pour GESTIONS CLIENTS                         2- Pour GESTIONS ARTICLES                      ##\n";
        std::cout << "\t##          3- Pour GESTIONS COMMANDES                       4- Pour GESTIONS LIVRAISONS                    ##\n";
        std::cout << "\t##          5- Pour AUTRES FONCTIONS                         0- QUITTER                                     ##\n";
        std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
        std::cout << "\t##     -----------------------------------------------------------------------------------------------      ##\n";
        std::cout << "\t##                                                                                                          ##\n";

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
        std::cout << "\t##############################################################################################################\n";    
        std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
        std::cout << "\t##                          BIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE                            ##\n";
        std::cout << "\t##                                                                                                          ##\n";
        std::cout << "\t##                          ---------------------------------------------------                             ##\n";
        std::cout << "\t##                          ---------------------------------------------------                             ##\n";
        std::cout << "\t##                                         %%%     %%%     %%%                                              ##\n";
        std::cout << "\t##                                          %%%   %%%      %%%                                              ##\n";
        std::cout << "\t##                                            %%%%%        %%%                                              ##\n";
        std::cout << "\t##                                            %%%%%        %%%                                              ##\n";
        std::cout << "\t##                                          %%%   %%%      %%%%%%%%%%                                       ##\n";
        std::cout << "\t##                                         %%%     %%%     %%%%%%%%%%                                       ##\n";
        std::cout << "\t##                          ---------------------------------------------------                             ##\n";
        std::cout << "\t##                          ---------------------------------------------------                             ##\n";
        std::cout << "\t##                              Veuillez suivre à la lettre les consigne !                                  ##\n";
        std::cout << "\t##                          ---------------------------------------------------                             ##\n";
        std::cout << "\t##      Tapez:                                                                                              ##\n";
        std::cout << "\t##              1 - Pour Liste des articles achetes par un client                                           ##\n";
        std::cout << "\t##              2 - Pour Liste des Clients d'un Article                                                     ##\n";
        std::cout << "\t##              3 - Pour Liste des Commandes en Cours d'un Client                                           ##\n";
        std::cout << "\t##              4 - Pour les Statistiques sur les Ventes d'un Article                                       ##\n";
        std::cout << "\t##              5 - Pour Liste des articles avec Prix Unitaire                                              ##\n";
        std::cout << "\t##              6 - Pour Liste des Articles a Ravitailler                                                   ##\n";
        std::cout << "\t##              7 - Pour Capital du SuperMarche XL                                                          ##\n";
        std::cout << "\t##              8 - Pour Meilleur Client de XL                                                              ##\n";
        std::cout << "\t##                                                                                                          ##\n";
        std::cout << "\t##              9 - Pour RETOUR                          0 - QUITTER LE PROGRAMME                           ##\n";
        std::cout << "\t##                                                                                                          ##\n";
        std::cout << "\t##     ---------------------------------------------------------------------------------------------        ##\n";
        std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
        std::cout << "\t##                                                                                                          ##\n";

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
                system("clear");
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
                system("clear");
                interface_capital();
               break;
          case '8': // Meilleur Client de XL
                system("clear");
                interface_meilleur_client();
               break;
          case '9': // retour
                system("clear");
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
        std::cout << "\t##     - 1 ENREGISTRE COMMANDE                     - 3 RECHERCHER COMMANDE              ##\n";
        std::cout << "\t##                                                                                      ##\n";
        std::cout << "\t##     - 2 MODIFICATION COMMANDE                   - 4 ANNULER COMMANDE                 ##\n";
        std::cout << "\t##                                                                                      ##\n";
        std::cout << "\t##     - 5 LISTE COMMANDES                         - 0 MENU PRINCIPAL                   ##\n";
        std::cout << "\t##                                                                                      ##\n";
        std::cout << "\t##         ----------------------------------------------------------------             ##\n";

        std::cout << "\t## Entrer votre choix: \t";
        std::cin >> choixUtilisateur;
        system("clear");
    }
    while(choixUtilisateur.c_str()[0] != '0' && choixUtilisateur.c_str()[0] != '1' && choixUtilisateur.c_str()[0] != '2' && choixUtilisateur.c_str()[0] != '3' && choixUtilisateur.c_str()[0] != '4'&& choixUtilisateur.c_str()[0] != '5');

    switch(choixUtilisateur.c_str()[0]){

        case '0': // fonction de retour au menu principal;
            system("clear");
            acceuil();
            break;
        case '1': // creation d'une;
            system("clear");
            interface_creation_commande();
            break;
        case '2': // fonction menu de modification d'une commande;
            system("clear");
            interface_modif_commande();
            break;
        case '3': // fonction menu de recherche d'une commande;
            system("clear");
            interface_recherche_commande();
            break;
        case '4': //fonction de supression d'une commande;
            system("clear");
            interface_suppression_commande();
            break;
        case '5': // Affichages des differentes commandes
            system("clear");
            interface_liste_commande();
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
        std::cout << "\t##     - 1 : ENREGISTRER LIVRAISON              - 3 : RECHERCHER LIVRAISON              ##\n";
        std::cout << "\t##                                                                                      ##\n";
        std::cout << "\t##     - 2 : MODIFIER LIVRAISON                 - 4 : SUPPRESSION LIVRAISON             ##\n";
        std::cout << "\t##                                                                                      ##\n";
        std::cout << "\t##     - 5 : LISTE DES LIVRAISONS               - 0 : MENU PRINCIPAL                    ##\n";
        std::cout << "\t##                                                                                      ##\n";
        std::cout << "\t##         ----------------------------------------------------------------             ##\n";

        std::cout << "\t## Entrer votre choix: \t";
        std::cin >> choixUtilisateur;
        system("clear");
    }
    while(choixUtilisateur.c_str()[0] != '0' && choixUtilisateur.c_str()[0] != '1' && choixUtilisateur.c_str()[0] != '2' && choixUtilisateur.c_str()[0] != '3' && choixUtilisateur.c_str()[0] != '4'&& choixUtilisateur.c_str()[0] != '5');


    switch(choixUtilisateur.c_str()[0]){

        case '0': // fonction de retour au menu principal;
            system("clear");
            acceuil();
            break;
        case '1': // creation d'une LIVRAISON;
            system("clear");
            interface_creation_livraison();
            
            break;
        case '2': // fonction menu de modification d'une LIVRAISON;
            break;
        case '3': // fonction menu de recherche d'une LIVRAISON;
            break;
        case '4': //fonction de supression d'une LIVRAISON;
            break;
        case '5': // Affichages des differentes LIVRAISON
            system("clear");
            interface_liste_livaison();
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
        std::cout <<"\n";
        std::cout << "\t Entrer PRENOM Client :\t";
        std::cin >> prenom;
        std::cout <<"\n";
        std::cout << "\t Entrer DATE NAISSANCE Client (JJ/MM/AAAA) :\t";
        std::cin >> date;
        std::cout <<"\n";
        std::cout << "\t Entrer SEXE Client (M/F) :\t";
        std::cin >> sexe;
        std::cout <<"\n";

    // Enregistrement de notre client
    gestionnaireClient.creer_client(nom.c_str(), prenom.c_str(), date.c_str(), sexe.c_str());
    std::cout <<"\n";


    do{
        std::cout <<"\t Voulez-vous refaire un enregistrement? \n";
        std::cout <<"\t     1 - pour OUI \n";
        std::cout <<"\t     0 - pour NON \n\n";
        std::cout <<"\t Votre choix: \t";
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

};   // fonction terminé

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
        // recuperation des informations du nouveau article
        std::cout <<"\n";
        std::cout << "\t Entrer le libelle de l'Article :\t";
        std::cin >>nomArticle;
        std::cout <<"\n";
        std::cout << "\t Entrer le Prix Unitaire de l'Article :\t";
        std::cin >> prixArticle;
        std::cout <<"\n";
        std::cout << "\t Entrer la Quantite en Stock :\t";
        std::cin >> quantite;
        std::cout <<"\n";
        std::cout << "\t Entrer le Seuil Critique de l'Article :\t";
        std::cin >> seuil;
    // Enregistrement de notre article
    gestionnaireArticle.creer(nomArticle.c_str(), prixArticle, quantite, seuil);
    std::cout <<"\n";


    do{
        std::cout <<"\t Voulez-vous refaire un enregistrement? \n";
        std::cout <<"\t 1 - pour OUI \n";
        std::cout <<"\t 0 - pour NON \n";
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

void interface_creation_commande(){
    // differentes variables a utiliser dans notre fonction
    typeId idClient;
    typeId idArticle;
    unsigned long quantite;
    std::string choixUtilisateur;
    int id;
    std::string nomR;
    Cellule<Client::Base> * personne ;
    //variable pour choix d'article         
    std::string choixU;
    int idA;
    std::string nomA;
    Cellule<Article::Base> * produit;

    // petit menu de presentation
    std::cout << "\t##########################################################################################\n";
    std::cout << "\t##-_-_-                                                                            -_-_-##\n";
    std::cout << "\t##               BIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL                ##\n";
    std::cout << "\t##                ----------------------------------------------------                  ##\n";
    std::cout << "\t##                          ------------------------------                              ##\n";
    std::cout << "\t##                         |    CREATION DES COMMANDES    |                             ##\n";
    std::cout << "\t##                          ------------------------------                              ##\n";
    std::cout << "\t##                                                                                      ##\n";
    std::cout << "\t##                    Veuillez suivre à la lettre les consigne !                        ##\n";
    std::cout << "\t##                      -------------------------------------                           ##\n";
    std::cout << "\t##-_-_-                                                                            -_-_-##\n";
    std::cout << "\t##                                                                                      ##\n";
    std::cout << "\t##         ----------------------------------------------------------------             ##\n";
        // recuperation des informations du nouveau article
        std::cout <<"\n";
        std::cout << "\t Cette commande conserne quel CLIENT? \n";
 a1:       do{ 
            std::cout <<"\n";
            std::cout <<"\t Voulez-vous faire la recherche du client via ID ou via NOM? \n";
            std::cout <<"\t\t 1 - pour ID \n";
            std::cout <<"\t\t 2 - pour NON \n\n";
            std::cout <<"\t Votre choix: \t";
            std::cin >> choixUtilisateur;
        } while (choixUtilisateur.c_str()[0] != '1' && choixUtilisateur.c_str()[0] != '2');

    switch (choixUtilisateur.c_str()[0]){
        case '1': // recherche via id
            std::cout <<"\n";            
            std::cout <<"\t Entrer l'ID \t";
            std::cin >> id;
            personne = gestionnaireClient.chercher_client(id);
            if (personne){
                std::cout <<"\n";
                std::cout << "\t##------------------------------------------------------------------------------------------------------##\n";            
                std::cout << "\t##\t     "<< personne->get().get_numero() <<"     \t"<< personne->get().get_nom() <<"     \t\t"<< personne->get().get_prenom() <<"     \t\t"<< personne->get().get_date() <<"     \t\t"<< personne->get().get_sexe() <<"\t##\n";                    
                std::cout << "\t##------------------------------------------------------------------------------------------------------##\n";  

                idClient =  personne->get().get_numero(); // recuperation de l'ID du produit

                // client existe alors on recherche le produit a commande
                    std::cout <<"\n";
                    std::cout << "\t Cette commande conserne quel ARTICLE? \n";
    a2:     do{ 
                    std::cout <<"\n";
                    std::cout <<"\t Voulez-vous faire la recherche de cette Article via ID ou via LIBELLE? \n";
                    std::cout <<"\t\t 1 - pour ID \n";
                    std::cout <<"\t\t 2 - pour LIBELLE \n\n";
                    std::cout <<"\t Votre choix: \t";
                    std::cin >> choixU;
                } while (choixU.c_str()[0] != '1' && choixU.c_str()[0] != '2');

                switch (choixU.c_str()[0]){
                    case '1': // recherche via id
                        std::cout <<"\n";            
                        std::cout <<"\t Entrer l'ID: \t";
                        std::cin >> idA;
                        produit = gestionnaireArticle.chercher(idA);
                    if (produit){
                        std::cout <<"\n";
                        std::cout << "\t##------------------------------------------------------------------------------------------------------##\n";            
                        std::cout << "\t##\t     "<< produit->get().get_reference() <<"     \t"<< produit->get().get_libelle() <<"     \t\t"<< produit->get().get_prix() <<"     \t\t"<< produit->get().get_quantite() <<"     \t\t"<< produit->get().get_seuil() <<"\t##\n";                    
                        std::cout << "\t##------------------------------------------------------------------------------------------------------##\n";            
                        
                        idArticle = produit->get().get_reference();// recuperation de l'id du produit
                        std::cout << "\n";
                        std::cout << "\t Entrer la Quantite de l'Article a commander:\t";  
                        std::cin >> quantite;  

                        gestionnaireCommande.creer(idClient,idArticle,quantite); 

                    }else{
                        std::cout << "\n";            
                        std::cout << "\t##------------------------------------------------------------------------------------------##\n";    
                        std::cout << "\t##                     CET ARTICLE N'EXISTE PAS DANS NOTRE BASE DE DONNEES                  ##\n";
                        std::cout << "\t##------------------------------------------------------------------------------------------##\n";
                        do{
                            std::cout << " \n ";
                            std::cout <<"\t Voulez-vous ANNULER la commande ou CHANGER l'article de la commande? \n";
                            std::cout <<"\t 1 - pour CHANGER \n";
                            std::cout <<"\t 0 - pour ANNULER \n";
                            std::cout <<"\t Votre choix: \t";
                            std::cin >> choixUtilisateur;
                        } while (choixUtilisateur.c_str()[0] != '0' && choixUtilisateur.c_str()[0] != '1');

                        switch (choixUtilisateur.c_str()[0]){
                            case '0':
                                system("clear");
                                menu_general_commande();
                                break;
                            case '1': 
                                goto a2;
                                break;
                        }    
                    }
                    break;
                case '2': // recherche via nom
                    std::cout <<"\n";            
                    std::cout <<"\t Entrer le LIBELLE: \t";
                    std::cin >> nomA;
                    produit = gestionnaireArticle.chercher(nomA.c_str());
                    if (produit){
                        std::cout <<"\n";
                        std::cout << "\t##------------------------------------------------------------------------------------------------------##\n";            
                        std::cout << "\t##\t     "<< produit->get().get_reference() <<"     \t"<< produit->get().get_libelle() <<"     \t\t"<< produit->get().get_prix() <<"     \t\t"<< produit->get().get_quantite() <<"     \t\t"<< produit->get().get_seuil() <<"\t##\n";                    
                        std::cout << "\t##------------------------------------------------------------------------------------------------------##\n"; 
                        idArticle = produit->get().get_reference();// recuperation de l'id du produit
                        std::cout << "\n";
                        std::cout << "\t Entrer la Quantite de l'Article a commander:\t";  
                        std::cin >> quantite;  

                        gestionnaireCommande.creer(idClient,idArticle,quantite);            

                    }else{
                        std::cout << "\n";            
                        std::cout << "\t##------------------------------------------------------------------------------------------##\n";    
                        std::cout << "\t##                     CET ARTICLE N'EXISTE PAS DANS NOTRE BASE DE DONNEES                  ##\n";
                        std::cout << "\t##------------------------------------------------------------------------------------------##\n";  
                        do{
                            std::cout << " \n ";
                            std::cout <<"\t Voulez-vous ANNULER la commande ou CHANGER l'article de la commande? \n";
                            std::cout <<"\t 1 - pour CHANGER \n";
                            std::cout <<"\t 0 - pour ANNULER \n";
                            std::cout <<"\t Votre choix: \t";
                            std::cin >> choixUtilisateur;
                        } while (choixUtilisateur.c_str()[0] != '0' && choixUtilisateur.c_str()[0] != '1');

                        switch (choixUtilisateur.c_str()[0]){
                            case '0':
                                system("clear");
                                menu_general_commande();
                                break;
                            case '1': 
                                goto a2;
                                break;
                        }   
                    }
                    break;
                };
            }else{
                std::cout << "\n";            
                std::cout << "\t##------------------------------------------------------------------------------------------##\n";    
                std::cout << "\t##                     CE CLIENT N'EXISTE PAS DANS NOTRE BASE DE DONNEES                    ##\n";
                std::cout << "\t##------------------------------------------------------------------------------------------##\n"; 
                        do{
                            std::cout << " \n ";
                            std::cout <<"\t Voulez-vous ANNULER la commande ou CHANGER le client de la commande? \n";
                            std::cout <<"\t 1 - pour CHANGER \n";
                            std::cout <<"\t 0 - pour ANNULER \n";
                            std::cout <<"\t Votre choix: \t";
                            std::cin >> choixUtilisateur;
                        } while (choixUtilisateur.c_str()[0] != '0' && choixUtilisateur.c_str()[0] != '1');

                        switch (choixUtilisateur.c_str()[0]){
                            case '0':
                                system("clear");
                                menu_general_commande();
                                break;
                            case '1': 
                                goto a1;
                                break;
                        }    
            }
        break;
        case '2': // recherche via nom
            std::cout <<"\n";            
            std::cout <<"\t Entrer le NOM \t";
            std::cin >> nomR;
            personne = gestionnaireClient.chercher_client(nomR.c_str());
            if (personne){
                std::cout <<"\n";
                std::cout << "\t##------------------------------------------------------------------------------------------------------##\n";            
                std::cout << "\t##\t     "<< personne->get().get_numero() <<"     \t"<< personne->get().get_nom() <<"     \t\t"<< personne->get().get_prenom() <<"     \t\t"<< personne->get().get_date() <<"     \t\t"<< personne->get().get_sexe() <<"\t##\n";                    
                std::cout << "\t##------------------------------------------------------------------------------------------------------##\n";
                idClient =  personne->get().get_numero(); // recuperation de l'ID du produit
                // client existe alors on recherche le produit a commande
                    std::cout <<"\n";
                    std::cout << "\t Cette commande conserne quel ARTICLE? \n";
    a3:             do{ 
                    std::cout <<"\n";
                    std::cout <<"\t Voulez-vous faire la recherche de cette Article via ID ou via LIBELLE? \n";
                    std::cout <<"\t\t 1 - pour ID \n";
                    std::cout <<"\t\t 2 - pour LIBELLE \n\n";
                    std::cout <<"\t Votre choix: \t";
                    std::cin >> choixU;
                } while (choixU.c_str()[0] != '1' && choixU.c_str()[0] != '2');

                switch (choixU.c_str()[0]){
                    case '1': // recherche via id
                        std::cout <<"\n";            
                        std::cout <<"\t Entrer l'ID: \t";
                        std::cin >> idA;
                        produit = gestionnaireArticle.chercher(idA);
                    if (produit){
                        std::cout <<"\n";
                        std::cout << "\t##------------------------------------------------------------------------------------------------------##\n";            
                        std::cout << "\t##\t     "<< produit->get().get_reference() <<"     \t"<< produit->get().get_libelle() <<"     \t\t"<< produit->get().get_prix() <<"     \t\t"<< produit->get().get_quantite() <<"     \t\t"<< produit->get().get_seuil() <<"\t##\n";                    
                        std::cout << "\t##------------------------------------------------------------------------------------------------------##\n";            
                        
                        idArticle = produit->get().get_reference();// recuperation de l'id du produit
                        std::cout << "\n";
                        std::cout << "\t Entrer la Quantite de l'Article a commander:\t";  
                        std::cin >> quantite;  

                        gestionnaireCommande.creer(idClient,idArticle,quantite); 

                    }else{
                        std::cout << "\n";            
                        std::cout << "\t##------------------------------------------------------------------------------------------##\n";    
                        std::cout << "\t##                     CET ARTICLE N'EXISTE PAS DANS NOTRE BASE DE DONNEES                  ##\n";
                        std::cout << "\t##------------------------------------------------------------------------------------------##\n";
                        do{
                            std::cout << " \n ";
                            std::cout <<"\t Voulez-vous ANNULER la commande ou CHANGER l'article de la commande? \n";
                            std::cout <<"\t 1 - pour CHANGER \n";
                            std::cout <<"\t 0 - pour ANNULER \n";
                            std::cout <<"\t Votre choix: \t";
                            std::cin >> choixUtilisateur;
                        } while (choixUtilisateur.c_str()[0] != '0' && choixUtilisateur.c_str()[0] != '1');

                        switch (choixUtilisateur.c_str()[0]){
                            case '0':
                                system("clear");
                                menu_general_commande();
                                break;
                            case '1': 
                                goto a3;
                                break;
                        }     
                    }
                    break;
                case '2': // recherche via nom
                    std::cout <<"\n";            
                    std::cout <<"\t Entrer le LIBELLE: \t";
                    std::cin >> nomA;
                    produit = gestionnaireArticle.chercher(nomA.c_str());
                    if (produit){
                        std::cout <<"\n";
                        std::cout << "\t##------------------------------------------------------------------------------------------------------##\n";            
                        std::cout << "\t##\t     "<< produit->get().get_reference() <<"     \t"<< produit->get().get_libelle() <<"     \t\t"<< produit->get().get_prix() <<"     \t\t"<< produit->get().get_quantite() <<"     \t\t"<< produit->get().get_seuil() <<"\t##\n";                    
                        std::cout << "\t##------------------------------------------------------------------------------------------------------##\n"; 
                        idArticle = produit->get().get_reference();// recuperation de l'id du produit
                        std::cout << "\n";
                        std::cout << "\t Entrer la Quantite de l'Article a commander:\t";  
                        std::cin >> quantite;  

                        gestionnaireCommande.creer(idClient,idArticle,quantite);            

                    }else{
                        std::cout << "\n";            
                        std::cout << "\t##------------------------------------------------------------------------------------------##\n";    
                        std::cout << "\t##                     CET ARTICLE N'EXISTE PAS DANS NOTRE BASE DE DONNEES                  ##\n";
                        std::cout << "\t##------------------------------------------------------------------------------------------##\n"; 
                        do{
                            std::cout << " \n ";
                            std::cout <<"\t Voulez-vous ANNULER la commande ou CHANGER l'article de la commande? \n";
                            std::cout <<"\t 1 - pour CHANGER \n";
                            std::cout <<"\t 0 - pour ANNULER \n";
                            std::cout <<"\t Votre choix: \t";
                            std::cin >> choixUtilisateur;
                        } while (choixUtilisateur.c_str()[0] != '0' && choixUtilisateur.c_str()[0] != '1');

                        switch (choixUtilisateur.c_str()[0]){
                            case '0':
                                system("clear");
                                menu_general_commande();
                                break;
                            case '1': 
                                goto a3;
                                break;
                        }    
                    }
                    break;
                };                
            }else{
                std::cout <<"\n";            
                std::cout << "\t##------------------------------------------------------------------------------------------##\n";    
                std::cout << "\t##                      CE CLIENT N'EXISTE PAS DANS NOTRE BASE DE DONNEES                   ##\n";
                std::cout << "\t##------------------------------------------------------------------------------------------##\n"; 
                        do{
                            std::cout << " \n ";
                            std::cout <<"\t Voulez-vous ANNULER la commande ou CHANGER le client de la commande? \n";
                            std::cout <<"\t 1 - pour CHANGER \n";
                            std::cout <<"\t 0 - pour ANNULER \n";
                            std::cout <<"\t Votre choix: \t";
                            std::cin >> choixUtilisateur;
                        } while (choixUtilisateur.c_str()[0] != '0' && choixUtilisateur.c_str()[0] != '1');

                        switch (choixUtilisateur.c_str()[0]){
                            case '0':
                                system("clear");
                                menu_general_commande();
                                break;
                            case '1': 
                                goto a1;
                                break;
                        }    
            }
        break;
    };

    do{
        std::cout << " \n ";
        std::cout <<"\t Voulez-vous refaire un enregistrement? \n";
        std::cout <<"\t 1 - pour OUI \n";
        std::cout <<"\t 0 - pour NON \n";
        std::cout <<"\t Votre choix: \t";
        std::cin >> choixUtilisateur;
    } while (choixUtilisateur.c_str()[0] != '0' && choixUtilisateur.c_str()[0] != '1');

    switch (choixUtilisateur.c_str()[0]){
        case '0':
            system("clear");
            menu_general_commande();
            break;
        case '1': 
            system("clear");
            interface_creation_commande();
            break;
    }

};// termine

void interface_creation_livraison(){
    // differentes variables a utiliser dans notre fonction
    typeId idClient;
    typeId ref;
    unsigned long quantite;
    std::string choixUtilisateur;
    int id;       
    int idA;
    Cellule<Commande::Base> * com;
    bool s;

    // petit menu de presentation
    std::cout << "\t##########################################################################################\n";
    std::cout << "\t##-_-_-                                                                            -_-_-##\n";
    std::cout << "\t##               BIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL                ##\n";
    std::cout << "\t##                ----------------------------------------------------                  ##\n";
    std::cout << "\t##                          ------------------------------                              ##\n";
    std::cout << "\t##                         |    CREATION DES LIVRAISONS   |                             ##\n";
    std::cout << "\t##                          ------------------------------                              ##\n";
    std::cout << "\t##                                                                                      ##\n";
    std::cout << "\t##                    Veuillez suivre à la lettre les consigne !                        ##\n";
    std::cout << "\t##                      -------------------------------------                           ##\n";
    std::cout << "\t##-_-_-                                                                            -_-_-##\n";
    std::cout << "\t##                                                                                      ##\n";
    std::cout << "\t##         ----------------------------------------------------------------             ##\n";

    std::cout <<"\n";
    std::cout << "\t Cette LIVRAISON conserne quel COMMANDE? \n";
    std::cout <<"\n";            
    std::cout <<"\t Entrer l'ID de la Commande: \t";
    std::cin >> id;

    ref = id;
    com = gestionnaireCommande.chercher(ref);
    if (com){
        s = com->get().est_livrer();
        if (s){
            std::cout << "\n";            
            std::cout << "\t##------------------------------------------------------------------------------------------##\n";    
            std::cout << "\t##                     CETTE COMMANDE EST DEJA EN COURS DE LIVRAISON                        ##\n";
            std::cout << "\t##------------------------------------------------------------------------------------------##\n";
        }else{
            idA = com->get().ref();
            idClient = com->get().ref_client();
            quantite = com->get().nombre();
            gestionnaireLivraison.creer(idA,idClient,quantite);
            com->get().livrer();
        }
    }else{
        std::cout << "\n";            
        std::cout << "\t##------------------------------------------------------------------------------------------##\n";    
        std::cout << "\t##                     IL N'EXISTE PAS DE COMMANDE A CE NUMERO                              ##\n";
        std::cout << "\t##------------------------------------------------------------------------------------------##\n";
    }
    do{
        std::cout << " \n ";
        std::cout <<"\t Voulez-vous cree une autre livraison? \n";
        std::cout <<"\t 1 - pour OUI \n";
        std::cout <<"\t 0 - pour NON \n";
        std::cout <<"\t Votre choix: \t";
        std::cin >> choixUtilisateur;
    } while (choixUtilisateur.c_str()[0] != '0' && choixUtilisateur.c_str()[0] != '1');

    switch (choixUtilisateur.c_str()[0]){
        case '0':
            system("clear");
            menu_general_livraison();
            break;
        case '1': 
            system("clear");
            interface_creation_livraison();    
            break;
    }
};// termine

/*
    fonction de listage
*/
void interface_liste_client(){
    // differentes variables a utiliser dans notre fonction
    std::string ch;
    Cellule<Client::Base> * personne ;

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
    
        std::cout << "\n";    
        personne = gestionnaireClient.recup_tete();
        std::cout << "\t\t     ID  |       NOM           |       PRENOM          |     DATE NAISSANCE \t |     SEXE \n";
        std::cout << "\t##------------------------------------------------------------------------------------------------------##\n";            
        std::cout << "\t##------------------------------------------------------------------------------------------------------##\n";
        while (personne != gestionnaireClient.recup_sentinelle())
        {   
            std::cout << "\t##\t     "<< personne->get().get_numero() <<"     \t"<< personne->get().get_nom() <<"     \t\t"<< personne->get().get_prenom() <<"     \t\t"<< personne->get().get_date() <<"     \t\t"<< personne->get().get_sexe() <<"\t##\n";    
            std::cout << "\t##------------------------------------------------------------------------------------------------------##\n";            
            personne = personne->get_next();
        }

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
            acceuil();
            break;
        case '1':
            system("clear");
            menu_general_client();
            break;
    }   
};//fonction termine

void interface_liste_commande(){
    // differentes variables a utiliser dans notre fonction
    typeId idClient;
    typeId idArticle;
    std::string choixUtilisateur;
    std::string nomR;
    Cellule<Client::Base> * personne ;
    Cellule<Commande::Base> * com ;       
    std::string ch;
    std::string nomA;
    Cellule<Article::Base> * produit;
    const char * message = "Effacer";
    std::string reponce1;
    std::string reponce2;
    std::string reponce3;

    const char * etat1 = "Livree";
    const char * etat2 = "En Cour...";
    bool s;

    // petit menu de presentation
    std::cout << "\t##########################################################################################\n";
    std::cout << "\t##-_-_-                                                                            -_-_-##\n";
    std::cout << "\t##               BIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL                ##\n";
    std::cout << "\t##                ----------------------------------------------------                  ##\n";
    std::cout << "\t##                          ------------------------------                              ##\n";
    std::cout << "\t##                         |    LISTE DES COMMANDES       |                             ##\n";
    std::cout << "\t##                          ------------------------------                              ##\n";
    std::cout << "\t##                                                                                      ##\n";
    std::cout << "\t##                    Veuillez suivre à la lettre les consigne !                        ##\n";
    std::cout << "\t##                      -------------------------------------                           ##\n";
    std::cout << "\t##-_-_-                                                                            -_-_-##\n";
    std::cout << "\t##                                                                                      ##\n";
    std::cout << "\t##         ----------------------------------------------------------------             ##\n";

        std::cout << "\n";    
        com = gestionnaireCommande.recup_tete();
        std::cout << "\t\t     ID  |       CLIENT       |    ETAT            |          LIBELLE          |     QUANTITE\n";
        std::cout << "\t##------------------------------------------------------------------------------------------------------##\n";            
        std::cout << "\t##------------------------------------------------------------------------------------------------------##\n";
        while (com != gestionnaireCommande.recup_sentinelle())
        {   reponce1.clear();
            reponce2.clear();
            reponce3.clear();
            idClient = com->get().ref_client();
            idArticle = com->get().ref_article();
            personne = gestionnaireClient.chercher_client(idClient);
            reponce1.append((personne)? personne->get().get_nom():message);
            produit = gestionnaireArticle.chercher(idArticle);
            reponce2.append((produit)? produit->get().get_libelle().c_str():message);
            s = com->get().est_livrer();
            reponce3 = (s)? etat1:etat2;

            std::cout << "\t##\t     "<< com->get().ref() <<"     \t"<< reponce1 <<"   \t "<< reponce3 <<"     \t\t"<< reponce2<<"     \t\t"<<com->get().nombre() <<"\n";    
            std::cout << "\t##------------------------------------------------------------------------------------------------------##\n";            
            com = com->get_next();
        }

    do{
        std::cout <<"\t Tapez: \n";
        std::cout <<"\t      1 - pour RETOUR AU MENU COMMANDE \n";
        std::cout <<"\t      0 - pour RETOUR AU MENU PRINCIPAL \n\n";
        std::cout <<"\t Entrer votre choix: \t";
        std::cin >> ch;
        system("clear");
    } while (ch.c_str()[0] != '0' && ch.c_str()[0] != '1');

    switch (ch.c_str()[0]){
        case '0':
            system("clear");
            acceuil();
            break;
        case '1':
            system("clear");
            menu_general_commande();
            break;
    } 

};//terminé

void interface_liste_article(){
    // differentes variables a utiliser dans notre fonction
    std::string ch;
    Cellule<Article::Base> * produit;

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
    std::cout << "\n";  
  
        produit = gestionnaireArticle.recup_tete();
        std::cout << "\t\t     ID  |       LIBELLE       |         PRIX U          |   QUANTITE \t |   SEUIL \n";
        std::cout << "\t##------------------------------------------------------------------------------------------------------##\n";            
        std::cout << "\t##------------------------------------------------------------------------------------------------------##\n";
        while (produit != gestionnaireArticle.recup_sentinelle())
        {   
            std::cout << "\t##\t     "<< produit->get().get_reference() <<"      \t"<< produit->get().get_libelle() <<"   \t\t"<< produit->get().get_prix() <<"      \t\t"<< produit->get().get_quantite() <<"    \t\t"<< produit->get().get_seuil() <<"\n";    
        std::cout << "\t##------------------------------------------------------------------------------------------------------##\n";            
            produit = produit->get_next();
        }  

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
            acceuil();
            break;
        case '1':
            system("clear");
            menu_general_article();
            break;
    }   
};//TERMINÉ

void interface_liste_livaison(){/*
    // differentes variables a utiliser dans notre fonction
    std::string ch;
    Cellule<Livraison::Base> * produit;

    // petit menu de presentation
    std::cout << "\t##########################################################################################\n";    
    std::cout << "\t##-_-_-                                                                            -_-_-##\n";
    std::cout << "\t##                 BIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL              ##\n";
    std::cout << "\t##                   ---------------------------------------------------                ##\n";
    std::cout << "\t##                           ---------------------------------                          ##\n";
    std::cout << "\t##                          |       LISTE DES LIVRAISONS      |                         ##\n";
    std::cout << "\t##                            --------------------------------                          ##\n";
    std::cout << "\t##                                                                                      ##\n";
    std::cout << "\t##-_-_-                                                                            -_-_-##\n";
    std::cout << "\t##         -----------------------------------------------------------------            ##\n";
    std::cout << "\n";  
  
        produit = gestionnaireLivraison.recup_sentinelle();
        std::cout << "\t\t     ID  |       LIBELLE       |         PRIX U          |   QUANTITE \t |   SEUIL \n";
        std::cout << "\t##------------------------------------------------------------------------------------------------------##\n";            
        std::cout << "\t##------------------------------------------------------------------------------------------------------##\n";
        while (produit != gestionnaireArticle.recup_sentinelle())
        {   
            std::cout << "\t##\t     "<< produit->get().get_reference() <<"      \t"<< produit->get().get_libelle() <<"   \t\t"<< produit->get().get_prix() <<"      \t\t"<< produit->get().get_quantite() <<"    \t\t"<< produit->get().get_seuil() <<"\n";    
        std::cout << "\t##------------------------------------------------------------------------------------------------------##\n";            
            produit = produit->get_next();
        }  

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
            acceuil();
            break;
        case '1':
            system("clear");
            menu_general_article();
            break;
    } */  
};//TERMINÉ 
/*
    fonction de suppression
*/
// suppression client
void interface_suppression_client(){
    // differentes variables a utiliser dans notre fonction
    std::string choixUtilisateur;
    int id;
    typeId identifiant;
    std::string nomR;
    std::string ch;
    Cellule<Client::Base> * personne ;

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
    
 do{ 
        std::cout <<"\n";
        std::cout <<"\t Voulez-vous faire la recherche du CLIENT a SUPPRIMER via son ID ou via son NOM? \n";
        std::cout <<"\t\t 1 - pour ID \n";
        std::cout <<"\t\t 2 - pour NOM \n\n";
        std::cout <<"\t Votre choix: \t";
        std::cin >> choixUtilisateur;
    } while (choixUtilisateur.c_str()[0] != '1' && choixUtilisateur.c_str()[0] != '2');

    switch (choixUtilisateur.c_str()[0]){
        case '1': // recherche via id
            std::cout <<"\n";            
            std::cout <<"\t Entrer l'ID \t";
            std::cin >> id;
            personne = gestionnaireClient.chercher_client(id);
            if (personne){
                std::cout <<"\n";
                std::cout << "\t##------------------------------------------------------------------------------------------------------##\n";            
                std::cout << "\t##\t     "<< personne->get().get_numero() <<"     \t"<< personne->get().get_nom() <<"     \t\t"<< personne->get().get_prenom() <<"     \t\t"<< personne->get().get_date() <<"     \t\t"<< personne->get().get_sexe() <<"\t##\n";                
                std::cout << "\t##------------------------------------------------------------------------------------------------------##\n"; 
                std::cout <<"\n";
                identifiant = id;
                gestionnaireClient.supprimer_client(identifiant);
            }else{
                std::cout << "\n";            
                std::cout << "\t##------------------------------------------------------------------------------------------##\n";    
                std::cout << "\t##                     CE CLIENT N'EXISTE PAS DANS NOTRE BASE DE DONNEES                    ##\n";
                std::cout << "\t##------------------------------------------------------------------------------------------##\n";    
            }
        break;
        case '2': // recherche via nom
            std::cout <<"\n";            
            std::cout <<"\t Entrer le NOM \t";
            std::cin >> nomR;
            personne = gestionnaireClient.chercher_client(nomR.c_str());
            if (personne){
                std::cout <<"\n";
                std::cout << "\t##------------------------------------------------------------------------------------------------------##\n";            
                std::cout << "\t##\t     "<< personne->get().get_numero() <<"     \t"<< personne->get().get_nom() <<"     \t\t"<< personne->get().get_prenom() <<"     \t\t"<< personne->get().get_date() <<"     \t\t"<< personne->get().get_sexe() <<"\t##\n";                    
                std::cout << "\t##------------------------------------------------------------------------------------------------------##\n"; 

                std::cout <<"\n";
                identifiant = personne->get().get_numero();

                gestionnaireClient.supprimer_client(identifiant);            
            }else{
                std::cout <<"\n";            
                std::cout << "\t##------------------------------------------------------------------------------------------##\n";    
                std::cout << "\t##                      CE CLIENT N'EXISTE PAS DANS NOTRE BASE DE DONNEES                   ##\n";
                std::cout << "\t##------------------------------------------------------------------------------------------##\n";    
            }
        break;
    };

    do{
        std::cout << "\n";
        std::cout <<"\t Voulez-vous refaire une suppresion? \n";
        std::cout <<"\t     1 - pour OUI \n";
        std::cout <<"\t     0 - pour NON \n\n";
        std::cout <<"\t Entrer votre choix: \t";
        std::cin >> ch;
    } while (ch.c_str()[0] != '0' && ch.c_str()[0] != '1');

    switch (ch.c_str()[0]){
        case '0':
            system("clear");
            menu_general_client();
            break;
        case '1':
            system("clear");             
            interface_suppression_client();
            break;
    }   
};// fonction terminé

void interface_suppression_article(){
    // differentes variables a utiliser dans notre fonction

    std::string choixUtilisateur;
    int id;
    typeId ref;
    std::string nomR;
    std::string ch;
    Cellule<Article::Base> * produit;

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
    
    do{ 
        std::cout <<"\n";
        std::cout <<"\t Voulez-vous faire la recherche de l'Article a SUPPRIMER via son ID ou via son LIBELLE? \n";
        std::cout <<"\t\t 1 - pour ID \n";
        std::cout <<"\t\t 2 - pour LIBELLE \n\n";
        std::cout <<"\t Votre choix: \t";
        std::cin >> choixUtilisateur;
    } while (choixUtilisateur.c_str()[0] != '1' && choixUtilisateur.c_str()[0] != '2');

    switch (choixUtilisateur.c_str()[0]){
        case '1': // recherche via id
            std::cout <<"\n";            
            std::cout <<"\t Entrer l'ID: \t";
            std::cin >> id;
            produit = gestionnaireArticle.chercher(id);
            if (produit){
                std::cout <<"\n";
                std::cout << "\t##------------------------------------------------------------------------------------------------------##\n";            
                std::cout << "\t##\t     "<< produit->get().get_reference() <<"     \t"<< produit->get().get_libelle() <<"     \t\t"<< produit->get().get_prix() <<"     \t\t"<< produit->get().get_quantite() <<"     \t\t"<< produit->get().get_seuil() <<"\t##\n";                
                std::cout << "\t##------------------------------------------------------------------------------------------------------##\n"; 
                std::cout <<"\n";
                ref = id;
                gestionnaireArticle.supprimer(ref);
            }else{
                std::cout << "\n";            
                std::cout << "\t##------------------------------------------------------------------------------------------##\n";    
                std::cout << "\t##                     CET ARTICLE N'EXISTE PAS DANS NOTRE BASE DE DONNEES                  ##\n";
                std::cout << "\t##------------------------------------------------------------------------------------------##\n";    
            }
        break;
        case '2': // recherche via nom
            std::cout <<"\n";            
            std::cout <<"\t Entrer le LIBELLE \t";
            std::cin >> nomR;
            produit = gestionnaireArticle.chercher(nomR.c_str());
            if (produit){
                std::cout <<"\n";
                std::cout << "\t##------------------------------------------------------------------------------------------------T-----##\n";            
                std::cout << "\t##\t     "<< produit->get().get_reference() <<"     \t"<< produit->get().get_libelle() <<"     \t\t"<< produit->get().get_prix() <<"     \t\t"<< produit->get().get_quantite() <<"     \t\t"<< produit->get().get_seuil() <<"\t##\n";                    
                std::cout << "\t##------------------------------------------------------------------------------------------------------##\n"; 

                std::cout <<"\n";
                ref = produit->get().get_reference();

                gestionnaireArticle.supprimer(ref);            
            }else{
                std::cout <<"\n";            
                std::cout << "\t##------------------------------------------------------------------------------------------##\n";    
                std::cout << "\t##                      CET ARTICLE N'EXISTE PAS DANS NOTRE BASE DE DONNEES                 ##\n";
                std::cout << "\t##------------------------------------------------------------------------------------------##\n";    
            }
        break;
    }

    do{
        std::cout <<"\t Voulez-vous refaire une suppresion? \n";
        std::cout <<"\t 1 - pour OUI \n";
        std::cout <<"\t 0 - pour NON \n\n";
        std::cout <<"\t Entrer votre choix: \t";
        std::cin >> ch;
    } while (ch.c_str()[0] != '0' && ch.c_str()[0] != '1');

    switch (ch.c_str()[0]){
        case '0':
            system("clear");
            menu_general_article();
            break;
        case '1': 
            system("clear");
            interface_suppression_article();
            break;
    }   
};// fonction terminé

void interface_suppression_commande(){
    // differentes variables a utiliser dans notre fonction
    std::string ch;
    int id;
    typeId ref;
    Cellule<Commande::Base> * com;

    // petit menu de presentation
    std::cout << "\t##########################################################################################\n";    
    std::cout << "\t##-_-_-                                                                            -_-_-##\n";
    std::cout << "\t##                 BIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL              ##\n";
    std::cout << "\t##                   ---------------------------------------------------                ##\n";
    std::cout << "\t##                           ---------------------------------                          ##\n";
    std::cout << "\t##                          |   SUPPRESSION D'UNE COMMANDE    |                         ##\n";
    std::cout << "\t##                            --------------------------------                          ##\n";
    std::cout << "\t##                                                                                      ##\n";
    std::cout << "\t##                      Veuillez suivre à la lettre les consigne !                      ##\n";
    std::cout << "\t##                               -----------------------                                ##\n";
    std::cout << "\t##-_-_-                                                                            -_-_-##\n";
    std::cout << "\t##                                                                                      ##\n";
    std::cout << "\t##--------------------------------------------------------------------------------------##\n";
    
        std::cout <<"\n";
        std::cout <<"\t Entrer l'ID de la Commande a supprimer: \t";
        std::cin >> id;
        ref = id;
        com = gestionnaireCommande.chercher(ref);

    if (com){// test si la commande existe
        gestionnaireCommande.supprimer(ref);
    }else{
        std::cout << "\n";            
        std::cout << "\t##---------------------------------------------------------------------------------------##\n";    
        std::cout << "\t##                  CETTE COMMANDE N'EXISTE PAS DANS NOTRE BASE DE DONNEES               ##\n";
        std::cout << "\t##---------------------------------------------------------------------------------------##\n";
    }

    do{
        std::cout <<"\t Voulez-vous refaire une suppresion? \n";
        std::cout <<"\t 1 - pour OUI \n";
        std::cout <<"\t 0 - pour NON \n\n";
        std::cout <<"\t Entrer votre choix: \t";
        std::cin >> ch;
    } while (ch.c_str()[0] != '0' && ch.c_str()[0] != '1');

    switch (ch.c_str()[0]){
        case '0':
            system("clear");
            menu_general_commande();
            break;
        case '1': 
            system("clear");
            interface_suppression_commande();
            break;
    }   
};// fonction terminé

/*
    fonction de recherche
*/
// recherche client
void interface_recherche_client(){
    // differentes variables a utiliser dans notre fonction
    std::string choixUtilisateur;
    int id;
    std::string nomR;
    std::string ch;
    Cellule<Client::Base> * personne ;
    // petit menu de presentation
    std::cout << "\t##########################################################################################\n";    
    std::cout << "\t##-_-_-                                                                            -_-_-##\n";
    std::cout << "\t##                 BIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL              ##\n";
    std::cout << "\t##                   ---------------------------------------------------                ##\n";
    std::cout << "\t##                           ---------------------------------                          ##\n";
    std::cout << "\t##                          |      RECHERCHE D'UN CLIENT      |                         ##\n";
    std::cout << "\t##                            --------------------------------                          ##\n";
    std::cout << "\t##                                                                                      ##\n";
    std::cout << "\t##                      Veuillez suivre à la lettre les consigne !                      ##\n";
    std::cout << "\t##                               -----------------------                                ##\n";
    std::cout << "\t##-_-_-                                                                            -_-_-##\n";
    std::cout << "\t##                                                                                      ##\n";
    std::cout << "\t##         ----------------------------------------------------------------             ##\n";
    
    do{ 
        std::cout <<"\n";
        std::cout <<"\t Voulez-vous faire la recherche via ID ou via NOM? \n";
        std::cout <<"\t\t 1 - pour ID \n";
        std::cout <<"\t\t 2 - pour NON \n\n";
        std::cout <<"\t Votre choix: \t";
        std::cin >> choixUtilisateur;
    } while (choixUtilisateur.c_str()[0] != '1' && choixUtilisateur.c_str()[0] != '2');

    switch (choixUtilisateur.c_str()[0]){
        case '1': // recherche via id
            std::cout <<"\n";            
            std::cout <<"\t Entrer l'ID \t";
            std::cin >> id;
            personne = gestionnaireClient.chercher_client(id);
            if (personne){
                std::cout <<"\n";
                std::cout << "\t##------------------------------------------------------------------------------------------------------##\n";            
                std::cout << "\t##\t     "<< personne->get().get_numero() <<"     \t"<< personne->get().get_nom() <<"     \t\t"<< personne->get().get_prenom() <<"     \t\t"<< personne->get().get_date() <<"     \t\t"<< personne->get().get_sexe() <<"\t##\n";                    
                std::cout << "\t##------------------------------------------------------------------------------------------------------##\n";            

            }else{
                std::cout << "\n";            
                std::cout << "\t##------------------------------------------------------------------------------------------##\n";    
                std::cout << "\t##                     CE CLIENT N'EXISTE PAS DANS NOTRE BASE DE DONNEES                    ##\n";
                std::cout << "\t##------------------------------------------------------------------------------------------##\n";    
            }
        break;
        case '2': // recherche via nom
            std::cout <<"\n";            
            std::cout <<"\t Entrer le NOM \t";
            std::cin >> nomR;
            personne = gestionnaireClient.chercher_client(nomR.c_str());
            if (personne){
                std::cout <<"\n";
                std::cout << "\t##------------------------------------------------------------------------------------------------------##\n";            
                std::cout << "\t##\t     "<< personne->get().get_numero() <<"     \t"<< personne->get().get_nom() <<"     \t\t"<< personne->get().get_prenom() <<"     \t\t"<< personne->get().get_date() <<"     \t\t"<< personne->get().get_sexe() <<"\t##\n";                    
                std::cout << "\t##------------------------------------------------------------------------------------------------------##\n";                
            }else{
                std::cout <<"\n";            
                std::cout << "\t##------------------------------------------------------------------------------------------##\n";    
                std::cout << "\t##                      CE CLIENT N'EXISTE PAS DANS NOTRE BASE DE DONNEES                   ##\n";
                std::cout << "\t##------------------------------------------------------------------------------------------##\n";    
            }
        break;
    };

    do{
        std::cout <<"\n";            
        std::cout <<"\t Voulez-vous refaire une recherche? \n";
        std::cout <<"\t\t 1 - pour OUI \n";
        std::cout <<"\t\t 0 - pour NOM \n\n";
        std::cout <<"\t Votre choix: \t";
        std::cin >> ch;
    } while (ch.c_str()[0] != '0' && ch.c_str()[0] != '1');

    switch (ch.c_str()[0]){
        case '0':
            system("clear");
            menu_general_client();
            break;
        case '1': 
            system("clear");
            interface_recherche_client();
            break;
    }   
     
};// fonction termine

void interface_recherche_article(){
    // differentes variables a utiliser dans notre fonction
    std::string choixUtilisateur;
    int id;
    std::string nomR;
    std::string ch;
    Cellule<Article::Base> * produit;
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
        std::cout <<"\n";
        std::cout <<"\t Voulez-vous faire la recherche via ID ou via LIBELLE? \n";
        std::cout <<"\t\t 1 - pour ID \n";
        std::cout <<"\t\t 2 - pour LIBELLE \n\n";
        std::cout <<"\t Votre choix: \t";
        std::cin >> choixUtilisateur;
    } while (choixUtilisateur.c_str()[0] != '1' && choixUtilisateur.c_str()[0] != '2');

    switch (choixUtilisateur.c_str()[0]){
        case '1': // recherche via id
            std::cout <<"\n";            
            std::cout <<"\t Entrer l'ID: \t";
            std::cin >> id;
            produit = gestionnaireArticle.chercher(id);
            if (produit){
                std::cout <<"\n";
                std::cout << "\t##------------------------------------------------------------------------------------------------------##\n";            
                std::cout << "\t##\t     "<< produit->get().get_reference() <<"     \t"<< produit->get().get_libelle() <<"     \t\t"<< produit->get().get_prix() <<"     \t\t"<< produit->get().get_quantite() <<"     \t\t"<< produit->get().get_seuil() <<"\t##\n";                    
                std::cout << "\t##------------------------------------------------------------------------------------------------------##\n";            

            }else{
                std::cout << "\n";            
                std::cout << "\t##------------------------------------------------------------------------------------------##\n";    
                std::cout << "\t##                     CET ARTICLE N'EXISTE PAS DANS NOTRE BASE DE DONNEES                    ##\n";
                std::cout << "\t##------------------------------------------------------------------------------------------##\n";    
            }
        break;
        case '2': // recherche via nom
            std::cout <<"\n";            
            std::cout <<"\t Entrer le LIBELLE: \t";
            std::cin >> nomR;
            produit = gestionnaireArticle.chercher(nomR.c_str());
            if (produit){
                std::cout <<"\n";
                std::cout << "\t##------------------------------------------------------------------------------------------------------##\n";            
                std::cout << "\t##\t     "<< produit->get().get_reference() <<"     \t"<< produit->get().get_libelle() <<"     \t\t"<< produit->get().get_prix() <<"     \t\t"<< produit->get().get_quantite() <<"     \t\t"<< produit->get().get_seuil() <<"\t##\n";                    
                std::cout << "\t##------------------------------------------------------------------------------------------------------##\n";            

            }else{
                std::cout << "\n";            
                std::cout << "\t##------------------------------------------------------------------------------------------##\n";    
                std::cout << "\t##                     CET ARTICLE N'EXISTE PAS DANS NOTRE BASE DE DONNEES                    ##\n";
                std::cout << "\t##------------------------------------------------------------------------------------------##\n";    
            }
        break;
    };

    do{
        std::cout <<"\t Voulez-vous faire une nouvelle recherche? \n";
        std::cout <<"\t 1 - pour OUI \n";
        std::cout <<"\t 0 - pour NON \n";
        std::cout <<"\t Entrer votre choix: \t";

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
};//TERMINÉ

void interface_recherche_commande(){
    // differentes variables a utiliser dans notre fonction
    int id;
    typeId ref;
    std::string ch;
    Cellule<Commande::Base> * com;
    typeId idClient;
    typeId idArticle;
    std::string nomR;
    Cellule<Client::Base> * personne ;     
    Cellule<Article::Base> * produit;
    const char * message = "Effacer";
    std::string reponce1;
    std::string reponce2;
    std::string reponce3;

    const char * etat1 = "Livree";
    const char * etat2 = "En Cour...";
    bool s;
    // petit menu de presentation
    std::cout << "\t##########################################################################################\n";    
    std::cout << "\t##-_-_-                                                                            -_-_-##\n";
    std::cout << "\t##                 BIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL              ##\n";
    std::cout << "\t##                   ---------------------------------------------------                ##\n";
    std::cout << "\t##                           ---------------------------------                          ##\n";
    std::cout << "\t##                          |      RECHERCHE D'UNE COMMANDE    |                        ##\n";
    std::cout << "\t##                            --------------------------------                          ##\n";
    std::cout << "\t##                                                                                      ##\n";
    std::cout << "\t##                      Veuillez suivre à la lettre les consigne !                      ##\n";
    std::cout << "\t##                               -----------------------                                ##\n";
    std::cout << "\t##-_-_-                                                                            -_-_-##\n";
    std::cout << "\t##                                                                                      ##\n";
    std::cout << "\t##--------------------------------------------------------------------------------------##\n";
    
        std::cout <<"\n";
        std::cout <<"\t Entrer l'ID de la Commande a recherche: \n";
        std::cout <<"\t Votre choix: \t";
        std::cin >> id;
            ref = id;
            com = gestionnaireCommande.chercher(ref);
            if (com){
                idClient = com->get().ref_client();
                idArticle = com->get().ref_article();
                personne = gestionnaireClient.chercher_client(idClient);
                reponce1.append((personne)? personne->get().get_nom():message);
                produit = gestionnaireArticle.chercher(idArticle);
                reponce2.append((produit)? produit->get().get_libelle().c_str():message);
                s = com->get().est_livrer();
                reponce3 = (s)? etat1:etat2;

                std::cout <<"\n";
                std::cout << "\t##---------------------------------------------------------------------------------------##\n";            
                std::cout << "\t##\t     "<< com->get().ref() <<"     \t"<< reponce1 <<"   \t "<< reponce3 <<"     \t\t"<< reponce2<<"     \t\t"<<com->get().nombre() <<"\n";
                std::cout << "\t##---------------------------------------------------------------------------------------##\n\ns";            

            }else{
                std::cout << "\n";            
                std::cout << "\t##------------------------------------------------------------------------------------------##\n";    
                std::cout << "\t##                   CETTE COMMANDE N'EXISTE PAS DANS NOTRE BASE DE DONNEES                 ##\n";
                std::cout << "\t##------------------------------------------------------------------------------------------##\n";    
            }

    do{
        std::cout <<"\t Voulez-vous faire une nouvelle recherche? \n";
        std::cout <<"\t 1 - pour OUI \n";
        std::cout <<"\t 0 - pour NON \n";
        std::cout <<"\t Entrer votre choix: \t";

        std::cin >> ch;
    } while (ch.c_str()[0] != '0' && ch.c_str()[0] != '1');

    switch (ch.c_str()[0]){
        case '0':
            system("clear");
            menu_general_commande();
            break;
        case '1': 
            system("clear");
            interface_recherche_commande();
            break;
    }   
};//TERMINÉ

/*
    fonction de modification
*/

void interface_modif_article(){
    // differentes variables a utiliser dans notre fonction
    std::string nomArticle;
    double prixArticle;
    unsigned long quantite;
    unsigned long seuil;
    std::string choixUtilisateur;
    int id;
    typeId ref;
    std::string nomR;
    std::string ch;
    Cellule<Article::Base> * produit;

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
 do{ 
        std::cout <<"\n";
        std::cout <<"\t Voulez-vous faire la recherche de l'Article a modifier via son ID ou via son LIBELLE? \n";
        std::cout <<"\t\t 1 - pour ID \n";
        std::cout <<"\t\t 2 - pour LIBELLE \n\n";
        std::cout <<"\t Votre choix: \t";
        std::cin >> choixUtilisateur;
    } while (choixUtilisateur.c_str()[0] != '1' && choixUtilisateur.c_str()[0] != '2');

    switch (choixUtilisateur.c_str()[0]){
        case '1': // recherche via id
            std::cout <<"\n";            
            std::cout <<"\t Entrer l'ID \t";
            std::cin >> id;
            produit = gestionnaireArticle.chercher(id);
            if (produit){
                std::cout <<"\n";
                std::cout << "\t##------------------------------------------------------------------------------------------------------##\n";            
                std::cout << "\t##\t     "<< produit->get().get_reference() <<"     \t"<< produit->get().get_libelle() <<"     \t\t"<< produit->get().get_prix() <<"     \t\t"<<produit->get().get_quantite() <<"     \t\t"<<produit->get().get_seuil() <<"\t##\n";                
                std::cout << "\t##------------------------------------------------------------------------------------------------------##\n"; 

                std::cout <<"\n";
                ref = id;
                std::cout << "\t Entrer le Libelle de l'Article :\t";
                std::cin >>nomArticle;
                std::cout << "\t Entrer le prix unitaire de l'article :\t";
                std::cin >>prixArticle;
                std::cout << "\t Entrer la quantite de l'Article :\t";
                std::cin >> quantite;
                std::cout << "\t Entrer le seuil :\t";
                std::cin >> seuil;

                gestionnaireArticle.mettre_a_jour(ref, nomArticle.c_str(),prixArticle,quantite,seuil);
            }else{
                std::cout << "\n";            
                std::cout << "\t##------------------------------------------------------------------------------------------##\n";    
                std::cout << "\t##                     CET ARTICLE N'EXISTE PAS DANS NOTRE BASE DE DONNEES                  ##\n";
                std::cout << "\t##------------------------------------------------------------------------------------------##\n";    
            }
        break;
        case '2': // recherche via nom
            std::cout <<"\n";            
            std::cout <<"\t Entrer le NOM \t";
            std::cin >> nomR;
            produit = gestionnaireArticle.chercher(nomR.c_str());
            if (produit){
                std::cout <<"\n";
                std::cout << "\t##------------------------------------------------------------------------------------------------------##\n";            
                std::cout << "\t##\t     "<< produit->get().get_reference() <<"     \t"<< produit->get().get_libelle() <<"     \t\t"<< produit->get().get_prix() <<"     \t\t"<<produit->get().get_quantite() <<"     \t\t"<<produit->get().get_seuil() <<"\t##\n";                
                std::cout << "\t##------------------------------------------------------------------------------------------------------##\n"; 

                std::cout <<"\n";
                ref = produit->get().get_reference();
                std::cout << "\t Entrer le Libelle de l'Article :\t";
                std::cin >>nomArticle;
                std::cout << "\t Entrer le prix unitaire de l'article :\t";
                std::cin >>prixArticle;
                std::cout << "\t Entrer la quantite de l'Article :\t";
                std::cin >> quantite;
                std::cout << "\t Entrer le seuil :\t";
                std::cin >> seuil;

                gestionnaireArticle.mettre_a_jour(ref, nomArticle.c_str(),prixArticle,quantite,seuil);       
            }else{
                std::cout <<"\n";            
                std::cout << "\t##------------------------------------------------------------------------------------------##\n";    
                std::cout << "\t##                      CET ARTICLE N'EXISTE PAS DANS NOTRE BASE DE DONNEES                 ##\n";
                std::cout << "\t##------------------------------------------------------------------------------------------##\n";    
            }
        break;
    };
    do{
        std::cout <<"\t Voulez-vous faire une nouvelle modification? \n";
        std::cout <<"\t 1 - pour OUI \n";
        std::cout <<"\t 0 - pour NON \n";
        std::cin >> choixUtilisateur;
    } while (choixUtilisateur.c_str()[0] != '0' && choixUtilisateur.c_str()[0] != '1');

    switch (choixUtilisateur.c_str()[0]){
        case '0':
            system("clear");
            menu_general_article();
            break;
        case '1': 
            system("clear");
            interface_modif_article();
            break;
    }

};//TERMINÉ

// modification client
void interface_modif_client(){
    // differentes variables a utiliser dans notre fonction
    std::string nom;
    std::string prenom;
    std::string date;
    std::string sexe;
    std::string choixUtilisateur;
    int id;
    typeId identifiant;
    std::string nomR;
    std::string ch;
    Cellule<Client::Base> * personne ;

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

        
    do{ 
        std::cout <<"\n";
        std::cout <<"\t Voulez-vous faire la recherche du CLIENT a modifier via son ID ou via son NOM? \n";
        std::cout <<"\t\t 1 - pour ID \n";
        std::cout <<"\t\t 2 - pour NOM \n\n";
        std::cout <<"\t Votre choix: \t";
        std::cin >> choixUtilisateur;
    } while (choixUtilisateur.c_str()[0] != '1' && choixUtilisateur.c_str()[0] != '2');

    switch (choixUtilisateur.c_str()[0]){
        case '1': // recherche via id
            std::cout <<"\n";            
            std::cout <<"\t Entrer l'ID \t";
            std::cin >> id;
            personne = gestionnaireClient.chercher_client(id);
            if (personne){
                std::cout <<"\n";
                std::cout << "\t##------------------------------------------------------------------------------------------------------##\n";            
                std::cout << "\t##\t     "<< personne->get().get_numero() <<"     \t"<< personne->get().get_nom() <<"     \t\t"<< personne->get().get_prenom() <<"     \t\t"<< personne->get().get_date() <<"     \t\t"<< personne->get().get_sexe() <<"\t##\n";                
                std::cout << "\t##------------------------------------------------------------------------------------------------------##\n"; 

                std::cout <<"\n";
                identifiant = id;
                std::cout << "\t Entrer NOM Client :\t";
                std::cin >>nom;
                std::cout << "\t Entrer PRENOM Client :\t";
                std::cin >> prenom;
                std::cout << "\t Entrer DATE NAISSANCE Client(JJ/MM/AAAA) :\t";
                std::cin >> date;
                std::cout << "\t Entrer SEXE Client(M/F) :\t";
                std::cin >> sexe;

                gestionnaireClient.mettre_a_jour_client(identifiant, nom.c_str(),prenom.c_str(),date.c_str(),sexe.c_str());
            }else{
                std::cout << "\n";            
                std::cout << "\t##------------------------------------------------------------------------------------------##\n";    
                std::cout << "\t##                     CE CLIENT N'EXISTE PAS DANS NOTRE BASE DE DONNEES                    ##\n";
                std::cout << "\t##------------------------------------------------------------------------------------------##\n";    
            }
        break;
        case '2': // recherche via nom
            std::cout <<"\n";            
            std::cout <<"\t Entrer le NOM \t";
            std::cin >> nomR;
            personne = gestionnaireClient.chercher_client(nomR.c_str());
            if (personne){
                std::cout <<"\n";
                std::cout << "\t##------------------------------------------------------------------------------------------------------##\n";            
                std::cout << "\t##\t     "<< personne->get().get_numero() <<"     \t"<< personne->get().get_nom() <<"     \t\t"<< personne->get().get_prenom() <<"     \t\t"<< personne->get().get_date() <<"     \t\t"<< personne->get().get_sexe() <<"\t##\n";                    
                std::cout << "\t##------------------------------------------------------------------------------------------------------##\n"; 

                std::cout <<"\n";
                identifiant = personne->get().get_numero();
                std::cout << "\t Entrer NOM Client :\t";
                std::cin >>nom;
                std::cout << "\t Entrer PRENOM Client :\t";
                std::cin >> prenom;
                std::cout << "\t Entrer DATE NAISSANCE Client(JJ/MM/AAAA) :\t";
                std::cin >> date;
                std::cout << "\t Entrer SEXE Client(M/F) :\t";
                std::cin >> sexe;

                gestionnaireClient.mettre_a_jour_client(identifiant, nom.c_str(),prenom.c_str(),date.c_str(),sexe.c_str());               
            }else{
                std::cout <<"\n";            
                std::cout << "\t##------------------------------------------------------------------------------------------##\n";    
                std::cout << "\t##                      CE CLIENT N'EXISTE PAS DANS NOTRE BASE DE DONNEES                   ##\n";
                std::cout << "\t##------------------------------------------------------------------------------------------##\n";    
            }
        break;
    };

    do{
        std::cout <<"\n";            
        std::cout <<"\t Voulez-vous refaire une nouvelle Modification? \n";
        std::cout <<"\t\t     1 - pour OUI \n";
        std::cout <<"\t\t     0 - pour NON \n\n";
        std::cout <<"\t Votre choix: \t";
        std::cin >> ch;
    } while (ch.c_str()[0] != '0' && ch.c_str()[0] != '1');

    switch (ch.c_str()[0]){
        case '0':
            system("clear");
            menu_general_client();
            break;
        case '1': 
            system("clear");
            interface_modif_client();
            break;
    } 
};// Fonction termine

void interface_modif_commande(){
    // differentes variables a utiliser dans notre fonction
    typeId idClient;
    typeId idArticle;
    typeId ref;
    std::string choixUtilisateur;
    int id;
    std::string nomC;
    typeId idCom;
    Cellule<Client::Base> * personne ;       
    std::string choixU;
    std::string nomA;
    Cellule<Article::Base> * produit;
    Cellule<Commande::Base> * com;
    // differentes variables a utiliser dans notre fonction
    std::string nomArticle;
    std::string nomR;
    unsigned long quantite;
    std::string ch;  
    const char * message = "Effacer";
    std::string reponce1;
    std::string reponce2;
    std::string reponce3;

    const char * etat1 = "Livree";
    const char * etat2 = "En Cour...";
    bool s;

    // petit menu de presentation
    std::cout << "\t##########################################################################################\n";
    std::cout << "\t##-_-_-                                                                            -_-_-##\n";
    std::cout << "\t##               BIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL                ##\n";
    std::cout << "\t##                ----------------------------------------------------                  ##\n";
    std::cout << "\t##                        ---------------------------------                             ##\n";
    std::cout << "\t##                       |   MODIFICATION D'UNE COMMANDE   |                            ##\n";
    std::cout << "\t##                        ---------------------------------                             ##\n";
    std::cout << "\t##                                                                                      ##\n";
    std::cout << "\t##                    Veuillez suivre à la lettre les consigne !                        ##\n";
    std::cout << "\t##                      -------------------------------------                           ##\n";
    std::cout << "\t##-_-_-                                                                            -_-_-##\n";
    std::cout << "\t##                                                                                      ##\n";
    std::cout << "\t##         ----------------------------------------------------------------             ##\n";

        std::cout <<"\n";
        std::cout <<"\t Entrer l'ID de la Commande dont vous voulez apporter des modification:\t";
        std::cin >> id;

        ref = id;

        com = gestionnaireCommande.chercher(ref);
            if (com){
                idClient = com->get().ref_client();
                idArticle = com->get().ref_article();
                personne = gestionnaireClient.chercher_client(idClient);
                reponce1.append((personne)? personne->get().get_nom():message);
                produit = gestionnaireArticle.chercher(idArticle);
                reponce2.append((produit)? produit->get().get_libelle().c_str():message);
                s = com->get().est_livrer();
                reponce3 = (s)? etat1:etat2;

                std::cout <<"\n";
                std::cout << "\t##---------------------------------------------------------------------------------------##\n";            
                std::cout << "\t##\t     "<< com->get().ref() <<"   \t"<< reponce1 <<"   \t "<< reponce3 <<"     \t"<< reponce2<<"    \t"<<com->get().nombre() <<"\n";
                std::cout << "\t##---------------------------------------------------------------------------------------##\n\n";  
                idCom =  com->get().ref(); // recuperation de l'ID du produit    
            a2:     std::cout << "\n";
                    std::cout << "\t Entrer le Nom du client:\t";  
                    std::cin >>nomC ;
                    personne = gestionnaireClient.chercher_client(nomC.c_str());
                    if (personne){
                        idClient =  personne->get().get_numero(); // recuperation de l'ID du produit
            a1:         std::cout << "\n";
                        std::cout << "\t Entrer le Nom de l'Article:\t";  
                        std::cin >>nomA ;
                        produit = gestionnaireArticle.chercher(nomA.c_str());
                        if (produit)
                        {
                            idArticle = produit->get().get_reference();// recuperation de l'id du produit 
                            std::cout << "\n";
                            std::cout << "\t Entrer la Quantite de l'Article a commander:\t";  
                            std::cin >> quantite;   
                        }else{
                            std::cout << "\n";            
                            std::cout << "\t##------------------------------------------------------------------------------------------##\n";    
                            std::cout << "\t##                   CET ARTICLE N'EXISTE PAS DANS NOTRE BASE DE DONNEES                    ##\n";
                            std::cout << "\t##------------------------------------------------------------------------------------------##\n"; 
                            do{
                                std::cout << " \n ";
                                std::cout <<"\t Voulez-vous ANNULER les modification ou CHANGER l'article de la commande? \n";
                                std::cout <<"\t 1 - pour CHANGER \n";
                                std::cout <<"\t 0 - pour ANNULER \n";
                                std::cout <<"\t Votre choix: \t";
                                std::cin >> choixUtilisateur;
                            } while (choixUtilisateur.c_str()[0] != '0' && choixUtilisateur.c_str()[0] != '1');

                            switch (choixUtilisateur.c_str()[0]){
                                case '0':
                                    system("clear");
                                    menu_general_commande();
                                    break;
                                case '1': 
                                    goto a1;
                                    break;
                            }    
                        }
                    }else{
                            std::cout << "\n";            
                            std::cout << "\t##------------------------------------------------------------------------------------------##\n";    
                            std::cout << "\t##                   CE CLIENT N'EXISTE PAS DANS NOTRE BASE DE DONNEES                    ##\n";
                            std::cout << "\t##------------------------------------------------------------------------------------------##\n"; 
                            do{
                                std::cout << " \n ";
                                std::cout <<"\t Voulez-vous ANNULER les modification ou CHANGER le client de la commande? \n";
                                std::cout <<"\t 1 - pour CHANGER \n";
                                std::cout <<"\t 0 - pour ANNULER \n";
                                std::cout <<"\t Votre choix: \t";
                                std::cin >> choixUtilisateur;
                            } while (choixUtilisateur.c_str()[0] != '0' && choixUtilisateur.c_str()[0] != '1');

                            switch (choixUtilisateur.c_str()[0]){
                                case '0':
                                    system("clear");
                                    menu_general_commande();
                                    break;
                                case '1': 
                                    goto a2;
                                    break;
                            }
                        }

                        gestionnaireCommande.modifier(idCom,idClient,idArticle,quantite,s); 
                    
                }else
                {
                    std::cout << "\n";            
                    std::cout << "\t##------------------------------------------------------------------------------------------##\n";    
                    std::cout << "\t##                   CETTE COMMANDE N'EXISTE PAS DANS NOTRE BASE DE DONNEES                 ##\n";
                    std::cout << "\t##------------------------------------------------------------------------------------------##\n";
                }
            
    do{
        std::cout << " \n ";
        std::cout <<"\t Voulez-vous faire une nouvelle recherche? \n";
        std::cout <<"\t 1 - pour OUI \n";
        std::cout <<"\t 0 - pour NON \n";
        std::cout <<"\t Votre choix: \t";
        std::cin >> choixUtilisateur;
    } while (choixUtilisateur.c_str()[0] != '0' && choixUtilisateur.c_str()[0] != '1');

    switch (choixUtilisateur.c_str()[0]){
        case '0':
            system("clear");
            menu_general_commande();
            break;
        case '1': 
            system("clear");
            interface_modif_commande();
            break;
    }

};//TERMINÉ


// debut des fonctions associer au second menu
void interface_meilleur_client(){
    // differentes variables a utiliser dans notre fonction
    std::string ch;
    Cellule<Article::Base> * produit;
    Cellule<Client::Base> * client;
    typeId idArticle;
    typeId idClient;
    const char * message1 = "CLIENT SUPPRIMER";
    const char * message2 = "PAS DE MEILLEUR CLIENT";

    // petit menu de presentation
    std::cout << "\t##############################################################################################################\n";    
    std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
    std::cout << "\t##                        BIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL                           ##\n";
    std::cout << "\t##                           ------------------------------------------------                               ##\n";
    std::cout << "\t##                           ------------------------------------------------                               ##\n";
    std::cout << "\t##                          |                MEILLEURS CLIENTS               |                              ##\n";
    std::cout << "\t##                           ------------------------------------------------                               ##\n";
    std::cout << "\t##                                                                                                          ##\n";
    std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
    std::cout << "\t##         ---------------------------------------------------------------------------------------          ##\n";


    produit = gestionnaireArticle.recup_tete();
    std::cout << "\t##                Nom de l'Article                      |            Nom du meilleur Client                 ##\n";
    std::cout << "\t##----------------------------------------------------------------------------------------------------------##\n";            
    std::cout << "\t##----------------------------------------------------------------------------------------------------------##\n";
        while (produit != gestionnaireArticle.recup_sentinelle())
        {   idArticle = produit->get().get_reference() ;
            std::cout <<"while\n";
            idClient = meilleur_client_de(idArticle);
            std::cout << idClient<< "\n";
            if (idClient){
                client = gestionnaireClient.chercher_client(idClient);
                if (client){ // Meilleur client existant et dans liste de client
                    std::cout << "\t##\t     "<<"      \t"<< produit->get().get_libelle() <<"   \t\t"<< client->get().get_nom() <<"\n";                        
                }else{ // Meilleur client existant mais supprimer de la liste des client
                    std::cout << "\t##\t     "<<"      \t"<< produit->get().get_libelle() <<"   \t\t"<< message1 <<"\n";
                }     
            }else{ // pas de meilleur client
                std::cout << "\t##\t     "<<"      \t"<< produit->get().get_libelle() <<"   \t\t"<< message2 <<"\n";                
            }
    std::cout << "\t##---------------------------------------------------------------------------------------------------------##\n";            
        produit = produit->get_next();
        }  

    do{
        std::cout <<"\t Tapez: \n";
        std::cout <<"\t      1 - pour RETOUR AU MENU \n";
        std::cout <<"\t      0 - pour RETOUR AU MENU PRINCIPAL \n\n";
        std::cout <<"\t Entrer votre choix: \t";
        std::cin >> ch;
    } while (ch.c_str()[0] != '0' && ch.c_str()[0] != '1');

    switch (ch.c_str()[0]){
        case '0':
            system("clear");
            acceuil();
            break;
        case '1':
            system("clear");
            autre_fonction();
            break;
    }   
};

void interface_capital(){
    // differentes variables a utiliser dans notre fonction
    std::string ch;
    long double capital;

    capital = gestionnaireArticle.capital();
    // petit menu de presentation
    std::cout << "\t##############################################################################################################\n";       
    std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
    std::cout << "\t##                        BIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL                           ##\n";
    std::cout << "\t##                           ------------------------------------------------                               ##\n";
    std::cout << "\t##                           ------------------------------------------------                               ##\n";
    std::cout << "\t##                          |                     CAPITAL                    |                              ##\n";
    std::cout << "\t##                            -----------------------------------------------                               ##\n";
    std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
    std::cout << "\t##      ----------------------------------------------------------------------------------------------      ##\n";  
    std::cout << "\t                           " << capital <<" Frs CFA\n";    
    std::cout << "\t##      ----------------------------------------------------------------------------------------------      ##\n";
    std::cout << "\t##                                                                                                          ##\n";    
    std::cout << "\t##############################################################################################################\n";    

    do{
        std::cout <<"\t Tapez: \n";
        std::cout <<"\t      1 - pour RETOUR AU MENU \n";
        std::cout <<"\t      0 - pour RETOUR AU MENU PRINCIPAL \n\n";
        std::cout <<"\t Entrer votre choix: \t";
        std::cin >> ch;
    } while (ch.c_str()[0] != '0' && ch.c_str()[0] != '1');

    switch (ch.c_str()[0]){
        case '0':
            system("clear");
            acceuil();
            break;
        case '1':
            system("clear");
            autre_fonction();
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
            acceuil();
            break;
        case '1':
            system("clear");
            autre_fonction();
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

typeId convertion(char * chaine)
{
    unsigned i = 0;
    typeId nombre = 0;
   
    while(chaine[i] != '\0'){
        if( chaine[i] > 47 && chaine[i] <  59){
            
            nombre =  nombre * 10*i +  chaine[i] - 48;
            
        }else{
            return ERROR_CODE;
        }
        i++;
    }
    return nombre ;
}