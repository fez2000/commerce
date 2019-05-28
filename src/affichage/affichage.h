#ifndef AFFICHAGE_H_INCLUDE
#define AFFICHAGE_H_INCLUDE
#include "../Client/Client.h"
#include "../Commande/Commande.h"
#include "../Article/Article.h"
#include "../Livraison/Livraison.h"
#include "../relations/relations.h"
#include "../fonctions/fonctions.h"

    void acceuil();// fonction qui affiche le menu d'acceuil
    void autre_fonction(); // second menu d'acceuil
    void menu_general_client(); // acceuil client
    
    void menu_general_livraison(); // acceuil livraison
    void interface_recherche_client(); // recherche client
    void interface_suppression_client(); // suppression client
    int choix_enregistrement();
    void interface_creation_client(); // creation client
    void interface_liste_client(); // liste des clients
    void interface_modif_client(); // modification client
    // menu article

    void menu_general_article(); // acceuil article
    void interface_creation_article();
    void interface_suppression_article();
    void interface_recherche_article();
    void interface_liste_article();
    void interface_modif_article();

    void interface_meilleur_client();
    void interface_capital();
    void interface_liste_client_article();

    void menu_general_commande(); // acceuil commande
    void interface_creation_commande();
    void interface_liste_commande();
    void interface_suppression_commande();
    void interface_recherche_commande();
    void interface_modif_commande();

    void interface_creation_livraison();
    void interface_liste_livaison();

    void interface_quantite_a_ravitailler();
    void interface_article_prix_unitaire();
    void interface_commande_client();

#endif