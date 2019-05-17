#include <iostream>
#include "fonctions.h"
#include <math.h>


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
    @name: client_article
    @brief: cette fonction donne la liste de client d'un article;
    @params: idArticles id de l'article dont on veut les clients 
    @return: retourne une liste de cleint s'il y a des clients ou une liste vide
*/

/*Liste<Client::Base> client_article(unsigned long idArticle){
    Liste<Client::Base> clients;
    Liste<Commande::Base> cmds = gestionCommande.commandes_pour(idArticle);
    if(!cmds.est_vide()){
        Cellule<Commande::Base> * i = cmds.recup_tete();
        while ( i!=cmds.recup_sentinelle())
        {
            clients.ajouter_trie(gestionClient.chercher_client(i->get().ref()));
        }
        
    }
    return clients;
};
*/
/*
    @name: article_client
    @brief: cette fonction donne la liste des article achete par un client 
    @params: idClient id du client dont on veut les articles 
    @return: retourne une liste d'article s'il y a des articles ou une liste vide
*/
/*Liste<Article::Base> article_client(unsigned long idClient){
    Liste<Article::Base> article;
    Liste<Commande::Base>  cmds = gestionCommande.commandes_de(idClient);
    if(!cmds.est_vide()){
        Cellule<Commande::Base> * i = cmds.recup_tete();
        while ( i!=cmds.recup_sentinelle())
        {
            article.ajouter_trie(gestionArticle.chercher(i->get().ref()));
        }
    }
    return article;
}
*/
