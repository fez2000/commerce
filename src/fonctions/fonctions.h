#ifndef FONCTIONS_H_INCLUDE
#define FONCTIONS_H_INCLUDE
#include <iostream>
#include <fstream>
#include <string>
#include <cstdarg>
#define ERROR_CODE 0
#define SUCCESS_CODE 1
enum  { PAS_DERREUR,PAS_TROUVER,PAS_UN_NOMBRE,ID_INVALID,PAS_SUFFISANT,ARTICLE_PAS_TROUVER,CLIENT_PAS_TROUVER, CMD_PAS_TROUVER, LIVRAISON_PAS_TROUVER, ERREUR_SYSTEME, CMD_DEJA_ANNULER,CMD_DEJA_LIVRER,ERREUR_FIC_LANG };
typedef unsigned long typeId;
std::string cat_many(int , ...);
    bool est_premier(long );
    long prochain_nb_premier(long);
    void acceuil();// fonction qui affiche le menu d'acceuil
    void menu_general_client(); // acceuil client
    void menu_general_article(); // acceuil article
    void menu_general_commande(); // acceuil commande
    void menu_general_livraison(); // acceuil livraison
    void interface_recherche_client();
    int choix_enregistrement();
    void interface_creation_client();
    void interface_modi_client();

    std::ostream& serialiser(std::ostream &os, const std::string &s);
    std::istream& deserialiser(std::istream &is, std::string &s);
    bool is_affirmatif(const char *);
#endif