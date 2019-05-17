#ifndef FONCTIONS_H_INCLUDE
#define FONCTIONS_H_INCLUDE
#include <fstream>
#include <string>
#include "../Liste/Liste.h"


/*
Client::Client  gestionClient;
Article::Article  gestionArticle;
Livraison::Livraison gestionLivraison;
Commande::Commande gestionCommande;

Liste<Client::Base> client_article(unsigned long);
Liste<Article::Base> article_client(unsigned long);
*/
    bool est_premier(long );
    long prochain_nb_premier(long);
    std::ostream& serialiser(std::ostream &os, const std::string &s);
    std::istream& deserialiser(std::istream &is, std::string &s);

#endif