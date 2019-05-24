#ifndef AFFICHAGE_H_INCLUDE
#define AFFICHAGE_H_INCLUDE
#include "../Client/Client.h"
#include "../Commande/Commande.h"
#include "../Article/Article.h"
#include "../Livraison/Livraison.h"
#include "../relations/relations.h"
#include "../fonctions/fonctions.h"

void acceuil();// fonction qui affiche le menu d'acceuil
void menu_general_client(); // acceuil client
void menu_general_article(); // acceuil article
void menu_general_commande(); // acceuil commande
void menu_general_livraison(); // acceuil livraison
void interface_recherche_client();
int choix_enregistrement();
void interface_creation_client();
void interface_modi_client();

void affiche_client_console( Client::Base );
void affiche_article_console(Article::Base);
void affiche_livraison_console(Livraison::Base);
void affiche_commande_console(Commande::Base);

#endif