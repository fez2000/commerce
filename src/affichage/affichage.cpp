#include "affichage.h"


/*
extern Client::Client  gestionClient;
extern Article::Article  gestionArticle;
extern Livraison::Livraison gestionLivraison;
extern Commande::Commande gestionCommande;
std::string choixUtilisateur;





void acceuil(){
    
    int i = charger("fr");
    
    std::string choixValide("012345");
    // differentes variables a utiliser dans notre fonction
    
     do{
          std::cout << get("menugestion");
          std::cin >> choixUtilisateur;
          system("clear");

     } while (choix_non_valide(choixUtilisateur,choixValide));


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
               std::cout << get("choixIndisponible") ;
          break;
     };
}



void menu_general_client(){
    
    std::string choixValide("012345");
    do
    {
    
        std::cout << get("menugeneralcleint");
        std::cin >> choixUtilisateur;
        system("clear");
    
    }while(choix_non_valide(choixUtilisateur,choixValide));

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
    
    std::string choixValide("012345");
    do
    {
        std::cout << get("menugeneralarticle");
        std::cin >> choixUtilisateur;
        system("clear");
    }
    while(choix_non_valide(choixUtilisateur,choixValide));

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
    
    std::string choixValide("012345");
    do
    {
        std::cout << get("menugeneralcommande");
        std::cin >> choixUtilisateur;
        system("clear");
    }
    while(choix_non_valide(choixUtilisateur,choixValide));

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
    //supprimer_choix();
    std::string choixValide("012345");
    do
    {
        std::cout << get("menugenerallivraison");
        std::cin >> choixUtilisateur;
        system("clear");
    }
    while(choix_non_valide(choixUtilisateur,choixValide));


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


void interface_creation_client(){
    std::string choixValide("01");    
    // differentes variables a utiliser dans notre fonction
    std::string nom;
    std::string prenom;
    std::string date;
    std::string sexe;

    // petit menu de presentation
    std::cout << get("creationclient");
    // recuperation des informations du nouveau client
    std::cout << get("nomclient");
    std::cin >>nom;
    std::cout << get("prenomclient");
    std::cin >> prenom;
    std::cout << get("dateNaisClient");
    std::cin >> date;
    std::cout << get("sexeClient");
    std::cin >> sexe;
    // Enregistrement de notre client
    gestionClient.creer_client(nom.c_str(), prenom.c_str(), date.c_str(), sexe.c_str());
    //gestion des erreurs
    do{

        std::cout << get("continuerSauvegarde");
        std::cin >> choixUtilisateur;
    } while (choix_non_valide(choixUtilisateur,choixValide ));

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
    //supprimer_choix();
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
        gestionClient.chercher_client(id);
            break;
        case '2': // recherche via nom
            std::cout <<"\t Entrer le NOM \t";
            std::cin >> nomR;
            gestionClient.chercher_client(nomR.c_str());
            break;
    };

        std::string ch;
    do{
        std::cout <<"\t Voulez-vous refaire une recherche? \n";
        std::cout <<"\t 1 - pour OUI \n";
        std::cout <<"\t 0 - pour Nom \n";
        std::cin >> choixUtilisateur;
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
*/