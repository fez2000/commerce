#ifndef FONCTIONS_H_INCLUDE
#define FONCTIONS_H_INCLUDE
#include <iostream>
#include <fstream>
#include <string>
#define ERROR_CODE 0
#define SUCCESS_CODE 1

typedef unsigned long typeId;
enum {PAS_DERREUR,PAS_TROUVER,PAS_UN_NOMBRE,ID_INVALID,PAS_SUFFISANT,ARTICLE_PAS_TROUVER,CLIENT_PAS_TROUVER, CMD_PAS_TROUVER, LIVRAISON_PAS_TROUVER, ERREUR_SYSTEME, CMD_DEJA_ANNULER,CMD_DEJA_LIVRER};
    bool est_premier(long );
    long prochain_nb_premier(long);
    void acceuil();// fonction qui affiche le menu d'acceuil
    void autre_fonction(); // second menu d'acceuil
    void menu_general_client(); // acceuil client
    
    void menu_general_commande(); // acceuil commande
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

    std::ostream& serialiser(std::ostream &os, const std::string &s);
    std::istream& deserialiser(std::istream &is, std::string &s);
    bool is_affirmatif(const char *);
#endif