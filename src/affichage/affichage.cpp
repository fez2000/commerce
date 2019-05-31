#include "affichage.h"
// variables globales
extern Article::Article  gestionnaireArticle;
extern Livraison::Livraison gestionnaireLivraison;
extern Commande::Commande gestionnaireCommande;
extern Client::Client gestionnaireClient;
std::string choixUtilisateur;
/*
    Acceuil
*/
void acceuil(){

    // differentes variables a utiliser dans notre fonction
    int i = charger("fr");//position a changer
    std::string choixValide("012345");
    do{
        
        // petit menu de presentation
        std::cout << "\t\033[36;1m##############################################################################################################\n";            
        std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
        std::cout << "\t##\033[36;0m                           \033[33;1mBIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE\033[33;0m                           \033[36;1m##\n";
        std::cout << "\t##                                                                                                          ##\n";
        std::cout << "\t##                          ---------------------------------------------------                             ##\n";
        std::cout << "\t##                          ---------------------------------------------------                             ##\n";
        std::cout << "\t##\033[36;0m                                         \033[33;1m%%%     %%%     %%%\033[33;0m                                              \033[36;1m##\n";
        std::cout << "\t##\033[36;0m                                          \033[33;1m%%%   %%%      %%%\033[33;0m                                              \033[36;1m##\n";
        std::cout << "\t##\033[36;0m                                            \033[33;1m%%%%%        %%%\033[33;0m                                              \033[36;1m##\n";
        std::cout << "\t##\033[36;0m                                            \033[33;1m%%%%%        %%%\033[33;0m                                              \033[36;1m##\n";
        std::cout << "\t##\033[36;0m                                          \033[33;1m%%%   %%%      %%%%%%%%%%\033[33;0m                                       \033[36;1m##\n";
        std::cout << "\t##\033[36;0m                                         \033[33;1m%%%     %%%     %%%%%%%%%%\033[33;0m                                       \033[36;1m##\n";
        std::cout << "\t##                          ---------------------------------------------------                             ##\n";
        std::cout << "\t##                          ---------------------------------------------------                             ##\n";
        std::cout << "\t##\033[36;0m                              \033[32;1mVeuillez suivre à la lettre les consigne !\033[32;0m                                  \033[36;1m##\n";
        std::cout << "\t##                          ---------------------------------------------------                             ##\n";
        std::cout << "\t##\033[36;0m      \033[33;1mTapez:\033[33;0m                                                                                              \033[36;1m##\n";
        std::cout << "\t##\033[36;0m          \033[33;1m1- Pour GESTIONS CLIENTS                         2- Pour GESTIONS ARTICLES\033[33;0m                      \033[36;1m##\n";
        std::cout << "\t##\033[36;0m          \033[33;1m3- Pour GESTIONS COMMANDES                       4- Pour GESTIONS LIVRAISONS\033[33;0m                    \033[36;1m##\n";
        std::cout << "\t##\033[36;0m          \033[33;1m5- Pour AUTRES FONCTIONS                         0- QUITTER\033[33;0m                                     \033[36;1m##\n";
        std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
        std::cout << "\t##     -----------------------------------------------------------------------------------------------      ##\n";
        std::cout << "\t##                                                                                                          ##\n";

        std::cout << "\t##\033[36;0m \033[33;1mEntrer votre choix:\033[33;0m \t";
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
        case '2': // gestion article
            menu_general_article();
            break;
        case '3': // gestion commande
            menu_general_commande();
            break;
        case '4': // gestion livraison
            menu_general_livraison();
            break;
        case '5': // a propos
            autre_fonction();
            break;
    };
}

