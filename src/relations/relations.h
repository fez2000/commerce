#ifndef RELATIONS
#define RELATIONS
#include "../Client/Clients.h"
#include "../Article/Articles.h"
#include "../Article/Articles.h"
#include "../Commande/Commandes.h"
#include "../Livraison/Livraisons.h"

Liste<Client::Base> client_article(typeId);
Liste<Article::Base> article_client(typeId);
int commander_article(const char *,const char *, unsigned long);
int commander_article(typeId,typeId, unsigned long);
int commander_article(const char *,typeId, unsigned long); 
int commander_article(typeId,const char *, unsigned long);
int annuler_commande(typeId id);
#endif