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
    std::ostream& serialiser(std::ostream &os, const std::string &s);
    std::istream& deserialiser(std::istream &is, std::string &s);
    bool is_affirmatif(const char *);
#endif