void autre_fonction(){
    // differentes variables a utiliser dans notre fonction
    std::string choixUtilisateur;
    std::string choixValide("0123456789");
    do{

        // petit menu de presentation
                // petit menu de presentation
        std::cout << "\t\033[36;1m##############################################################################################################\n";    
        std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
        std::cout << "\t##\033[36;0m                          \033[33;1mBIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE\033[33;0m                            \033[36;1m##\n";
        std::cout << "\t##                                                                                                          ##\n";
        std::cout << "\t##                          ---------------------------------------------------                             ##\n";
        std::cout << "\t##                          ---------------------------------------------------                             ##\n";
        std::cout << "\t##\033[36;0m                                         \033[33;1m%%%     %%%     %%%\033[33;0m                                              \033[36;1m##\n";
        std::cout << "\t##\033[36;0m                                          \033[33;1m%%%   %%%      %%%\033[33;0m                                              \033[36;1m##\n";
        std::cout << "\t##\033[36;0m                                            \033[33;1m%%%%%        %%%\033[33;0m                                              \033[36;1m##\n";
        std::cout << "\t##\033[36;0m                                            \033[33;1m%%%%%        %%%\033[33;0m                                              \033[36;1m##\n";
        std::cout << "\t##\033[36;0m                                          \033[33;1m%%%   %%%      %%%%%%%%%%\033[33;0m                                       \033[36;1m##\n";
        std::cout << "\t##\033[36;0m                                         \033[33;1m%%%     %%%     %%%%%%%%%%\033[33;0m                                       \033[36;1m##\n";
        std::cout << "\t##                          ---------------------------------------------------                             ##\n";
        std::cout << "\t##                          ---------------------------------------------------                             ##\n";
        std::cout << "\t##\033[36;0m                              \033[32;1mVeuillez suivre à la lettre les consigne !\033[32;0m                                  \033[36;1m##\n";
        std::cout << "\t##                          ---------------------------------------------------                             ##\n";
        std::cout << "\t##\033[36;0m      \033[33;1mTapez:\033[33;0m                                                                                              \033[36;1m##\n";
        std::cout << "\t##\033[36;0m              \033[33;1m1 - Pour Liste des articles achetes par un client\033[33;0m                                           \033[36;1m##\n";
        std::cout << "\t##\033[36;0m              \033[33;1m2 - Pour Liste des Clients d'un Article\033[33;0m                                                     \033[36;1m##\n";
        std::cout << "\t##\033[36;0m              \033[33;1m3 - Pour Liste des Commandes en Cours d'un Client\033[33;0m                                           \033[36;1m##\n";
        std::cout << "\t##\033[36;0m              \033[33;1m4 - Pour les Statistiques sur les Ventes d'un Article\033[33;0m                                       \033[36;1m##\n";
        std::cout << "\t##\033[36;0m              \033[33;1m5 - Pour Liste des articles avec Prix Unitaire\033[33;0m                                              \033[36;1m##\n";
        std::cout << "\t##\033[36;0m              \033[33;1m6 - Pour Liste des Articles a Ravitailler\033[33;0m                                                   \033[36;1m##\n";
        std::cout << "\t##\033[36;0m              \033[33;1m7 - Pour Capital du SuperMarche XL\033[33;0m                                                          \033[36;1m##\n";
        std::cout << "\t##\033[36;0m              \033[33;1m8 - Pour Meilleur Client de XL\033[33;0m                                                              \033[36;1m##\n";
        std::cout << "\t##                                                                                                          ##\n";
        std::cout << "\t##\033[36;0m              \033[33;1m9 - Pour RETOUR                          0 - QUITTER LE PROGRAMME\033[33;0m                           \033[36;1m##\n";
        std::cout << "\t##                                                                                                          ##\n";
        std::cout << "\t##     ---------------------------------------------------------------------------------------------        ##\n";
        std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
        std::cout << "\t##                                                                                                          ##\n";

        std::cout << "\t##\033[36;0m \033[33;1mEntrer votre choix:\033[33;0m \t";
        std::cin >> choixUtilisateur;
        system("clear");

    } while (choix_non_valide(choixUtilisateur,choixValide));


    switch (choixUtilisateur.c_str()[0]){
        case '0':
            system("exit");
            break;
        case '1': // Liste des articles achetes par un client
              system("clear");
              interface_article_achete_par_un_client(); 
            break;
        case '2': // Liste des Clients d'un Article
                system("clear");
                interface_liste_client_article();
               break;
          case '3': // Liste des Commandes en Cours d'un Client
            system("clear");
            interface_commande_client();  
               break;
          case '4': // les Statistiques sur les Ventes d'un Article
            system("clear");
            interface_statistique();
               break;
          case '5': // Liste des articles avec Prix Unitaire
            system("clear");
            interface_article_prix_unitaire();
               break;
          case '6': // Liste des Articles a Ravitailler
            system("clear");
            interface_quantite_a_ravitailler(); 

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
    std::string choixValide("012345");
    do
    {
        std::cout << "\t\033[36;1m##############################################################################################################\n";                      
        std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
        std::cout << "\t##\033[36;0m                           \033[33;1mBIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL\033[33;0m                        \033[36;1m##\n";
        std::cout << "\t##                             --------------------------------------------------                           ##\n";
        std::cout << "\t##                                                                                                          ##\n";
        std::cout << "\t##                             --------------------------------------------------                           ##\n";
        std::cout << "\t##                            |\033[36;0m               \033[32;1mGESTION DES CLIENTS\033[32;0m                \033[36;1m|                          ##\n";
        std::cout << "\t##                             --------------------------------------------------                           ##\n";
        std::cout << "\t##                                                                                                          ##\n";
        std::cout << "\t##\033[36;0m                                \033[32;1mVeuillez suivre à la lettre les consigne !\033[32;0m                                \033[36;1m##\n";
        std::cout << "\t##                                  ------------------------------------                                    ##\n";
        std::cout << "\t##-_-_-  \033[36;0m\033[33;1mAppuyez sur:\033[33;0m                                                                                  \033[36;1m-_-_-##\n";
        std::cout << "\t##                                                                                                          ##\n";
        std::cout << "\t##\033[36;0m     \033[33;1m- 1 pour Enregistrer un nouveau client                  - 3 pour Rechercher un client\033[33;0m                \033[36;1m##\n";
        std::cout << "\t##                                                                                                          ##\n";
        std::cout << "\t##\033[36;0m     \033[33;1m- 2 pour la Modification d'un client                    - 4 pour Supprimer un client\033[33;0m                 \033[36;1m##\n";
        std::cout << "\t##                                                                                                          ##\n";
        std::cout << "\t##\033[36;0m     \033[33;1m- 5 pour afficher les CLIENTS                           - 0 pour Menu principal\033[33;0m                      \033[36;1m##\n";
        std::cout << "\t##                                                                                                          ##\n";
        std::cout << "\t##      --------------------------------------------------------------------------------------------        ##\n";

        std::cout << "\t##\033[36;0m \033[33;1mEntrer votre choix:\033[33;0m \t";
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
    std::string choixValide("012345");
    do
    {
        std::cout << "\033[36;1m\t##############################################################################################################\n";                      
        std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
        std::cout << "\t##\033[36;0m                         \033[33;1mBIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL\033[33;0m                          \033[36;1m##\n";
        std::cout << "\t##                          ---------------------------------------------------                             ##\n";
        std::cout << "\t##                                                                                                          ##\n";
        std::cout << "\t##                          --------------------------------------------------                              ##\n";
        std::cout << "\t##                         |\033[36;0m               \033[32;1mGESTION DES ARTICLES\033[32;0m                \033[36;1m|                            ##\n";
        std::cout << "\t##                          --------------------------------------------------                              ##\n";
        std::cout << "\t##                                                                                                          ##\n";
        std::cout << "\t##\033[36;0m                               \033[32;1mVeuillez suivre à la lettre les consigne !\033[32;0m                                 \033[36;1m##\n";
        std::cout << "\t##                                 --------------------------------------                                   ##\n";
        std::cout << "\t##-_-_-\033[36;0m  \033[33;1mAppuyez sur:\033[33;0m                                                                                  \033[36;1m-_-_-##\n";
        std::cout << "\t##                                                                                                          ##\n";
        std::cout << "\t##\033[36;0m     \033[33;1m- 1 pour Enregistrer un nouveau ARTICLE             - 3 pour Rechercher un ARTICLE\033[33;0m                   \033[36;1m##\n";
        std::cout << "\t##                                                                                                          ##\n";
        std::cout << "\t##\033[36;0m     \033[33;1m- 2 pour la Modification d'un ARTICLE               - 4 pour Supprimer un ARTICLE\033[33;0m                    \033[36;1m##\n";
        std::cout << "\t##                                                                                                          ##\n";
        std::cout << "\t##\033[36;0m     \033[33;1m- 5 pour la liste des ARTICLES                      - 0 pour Menu principal\033[33;0sm                         \033[36;1m##\n";
        std::cout << "\t##                                                                                                          ##\n";
        std::cout << "\t##      ----------------------------------------------------------------------------------------------      ##\n";

        std::cout << "\t##\033[36;0m \033[33;1mEntrer votre choix: \033[33;0m\t";
        std::cin >> choixUtilisateur;
        system("clear");
    }
    while(choix_non_valide(choixUtilisateur,choixValide));

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
    std::string choixValide("012345");
    do
    {
    
        std::cout << "\033[36;1m\t##############################################################################################################\n";                      
        std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
        std::cout << "\t##\033[36;0m                         \033[33;1mBIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL\033[33;0m                          \033[36;1m##\n";
        std::cout << "\t##                          ---------------------------------------------------                             ##\n";
        std::cout << "\t##                                                                                                          ##\n";
        std::cout << "\t##                          --------------------------------------------------                              ##\n";
        std::cout << "\t##                         |\033[36;0m               \033[32;1mGESTION DES COMMADES\033[32;0m                \033[36;1m|                            ##\n";
        std::cout << "\t##                          --------------------------------------------------                              ##\n";
        std::cout << "\t##                                                                                                          ##\n";
        std::cout << "\t##\033[36;0m                               \033[32;1mVeuillez suivre à la lettre les consigne !\033[32;0m                                 \033[36;1m##\n";
        std::cout << "\t##                                 --------------------------------------                                   ##\n";
        std::cout << "\t##-_-_-\033[36;0m  \033[33;1mAppuyez sur:\033[33;0m                                                                                  \033[36;1m-_-_-##\n";
        std::cout << "\t##                                                                                                          ##\n";
        std::cout << "\t##\033[36;0m          \033[33;1m- 1 ENREGISTRE COMMANDE                     - 3 RECHERCHER COMMANDE\033[33;0m                             \033[36;1m##\n";
        std::cout << "\t##                                                                                                          ##\n";
        std::cout << "\t##\033[36;0m          \033[33;1m- 2 MODIFICATION COMMANDE                   - 4 ANNULER COMMANDE\033[33;0m                                \033[36;1m##\n";
        std::cout << "\t##                                                                                                          ##\n";
        std::cout << "\t##\033[36;0m          \033[33;1m- 5 LISTE COMMANDES                         - 0 MENU PRINCIPAL\033[33;0m                                  \033[36;1m##\n";
        std::cout << "\t##                                                                                                          ##\n";
        std::cout << "\t##         ------------------------------------------------------------------------------------             ##\n";

        std::cout << "\t##\033[36;0m \033[33;1mEntrer votre choix:\033[33;0m \t";
        std::cin >> choixUtilisateur;
        system("clear");
    }
    while(choix_non_valide(choixUtilisateur,choixValide));

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
    std::string choixValide("012345");
    do
    {
    
        
        std::cout << "\033[36;1m\t##############################################################################################################\n";                      
        std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
        std::cout << "\t##\033[36;0m                         \033[33;1mBIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL\033[33;0m                          \033[36;1m##\n";
        std::cout << "\t##                          ---------------------------------------------------                             ##\n";
        std::cout << "\t##                                                                                                          ##\n";
        std::cout << "\t##                          --------------------------------------------------                              ##\n";
        std::cout << "\t##                         |\033[36;0m             \033[32;1mGESTION DES LIVRAISONS\033[32;0m                \033[36;1m|                            ##\n";
        std::cout << "\t##                          --------------------------------------------------                              ##\n";
        std::cout << "\t##                                                                                                          ##\n";
        std::cout << "\t##\033[36;0m                               \033[32;1mVeuillez suivre à la lettre les consigne !\033[32;0m                                 \033[36;1m##\n";
        std::cout << "\t##                                 --------------------------------------                                   ##\n";
        std::cout << "\t##-_-_-\033[36;0m  \033[33;1mAppuyez sur:\033[33;0m                                                                                  \033[36;1m-_-_-##\n";
        std::cout << "\t##                                                                                                          ##\n";
        std::cout << "\t##\033[36;0m     \033[33;1m- 1 : ENREGISTRER LIVRAISON                   - 3 : RECHERCHER LIVRAISON\033[33;0m                             \033[36;1m##\n";
        std::cout << "\t##                                                                                                          ##\n";
        std::cout << "\t##\033[36;0m     \033[33;1m- 2 : MODIFIER LIVRAISON                      - 4 : SUPPRESSION LIVRAISON\033[33;0m                            \033[36;1m##\n";
        std::cout << "\t##                                                                                                          ##\n";
        std::cout << "\t##\033[36;0m     \033[33;1m- 5 : LISTE DES LIVRAISONS                    - 0 : MENU PRINCIPAL\033[33;0m                                   \033[36;1m##\n";
        std::cout << "\t##                                                                                                          ##\n";
        std::cout << "\t##         ------------------------------------------------------------------------------------S             ##\n";

        std::cout << "\t##\033[36;0m \033[33;1mEntrer votre choix:\033[33;0m \t";
        std::cin >> choixUtilisateur;
        system("clear");
    }
    while(choix_non_valide(choixUtilisateur,choixValide));


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
            system("clear");
            interface_recherche_livraison();
            break;
        case '4': //fonction de supression d'une LIVRAISON;
            system("clear");
            interface_suppression_livraison();
            break;
        case '5': // Affichages des differentes LIVRAISON
            system("clear");
            interface_liste_livaison();
            break;

    }
}

// --------------------------------- Question 1.1: Enregistrement terminé--------------------------------------

    //  Enregistrement client
void interface_creation_client(){
    // differentes variables a utiliser dans notre fonction
    char nom[MAX], prenom[MAX], sexe[MAX];
    std::string choixValide("01");
    Date::Date date;
    // petit menu de presentation
    std::cout << "\t\033[36;1m##############################################################################################################\n";                      
    std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
    std::cout << "\t##\033[36;0m                             \033[33;1mBIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL\033[33;0m                      \033[36;1m##\n";
    std::cout << "\t##                              ----------------------------------------------------                        ##\n";
    std::cout << "\t##                                           ------------------------------                                 ##\n";
    std::cout << "\t##                                          |\033[36;0m \033[32;1mCREATION D'UN NOUVEAU CLIENT\033[32;0m \033[36;1m|                                ##\n";
    std::cout << "\t##                                           ------------------------------                                 ##\n";
    std::cout << "\t##                                                                                                          ##\n";
    std::cout << "\t##\033[36;0m                                    \033[32;1mVeuillez suivre à la lettre les consigne !\033[32;0m                            \033[36;1m##\n";
    std::cout << "\t##                                       -------------------------------------                              ##\n";
    std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
    std::cout << "\t##                                                                                                          ##\n";
    std::cout << "\t##         ------------------------------------------------------------------------------------             ##\033[36;0m\n";
    // recuperation des informations du nouveau client
    
    nomNonNull:    std::cout << "\t \033[33;1mEntrer le NOM du Client :\033[33;0m\t" ;
    std::cin.ignore();
    std::cin.getline(nom,MAX);
    if(strlen(nom)==0)goto nomNonNull;
    std::cout <<"\n";
    std::cout << "\t \033[33;1mEntrer le PRENOM du Client :\033[33;0m\t";
    std::cin.getline(prenom,MAX);
    std::cout <<"\n";
    std::cout << "\t \033[33;1mEntrer DATE NAISSANCE Client :\033[33;0m\n";
    date = Date::recup_date("\t\t\033[32;1m","Date invalide","Jour:","Jour invalide","Mois:","Mois invalide","Annee:","Annee invalide");
    std::cout <<"\n\033[32;0m";
    std::cout << "\t \033[33;1mEntrer SEXE Client (M/F) :\033[33;0m\t";
    do{
        std::cin.getline(sexe,MAX);
        bool sexeValide = is_sexe(sexe);
        if(!sexeValide){
            std::cout <<"\t \033[33;1mEntrez un SEXE valide F ou M\033[33;0m\t";
        }else{
            break;
        }
    }while (true);
    
    // Enregistrement de notre client
    gestionnaireClient.creer_client( majuscule(nom).c_str(), majuscule(prenom).c_str() , date, sexe);
    std::cout <<"\n";
    
    std::cout <<"\n";
    do{
        std::cout <<"\t \033[33;1mVoulez-vous refaire un enregistrement? \n";
        std::cout <<"\t [1] - pour OUI \n";
        std::cout <<"\t [0] - pour NON \n";
        std::cout <<"\t Votre choix:\033[33;0m \t";
        std::cin >> choixUtilisateur;
    } while (choix_non_valide(choixUtilisateur,choixValide));

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


}; 
    // Enregistrement article
void interface_creation_article(){
    // differentes variables a utiliser dans notre fonction
    double prixArticle;
    long long quantite;
    unsigned long seuil;
    char nomArticle[MAX];
    std::string choixValide("01");

    // petit menu de presentation
    std::cout << "\t\033[36;1m##############################################################################################################\n";                      
    std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
    std::cout << "\t##\033[36;0m                             \033[33;1mBIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL\033[33;0m                      \033[36;1m##\n";
    std::cout << "\t##                              ----------------------------------------------------                        ##\n";
    std::cout << "\t##                                           ------------------------------                                 ##\n";
    std::cout << "\t##                                          |\033[36;0m    \033[32;1mCREATION D'UN ARTICLE    \033[32;0m \033[36;1m|                                ##\n";
    std::cout << "\t##                                           ------------------------------                                 ##\n";
    std::cout << "\t##                                                                                                          ##\n";
    std::cout << "\t##\033[36;0m                                    \033[32;1mVeuillez suivre à la lettre les consigne !\033[32;0m                            \033[36;1m##\n";
    std::cout << "\t##                                       -------------------------------------                              ##\n";
    std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
    std::cout << "\t##                                                                                                          ##\n";
    std::cout << "\t##         ------------------------------------------------------------------------------------             ##\033[36;0m\n";
        // recuperation des informations du nouveau article
        std::cin.ignore();
    articleNotNull:        std::cout <<"\n";
        std::cout <<"\n";
        std::cout << "\t \033[33;1mEntrer le libelle de l'Article :\033[33;0m\t";        
        
        std::cin.getline(nomArticle,MAX);
        if(strlen(nomArticle) == 0) goto articleNotNull; 

        std::cout <<"\n";
        std::cout << "\t \033[33;1mEntrer le Prix Unitaire de l'Article :\033[33;0m\t";
        std::cin >> prixArticle;
        std::cout <<"\n";
        std::cout << "\t \033[33;1mEntrer la Quantite en Stock :\033[33;0m\t";
        std::cin >> quantite;
        std::cout <<"\n";
        std::cout << "\t \033[33;1mEntrer le Seuil Critique de l'Article :\033[33;0m\t";
        std::cin >> seuil;
    // Enregistrement de notre article
    gestionnaireArticle.creer(majuscule(nomArticle).c_str(), prixArticle, quantite, seuil);
    std::cout <<"\n";


    do{
        std::cout <<"\t \033[33;1mVoulez-vous refaire un enregistrement? \n";
        std::cout <<"\t [1] - pour OUI \n";
        std::cout <<"\t [0] - pour NON \n";
        std::cout <<"\t Votre choix: \033[33;0m\t";
        std::cin >> choixUtilisateur;
    } while (choix_non_valide(choixUtilisateur,choixValide));

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

};
    // Enregistrement commande
void interface_creation_commande(){
    // differentes variables a utiliser dans notre fonction
    typeId idClient;
    typeId idArticle;
    long long _quantite;
    int _id;
    char id[MAX],nomR[MAX],quantite[MAX];
    Cellule<Client::Base> * personne ;
    //variable pour choix d'article         
    std::string choixU;
    int _idA,code;
    char nomA[MAX],idA[MAX];
    Cellule<Article::Base> * produit;
    std::string choixValide("12"),choixValide2("01");
    Liste<Client::Base> listeC;
    Liste<Article::Base>listeA;
    // petit menu de presentation
    std::cout << "\t\033[36;1m##############################################################################################################\n";                      
    std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
    std::cout << "\t##\033[36;0m                             \033[33;1mBIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL\033[33;0m                      \033[36;1m##\n";
    std::cout << "\t##                              ----------------------------------------------------                        ##\n";
    std::cout << "\t##                                           ------------------------------                                 ##\n";
    std::cout << "\t##                                          |\033[36;0m    \033[32;1mCREATION D'UNE COMMADE    \033[32;0m \033[36;1m|                               ##\n";
    std::cout << "\t##                                           ------------------------------                                 ##\n";
    std::cout << "\t##                                                                                                          ##\n";
    std::cout << "\t##\033[36;0m                                    \033[32;1mVeuillez suivre à la lettre les consigne !\033[32;0m                            \033[36;1m##\n";
    std::cout << "\t##                                       -------------------------------------                              ##\n";
    std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
    std::cout << "\t##                                                                                                          ##\n";
    std::cout << "\t##         ------------------------------------------------------------------------------------             ##\033[36;0m\n";
        // recuperation des informations du nouveau article
        std::cout <<"\n";
        std::cout << "\t \033[33;1mCette commande conserne quel CLIENT?\033[33;0m \n";
 a1:       do{ 
            std::cout <<"\n\033[33;1m";
            std::cout <<"\t Voulez-vous faire la recherche du client via ID ou via NOM? \n";
            std::cout <<"\t\t [1] - pour ID \n";
            std::cout <<"\t\t [2] - pour NON \n\n";
            std::cout <<"\t Votre choix:\033[33;1m \t";
            std::cin >> choixUtilisateur;
        } while (choix_non_valide(choixUtilisateur,choixValide));

    switch (choixUtilisateur.c_str()[0]){
        case '1': // recherche via id
    idinvalide:            std::cout <<"\n";            
            std::cout <<"\t \033[33;1mEntrer l'ID:\033[33;0m \t";
            std::cin.ignore();
            std::cin.getline(id,MAX);
            _id = convertion1(id);
            if(_id<0)goto idinvalide;
            personne = gestionnaireClient.chercher_client(_id);
            if (personne){
                std::cout <<"\n";
                std::cout << "\t\033[36;1m##----------------------------------------------------------------------------------------------------------------##\033[36;0m\n";            
                std::cout << "\t\033[32;1m\t     "<< personne->get().get_numero() <<"     \t"<< personne->get().get_nom() <<"     \t\t"<< personne->get().get_prenom() <<"     \t\t"<< personne->get().get_date() <<"     \t\t"<< personne->get().get_sexe() <<"\033[32;0m\n";                    
                std::cout << "\t\033[36;1m##----------------------------------------------------------------------------------------------------------------##\033[36;0m\n";  

                idClient =  personne->get().get_numero(); // recuperation de l'ID du produit

                // client existe alors on recherche le produit a commande
                    std::cout <<"\n";
                    std::cout << "\t \033[33;1mCette commande conserne quel ARTICLE?\033[33;0m \n";
    a2:         do{ 
                    std::cout <<"\n\033[33;1m";
                    std::cout <<"\t Voulez-vous faire la recherche de cette Article via ID ou via LIBELLE? \n";
                    std::cout <<"\t\t [1] - pour ID \n";
                    std::cout <<"\t\t [2] - pour LIBELLE \n\n";
                    std::cout <<"\t Votre choix:\033[33;0m \t";
                    std::cin >> choixU;
                } while (choix_non_valide(choixUtilisateur,choixValide));

                switch (choixU.c_str()[0]){
                    case '1': // recherche via id
    invalideid2:                        std::cout <<"\n";            
                        std::cout <<"\t \033[33;1mEntrer l'ID:\033[33;0m \t";
                        std::cin.ignore();
                        std::cin.getline(idA,MAX);
                        _idA = convertion1(idA);
                        if(_idA < 0)goto invalideid2;
                        produit = gestionnaireArticle.chercher(_idA);
                    if (produit){
                        std::cout <<"\n";
                        std::cout << "\t\033[36;1m##--------------------------------------------------------------------------------------------------------------------------##\033[36;0m\n";            
                        std::cout << "\t\033[32;1m\t     "<< produit->get().get_reference() <<"     \t"<< produit->get().get_libelle() <<"     \t\t"<< produit->get().get_prix() <<"     \t\t"<< produit->get().get_quantite() <<"     \t\t"<< produit->get().get_seuil() <<"\033[32;0m\n";                    
                        std::cout << "\t\033[36;1m##--------------------------------------------------------------------------------------------------------------------------##\033[36;0m\n";            
                        
                        idArticle = produit->get().get_reference();// recuperation de l'id du produit
                        do{ std::cout << "\n";
                            std::cout << "\t \033[33;1mEntrer la Quantite de l'Article a commander:\033[33;0m\t";  
                            std::cin.getline(quantite,MAX);
                            _quantite = convertion1(quantite);
                        }while(_quantite < 0);  
                        code = commander_article(idClient,idArticle,_quantite); 
                        switch (code)
                        {
                        case PAS_SUFFISANT:
                            std::cout << "\n";            
                            std::cout << "\t\033[36;1m##--------------------------------------------------------------------------------------------------------------##\033[36;0m\n";    
                            std::cout << "\t                                \033[31;1mQUANTITE INSUFISANT DANS NOTRE BASE DE DONNEES\033[31;0m                          \n";
                            std::cout << "\t##--------------------------------------------------------------------------------------------------------------##\033[36;0m\n";
                            break;
                        case ERREUR_SYSTEME:
                            break;                        
                        default:
                            break;
                        }
                    }else{
                        std::cout << "\n";            
                        std::cout << "\t\033[36;1m##--------------------------------------------------------------------------------------------------------------##\n";    
                        std::cout << "\t##\033[36;0m                                \033[32;1mCET ARTICLE N'EXISTE PAS DANS NOTRE BASE DE DONNEES\033[32;0m                           \033[36;1m##\n";
                        std::cout << "\t##--------------------------------------------------------------------------------------------------------------##\033[36;0m\n";
                        do{
                            std::cout << " \n ";
                            std::cout <<"\t \033[36;1mVoulez-vous ANNULER la commande ou CHANGER l'article de la commande? \n";
                            std::cout <<"\t [1] - pour CHANGER \n";
                            std::cout <<"\t [0] - pour ANNULER \n";
                            std::cout <<"\t Votre choix:\033[36;0m \t";
                            std::cin >> choixUtilisateur;
                        } while (choix_non_valide(choixUtilisateur,choixValide2));

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
                    do{
                        std::cout <<"\n";            
                        std::cout <<"\t \033[33;1mEntrer le LIBELLE:\033[33;0m \t";
                        std::cin.getline(nomA,MAX);
                    }while (strlen(nomA)==0);
                    
                    listeA =  gestionnaireArticle.liste_ayant_nom( majuscule(nomA).c_str());
                    produit = listeA.recup_tete();
                    if (!listeA.est_vide()){
                        while(produit != listeA.recup_sentinelle()){
                            std::cout <<"\n";
                            std::cout << "\t\033[36;1m##--------------------------------------------------------------------------------------------------------------------------##\033[36;0m\n";            
                            std::cout << "\t\033[32;1m\t     "<< produit->get().get_reference() <<"     \t"<< produit->get().get_libelle() <<"     \t\t"<< produit->get().get_prix() <<"     \t\t"<< produit->get().get_quantite() <<"     \t\t"<< produit->get().get_seuil() <<"\033[32;0m\n";                    
                            std::cout << "\t\033[36;1m##----------------------------------------------------------------------------------------------------------------------------##\033[36;0m\n"; 
                            produit = produit->get_next();
                        }
                        if(listeA.recup_taille() != 1)goto a2;
                        produit = listeA.recup_tete();
                        idArticle = produit->get().get_reference();// recuperation de l'id du produit
                        do{std::cout << "\n";
                        std::cout << "\t \033[33;1mEntrer la Quantite de l'Article a commander:\033[33;0m\t";  
                        std::cin.ignore();
                        std::cin.getline(quantite,MAX);
                        _quantite = convertion1(quantite);  
                        }while(_quantite < 0);
                        code = commander_article(idClient,idArticle,_quantite); 
                        switch (code)
                        {
                        case PAS_SUFFISANT:
                            std::cout << "\n";            
                            std::cout << "\t\033[36;1m##--------------------------------------------------------------------------------------------------------------##\033[36;0m\n";    
                            std::cout << "\t                                \033[31;1mQUANTITE INSUFISANT DANS NOTRE BASE DE DONNEES\033[31;0m                          \n";
                            std::cout << "\t##--------------------------------------------------------------------------------------------------------------##\033[36;0m\n";
                            break;
                        case ERREUR_SYSTEME:
                            break;                        
                        default:
                            break;
                        }
                    }else{
                        std::cout << "\n";            
                        std::cout << "\t\033[36;1m##--------------------------------------------------------------------------------------------------------------##\n";    
                        std::cout << "\t##\033[36;0m                                \033[32;1mCET ARTICLE N'EXISTE PAS DANS NOTRE BASE DE DONNEES\033[32;0m                           \033[36;1m##\n";
                        std::cout << "\t##--------------------------------------------------------------------------------------------------------------##\033[36;0m\n";  
                        do{
                            std::cout << " \n ";
                            std::cout <<"\t \033[33;1mVoulez-vous ANNULER la commande ou CHANGER l'article de la commande? \n";
                            std::cout <<"\t [1] - pour CHANGER \n";
                            std::cout <<"\t [0] - pour ANNULER \n";
                            std::cout <<"\t Votre choix:\033[36;0m \t";
                            std::cin >> choixUtilisateur;
                        } while(choix_non_valide(choixUtilisateur,choixValide2));

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
                std::cout << "\t\033[36;1m##--------------------------------------------------------------------------------------------------------------##\n";    
                std::cout << "\t##\033[36;0m                                \033[32;1mCE CLIENT N'EXISTE PAS DANS NOTRE BASE DE DONNEES\033[32;0m                             \033[36;1m##\n";
                std::cout << "\t##--------------------------------------------------------------------------------------------------------------##\033[36;0m\n"; 
                        do{
                            std::cout << " \n ";
                            std::cout <<"\t \033[36;1mVoulez-vous ANNULER la commande ou CHANGER le client de la commande? \n";
                            std::cout <<"\t [1] - pour CHANGER \n";
                            std::cout <<"\t [0] - pour ANNULER \n";
                            std::cout <<"\t Votre choix: \033[36;0m\t";
                            std::cin >> choixUtilisateur;
                        } while(choix_non_valide(choixUtilisateur,choixValide2));

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
            do{
                std::cout <<"\n";            
                std::cout <<"\t \033[33;1mEntrer le NOM:\033[33;0m \t";
            
                std::cin.ignore();
                std::cin.getline(nomR,MAX);
            }while (strlen(nomR) == 0);
            listeC = gestionnaireClient.liste_ayant_nom(majuscule(nomR).c_str());
            personne = listeC.recup_tete();
            
            if (!listeC.est_vide()){
                while (personne != listeC.recup_sentinelle())
                {
                    std::cout <<"\n";
                std::cout << "\t\033[36;1m##--------------------------------------------------------------------------------------------------------------------------##\033[36;0m\n";            
                std::cout << "\t\t\033[32;1m     "<< personne->get().get_numero() <<"     \t"<< personne->get().get_nom() <<"     \t\t"<< personne->get().get_prenom() <<"     \t\t"<< personne->get().get_date() <<"     \t\t"<< personne->get().get_sexe() <<"\033[32;0m\n";                    
                std::cout << "\t\033[36;1m##--------------------------------------------------------------------------------------------------------------------------##\033[36;0m\n";
                    personne = personne->get_next();
                }
                
                if(listeC.recup_taille() != 1)goto a1;
                personne = listeC.recup_tete();
                idClient =  personne->get().get_numero(); // recuperation de l'ID du produit
                // client existe alors on recherche le produit a commande
                    std::cout <<"\n";
                    std::cout << "\t \033[33;1mCette commande conserne quel ARTICLE?\033[33;0m \n";
    a3:             do{ 
                    std::cout <<"\n";
                    std::cout <<"\t \033[33;1mVoulez-vous faire la recherche de cette Article via ID ou via LIBELLE? \n";
                    std::cout <<"\t\t [1] - pour ID \n";
                    std::cout <<"\t\t [2] - pour LIBELLE \n\n";
                    std::cout <<"\t Votre choix:\033[33;0m \t";
                    std::cin >> choixU;
                } while (choix_non_valide(choixUtilisateur,choixValide));

                switch (choixU.c_str()[0]){
                    case '1': // recherche via id
                        std::cout <<"\n";            
                        std::cout <<"\t \033[33;1mEntrer l'ID:\033[33;0m \t";
                        std::cin >> idA;
                        produit = gestionnaireArticle.chercher(idA);
                    if (produit){
                        std::cout <<"\n";
                        std::cout << "\t\033[36;1m##--------------------------------------------------------------------------------------------------------------------------##\033[36;0m\n";            
                        std::cout << "\t\033[33;1m\t     "<< produit->get().get_reference() <<"     \t"<< produit->get().get_libelle() <<"     \t\t"<< produit->get().get_prix() <<"     \t\t"<< produit->get().get_quantite() <<"     \t\t"<< produit->get().get_seuil() <<"\033[33;0m\n";                    
                        std::cout << "\t\033[36;1m##--------------------------------------------------------------------------------------------------------------------------##\033[36;0m\n";            
                        
                        idArticle = produit->get().get_reference();// recuperation de l'id du produit
                        do{ std::cout << "\n";
                        std::cout << "\t \033[33;1mEntrer la Quantite de l'Article a commander:\033[33;0m\t"; 
                        std::cin.ignore(); 
                        std::cin.getline(quantite,MAX);
                        _quantite = convertion1(quantite);  
                        }while(_quantite < 0);    
                        code = commander_article(idClient,idArticle,_quantite); 
                        switch (code)
                        {
                        case PAS_SUFFISANT:
                            std::cout << "\n";            
                            std::cout << "\t\033[36;1m##--------------------------------------------------------------------------------------------------------------##\033[36;0m\n";    
                            std::cout << "\t                                \033[31;1mQUANTITE INSUFISANT DANS NOTRE BASE DE DONNEES\033[31;0m                          \n";
                            std::cout << "\t##--------------------------------------------------------------------------------------------------------------##\033[36;0m\n";
                            break;
                        case ERREUR_SYSTEME:
                            break;                        
                        default:
                            break;
                        } 

                    }else{
                        std::cout << "\n";            
                        std::cout << "\t\033[36;1m##--------------------------------------------------------------------------------------------------------------##\n";    
                        std::cout << "\t##\033[36;0m                               \033[32;1mCET ARTICLE N'EXISTE PAS DANS NOTRE BASE DE DONNEES\033[32;0m                            \033[36;1m##\n";
                        std::cout << "\t##--------------------------------------------------------------------------------------------------------------##\033[36;0m\n";
                        do{
                            std::cout << " \n ";
                            std::cout <<"\t \033[33;1mVoulez-vous ANNULER la commande ou CHANGER l'article de la commande? \n";
                            std::cout <<"\t [1] - pour CHANGER \n";
                            std::cout <<"\t [0] - pour ANNULER \n";
                            std::cout <<"\t Votre choix: \033[33;0m\t";
                            std::cin >> choixUtilisateur;
                        } while (choix_non_valide(choixUtilisateur,choixValide2));

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
                    do{
                        std::cout <<"\n";            
                        std::cout <<"\t \033[33;1mEntrer le LIBELLE:\033[33;0m \t";
                        std::cin.ignore();
                        std::cin.getline(nomA,MAX);
                    }while(strlen(nomA) == 0);
                        listeA = gestionnaireArticle.liste_ayant_nom(majuscule(nomA).c_str());
                    produit = listeA.recup_tete(); 
                    if (!listeA.est_vide()){
                        while(produit!=listeA.recup_sentinelle()){std::cout <<"\n";
                            std::cout << "\t\033[36;1m##--------------------------------------------------------------------------------------------------------------------------##\033[36;0m\n";            
                            std::cout << "\t\033[33;1m\t     "<< produit->get().get_reference() <<"     \t"<< produit->get().get_libelle() <<"     \t\t"<< produit->get().get_prix() <<"     \t\t"<< produit->get().get_quantite() <<"     \t\t"<< produit->get().get_seuil() <<"\t\n";                    
                            std::cout << "\t\033[36;1m##--------------------------------------------------------------------------------------------------------------------------##\033[36;0m\n";
                            produit = produit->get_next(); 
                        }
                        if(listeA.recup_taille()!=1)goto a3;
                        produit = listeA.recup_tete();
                        idArticle = produit->get().get_reference();// recuperation de l'id du produit
                        do{ std::cout << "\n";
                            std::cout << "\t \033[33;1mEntrer la Quantite de l'Article a commander:\033[33;0m\t"; 
                            std::cin.ignore(); 
                            std::cin.getline(quantite,MAX);
                            _quantite = convertion1(quantite);  
                        }while(_quantite <0);    
                        code = commander_article(idClient,idArticle,_quantite); 
                        switch (code)
                        {
                        case PAS_SUFFISANT:
                            std::cout << "\n";            
                            std::cout << "\t\033[36;1m##--------------------------------------------------------------------------------------------------------------##\033[36;0m\n";    
                            std::cout << "\t                                \033[31;1mQUANTITE INSUFISANT DANS NOTRE BASE DE DONNEES\033[31;0m                          \n";
                            std::cout << "\t##--------------------------------------------------------------------------------------------------------------##\033[36;0m\n";
                            break;
                        case ERREUR_SYSTEME:
                            break;                        
                        default:
                            break;
                        }
                    }else{
                        std::cout << "\n";            
                        std::cout << "\t\033[36;1m##--------------------------------------------------------------------------------------------------------------##\n";    
                        std::cout << "\t##\033[36;0m                                 \033[32;1mCET ARTICLE N'EXISTE PAS DANS NOTRE BASE DE DONNEES\033[32;0m                          \033[36;1m##\n";
                        std::cout << "\t##--------------------------------------------------------------------------------------------------------------##\033[36;0m\n"; 
                        do{
                            std::cout << " \n ";
                            std::cout <<"\t \033[33;1mVoulez-vous ANNULER la commande ou CHANGER l'article de la commande? \n";
                            std::cout <<"\t [1] - pour CHANGER \n";
                            std::cout <<"\t [0] - pour ANNULER \n";
                            std::cout <<"\t Votre choix: \033[33;0m\t";
                            std::cin >> choixUtilisateur;
                        } while (choix_non_valide(choixUtilisateur,choixValide2));

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
                std::cout << "\t\033[36;1m##--------------------------------------------------------------------------------------------------------------##\n";    
                std::cout << "\t##\033[36;0m                              \033[32;1mCE CLIENT N'EXISTE PAS DANS NOTRE BASE DE DONNEES\033[32;0m                               \033[36;1m##\n";
                std::cout << "\t##--------------------------------------------------------------------------------------------------------------##\033[36;0m\n"; 
                        do{
                            std::cout << " \n \033[33;1m";
                            std::cout <<"\t Voulez-vous ANNULER la commande ou CHANGER le client de la commande? \n";
                            std::cout <<"\t [1] - pour CHANGER \n";
                            std::cout <<"\t [0] - pour ANNULER \n";
                            std::cout <<"\t Votre choix: \033[33;0m\t";
                            std::cin >> choixUtilisateur;
                        } while (choix_non_valide(choixUtilisateur,choixValide2));

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
        std::cout << " \n\033[33;1m ";
        std::cout <<"\t Voulez-vous refaire un enregistrement? \n";
        std::cout <<"\t [1] - pour OUI \n";
        std::cout <<"\t [0] - pour NON \n";
        std::cout <<"\t Votre choix: \033[33;0m\t";
        std::cin >> choixUtilisateur;
    } while (choix_non_valide(choixUtilisateur,choixValide2));

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

};
    // Enregistrement livraison -----------------------pas terminé-------------
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
    std::string choixValide("01");

    // petit menu de presentation
    std::cout << "\t\033[36;1m##############################################################################################################\n";                      
    std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
    std::cout << "\t##\033[36;0m                             \033[33;1mBIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL\033[33;0m                      \033[36;1m##\n";
    std::cout << "\t##                              ----------------------------------------------------                        ##\n";
    std::cout << "\t##                                           ------------------------------                                 ##\n";
    std::cout << "\t##                                          |\033[36;0m   \033[32;1mCREATION D'UNE LIVRAISON  \033[32;0m \033[36;1m|                                ##\n";
    std::cout << "\t##                                           ------------------------------                                 ##\n";
    std::cout << "\t##                                                                                                          ##\n";
    std::cout << "\t##\033[36;0m                                    \033[32;1mVeuillez suivre à la lettre les consigne !\033[32;0m                            \033[36;1m##\n";
    std::cout << "\t##                                       -------------------------------------                              ##\n";
    std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
    std::cout << "\t##                                                                                                          ##\n";
    std::cout << "\t##         ------------------------------------------------------------------------------------             ##\033[36;0m\n";

    std::cout <<"\n\033[33;1m";
    std::cout << "\t Cette LIVRAISON conserne quel COMMANDE? \n";
    std::cout <<"\n\033[33;0m";            
    std::cout <<"\t \033[32;1mEntrer l'ID de la Commande:\033[32;0m \t";
    std::cin >> id;

    ref = id;
    com = gestionnaireCommande.chercher(ref);
    if (com){
        s = com->get().est_livrer();
        if (s){
            std::cout << "\n";            
            std::cout << "\t\033[36;1m##---------------------------------------------------------------------------------------------------------------##\n";    
            std::cout << "\t##\033[36;0m                              \033[31;1mCETTE COMMANDE EST DEJA EN COURS DE LIVRAISON\033[31;0m                                  \033[36;1m##\n";
            std::cout << "\t##--------------------------------------------------------------------------------------------------------------##\033[36;0m\n";
        }else{
            idA = com->get().ref();
            idClient = com->get().ref_client();
            quantite = com->get().nombre();
            gestionnaireLivraison.creer(idA,idClient,quantite);
            com->get().livrer();// A REVOIR
        }
    }else{
        std::cout << "\n";            
        std::cout << "\t\033[36;1m##------------------------------------------------------------------------------------------------------------------##\n";    
        std::cout << "\t##\033[36;0m                               \033[31;1mIL N'EXISTE PAS DE COMMANDE A CE NUMERO\033[31;0m                                        \033[36;1m##\n";
        std::cout << "\t##-----------------------------------------------------------------------------------------------------------------##\033[36;0m\n";
    }
    do{
        std::cout << " \n\033[33;1m ";
        std::cout <<"\t Voulez-vous cree une autre livraison? \n";
        std::cout <<"\t [1] - pour OUI \n";
        std::cout <<"\t [0] - pour NON \n";
        std::cout <<"\t Votre choix:\033[33;0m \t";
        std::cin >> choixUtilisateur;
    } while (choix_non_valide(choixUtilisateur,choixValide));

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
};
// ---------------------------------- Question 1.2: Affichage de données terminé ------------------------------
    // Lister les clients
void interface_liste_client(){
    // differentes variables a utiliser dans notre fonction
    std::string ch;
    Cellule<Client::Base> * personne ;
    std::string choixValide("01");

    // petit menu de presentation
    std::cout << "\t\033[36;1m##############################################################################################################\n";    
    std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
    std::cout << "\t##\033[36;0m                            \033[33;1mBIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL\033[33;0m                       \033[36;1m##\n";
    std::cout << "\t##                              ---------------------------------------------------                         ##\n";
    std::cout << "\t##                                        ---------------------------------                                 ##\n";
    std::cout << "\t##                                       |\033[36;0m        \033[32;1mLISTE DES CLIENTS\033[32;0m        \033[36;1m|                                ##\n";
    std::cout << "\t##                                        --------------------------------                                  ##\n";
    std::cout << "\t##                                                                                                          ##\n";
    std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
    std::cout << "\t##         -------------------------------------------------------------------------------------            ##\033[36;0m\n";
    
        std::cout << "\n";    
        personne = gestionnaireClient.recup_tete();
        std::cout << "\t\t     \033[37;1mID\033[37;0m  \033[36;1m|\033[36;0m       \033[37;1mNOM\033[37;0m           \033[36;1m|\033[36;0m       \033[37;1mPRENOM\033[37;0m          \033[36;1m|\033[36;0m     \033[37;1mDATE NAISSANCE\033[37;0m \t \033[36;1m|\033[36;0m     \033[37;1mSEXE\033[37;0m \n";
        std::cout << "\t\033[36;1m##----------------------------------------------------------------------------------------------------------##\033[36;0m\n";            
        std::cout << "\t\033[36;1m##----------------------------------------------------------------------------------------------------------##\033[36;0m\n";
        while (personne != gestionnaireClient.recup_sentinelle())
        {   
            std::cout << "\t\033[32;1m\t     "<< personne->get().get_numero() <<"     \t"<< personne->get().get_nom() <<"     \t\t"<< personne->get().get_prenom() <<"     \t\t"<< personne->get().get_date() <<"     \t\t"<< personne->get().get_sexe() <<"\033[33;0m\n";    
            std::cout << "\t\033[36;1m##----------------------------------------------------------------------------------------------------------##\033[36;0m\n";            
            personne = personne->get_next();
        }

    do{
        std::cout <<"\t \033[33;1mTapez: \n";
        std::cout <<"\t      [1] - pour RETOUR AU MENU CLIENT \n";
        std::cout <<"\t      [0] - pour RETOUR AU MENU PRINCIPAL \n\n";
        std::cout <<"\t Entrer votre choix:\033[33;0m \t";
        std::cin >> ch;
        system("clear");
    } while (choix_non_valide(ch,choixValide));

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
};
    // Lister les commandes
void interface_liste_commande(){
    // differentes variables a utiliser dans notre fonction
    typeId idClient;
    typeId idArticle;
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

    const char * etat2 = "Livree";
    const char * etat1 = "En Cour...";
    const char * etat3 = "En cour Livraison";
    const char * etat4 = "Annuler";
    std::string choixValide("01");

    // petit menu de presentation
    std::cout << "\t\033[36;1m###############################################################################################################\n";
    std::cout << "\t##-_-_-                                                                                                 -_-_-##\n";
    std::cout << "\t##\033[36;0m                          \033[33;1mBIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL\033[33;0m                          \033[36;1m##\n";
    std::cout << "\t##                           ----------------------------------------------------                            ##\n";
    std::cout << "\t##                                     ------------------------------                                        ##\n";
    std::cout << "\t##                                    |\033[36;0m    \033[32;1mLISTE DES COMMANDES\033[32;1m       \033[36;1m|                                       ##\n";
    std::cout << "\t##                                     ------------------------------                                        ##\n";
    std::cout << "\t##                                                                                                           ##\n";
    std::cout << "\t##\033[36;0m                                \033[32;1mVeuillez suivre à la lettre les consigne !\033[32;0m                                 \033[36;1m##\n";
    std::cout << "\t##                                 -------------------------------------                                     ##\n";
    std::cout << "\t##-_-_-                                                                                                 -_-_-##\n";
    std::cout << "\t##                                                                                                           ##\n";
    std::cout << "\t##         -------------------------------------------------------------------------------------             ##\033[36;0m\n";

        std::cout << "\n";    
        com = gestionnaireCommande.recup_tete();
        std::cout << "\t\t     \033[37;1mID\033[37;0m  \033[36;1m|\033[36;0m       \033[37;1mCLIENT\033[37;0m       \033[36;1m|\033[36;0m    \033[37;1mETAT\033[37;0m            \033[36;1m|\033[36;0m          \033[37;1mLIBELLE\033[37;1m          \033[36;1m|\033[36;0m     \033[37;1mQUANTITE\033[37;0m\n";
        std::cout << "\t\033[36;1m##------------------------------------------------------------------------------------------------------##\033[36;0m\n";            
        std::cout << "\t\033[36;1m##------------------------------------------------------------------------------------------------------##\033[36;0m\n";
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
            
            switch(com->get().status()){
                case Commande::ENCOUR:
                    reponce3 = etat1;
                break;
                case Commande::ENCOURLIVRAISON:
                    reponce3 = etat2;
                break;
                case Commande::TERMINER:
                    reponce3 = etat3;
                break;
                case Commande::ANNULER:
                    reponce3 = etat4;
                break;
            } 
            

            std::cout << "\t\033[32;1m\t     "<< com->get().ref() <<"     \t"<< reponce1 <<"   \t "<< reponce3 <<"     \t\t"<< reponce2<<"     \t\t"<<com->get().nombre() <<"\033[36;0m\n";    
            std::cout << "\t\033[36;1m##------------------------------------------------------------------------------------------------------##\033[36;0m\n";            
            com = com->get_next();
        }

    do{
        std::cout <<"\t \033[33;1mTapez: \n";
        std::cout <<"\t      [1] - pour RETOUR AU MENU COMMANDE \n";
        std::cout <<"\t      [0] - pour RETOUR AU MENU PRINCIPAL \n\n";
        std::cout <<"\t Entrer votre choix:\033[33;0m \t";
        std::cin >> ch;
        system("clear");
    } while (choix_non_valide(ch,choixValide));

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

};
    // Lister les articles
void interface_liste_article(){
    // differentes variables a utiliser dans notre fonction
    std::string ch;
    Cellule<Article::Base> * produit;
    std::string choixValide("01");

    // petit menu de presentation
    std::cout << "\t\033[36;1m##############################################################################################################\n";    
    std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
    std::cout << "\t##\033[36;0m                           \033[33;1mBIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL\033[33;0m                        \033[36;1m##\n";
    std::cout << "\t##                          ---------------------------------------------------                             ##\n";
    std::cout << "\t##                                      ---------------------------------                                   ##\n";
    std::cout << "\t##                                     |\033[36;0m        \033[32;1mLISTE DES ARTICLES\033[32;0m       \033[36;1m|                                  ##\n";
    std::cout << "\t##                                      --------------------------------                                    ##\n";
    std::cout << "\t##                                                                                                          ##\n";
    std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
    std::cout << "\t##         -----------------------------------------------------------------                                ##\033[36;0m\n";
    std::cout << "\n";  
  
        produit = gestionnaireArticle.recup_tete();
        std::cout << "\t\t     \033[37;1mID\033[37;0m  \033[36;1m|\033[36;0m       \033[37;1mLIBELLE\033[37;0m       \033[36;1m|\033[36;0m         \033[37;1mPRIX U\033[37;0m          \033[36;1m|\033[36;0m   \033[37;1mQUANTITE\033[37;0m \t \033[36;1m|\033[36;0m           \033[37;1mSEUIL\033[37;0m \n";
        std::cout << "\t\033[36;1m##----------------------------------------------------------------------------------------------------------##\n";            
        std::cout << "\t##----------------------------------------------------------------------------------------------------------##\033[36;0m\n";
        while (produit != gestionnaireArticle.recup_sentinelle())
        {   
            std::cout << "\t##\t    \033[33;1m"<< produit->get().get_reference() <<"\033[33;0m      \t\033[32;1m"<< produit->get().get_libelle() <<"   \t\t"<< produit->get().get_prix() <<"      \t\t"<< produit->get().get_quantite() <<"      \t\t"<< produit->get().get_seuil() <<"\033[36;0m\n";    
        std::cout << "\t\033[36;1m##----------------------------------------------------------------------------------------------------------##\033[36;0m\n";            
            produit = produit->get_next();
        }  

    do{
        std::cout <<"\n\t \033[33;1mTapez: \n";
        std::cout <<"\t      [1] - pour RETOUR AU MENU DES ARTICLES \n";
        std::cout <<"\t      [0] - pour RETOUR AU MENU PRINCIPAL \n\n";
        std::cout <<"\t Entrer votre choix:\033[33;0m \t";
        std::cin >> ch;
        system("clear");
    } while (choix_non_valide(ch,choixValide));

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
};
    // Lister les livraisons ---------------------- pas terminé -------------------
void interface_liste_livaison(){
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
    std::string choixValide("01");

    // petit menu de presentation
    std::cout << "\t\033[36;1m###############################################################################################################\n";
    std::cout << "\t##-_-_-                                                                                                 -_-_-##\n";
    std::cout << "\t##\033[36;0m                          \033[33;1mBIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL\033[33;0m                          \033[36;1m##\n";
    std::cout << "\t##                           ----------------------------------------------------                            ##\n";
    std::cout << "\t##                                     ------------------------------                                        ##\n";
    std::cout << "\t##                                    |\033[36;0m    \033[32;1mLISTE DES LIVRAISONS\033[32;1m      \033[36;1m|                                       ##\n";
    std::cout << "\t##                                     ------------------------------                                        ##\n";
    std::cout << "\t##-_-_-                                                                                                 -_-_-##\n";
    std::cout << "\t##                                                                                                           ##\n";
    std::cout << "\t##         -------------------------------------------------------------------------------------             ##\033[36;0m\n";

        std::cout << "\n";    
        com = gestionnaireCommande.recup_tete();

        std::cout << "\t\t     \033[37;1mID\033[37;0m  \033[36;1m|\033[36;0m       \033[37;1mCLIENT\033[37;0m       \033[36;1m|\033[36;0m    \033[37;1mETAT\033[37;0m            \033[36;1m|\033[36;0m          \033[37;1mLIBELLE\033[37;1m          \033[36;1m|\033[36;0m     \033[37;1mQUANTITE\033[37;0m\n";
        std::cout << "\t\033[36;1m##------------------------------------------------------------------------------------------------------##\033[36;0m\n";            
        std::cout << "\t\033[36;1m##------------------------------------------------------------------------------------------------------##\033[36;0m\n";
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

            std::cout << "\t\033[32;1m\t     "<< com->get().ref() <<"     \t"<< reponce1 <<"   \t "<< reponce3 <<"     \t\t"<< reponce2<<"     \t\t"<<com->get().nombre() <<"\033[36;0m\n";    
            std::cout << "\t\033[36;1m##------------------------------------------------------------------------------------------------------##\033[36;0m\n";            
            com = com->get_next();
        }

    do{
        std::cout <<"\t \033[33;1mTapez: \n";
        std::cout <<"\t      [1] - pour RETOUR AU MENU COMMANDE \n";
        std::cout <<"\t      [0] - pour RETOUR AU MENU PRINCIPAL \n\n";
        std::cout <<"\t Entrer votre choix:\033[33;0m \t";
        std::cin >> ch;
        system("clear");
    } while (choix_non_valide(ch,choixValide));

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

};
// ----------------------------------------- Question 1.3: Suppression de données ------------------------------
    // suppression client
void interface_suppression_client(){
    // differentes variables a utiliser dans notre fonction
    std::string choixUtilisateur;
    int id;
    typeId identifiant;
    std::string nomR;
    std::string ch;
    Cellule<Client::Base> * personne ;
    std::string choixValide("01"),choixValide1("12");

    // petit menu de presentation
    std::cout << "\t\033[36;1m##############################################################################################################\n";    
    std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
    std::cout << "\t##\033[36;0m                               \033[33;1mBIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL\033[33;0m                    \033[36;1m##\n";
    std::cout << "\t##                                 ---------------------------------------------------                      ##\n";
    std::cout << "\t##                                         ---------------------------------                                ##\n";
    std::cout << "\t##                                        |\033[36;0m    \033[32;1mSUPPRESSION D'UN CLIENT\033[32;0m      \033[36;1m|                               ##\n";
    std::cout << "\t##                                          --------------------------------                                ##\n";
    std::cout << "\t##                                                                                                          ##\n";
    std::cout << "\t##\033[36;0m                                    \033[32;1mVeuillez suivre à la lettre les consigne !\033[32;0m                            \033[36;1m##\n";
    std::cout << "\t##                                             -----------------------                                      ##\n";
    std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
    std::cout << "\t##                                                                                                          ##\n";
    std::cout << "\t##         ------------------------------------------------------------------------------------             ##\033[36;0m\n";
    
 do{ 
        std::cout <<"\n\033[33;1m";
        std::cout <<"\t Voulez-vous faire la recherche du CLIENT a SUPPRIMER via son ID ou via son NOM? \n";
        std::cout <<"\t\t [1] - pour ID \n";
        std::cout <<"\t\t [2] - pour NOM \n\n";
        std::cout <<"\t Votre choix:\033[33;0m \t";
        std::cin >> choixUtilisateur;
    } while (choix_non_valide(choixUtilisateur,choixValide1));

    switch (choixUtilisateur.c_str()[0]){
        case '1': // recherche via id
            std::cout <<"\n";            
            std::cout <<"\t \033[33;1mEntrer l'ID:\033[33;0m \t";
            std::cin >> id;
            personne = gestionnaireClient.chercher_client(id);
            if (personne){
                std::cout <<"\n";
                std::cout << "\t\033[36;1m##------------------------------------------------------------------------------------------------------##\033[36;0m\n";            
                std::cout << "\t\033[32;1m\t     "<< personne->get().get_numero() <<"     \t"<< personne->get().get_nom() <<"     \t\t"<< personne->get().get_prenom() <<"     \t\t"<< personne->get().get_date() <<"     \t\t"<< personne->get().get_sexe() <<"\033[32;0m\n";                
                std::cout << "\t\033[36;1m##------------------------------------------------------------------------------------------------------##\033[36;0m\n"; 
                std::cout <<"\n";
                identifiant = id;
                gestionnaireClient.supprimer_client(identifiant);
            }else{
                std::cout << "\n";            
                std::cout << "\t\033[36;1m##--------------------------------------------------------------------------------------------------------------##\n";    
                std::cout << "\t##\033[36;0m                             \033[37;1mCE CLIENT N'EXISTE PAS DANS NOTRE BASE DE DONNEES\033[37;0m                                \033[36;1m##\n";
                std::cout << "\t##--------------------------------------------------------------------------------------------------------------##\033[36;0m\n";    
            }
        break;
        case '2': // recherche via nom
            std::cout <<"\n";            
            std::cout <<"\t \033[33;1mEntrer le NOM:\033[33;0m \t";
            std::cin >> nomR;
            personne = gestionnaireClient.chercher_client(nomR.c_str());
            if (personne){
                std::cout <<"\n";
                std::cout << "\t\033[36;1m##-----------------------------------------------------------------------------------------------------##\033[36;0m\n";            
                std::cout << "\t\033[32;1m\t     "<< personne->get().get_numero() <<"     \t"<< personne->get().get_nom() <<"     \t\t"<< personne->get().get_prenom() <<"     \t\t"<< personne->get().get_date() <<"     \t\t"<< personne->get().get_sexe() <<"\033[32;0m\n";                    
                std::cout << "\t\033[36;1m##------------------------------------------------------------------------------------------------------##\033[36;0m\n"; 

                identifiant = personne->get().get_numero();

                gestionnaireClient.supprimer_client(identifiant);            
            }else{
                std::cout <<"\n";            
                std::cout << "\t\033[36;1m##--------------------------------------------------------------------------------------------------------------##\n";    
                std::cout << "\t##\033[36;0m                                \033[37;1mCE CLIENT N'EXISTE PAS DANS NOTRE BASE DE DONNEES\033[37;0m                             \033[36;1m##\n";
                std::cout << "\t##--------------------------------------------------------------------------------------------------------------##\033[36;0m\n";    
            }
        break;
    };

    do{
        std::cout << "\n\033[33;1m";
        std::cout <<"\t Voulez-vous refaire une suppresion? \n";
        std::cout <<"\t     [1] - pour OUI \n";
        std::cout <<"\t     [0] - pour NON \n\n";
        std::cout <<"\t Entrer votre choix:\033[33;0m \t";
        std::cin >> ch;
    } while (choix_non_valide(ch,choixValide));

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
};
    // suppression article
void interface_suppression_article(){
    // differentes variables a utiliser dans notre fonction

    long long _id;
    char id[MAX],nomR[MAX];
    typeId ref;
    std::string ch;
    Liste<Article::Base> liste;
    Cellule<Article::Base> * produit;
    std::string choixValide("12");
    std::string choixValide1("01");

    // petit menu de presentation
    std::cout << "\t\033[36;1m##############################################################################################################\n";        
    std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
    std::cout << "\t##\033[36;0m                             \033[33;1mBIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL \033[33;0m                     \033[36;1m##\n";
    std::cout << "\t##                              ---------------------------------------------------                         ##\n";
    std::cout << "\t##                                     ---------------------------------                                    ##\n";
    std::cout << "\t##                                    |\033[36;0m    \033[32;1mSUPPRESSION D'UN ARTICLE\033[32;0m     \033[36;1m|                                   ##\n";
    std::cout << "\t##                                      --------------------------------                                    ##\n";
    std::cout << "\t##                                                                                                          ##\n";
    std::cout << "\t##\033[36;0m                                \033[37;1mVeuillez suivre à la lettre les consigne !\033[37;0m                                \033[36;1m##\n";
    std::cout << "\t##                                        -----------------------                                           ##\n";
    std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
    std::cout << "\t##                                                                                                          ##\n";
    std::cout << "\t##         ------------------------------------------------------------------------------------             ##\033[36;0m\n";
    
 resup:   do{ 
        std::cout <<"\n\033[33;1m";
        std::cout <<"\t Voulez-vous faire la recherche de l'Article a SUPPRIMER via son ID ou via son LIBELLE? \n";
        std::cout <<"\t\t [1] - pour ID \n";
        std::cout <<"\t\t [2] - pour LIBELLE \n\n";
        std::cout <<"\t Votre choix:\033[33;0m \t";
        std::cin >> choixUtilisateur;
    } while (choix_non_valide(choixUtilisateur,choixValide));

    switch (choixUtilisateur.c_str()[0]){
        case '1': // recherche via id
            do{
                std::cout <<"\n";            
                std::cout <<"\t \033[33;1mEntrer l'ID:\033[33;0m \t";
                std::cin.ignore();
                std::cin.getline(id,MAX);
                _id = convertion1(id); 
            }while (_id<0);
            
            produit = gestionnaireArticle.chercher(_id);
            if (produit){
                std::cout <<"\n";
                std::cout << "\t\033[36;1m##--------------------------------------------------------------------------------------------------------------------------##\033[36;0m\n";            
                std::cout << "\033[32;1m\t     "<< produit->get().get_reference() <<"     \t"<< produit->get().get_libelle() <<"     \t\t"<< produit->get().get_prix() <<"     \t\t"<< produit->get().get_quantite() <<"     \t\t"<< produit->get().get_seuil() <<"\033[32;0m\n";                
                std::cout << "\t\033[36;1m##--------------------------------------------------------------------------------------------------------------------------##\033[36;0m\n"; 
                std::cout <<"\n";
                gestionnaireArticle.supprimer(_id);
            }else{
                std::cout << "\n";            
                std::cout << "\t\033[36;1m##--------------------------------------------------------------------------------------------------------------##\n";    
                std::cout << "\t##\033[36;0m                              \033[31;1mCET ARTICLE N'EXISTE PAS DANS NOTRE BASE DE DONNEES\033[31;0m                             \033[36;1m##\n";
                std::cout << "\t##--------------------------------------------------------------------------------------------------------------##\033[36;0m\n";    
            }
        break;
        case '2': // recherche via nom
            do{std::cout <<"\n";            
            std::cout <<"\t Entrer le LIBELLE \t";
            std::cin.ignore();
            std::cin.getline(nomR,MAX); 
            }while (strlen(nomR) == 0);
            liste =  gestionnaireArticle.liste_ayant_nom(majuscule(nomR).c_str());
            produit = liste.recup_tete(); 
            if (!liste.est_vide()){
                while (produit != liste.recup_sentinelle())
                {
                    std::cout <<"\n";
                    std::cout << "\t\033[36;1m##--------------------------------------------------------------------------------------------------------------------------##\033[36;0m\n";            
                    std::cout << "\033[32;1m\t     "<< produit->get().get_reference() <<"     \t"<< produit->get().get_libelle() <<"     \t\t"<< produit->get().get_prix() <<"     \t\t"<< produit->get().get_quantite() <<"     \t\t"<< produit->get().get_seuil() <<"\033[32;0m\n";                
                    std::cout << "\t\033[36;1m##--------------------------------------------------------------------------------------------------------------------------##\033[36;0m\n"; 
                    std::cout <<"\n";
                    produit = produit->get_next();
                }
                

                if(liste.recup_taille() != 1)goto resup;
                produit = liste.recup_tete();
                ref = produit->get().get_reference();
                gestionnaireArticle.supprimer(ref);
            }else{
                std::cout << "\n";            
                std::cout << "\t\033[36;1m##--------------------------------------------------------------------------------------------------------------##\n";    
                std::cout << "\t##\033[36;0m                              \033[31;1mCET ARTICLE N'EXISTE PAS DANS NOTRE BASE DE DONNEES\033[31;0m                             \033[36;1m##\n";
                std::cout << "\t##--------------------------------------------------------------------------------------------------------------##\033[36;0m\n";    
            }
        break;
    }

    do{
        std::cout <<"\t\033[33;1m Voulez-vous refaire une suppresion? \n";
        std::cout <<"\t [1] - pour OUI \n";
        std::cout <<"\t [0] - pour NON \n\n";
        std::cout <<"\t Entrer votre choix:\033[33;0m \t";
        std::cin >> ch;
    } while (choix_non_valide(ch,choixValide1));

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
};
    // suppression commande
void interface_suppression_commande(){
    // differentes variables a utiliser dans notre fonction
    std::string ch;
    char id[MAX];
    long long _id;
    typeId ref;
    int code;
    Cellule<Commande::Base> * com;
    std::string choixValide("01");

    // petit menu de presentation
    std::cout << "\t\033[36;1m##############################################################################################################\n";        
    std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
    std::cout << "\t##\033[36;0m                             \033[33;1mBIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL \033[33;0m                     \033[36;1m##\n";
    std::cout << "\t##                              ---------------------------------------------------                         ##\n";
    std::cout << "\t##                                     ---------------------------------                                    ##\n";
    std::cout << "\t##                                    |\033[36;0m   \033[32;1mSUPPRESSION D'UNE COMMANDE\033[32;0m    \033[36;1m|                                   ##\n";
    std::cout << "\t##                                      --------------------------------                                    ##\n";
    std::cout << "\t##                                                                                                          ##\n";
    std::cout << "\t##\033[36;0m                                \033[37;1mVeuillez suivre à la lettre les consigne !\033[37;0m                                \033[36;1m##\n";
    std::cout << "\t##                                        -----------------------                                           ##\n";
    std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
    std::cout << "\t##                                                                                                          ##\n";
    std::cout << "\t##         ------------------------------------------------------------------------------------             ##\033[36;0m\n";
        std::cin.ignore();
        do{
            std::cout <<"\n\033[33;1m";
            std::cout <<"\t Entrer l'ID de la Commande a supprimer:\033[33;0m \t";
            std::cin.getline(id,MAX);
            _id = convertion1(id);
        }while(_id<0);
        ref = _id;
        com = gestionnaireCommande.chercher(ref);
        code = annuler_commande(_id);
        switch(code){
        case CMD_PAS_TROUVER:
            std::cout << "\n";            
            std::cout << "\t\033[36;1m##-----------------------------------------------------------------------------------------------------------##\n";    
            std::cout << "\t##\033[36;0m                           \033[31;1mCETTE COMMANDE N'EXISTE PAS DANS NOTRE BASE DE DONNEES\033[31;0m                          \033[36;1m##\n";
            std::cout << "\t##-----------------------------------------------------------------------------------------------------------##\033[36;0m\n";
        break;
        case CMD_DEJA_LIVRER:
            std::cout << "\n";            
            std::cout << "\t\033[36;1m##-----------------------------------------------------------------------------------------------------------##\n";    
            std::cout << "\t##\033[36;0m                           \033[31;1mCETTE COMMANDE A DEJA ETE LIVRER\033[31;0m                          \033[36;1m##\n";
            std::cout << "\t##-----------------------------------------------------------------------------------------------------------##\033[36;0m\n";
        break;
        case CMD_DEJA_ANNULER:
            std::cout << "\n";            
            std::cout << "\t\033[36;1m##-----------------------------------------------------------------------------------------------------------##\n";    
            std::cout << "\t##\033[36;0m                           \033[31;1mCETTE COMMANDE A DEJA ANNULER\033[31;0m                          \033[36;1m##\n";
            std::cout << "\t##-----------------------------------------------------------------------------------------------------------##\033[36;0m\n";
        break;
        default: break;
        }
    

    do{
        std::cout <<"\t \033[33;1mVoulez-vous refaire une suppresion? \n";
        std::cout <<"\t [1] - pour OUI \n";
        std::cout <<"\t [0] - pour NON \n\n";
        std::cout <<"\t Entrer votre choix:\033[33;0m \t";
        std::cin >> ch;
    } while (choix_non_valide(ch,choixValide));

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
};
    // annulation livraison ----------------- pas terminé ------------------------
void interface_suppression_livraison(){
    // differentes variables a utiliser dans notre fonction
    std::string ch;
    int id;
    typeId ref;
    Cellule<Livraison::Base> * com;
    std::string choixValide("01");

    // petit menu de presentation
    std::cout << "\t\033[36;1m##############################################################################################################\n";        
    std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
    std::cout << "\t##\033[36;0m                             \033[33;1mBIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL \033[33;0m                     \033[36;1m##\n";
    std::cout << "\t##                              ---------------------------------------------------                         ##\n";
    std::cout << "\t##                                     ---------------------------------                                    ##\n";
    std::cout << "\t##                                    |\033[36;0m     \033[32;1mANNULlER UNE LIVRAISON\033[32;0m      \033[36;1m|                                   ##\n";
    std::cout << "\t##                                      --------------------------------                                    ##\n";
    std::cout << "\t##                                                                                                          ##\n";
    std::cout << "\t##\033[36;0m                                \033[37;1mVeuillez suivre à la lettre les consigne !\033[37;0m                                \033[36;1m##\n";
    std::cout << "\t##                                        -----------------------                                           ##\n";
    std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
    std::cout << "\t##                                                                                                          ##\n";
    std::cout << "\t##         ------------------------------------------------------------------------------------             ##\033[36;0m\n";
    
        std::cout <<"\n\033[33;1m";
        std::cout <<"\t Entrer l'ID de la livraison a annuller:\033[33;0m \t";
        std::cin >> id;
        ref = id;
        com = gestionnaireLivraison.chercher(ref);

    if (com){// test si la commande existe
        gestionnaireLivraison.supprimer(ref);
    }else{
        std::cout << "\n";            
        std::cout << "\t\033[36;1m##-----------------------------------------------------------------------------------------------------------##\n";    
        std::cout << "\t##\033[36;0m                          \033[31;1mCETTE LIVRAISON N'EXISTE PAS DANS NOTRE BASE DE DONNEES\033[31;0m                          \033[36;1m##\n";
        std::cout << "\t##-----------------------------------------------------------------------------------------------------------##\033[36;0m\n";
    }

    do{
        std::cout <<"\t \033[33;1mVoulez-vous refaire une suppresion? \n";
        std::cout <<"\t [1] - pour OUI \n";
        std::cout <<"\t [0] - pour NON \n\n";
        std::cout <<"\t Entrer votre choix:\033[33;0m \t";
        std::cin >> ch;
    } while (choix_non_valide(ch,choixValide));

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
};

// ------------------------------------------ Question 1.4: Recherche de données ---------------------------------
    // recherche client
void interface_recherche_client(){
    // differentes variables a utiliser dans notre fonction
    int _id;
    char id[MAX],nomR[MAX];
    std::string ch,choixValide("12"),choixValide1("01");
    Cellule<Client::Base> * personne ;
    Liste<Client::Base> liste;
    // petit menu de presentation
    std::cout << "\t\033[36;1m##############################################################################################################\n";    
    std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
    std::cout << "\t##\033[36;0m                               \033[33;1mBIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL\033[33;0m                    \033[36;1m##\n";
    std::cout << "\t##                                 ---------------------------------------------------                      ##\n";
    std::cout << "\t##                                         ---------------------------------                                ##\n";
    std::cout << "\t##                                        |\033[36;0m      \033[32;1mRECHERCHE D'UN CLIENT\033[32;0m      \033[36;1m|                               ##\n";
    std::cout << "\t##                                          --------------------------------                                ##\n";
    std::cout << "\t##                                                                                                          ##\n";
    std::cout << "\t##\033[36;0m                                    \033[32;1mVeuillez suivre à la lettre les consigne !\033[32;0m                            \033[36;1m##\n";
    std::cout << "\t##                                             -----------------------                                      ##\n";
    std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
    std::cout << "\t##                                                                                                          ##\n";
    std::cout << "\t##         ------------------------------------------------------------------------------------             ##\033[36;0m\n";
    
    do{ 
        std::cout <<"\n\033[33;1m";
        std::cout <<"\t Voulez-vous faire la recherche via ID ou via NOM? \n";
        std::cout <<"\t\t [1] - pour ID \n";
        std::cout <<"\t\t [2] - pour NON \n\n";
        std::cout <<"\t Votre choix:\033[33;0m \t";
        std::cin >> choixUtilisateur;
    } while (choix_non_valide(choixUtilisateur,choixValide));

    switch (choixUtilisateur.c_str()[0]){
        case '1': // recherche via id
            do{ std::cout <<"\n";            
                std::cout <<"\t \033[33;1mEntrer l'ID:\033[33;1m \t";
                std::cin.ignore();
                std::cin.getline( id,MAX);
                _id = convertion1(id);
            }while(_id<0);
            personne = gestionnaireClient.chercher_client(_id);
            if (personne){
                std::cout <<"\n";
                std::cout << "\t\033[36;1m##--------------------------------------------------------------------------------------------------------------------------##\033[36;0m\n";            
                std::cout << "\033[32;1m\t     "<< personne->get().get_numero() <<"     \t"<< personne->get().get_nom() <<"     \t\t"<< personne->get().get_prenom() <<"     \t\t"<< personne->get().get_date() <<"     \t\t"<< personne->get().get_sexe() <<"\033[32;0m\n";                    
                std::cout << "\t\033[36;1m##--------------------------------------------------------------------------------------------------------------------------##\033[36;0m\n";            

            }else{
                std::cout << "\n";            
                std::cout << "\t\033[36;1m##--------------------------------------------------------------------------------------------------------------##\n";    
                std::cout << "\t##\033[36;0m                            \033[31;1mCE CLIENT N'EXISTE PAS DANS NOTRE BASE DE DONNEES\033[31;0m                                 \033[36;1m##\n";
                std::cout << "\t##--------------------------------------------------------------------------------------------------------------##\033[36;0m\n";    
            }
        break;
        case '2': // recherche via nom
            do{std::cout <<"\n";            
            std::cout <<"\t\033[33;1m Entrer le NOM:\033[33;0m \t";
            std::cin.ignore();
            std::cin.getline(nomR,MAX);
            }while(strlen(nomR) == 0);
            liste = gestionnaireClient.liste_ayant_nom(majuscule(nomR).c_str());
            personne = liste.recup_tete();
            if (!liste.est_vide()){
                while(personne != liste.recup_sentinelle()){
                    std::cout <<"\n";
                    std::cout << "\t\033[36;1m##------------------------------------------------------------------------------------------------------##\033[36;0m\n";            
                    std::cout << "\t\033[37;1m     "<< personne->get().get_numero() <<"     \t"<< personne->get().get_nom() <<"     \t\t"<< personne->get().get_prenom() <<"     \t\t"<< personne->get().get_date() <<"     \t\t"<< personne->get().get_sexe() <<"\033[37;0m\n";                    
                    std::cout << "\t\033[36;1m##------------------------------------------------------------------------------------------------------##\033[36;0m\n";             
                    personne = personne->get_next();
                }
                   
            }else{
                std::cout <<"\n";            
                std::cout << "\t\033[36;1m##-------------------------------------------------------------------------------------------------------------##\n";    
                std::cout << "\t##\033[36;0m                      \033[31;1mCE CLIENT N'EXISTE PAS DANS NOTRE BASE DE DONNEES\033[31;0m                   \033[36;1m##\n";
                std::cout << "\t##--------------------------------------------------------------------------------------------------------------##\033[36;0m\n";    
            }
        break;
    };

    do{
        std::cout <<"\n\033[33;1m";            
        std::cout <<"\t Voulez-vous refaire une recherche? \n";
        std::cout <<"\t\t [1] - pour OUI \n";
        std::cout <<"\t\t [0] - pour NOM \n\n";
        std::cout <<"\t Votre choix:\033[36;0m \t";
        std::cin >> ch;
    } while (choix_non_valide(ch,choixValide1));

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
     
};
    // recherche article
void interface_recherche_article(){
    // differentes variables a utiliser dans notre fonction
    int id;
    std::string nomR,ch,choixValide("12"),choixValide1("01");
    Cellule<Article::Base> * produit;
    Liste<Article::Base> liste;
    // petit menu de presentation
    std::cout << "\t\033[36;1m##############################################################################################################\n";    
    std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
    std::cout << "\t##\033[36;0m                               \033[33;1mBIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL\033[33;0m                    \033[36;1m##\n";
    std::cout << "\t##                                 ---------------------------------------------------                      ##\n";
    std::cout << "\t##                                         ---------------------------------                                ##\n";
    std::cout << "\t##                                        |\033[36;0m     \033[32;1mRECHERCHE D'UN ARTICLE\033[32;0m      \033[36;1m|                               ##\n";
    std::cout << "\t##                                          --------------------------------                                ##\n";
    std::cout << "\t##                                                                                                          ##\n";
    std::cout << "\t##\033[36;0m                                    \033[32;1mVeuillez suivre à la lettre les consigne !\033[32;0m                            \033[36;1m##\n";
    std::cout << "\t##                                             -----------------------                                      ##\n";
    std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
    std::cout << "\t##                                                                                                          ##\n";
    std::cout << "\t##         ------------------------------------------------------------------------------------             ##\033[36;0m\n";
    

     do{ 
        std::cout <<"\n\033[33;1m";
        std::cout <<"\t Voulez-vous faire la recherche via ID ou via LIBELLE? \n";
        std::cout <<"\t\t [1] - pour ID \n";
        std::cout <<"\t\t [2] - pour LIBELLE \n\n";
        std::cout <<"\t Votre choix:\033[33;0m \t";
        std::cin >> choixUtilisateur;
    } while (choix_non_valide(choixUtilisateur,choixValide));

    switch (choixUtilisateur.c_str()[0]){
        case '1': // recherche via id
            std::cout <<"\n";            
            std::cout <<"\t \033[33;1mEntrer l'ID:\033[33;1m \t";
            std::cin >> id;
            produit = gestionnaireArticle.chercher(id);
            if (produit){
                std::cout <<"\n";
                std::cout << "\t\033[36;1m##------------------------------------------------------------------------------------------------------##\033[36;0m\n";            
                std::cout << "\033[37;1m\t     "<< produit->get().get_reference() <<"     \t"<< produit->get().get_libelle() <<"     \t\t"<< produit->get().get_prix() <<"     \t\t"<< produit->get().get_quantite() <<"     \t\t"<< produit->get().get_seuil() <<"\033[37;0m\n";                    
                std::cout << "\t\033[36;1m##------------------------------------------------------------------------------------------------------##\033[36;0m\n";            

            }else{
                std::cout << "\n";            
                std::cout << "\t\033[36;1m##--------------------------------------------------------------------------------------------------------------##\n";    
                std::cout << "\t##\033[36;0m                                \033[31;1mCET ARTICLE N'EXISTE PAS DANS NOTRE BASE DE DONNEES\033[31;0m                           \033[36;1m##\n";
                std::cout << "\t##--------------------------------------------------------------------------------------------------------------##\033[36;0m\n";    
            }
        break;
        case '2': // recherche via nom
            std::cout <<"\n";            
            std::cout <<"\t 033[33;1mEntrer le LIBELLE:033[33;0m \t";
            std::cin >> nomR;
            liste = gestionnaireArticle.liste_ayant_nom(majuscule(nomR).c_str());
            produit = liste.recup_tete();
            if(liste.est_vide()){
                std::cout << "\n";            
                std::cout << "\t\033[36;1m##--------------------------------------------------------------------------------------------------------------##\n";    
                std::cout << "\t##\033[36;0m                                 \033[31;1mCET ARTICLE N'EXISTE PAS DANS NOTRE BASE DE DONNEES\033[31;0m                          \033[36;1m##\n";
                std::cout << "\t##--------------------------------------------------------------------------------------------------------------##\033[36;0m\n";    
            }else{
                while(produit != liste.recup_sentinelle()){
                    std::cout <<"\n";
                    std::cout << "\t\033[36;1m##------------------------------------------------------------------------------------------------------##\033[36;0m\n";            
                    std::cout << "\033[37;1m\t     "<< produit->get().get_reference() <<"     \t"<< produit->get().get_libelle() <<"     \t\t"<< produit->get().get_prix() <<"     \t\t"<< produit->get().get_quantite() <<"     \t\t"<< produit->get().get_seuil() <<"\033[37;0m\n";                    
                    std::cout << "\t\033[36;1m##------------------------------------------------------------------------------------------------------##\033[36;0m\n";
                    produit = produit->get_next();
                }
            }
            
        break;
    };

    do{
        std::cout <<"\t \033[33;1mVoulez-vous faire une nouvelle recherche? \n";
        std::cout <<"\t [1] - pour OUI \n";
        std::cout <<"\t [0] - pour NON \n";
        std::cout <<"\t Entrer votre choix:\033[33;0m \t";

        std::cin >> ch;
    } while (choix_non_valide(choixUtilisateur,choixValide1));

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
};
    // recherche commande
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
    std::string reponce3, choixValide1("01");

    const char * etat1 = "Livree";
    const char * etat2 = "En Cour...";
    bool s;
    // petit menu de presentation
    std::cout << "\t\033[36;1m##############################################################################################################\n";    
    std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
    std::cout << "\t##\033[36;0m                               \033[33;1mBIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL\033[33;0m                    \033[36;1m##\n";
    std::cout << "\t##                                 ---------------------------------------------------                      ##\n";
    std::cout << "\t##                                         ---------------------------------                                ##\n";
    std::cout << "\t##                                        |\033[36;0m    \033[32;1mRECHERCHE D'UNE COMMANDE\033[32;0m     \033[36;1m|                               ##\n";
    std::cout << "\t##                                          --------------------------------                                ##\n";
    std::cout << "\t##                                                                                                          ##\n";
    std::cout << "\t##\033[36;0m                                    \033[32;1mVeuillez suivre à la lettre les consigne !\033[32;0m                            \033[36;1m##\n";
    std::cout << "\t##                                             -----------------------                                      ##\n";
    std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
    std::cout << "\t##                                                                                                          ##\n";
    std::cout << "\t##         ------------------------------------------------------------------------------------             ##\033[36;0m\n";
    
        std::cout <<"\n";
        std::cout <<"\t \033[33;1mEntrer l'ID de la Commande a recherche: \n";
        std::cout <<"\t Votre choix:\033[33;0m \t";
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
                std::cout << "\t\033[36;1m##---------------------------------------------------------------------------------------##\033[36;0m\n";            
                std::cout << "\033[37;1m\t     "<< com->get().ref() <<"     \t"<< reponce1 <<"   \t "<< reponce3 <<"     \t\t"<< reponce2<<"     \t\t"<<com->get().nombre() <<"\033[37;0m\n";
                std::cout << "\t\033[36;1m##---------------------------------------------------------------------------------------##\033[36;0m\n\ns";            

            }else{
                std::cout << "\n";            
                std::cout << "\t\033[36;1m##-------------------------------------------------------------------------------------------------------------##\n";    
                std::cout << "\t##\033[36;0m                             \033[31;1mCETTE COMMANDE N'EXISTE PAS DANS NOTRE BASE DE DONNEES\033[31;0m                          \033[36;1m##\n";
                std::cout << "\t##-------------------------------------------------------------------------------------------------------------##\033[36;0m\n";    
            }

    do{
        std::cout <<"\t \033[31;1mVoulez-vous faire une nouvelle recherche? \n";
        std::cout <<"\t [1] - pour OUI \n";
        std::cout <<"\t [0] - pour NON \n";
        std::cout <<"\t Entrer votre choix: \033[33;0m\t";

        std::cin >> ch;
    } while (choix_non_valide(choixUtilisateur,choixValide1));

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
};
    // recherche commande --------------------- pas terminé ---------------------
void interface_recherche_livraison(){
    // differentes variables a utiliser dans notre fonction
    int id;
    typeId ref;
    std::string ch;
    Cellule<Livraison::Base> * com;
    std::string nomR;     
    std::string reponce1;
    std::string reponce2;
    std::string reponce3, choixValide1("01");

    // petit menu de presentation
    std::cout << "\t\033[36;1m##############################################################################################################\n";    
    std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
    std::cout << "\t##\033[36;0m                               \033[33;1mBIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL\033[33;0m                    \033[36;1m##\n";
    std::cout << "\t##                                 ---------------------------------------------------                      ##\n";
    std::cout << "\t##                                         ---------------------------------                                ##\n";
    std::cout << "\t##                                        |\033[36;0m   \033[32;1mRECHERCHE D'UNE LIVRAISON\033[32;0m     \033[36;1m|                               ##\n";
    std::cout << "\t##                                          --------------------------------                                ##\n";
    std::cout << "\t##                                                                                                          ##\n";
    std::cout << "\t##\033[36;0m                                    \033[32;1mVeuillez suivre à la lettre les consigne !\033[32;0m                            \033[36;1m##\n";
    std::cout << "\t##                                             -----------------------                                      ##\n";
    std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
    std::cout << "\t##                                                                                                          ##\n";
    std::cout << "\t##         ------------------------------------------------------------------------------------             ##\033[36;0m\n";
    
        std::cout <<"\n";
        std::cout <<"\t \033[33;1mEntrer l'ID de la Livraison a recherche: \n";
        std::cout <<"\t Votre choix:\033[33;0m \t";
        std::cin >> id;
            ref = id;
            com = gestionnaireLivraison.chercher(ref);
            if (com){


                std::cout <<"\n";
                std::cout << "\t\033[36;1m##---------------------------------------------------------------------------------------##\033[36;0m\n";            
                std::cout << "\033[37;1m\t     "<< com->get().ref() <<"     \t"<< reponce1 <<"   \t "<< reponce3 <<"     \t\t"<< reponce2<<"     \t\t"<<com->get().nombre() <<"\033[37;0m\n";
                std::cout << "\t\033[36;1m##---------------------------------------------------------------------------------------##\033[36;0m\n\ns";            

            }else{
                std::cout << "\n";            
                std::cout << "\t\033[36;1m##-------------------------------------------------------------------------------------------------------------##\n";    
                std::cout << "\t##\033[36;0m                            \033[31;1mCETTE LIVRAISON N'EXISTE PAS DANS NOTRE BASE DE DONNEES\033[31;0m                          \033[36;1m##\n";
                std::cout << "\t##-------------------------------------------------------------------------------------------------------------##\033[36;0m\n";    
            }

    do{
        std::cout <<"\t \033[31;1mVoulez-vous faire une nouvelle recherche? \n";
        std::cout <<"\t [1] - pour OUI \n";
        std::cout <<"\t [0] - pour NON \n";
        std::cout <<"\t Entrer votre choix: \033[33;0m\t";

        std::cin >> ch;
    } while (choix_non_valide(choixUtilisateur,choixValide1));

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
};

// ---------------------------------------- pas terminé -------------------

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
    std::string choixValide("01"), choixValide1("12");

    // petit menu de presentation
    std::cout << "\t\033[36;1m##############################################################################################################\n";    
    std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
    std::cout << "\t##\033[36;0m                          \033[33;1mBIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL\033[33;0m                         \033[36;1m##\n";
    std::cout << "\t##                           ----------------------------------------------------                           ##\n";
    std::cout << "\t##                                    ---------------------------------                                     ##\n";
    std::cout << "\t##                                   |\033[36;0m    \033[32;1mMODIFICATION D'UN ARTICLE\033[32;0m    |                                    \033[36;1m##\n";
    std::cout << "\t##                                    ---------------------------------                                     ##\n";
    std::cout << "\t##                                                                                                          ##\n";
    std::cout << "\t##\033[36;0m                              \033[32;1mVeuillez suivre à la lettre les consigne !\033[32;0m                                  \033[36;1m##\n";
    std::cout << "\t##                                -------------------------------------                                     ##\n";
    std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
    std::cout << "\t##                                                                                                          ##\n";
    std::cout << "\t##         ------------------------------------------------------------------------------------             ##\033[36;0m\n";
 do{ 
        std::cout <<"\n";
        std::cout <<"\t \033[33;1mVoulez-vous faire la recherche de l'Article a modifier via son ID ou via son LIBELLE? \n";
        std::cout <<"\t\t [1] - pour ID \n";
        std::cout <<"\t\t [2] - pour LIBELLE \n\n";
        std::cout <<"\t Votre choix:\033[33;0m \t";
        std::cin >> choixUtilisateur;
    } while (choix_non_valide(choixUtilisateur,choixValide1));

    switch (choixUtilisateur.c_str()[0]){
        case '1': // recherche via id
            std::cout <<"\n";            
            std::cout <<"\t \033[33;1mEntrer l'ID:\033[33;0m \t";
            std::cin >> id;
            produit = gestionnaireArticle.chercher(id);
            if (produit){
                std::cout <<"\n";
                std::cout << "\t\033[36;1m##------------------------------------------------------------------------------------------------------##\033[36;0m\n";            
                std::cout << "\t\033[37;1m     "<< produit->get().get_reference() <<"     \t"<< produit->get().get_libelle() <<"     \t\t"<< produit->get().get_prix() <<"     \t\t"<<produit->get().get_quantite() <<"     \t\t"<<produit->get().get_seuil() <<"\033[37;0m\n";                
                std::cout << "\t\033[36;1m##------------------------------------------------------------------------------------------------------##\033[36;0m\n"; 

                std::cout <<"\n";
                ref = id;
                std::cout << "\t\033[33;1m Entrer le Libelle de l'Article :\033[33;0m\t";
                std::cin >>nomArticle;
                std::cout << "\t \033[33;1mEntrer le prix unitaire de l'article :\033[33;0m\t";
                std::cin >>prixArticle;
                std::cout << "\t \033[33;1mEntrer la quantite de l'Article :\033[33;0m\t";
                std::cin >> quantite;
                std::cout << "\t \033[33;1mEntrer le seuil :\033[33;0m\t";
                std::cin >> seuil;

                gestionnaireArticle.mettre_a_jour(ref, nomArticle.c_str(),prixArticle,quantite,seuil);
            }else{
                std::cout << "\n";            
                std::cout << "\t\033[36;1m##-----------------------------------------------------------------------------------------------------------##\n";    
                std::cout << "\t##\033[36;0m                               \033[31;1mCET ARTICLE N'EXISTE PAS DANS NOTRE BASE DE DONNEES\033[31;0m                         \033[36;1m##\n";
                std::cout << "\t##-----------------------------------------------------------------------------------------------------------##\033[36;0m\n";    
            }
        break;
        case '2': // recherche via nom
            std::cout <<"\n";            
            std::cout <<"\t \033[33;1mEntrer le NOM:\033[33;0m \t";
            std::cin >> nomR;
            produit = gestionnaireArticle.chercher(nomR.c_str());
            if (produit){
                std::cout <<"\n";
                std::cout << "\t\033[36;1m##------------------------------------------------------------------------------------------------------##\033[36;0m\n";            
                std::cout << "\t\033[37;1m     "<< produit->get().get_reference() <<"     \t"<< produit->get().get_libelle() <<"     \t\t"<< produit->get().get_prix() <<"     \t\t"<<produit->get().get_quantite() <<"     \t\t"<<produit->get().get_seuil() <<"\033[37;0m\n";                
                std::cout << "\t\033[36;1m##------------------------------------------------------------------------------------------------------##\033[36;0m\n"; 

                std::cout <<"\n";
                ref = produit->get().get_reference();
                std::cout << "\t\033[33;1m Entrer le Libelle de l'Article :\033[33;0m\t";
                std::cin >>nomArticle;
                std::cout << "\t \033[33;1mEntrer le prix unitaire de l'article :\033[33;0m\t";
                std::cin >>prixArticle;
                std::cout << "\t \033[33;1mEntrer la quantite de l'Article :\033[33;0m\t";
                std::cin >> quantite;
                std::cout << "\t \033[33;1mEntrer le seuil :\033[33;0m\t";
                std::cin >> seuil;

                gestionnaireArticle.mettre_a_jour(ref, nomArticle.c_str(),prixArticle,quantite,seuil);       
            }else{
                std::cout << "\n";            
                std::cout << "\t\033[36;1m##-----------------------------------------------------------------------------------------------------------##\n";    
                std::cout << "\t##\033[36;0m                               \033[31;1mCET ARTICLE N'EXISTE PAS DANS NOTRE BASE DE DONNEES\033[31;0m                         \033[36;1m##\n";
                std::cout << "\t##-----------------------------------------------------------------------------------------------------------##\033[36;0m\n";    
            }
        break;
    };
    do{
        std::cout <<"\t\033[33;1m Voulez-vous faire une nouvelle modification? \n";
        std::cout <<"\t [1] - pour OUI \n";
        std::cout <<"\t [0] - pour NON \n";
        std::cout <<"\t Votre choix:\033[33;0m\t";
        std::cin >> choixUtilisateur;
    } while (choix_non_valide(choixUtilisateur,choixValide));

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

};

// modification client
void interface_modif_client(){
    // differentes variables a utiliser dans notre fonction
    char nom[MAX],prenom[MAX], nomR[MAX];
    Date::Date date;
    std::string sexe;
    int _id;
    char id[MAX];
    typeId identifiant;
    std::string ch;
    Cellule<Client::Base> * personne ;
    Liste<Client::Base> liste;
    std::string choixValide("12"),choixValide1("01"),sexeValide("FM");
    
        // petit menu de presentation
    std::cout << "\t\033[36;1m##############################################################################################################\n";    
    std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
    std::cout << "\t##\033[36;0m                          \033[33;1mBIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL\033[33;0m                         \033[36;1m##\n";
    std::cout << "\t##                           ----------------------------------------------------                           ##\n";
    std::cout << "\t##                                    ---------------------------------                                     ##\n";
    std::cout << "\t##                                   |\033[36;0m    \033[32;1mMODIFICATION D'UN CLIENT \033[32;0m    |                                    \033[36;1m##\n";
    std::cout << "\t##                                    ---------------------------------                                     ##\n";
    std::cout << "\t##                                                                                                          ##\n";
    std::cout << "\t##\033[36;0m                              \033[32;1mVeuillez suivre à la lettre les consigne !\033[32;0m                                  \033[36;1m##\n";
    std::cout << "\t##                                -------------------------------------                                     ##\n";
    std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
    std::cout << "\t##                                                                                                          ##\n";
    std::cout << "\t##         ------------------------------------------------------------------------------------             ##\033[36;0m\n";

        
ench:    do{ 
        std::cout <<"\n";
        std::cout <<"\t \033[33;1mVoulez-vous faire la recherche du CLIENT a modifier via son ID ou via son NOM? \n";
        std::cout <<"\t\t [1] - pour ID \n";
        std::cout <<"\t\t [2] - pour NOM \n\n";
        std::cout <<"\t Votre choix:\033[33;0m \t";
        std::cin >> choixUtilisateur;
    } while (choix_non_valide(choixUtilisateur,choixValide));

    switch (choixUtilisateur.c_str()[0]){
        case '1': // recherche via id
            std::cin.ignore();
            do{
                std::cout <<"\n";            
                std::cout <<"\t \033[33;1mEntrer l'ID:\033[33;0m \t";
                std::cin.getline(id,MAX);
                _id = convertion1(id);
            }while (_id < 0);
            
            
            
            personne = gestionnaireClient.chercher_client(_id);
            if (personne){
                std::cout <<"\n";
                std::cout << "\t\033[36;1m##------------------------------------------------------------------------------------------------------##\033[36;0m\n";            
                std::cout << "\033[31;1m\t     "<< personne->get().get_numero() <<"     \t"<< personne->get().get_nom() <<"     \t\t"<< personne->get().get_prenom() <<"     \t\t"<< personne->get().get_date() <<"     \t\t"<< personne->get().get_sexe() <<"\033[31;0m\n";                
                std::cout << "\t\033[36;1m##------------------------------------------------------------------------------------------------------##\033[36;0m\n"; 

                std::cout <<"\n";
                identifiant = _id;
                do{ std::cout << "\t\033[33;1m Entrer NOM Client :\033[33;0m\t";
                    std::cin.getline(nom,MAX);
                }while(strlen(nom) == 0);
                std::cout << "\t \033[33;1mEntrer PRENOM Client :\033[33;0m\t";
                std::cin.getline(prenom,MAX);
                std::cout << "\t \033[33;1mEntrer DATE NAISSANCE Client:\033[33;0m\t";

                date = Date::recup_date("\t\\033[32;1mt","Date invalide","Jour:","Jour invalide","Mois:","Mois invalide","Annee:","Annee invalide\033[32;0m");
                do{std::cout << "\t \033[33;1mEntrer SEXE Client(M/F) :\033[33;0m\t";
                std::cin >> sexe;
                }while (choix_non_valide(sexe,sexeValide));
                
                gestionnaireClient.mettre_a_jour_client(identifiant,majuscule(nom).c_str(),majuscule(prenom).c_str(),date,sexe.c_str());
            }else{
                std::cout << "\n";            
                std::cout << "\t\033[36;1m##--------------------------------------------------------------------------------------------------------------##\n";    
                std::cout << "\t##\033[36;0m                                  \033[31;1mCE CLIENT N'EXISTE PAS DANS NOTRE BASE DE DONNEES\033[31;0m                           \033[36;1m##\n";
                std::cout << "\t##--------------------------------------------------------------------------------------------------------------##\033[36;0m\n";    
            }
        break;
        case '2': // recherche via nom
            std::cout <<"\n";            
            std::cout <<"\t \033[33;1mEntrer le NOM:\033[33;0m \t";
            std::cin.getline(nomR,MAX);

            liste = gestionnaireClient.liste_ayant_nom(majuscule(nomR).c_str());
            personne = liste.recup_tete();
            if (!liste.est_vide()){
                while (personne != liste.recup_sentinelle())
                {
                    std::cout <<"\n";
                    std::cout << "\t\033[36;1m##------------------------------------------------------------------------------------------------------##\033[36;0m\n";            
                    std::cout << "\033[37;1m\t     "<< personne->get().get_numero() <<"     \t"<< personne->get().get_nom() <<"     \t\t"<< personne->get().get_prenom() <<"     \t\t"<< personne->get().get_date() <<"     \t\t"<< personne->get().get_sexe() <<"\033[37;0m\n";                    
                    std::cout << "\t\033[36;1m##------------------------------------------------------------------------------------------------------##\033[36;0m\n"; 

                    personne = personne->get_next();
                }
                if(liste.recup_taille() != 1) goto ench;
                personne = liste.recup_tete();
                std::cout <<"\n";
                identifiant = personne->get().get_numero();
                                
                do{ std::cout << "\t\033[33;1m Entrer NOM Client :\033[33;0m\t";
                    std::cin.getline(nom,MAX);
                }while(strlen(nom) == 0);
                std::cout << "\t \033[33;1mEntrer PRENOM Client :\033[33;0m\t";
                std::cin.getline(prenom,MAX);
                std::cout << "\t \033[33;1mEntrer DATE NAISSANCE Client:\033[33;0m\t";
                date = Date::recup_date("\t\\033[32;1mt","Date invalide","Jour:","Jour invalide","Mois:","Mois invalide","Annee:","Annee invalide\033[32;0m");
                do{std::cout << "\t \033[33;1mEntrer SEXE Client(M/F) :\033[33;0m\t";
                std::cin >> sexe;
                }while (choix_non_valide(sexe,sexeValide));
                
                gestionnaireClient.mettre_a_jour_client(identifiant,majuscule(nom).c_str(),majuscule(prenom).c_str(),date,sexe.c_str());
                               
            }else{
                std::cout <<"\n";            
                std::cout << "\t\033[36;1m##--------------------------------------------------------------------------------------------------------------##\n";    
                std::cout << "\t##\033[36;0m                      \033[31;1mCE CLIENT N'EXISTE PAS DANS NOTRE BASE DE DONNEES\033[31;0m                   \033[36;1m##\n";
                std::cout << "\t##--------------------------------------------------------------------------------------------------------------##\033[36;0m\n";    
            }
        break;
    };
    choixValide.clear();
    choixValide.append("01");
    do{
        std::cout <<"\n";            
        std::cout <<"\t \033[33;1mVoulez-vous refaire une nouvelle Modification? \n";
        std::cout <<"\t\t     [1] - pour OUI \n";
        std::cout <<"\t\t     [0] - pour NON \n\n";
        std::cout <<"\t Votre choix:\033[33;0m \t";
        std::cin >> choixUtilisateur;
    } while (choix_non_valide(choixUtilisateur,choixValide1));

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

void interface_modif_commande(){
    // differentes variables a utiliser dans notre fonction
    typeId idClient;
    typeId idArticle;
    typeId ref;
    int _id,_idC,_idA;
    char quantite[MAX],idC[MAX],id[MAX],idA[MAX];
    
    Cellule<Client::Base> * personne ;       
    std::string choixU;
    std::string nomA;
    Cellule<Article::Base> * produit;
    Cellule<Commande::Base> * com;
    // differentes variables a utiliser dans notre fonction
    
    long long _quantite; 
    std::string ch;  
    const char * message = "Effacer";
    std::string reponce1;
    std::string reponce2;
    std::string reponce3;

    std::string choixValide("01");
    const char * etat2 = "Livree";
    const char * etat1 = "En Cour...";
    const char * etat3 = "En cour Livraison";
    const char * etat4 = "Annuler";
  

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
        
        std::cin.ignore();
recommencerD:        do{std::cout <<"\n";
        std::cout <<"\t Entrer l'ID de la Commande dont vous voulez apporter des modification:\t";
        
        std::cin.getline(id,MAX);
        _id = convertion1(id);
        }while(_id<0);
        if(_id == 0 && strlen(id)== 0)goto recommencerD;
            ref = _id;
            
        

        com = gestionnaireCommande.chercher(ref);
            if (com){
                idClient = com->get().ref_client();
                idArticle = com->get().ref_article();
                personne = gestionnaireClient.chercher_client(idClient);
                reponce1.append((personne)? personne->get().get_nom():message);
                produit = gestionnaireArticle.chercher(idArticle);
                reponce2.append((produit)? produit->get().get_libelle().c_str():message);
                switch(com->get().status()){
                    case Commande::ENCOUR:
                        reponce3 = etat1;
                    break;
                    case Commande::ENCOURLIVRAISON:
                        reponce3 = etat2;
                    break;
                    case Commande::TERMINER:
                        reponce3 = etat3;
                        std::cout << "\n";            
                            std::cout << "\t##------------------------------------------------------------------------------------------##\n";    
                            std::cout << "\t##                   COMMANDE TERMINER NON MODIFIABLE                    ##\n";
                            std::cout << "\t##------------------------------------------------------------------------------------------##\n";
                    break;
                    case Commande::ANNULER:
                        reponce3 = etat4;
                        std::cout << "\n";            
                            std::cout << "\t##------------------------------------------------------------------------------------------##\n";    
                            std::cout << "\t##                   COMMANDE ANNULER NON MODIFIABLE                    ##\n";
                            std::cout << "\t##------------------------------------------------------------------------------------------##\n";
                    break;
                }
                std::cout <<"\n";

                std::cout << "\t##---------------------------------------------------------------------------------------##\n";            
                std::cout << "\t##\t     "<< com->get().ref() <<"   \t"<< reponce1 <<"   \t "<< reponce3 <<"     \t"<< reponce2<<"    \t"<<com->get().nombre() <<"\n";
                std::cout << "\t##---------------------------------------------------------------------------------------##\n\n";  
                 // recuperation de l'ID du produit
                if(com->get().status() == Commande::ANNULER || com->get().status() == Commande::TERMINER)goto finmodifC;    
            a2:     
                    
                    do{
                        std::cout << "\n";
                        std::cout << "\t Entrer l'ID du client, Rien pour passer:\t";  
                        std::cin.getline(idC,MAX);
                        _idC = convertion1(idC);
                    }while(_idC < 0);
                    if(_idC == 0 && strlen(idC) == 0){
                        personne = gestionnaireClient.chercher_client(com->get().ref_client());
                    }
                    else{
                        personne = gestionnaireClient.chercher_client(_idC);
                    }
                    if (personne){
                        idClient =  personne->get().get_numero(); // recuperation de l'ID du produit
            a1:         
                        do{
                            std::cout << "\n";
                            std::cout << "\t Entrer l'ID de l'Article, Rien Pour Passer:\t";  
                            std::cin.getline(idA,MAX);
                            _idA = convertion1(idA);
                        }while(_idA < 0);
                        if(_idA == 0 && strlen(idA) == 0){
                            produit = gestionnaireArticle.chercher(com->get().ref_article());
                        }else{
                            produit = gestionnaireArticle.chercher(_idA);
                        }
                        
                        if (produit)
                        {
                            idArticle = produit->get().get_reference();// recuperation de l'id du produit 
                           
                           do{ std::cout << "\n";
                            std::cout << "\t Entrer la Quantite de l'Article a commander:\t";  
                            std::cin.getline( quantite,MAX);
                            _quantite = convertion1(quantite);
                           }while(_quantite < 0);   
                           modifier_commande(ref,idClient,idArticle,_quantite);
                        }else{
                            std::cout << "\n";            
                            std::cout << "\t\033[36;1m##-------------------------------------------------------------------------------------------------------------------##\n";    
                            std::cout << "\t##\033[36;0m                                \033[31;1mCET ARTICLE N'EXISTE PAS DANS NOTRE BASE DE DONNEES\033[31;0m                           \033[36;1m##\n";
                            std::cout << "\t##-------------------------------------------------------------------------------------------------------------------##\033[36;0m\n"; 
                            do{
                                std::cout << " \n ";
                                std::cout <<"\t \033[33;1mVoulez-vous ANNULER les modification ou CHANGER l'article de la commande? \n";
                                std::cout <<"\t [1] - pour CHANGER \n";
                                std::cout <<"\t [0] - pour ANNULER \n";
                                std::cout <<"\t Votre choix:\033[33;0m \t";
                                std::cin >> choixUtilisateur;

                            } while (choix_non_valide(choixUtilisateur,choixValide));

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
finmodifC:                            do{
                                std::cout << " \n ";
                                std::cout <<"\t \033[33;1mVoulez-vous ANNULER les modification ou CHANGER le client de la commande? \n";
                                std::cout <<"\t [1] - pour CHANGER \n";
                                std::cout <<"\t [0] - pour ANNULER \n";
                                std::cout <<"\t Votre choix: \033[33;0m\t";
                                std::cin >> choixUtilisateur;

                            } while (choix_non_valide(choixUtilisateur,choixValide));

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
                         
                    
                }else
                {
                    std::cout << "\n";            
                    std::cout << "\t\033[36;1m##---------------------------------------------------------------------------------------------------------------##\n";    
                    std::cout << "\t##\033[36;0m                            \033[31;1mCETTE COMMANDE N'EXISTE PAS DANS NOTRE BASE DE DONNEES\033[31;0m                             \033[36;1m##\n";
                    std::cout << "\t##---------------------------------------------------------------------------------------------------------------##\033[36;1m\n";
                }
            
    do{
        std::cout << " \n ";
        std::cout <<"\t Voulez-vous faire une nouvelle modification? \n";
        std::cout <<"\t [1] - pour OUI \n";
        std::cout <<"\t [0] - pour NON \n";
        std::cout <<"\t Votre choix:\033[33;0m \t";
        std::cin >> choixUtilisateur;

    } while (choix_non_valide(choixUtilisateur,choixValide));

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





// Question 2 pas terminé
void interface_article_achete_par_un_client(){
    // differentes variables a utiliser dans notre fonction
    std::string ch;
    std::string choixValide1("12"),choixValide2("01");
    int _id;
    char id[MAX],nomR[MAX];
    Cellule<Client::Base> * personne ;
    Liste<Client::Base> liste;
    // petit menu de presentation
    std::cout << "\t\033[36;1m##############################################################################################################\n";       
    std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
    std::cout << "\t##\033[36;0m                        \033[33;1mBIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL\033[33;0sm                          \033[36;1m##\n";
    std::cout << "\t##                           ------------------------------------------------                               ##\n";
    std::cout << "\t##                           ------------------------------------------------                               ##\n";
    std::cout << "\t##                          |\033[36;0m   \033[32;1mLISTE ARTICLE ACHETE PAR UN CLIENT \033[32;0m           \033[36;1m|                              ##\n";
    std::cout << "\t##                           ------------------------------------------------                               ##\n";
    std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
    std::cout << "\t##      ----------------------------------------------------------------------------------------------      ##\n\033[36;0m";
    std::cout << "\n"; 

    do{ 
        std::cout <<"\n\033[33;1m";
        std::cout <<"\t Voulez-vous faire la recherche via ID ou via NOM du client dont on veut les articles achete? \n";
        std::cout <<"\t\t [1] - pour ID \n";
        std::cout <<"\t\t [2] - pour NOM\n\n";
        std::cout <<"\t Votre choix:\033[33;0m \t";
        std::cin >> choixUtilisateur;
    } while (choix_non_valide(choixUtilisateur,choixValide1));

    switch (choixUtilisateur.c_str()[0]){
        case '1': // recherche via id
            do{
                std::cout <<"\n";            
                std::cout <<"\t\033[33;1m Entrer l'ID:\033[33;0m \t";
                std::cin.ignore();
                std::cin.getline( id,MAX);
                _id = convertion1(id);
            }while(_id<0);
            personne = gestionnaireClient.chercher_client(_id);
            if(personne){
                // fonction de recherche ici

            }else{
                std::cout << "\n";            
                std::cout << "\t\033[36;1m##--------------------------------------------------------------------------------------------------------------##\n";    
                std::cout << "\t##\033[36;0m                            \033[31;1mCE CLIENT N'EXISTE PAS DANS NOTRE BASE DE DONNEES\033[31;0m                                 \033[36;1m##\n";
                std::cout << "\t##--------------------------------------------------------------------------------------------------------------##\033[36;0m\n";   
            }
            break;

        case '2': // recherche via nom
            do{std::cout <<"\n";            
                std::cout <<"\t\033[33;1m Entrer le NOM:\033[33;0m \t";
                std::cin.ignore();
                std::cin.getline(nomR,MAX);
            }while(strlen(nomR) == 0);
            liste = gestionnaireClient.liste_ayant_nom(majuscule(nomR).c_str());
            personne = liste.recup_tete();
            if (!liste.est_vide()){
                // fonction ici
                /*
                while(personne != liste.recup_sentinelle()){
                    std::cout <<"\n";
                    std::cout << "\t\033[36;1m##------------------------------------------------------------------------------------------------------##\033[36;0m\n";            
                    std::cout << "\t\033[37;1m     "<< personne->get().get_numero() <<"     \t"<< personne->get().get_nom() <<"     \t\t"<< personne->get().get_prenom() <<"     \t\t"<< personne->get().get_date() <<"     \t\t"<< personne->get().get_sexe() <<"\033[37;0m\n";                    
                    std::cout << "\t\033[36;1m##------------------------------------------------------------------------------------------------------##\033[36;0m\n";             
                    personne = personne->get_next();
                }
                   */
            }else{
                std::cout <<"\n";            
                std::cout << "\t\033[36;1m##-------------------------------------------------------------------------------------------------------------##\n";    
                std::cout << "\t##\033[36;0m                      \033[31;1mCE CLIENT N'EXISTE PAS DANS NOTRE BASE DE DONNEES\033[31;0m                   \033[36;1m##\n";
                std::cout << "\t##--------------------------------------------------------------------------------------------------------------##\033[36;0m\n";    
            }
            
        break;
    };

    do{
        std::cout <<"\t \033[33;1mTapez: \n";
        std::cout <<"\t      [1] - pour RETOUR AU MENU \n";
        std::cout <<"\t      [0]- pour RETOUR AU MENU PRINCIPAL \n\n";
        std::cout <<"\t Entrer votre choix:\033[33;0m \t";
        std::cin >> ch;
    } while (choix_non_valide(ch,choixValide2));

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

// Question 3 pas terminé
void interface_liste_client_article(){
    // differentes variables a utiliser dans notre fonction
    std::string ch, nomR;
    std::string choixValide1("12"),choixValide2("01");
    typeId id;
    // petit menu de presentation
    std::cout << "\t\033[36;1m##############################################################################################################\n";       
    std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
    std::cout << "\t##\033[36;0m                        \033[33;1mBIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL\033[33;0sm                          \033[36;1m##\n";
    std::cout << "\t##                           ------------------------------------------------                               ##\n";
    std::cout << "\t##                           ------------------------------------------------                               ##\n";
    std::cout << "\t##                          |\033[36;0m             \033[32;1mCLIENT D'UN ARTICLE     \033[32;0m           \033[36;1m|                              ##\n";
    std::cout << "\t##                           ------------------------------------------------                               ##\n";
    std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
    std::cout << "\t##      ----------------------------------------------------------------------------------------------      ##\n\033[36;0m";
    std::cout << "\n"; 

    do{ 
        std::cout <<"\n\033[33;1m";
        std::cout <<"\t Voulez-vous faire la recherche via ID ou via LIBELLE de l'aricle dont on veut les client? \n";
        std::cout <<"\t\t [1] - pour ID \n";
        std::cout <<"\t\t [2] - pour LIBELLE \n\n";
        std::cout <<"\t Votre choix:\033[33;0m \t";
        std::cin >> choixUtilisateur;
    } while (choix_non_valide(choixUtilisateur,choixValide1));

    switch (choixUtilisateur.c_str()[0]){
        case '1': // recherche via id
            std::cout <<"\n";            
            std::cout <<"\t\033[33;1m Entrer l'ID:\033[33;0m \t";
            std::cin >> id;
            // fonction de recherche ici
            /*
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
            }*/
        break;
        case '2': // recherche via nom
            std::cout <<"\n";            
            std::cout <<"\t \033[33;1mEntrer le LIBELLE:\033[33;0m \t";
            std::cin >> nomR;
            // fonction de recherche ici
            /*
            liste = gestionnaireArticle.liste_ayant_nom(majuscule(nomR).c_str());
            produit = liste.recup_tete();
            if(liste.est_vide()){
                std::cout << "\n";            
                std::cout << "\t##------------------------------------------------------------------------------------------##\n";    
                std::cout << "\t##                     CET ARTICLE N'EXISTE PAS DANS NOTRE BASE DE DONNEES                   ##\n";
                std::cout << "\t##------------------------------------------------------------------------------------------##\n";    
            }else{
                while(produit != liste.recup_sentinelle()){
                    std::cout <<"\n";
                    std::cout << "\t##------------------------------------------------------------------------------------------------------##\n";            
                    std::cout << "\t##\t     "<< produit->get().get_reference() <<"     \t"<< produit->get().get_libelle() <<"     \t\t"<< produit->get().get_prix() <<"     \t\t"<< produit->get().get_quantite() <<"     \t\t"<< produit->get().get_seuil() <<"\t##\n";                    
                    std::cout << "\t##------------------------------------------------------------------------------------------------------##\n";
                    produit = produit->get_next();
                }
            }*/
            
        break;
    };

    do{
        std::cout <<"\t \033[33;1mTapez: \n";
        std::cout <<"\t      [1] - pour RETOUR AU MENU \n";
        std::cout <<"\t      [0]- pour RETOUR AU MENU PRINCIPAL \n\n";
        std::cout <<"\t Entrer votre choix:\033[33;0m \t";
        std::cin >> ch;
    } while (choix_non_valide(ch,choixValide2));

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
    // Question 4 terminé
void interface_commande_client(){
    // differentes variables a utiliser dans notre fonction
    std::string ch;
    typeId idClient;
    Liste<Commande::Base> liste;
    Cellule<Client::Base> * p ;
    Cellule<Commande::Base> * com;
    Cellule<Article::Base> * article;
    std::string choixValide1("01");
    // petit menu de presentation
    std::cout << "\t\033[36;1m##############################################################################################################\n";       
    std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
    std::cout << "\t##\033[36;0m                        \033[33;1mBIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL\033[33;0sm                          \033[36;1m##\n";
    std::cout << "\t##                           ------------------------------------------------                               ##\n";
    std::cout << "\t##                           ------------------------------------------------                               ##\n";
    std::cout << "\t##                          |\033[36;0m        \033[32;1mCOMMANDE EN COURS D'UN CLIENT\033[32;0m           \033[36;1m|                              ##\n";
    std::cout << "\t##                           ------------------------------------------------                               ##\n";
    std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
    std::cout << "\t##      ----------------------------------------------------------------------------------------------      ##\n\033[36;0m";  

    std::cout << "\n";
    std::cout << "\t\033[36;1m##\033[36;0m  \033[33;1mEntrer l'ID du Client:\033[33;0m\t";
    std::cin >> idClient; // cas des char a gerer

    p = gestionnaireClient.chercher_client(idClient);

    if (p){
        liste = gestionnaireCommande.commandes_encour_de(idClient);
        if (liste.est_vide()){
            std::cout << "\n\n\n";
            std::cout << "\t\033[36;1m##----------------------------------------------------------------------------------------------------------##\n";
            std::cout << "\t##\033[36;0m                                       \033[33;1mPAS DE COMMANDE POUR CE CLIENT\033[33;0m                                     \033[36;1m##\n";       
            std::cout << "\t##----------------------------------------------------------------------------------------------------------##\033[36;0m\n";
        }else{
            std::cout << "\n\n";
            std::cout << "\t##\033[36;0m                  \033[37;1mID\033[37;0m             \033[36;1m|\033[36;0m     \033[37;1mNOM CLIENT\033[37;0m     \033[36;1m|\033[36;0m       \033[37;1mARTICLE\033[37;0m       \033[36;1m|\033[36;0m           \033[37;1mQUANTITE\033[37;0m          \033[36;1m##\n";
            std::cout << "\t\033[36;1m##----------------------------------------------------------------------------------------------------------##\n";
            std::cout << "\t##----------------------------------------------------------------------------------------------------------##\033[36;0m\n";
            com = liste.recup_tete();
            while ( com != liste.recup_sentinelle()){   
                article = gestionnaireArticle.chercher(com->get().ref_article());
                if(article){
                std::cout << "\t##\t\033[32;1m            "<< com->get().ref() <<" \t\t\t"<< p->get().get_nom() <<"   \t\t"<< article->get().get_libelle() <<"\t\t\t"<< com->get().nombre() <<" \033[32;0m\n";                                    
                std::cout << "\t\033[36;1m##----------------------------------------------------------------------------------------------------------##\033[36;0m\n";
                }else{
                    std::cout << "\t##\t\033[32;1m            "<< com->get().ref() <<" \t\t\t"<< p->get().get_nom() <<"    \t\t"<< com->get().ref_article() <<"\t\t\t"<< com->get().nombre() <<" \033[32;0m\n";                                    
                    std::cout << "\t\033[36;1m##----------------------------------------------------------------------------------------------------------##\033[36;0m\n";
                }
                
                com = com->get_next();
            }  
        }
        
    }else{
        std::cout << "\n\n\n";
        std::cout << "\t\033[36;1m##----------------------------------------------------------------------------------------------------------##\n";
        std::cout << "\t##\033[36;0m                                           \033[33;1mCE CLIENT N'EXISTE PAS\033[33;0m                                         \033[36;1m##\n";       
        std::cout << "\t##----------------------------------------------------------------------------------------------------------##\033[36;0m\n";       
    }

    do{
        std::cout <<"\t \033[33;1mTapez: \n";
        std::cout <<"\t      [1] - pour RETOUR AU MENU \n";
        std::cout <<"\t      [0]- pour RETOUR AU MENU PRINCIPAL \n\n";
        std::cout <<"\t Entrer votre choix:\033[33;0m \t";
        std::cin >> ch;
    } while (choix_non_valide(ch,choixValide1));

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
    // Question 5 pas terminé
void interface_statistique(){
    // differentes variables a utiliser dans notre fonction
    std::string ch;
    Cellule<Article::Base> * p ;
    std::string choixValide1("01");
    // petit menu de presentation
    std::cout << "\t\033[36;1m##############################################################################################################\n";       
    std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
    std::cout << "\t##\033[36;0m                        \033[33;1mBIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL\033[33;0sm                          \033[36;1m##\n";
    std::cout << "\t##                           ------------------------------------------------                               ##\n";
    std::cout << "\t##                           ------------------------------------------------                               ##\n";
    std::cout << "\t##                          |\033[36;0m                  \033[32;1mSTATISTIQUES       \033[32;0m            \033[36;1m|                             ##\n";
    std::cout << "\t##                            -----------------------------------------------                               ##\n";
    std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
    std::cout << "\t##      ----------------------------------------------------------------------------------------------      ##\n\033[36;0m";  

    p = gestionnaireArticle.recup_tete();
    if(gestionnaireArticle.est_vide()){
        std::cout << "\n\n\n";
        std::cout << "\t\033[36;1m##----------------------------------------------------------------------------------------------------------##\n";
        std::cout << "\t##\033[36;0m                            \033[33;1mAUCUNE DONNEE DISPONIBLE\033[33;0m                                      \033[36;1m##\n";       
        std::cout << "\t##----------------------------------------------------------------------------------------------------------##\033[36;0m\n";       
    }else
    {   
        std::cout << "\t##\033[36;0m                          \033[37;1mARTICLE\033[37;0m                    \033[36;1m|\033[36;0m                           \033[37;1mPRIX UNITAIRE           \033[37;0m \033[36;1m##\n";
        std::cout << "\t\033[36;1m##----------------------------------------------------------------------------------------------------------##\n";            
        std::cout << "\t##----------------------------------------------------------------------------------------------------------##\033[36;0m\n";
        while ( p != gestionnaireArticle.recup_sentinelle())
        {
            std::cout << "\t##\033[32;1m                        \t"<< p->get().get_libelle() <<"   \t\t\t\t"<< p->get().get_prix() <<"\033[32;0m\n"; 
            std::cout << "\t\033[36;1m##----------------------------------------------------------------------------------------------------------##\033[36;0m\n";

            p = p->get_next();
        }   
    } 

    do{
        std::cout <<"\t \033[33;1mTapez: \n";
        std::cout <<"\t      [1] - pour RETOUR AU MENU \n";
        std::cout <<"\t      [0] - pour RETOUR AU MENU PRINCIPAL \n\n";
        std::cout <<"\t Entrer votre choix:\033[33;0m \t";
        std::cin >> ch;
    } while (choix_non_valide(ch,choixValide1));

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
    // Question 6 terminé
void interface_article_prix_unitaire(){
    // differentes variables a utiliser dans notre fonction
    std::string ch;
    Cellule<Article::Base> * p ;
    std::string choixValide1("01");
    // petit menu de presentation
    std::cout << "\t\033[36;1m##############################################################################################################\n";       
    std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
    std::cout << "\t##\033[36;0m                        \033[33;1mBIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL\033[33;0sm                          \033[36;1m##\n";
    std::cout << "\t##                           ------------------------------------------------                               ##\n";
    std::cout << "\t##                           ------------------------------------------------                               ##\n";
    std::cout << "\t##                          |\033[36;0m             \033[32;1mARTICLE ET PRIX UNITAIRE\033[32;0m            \033[36;1m|                             ##\n";
    std::cout << "\t##                            -----------------------------------------------                               ##\n";
    std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
    std::cout << "\t##      ----------------------------------------------------------------------------------------------      ##\n\033[36;0m";  

    p = gestionnaireArticle.recup_tete();
    if(gestionnaireArticle.est_vide()){
        std::cout << "\n\n\n";
        std::cout << "\t\033[36;1m##----------------------------------------------------------------------------------------------------------##\n";
        std::cout << "\t##\033[36;0m                            \033[33;1mPAS D'ARTICLE DISPONIBLE\033[33;0m                                      \033[36;1m##\n";       
        std::cout << "\t##----------------------------------------------------------------------------------------------------------##\033[36;0m\n";       
    }else
    {   
        std::cout << "\t##\033[36;0m                          \033[37;1mARTICLE\033[37;0m                    \033[36;1m|\033[36;0m                           \033[37;1mPRIX UNITAIRE           \033[37;0m \033[36;1m##\n";
        std::cout << "\t\033[36;1m##----------------------------------------------------------------------------------------------------------##\n";            
        std::cout << "\t##----------------------------------------------------------------------------------------------------------##\033[36;0m\n";
        while ( p != gestionnaireArticle.recup_sentinelle())
        {
            std::cout << "\t##\033[32;1m                        \t"<< p->get().get_libelle() <<"   \t\t\t\t"<< p->get().get_prix() <<"\033[32;0m\n"; 
            std::cout << "\t\033[36;1m##----------------------------------------------------------------------------------------------------------##\033[36;0m\n";

            p = p->get_next();
        }   
    } 

    do{
        std::cout <<"\t \033[33;1mTapez: \n";
        std::cout <<"\t      [1] - pour RETOUR AU MENU \n";
        std::cout <<"\t      [0] - pour RETOUR AU MENU PRINCIPAL \n\n";
        std::cout <<"\t Entrer votre choix:\033[33;0m \t";
        std::cin >> ch;
    } while (choix_non_valide(ch,choixValide1));

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
    // Question 7 terminé
void interface_quantite_a_ravitailler(){
    // differentes variables a utiliser dans notre fonction
    std::string ch;
    Liste<Article::Base> liste;
    Cellule<Article::Base> * p ;
    std::string choixValide1("01");
    // petit menu de presentation
    std::cout << "\t\033[36;1m##############################################################################################################\n";       
    std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
    std::cout << "\t##\033[36;0m                        \033[33;1mBIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL\033[33;0sm                          \033[36;1m##\n";
    std::cout << "\t##                           ------------------------------------------------                               ##\n";
    std::cout << "\t##                           ------------------------------------------------                               ##\n";
    std::cout << "\t##                          |\033[36;0m              \033[32;1mARTICLE A RAVITAILLER\033[32;0m             \033[36;1m|                              ##\n";
    std::cout << "\t##                            -----------------------------------------------                               ##\n";
    std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
    std::cout << "\t##      ----------------------------------------------------------------------------------------------      ##\n\033[36;0m";  

    liste = gestionnaireArticle.critiques();
    
    if(liste.est_vide()){
        std::cout << "\n\n\n";
        std::cout << "\t\033[36;1m##----------------------------------------------------------------------------------------------------------##\n";
        std::cout << "\t##\033[36;0m                                 \033[33;1mPAS D'ARTICLE A RAVITAILLER POUR LE MOMENT\033[33;0m                               \033[36;1m##\n";       
        std::cout << "\t##----------------------------------------------------------------------------------------------------------##\033[36;0m\n";       
    }else
    {   std::cout << "\n\n\n";
        std::cout << "\t##\033[36;0m                       \033[37;1mID\033[37;0m                    \033[36;1m|\033[36;0m            \033[37;1mARTICLE\033[37;0m                   \033[36;1m\n";
        std::cout << "\t##----------------------------------------------------------------------------------------------------------##\n";       
        std::cout << "\t##----------------------------------------------------------------------------------------------------------##\033[36;0m\n";       
        p = liste.recup_tete();
        while ( p != liste.recup_sentinelle())
        {
            std::cout << "\t##\t\033[32;1m              \t"<< p->get().get_reference() <<"   \t\t\t\t\t"<< p->get().get_libelle() <<"\033[32;0m\n";                                    
            p = p->get_next();
        }   
    } 

    do{
        std::cout <<"\t \033[33;1mTapez: \n";
        std::cout <<"\t      [1] - pour RETOUR AU MENU \n";
        std::cout <<"\t      [0] - pour RETOUR AU MENU PRINCIPAL \n\n";
        std::cout <<"\t Entrer votre choix:\033[33;0m \t";
        std::cin >> ch;
    } while (choix_non_valide(ch,choixValide1));

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
    // Question 8 terminé
void interface_capital(){
    // differentes variables a utiliser dans notre fonction
    std::string ch;
    long double capital;
    std::string choixValide1("01");

    capital = gestionnaireArticle.capital();
    // petit menu de presentation
    std::cout << "\t\033[36;1m##############################################################################################################\n";       
    std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
    std::cout << "\t##\033[36;0m                        \033[33;1mBIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL\033[33;0sm                          \033[36;1m##\n";
    std::cout << "\t##                           ------------------------------------------------                               ##\n";
    std::cout << "\t##                           ------------------------------------------------                               ##\n";
    std::cout << "\t##                          |\033[36;0m                     \033[32;1mCAPITAL\033[32;0m                    \033[36;1m|                              ##\n";
    std::cout << "\t##                            -----------------------------------------------                               ##\n";
    std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
    std::cout << "\t##      ----------------------------------------------------------------------------------------------      ##\n";  
    std::cout << "\t\t\t\033[36;0m                                \033[33;1m" << std::fixed << capital <<" Frs CFA\033[33;0m\n\033[36;1m";   
    std::cout << "\t##      ----------------------------------------------------------------------------------------------      ##\n";
    std::cout << "\t##                                                                                                          ##\n";    
    std::cout << "\t##############################################################################################################\033[36;0m\n\n";    

    do{
        std::cout <<"\t \033[33;1mTapez: \n";
        std::cout <<"\t      [1] - pour RETOUR AU MENU \n";
        std::cout <<"\t      [0] - pour RETOUR AU MENU PRINCIPAL \n\n";
        std::cout <<"\t Entrer votre choix:\033[33;0m \t";
        std::cin >> ch;
    } while (choix_non_valide(ch,choixValide1));

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
    // Question 9 terminé
void interface_meilleur_client(){
    // differentes variables a utiliser dans notre fonction
    std::string ch;
    Cellule<Article::Base> * produit;
    Cellule<Client::Base> * client;
    typeId idArticle;
    typeId idClient;
    const char * message1 = "CLIENT SUPPRIMER";
    const char * message2 = "PAS DE MEILLEUR CLIENT";
    std::string choixValide1("01");

    // petit menu de presentation
    std::cout << "\t\033[36;1m##############################################################################################################\n";    
    std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
    std::cout << "\t##\033[36;0m                        \033[33;1mBIENVENUE DANS LE LOGICIEL DE GESTION DU SUPERMARCHE XL\033[33;0m                           \033[36;1m##\n";
    std::cout << "\t##                           ------------------------------------------------                               ##\n";
    std::cout << "\t##                           ------------------------------------------------                               ##\n";
    std::cout << "\t##                          |\033[36;0m                \033[32;1mMEILLEURS CLIENTS\033[32;0m               \033[36;1m|                              ##\n";
    std::cout << "\t##                           ------------------------------------------------                               ##\n";
    std::cout << "\t##                                                                                                          ##\n";
    std::cout << "\t##-_-_-                                                                                                -_-_-##\n";
    std::cout << "\t##         ---------------------------------------------------------------------------------------          ##\n\n\n";


    produit = gestionnaireArticle.recup_tete();
    std::cout << "\t##\033[36;0m                \033[37;1mNom de l'Article\033[37;0m                    \033[36;1m|\033[36;0m            \033[37;1mNom du meilleur Client\033[37;0m                   \033[36;1m##\n";
    std::cout << "\t##----------------------------------------------------------------------------------------------------------##\n";            
    std::cout << "\t##----------------------------------------------------------------------------------------------------------##\033[36;0m\n";
        while (produit != gestionnaireArticle.recup_sentinelle())
        {   idArticle = produit->get().get_reference() ;
            idClient = meilleur_client_de(idArticle);
            if (idClient){
                client = gestionnaireClient.chercher_client(idClient);
                if (client){ // Meilleur client existant et dans liste de client
                    std::cout << "\t##\t\033[32;1m              \t"<< produit->get().get_libelle() <<"   \t\t\t\t\t"<< client->get().get_nom() <<"\033[32;0m\n";                        
                }else{ // Meilleur client existant mais supprimer de la liste des client
                    std::cout << "\t##\t\033[32;1m               \t"<< produit->get().get_libelle() <<"   \t\t\t\t\t"<< message1 <<"\033[32;0m\n";
                }     
            }else{ // pas de meilleur client
                std::cout << "\t##\t\033[32;1m               \t"<< produit->get().get_libelle() <<"   \t\t\t\t\t"<< message2 <<"\033[32;0m\n";                
            }
    std::cout << "\t\033[36;1m##----------------------------------------------------------------------------------------------------------##\033[36;0m\n";            
        produit = produit->get_next();
        }  

    do{ 
        std::cout <<"\n\033[33;1m";
        std::cout <<"\t Tapez: \n";
        std::cout <<"\t      [1] - pour RETOUR AU MENU \n";
        std::cout <<"\t      [0] - pour RETOUR AU MENU PRINCIPAL \n\n";
        std::cout <<"\t Entrer votre choix: \t\033[33;0m";
        std::cin >> ch;
    } while (choix_non_valide(ch,choixValide1));

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
