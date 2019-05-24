#include "relations.h"

Client::Client  gestionClient;
Article::Article  gestionArticle;
Livraison::Livraison gestionLivraison;
Commande::Commande gestionCommande;

/*
    @name: client_article
    @brief: cette fonction donne la liste de client d'un article;
    @params: idArticles id de l'article dont on veut les clients 
    @return: retourne une liste de cleint s'il y a des clients ou une liste vide
*/

Liste<Client::Base> client_article(unsigned long idArticle){
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

/*
    @name: article_client
    @brief: cette fonction donne la liste des article achete par un client 
    @params: idClient id du client dont on veut les articles 
    @return: retourne une liste d'article s'il y a des articles ou une liste vide
*/
Liste<Article::Base> article_client(unsigned long idClient){
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

/*

*/
int commander_article(const char * nomClient ,const char * libelle, unsigned long quantite){
    Cellule<Client::Base> * pc = gestionClient.chercher_client(nomClient);
    if(pc == NULL){
        return CLIENT_PAS_TROUVER;
    }
    Cellule<Article::Base> * pa = gestionArticle.chercher(libelle);
    if(pa == NULL){
        return ARTICLE_PAS_TROUVER;
    }
    if(pa->get().tester_quantite(quantite) < 0){
        return PAS_SUFFISANT;
    }
    pa->get().ajouter_quantite(-quantite);
    int code = gestionCommande.creer(pc->get().get_numero(),pa->get().get_reference(),quantite);
    if(code == ERROR_CODE){
        return ERREUR_SYSTEME;
    }
    code = gestionLivraison.creer(code,pc->get().get_numero(),quantite);
    if(code == ERROR_CODE){
        return ERREUR_SYSTEME;
    }
    return PAS_DERREUR;
};
int annuler_commande(typeId id){
     Cellule <Commande::Base> * c = gestionCommande.chercher(id);
     if(!c){
         return CMD_PAS_TROUVER;
     }
     if(c->get().status() == Commande::ANNULER){
         return CMD_DEJA_ANNULER;
     }
     if(c->get().status() == Commande::LIVRER){
         return CMD_DEJA_LIVRER;
     }
     int code = gestionCommande.annuler(id);
    if( code  != SUCCESS_CODE){
        return code;
    };
    Cellule<Livraison::Base> * l = gestionLivraison.livraisons_apropos(c->get().ref());
    if(!l){
        return LIVRAISON_PAS_TROUVER;
    }
    return gestionLivraison.supprimer(l->get().ref());
}

