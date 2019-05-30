#include "relations.h"
#include <map>
Article::Article  gestionnaireArticle;
Livraison::Livraison gestionnaireLivraison;
Commande::Commande gestionnaireCommande;
Client::Client gestionnaireClient;

/*
    @name: client_article
    @brief: cette fonction donne la liste de client d'un article;
    @params: idArticles id de l'article dont on veut les clients 
    @return: retourne une liste de cleint s'il y a des clients ou une liste vide
*/

Liste<Client::Base> client_article(unsigned long idArticle){
    Liste<Client::Base> clients;
    Liste<Commande::Base> cmds = gestionnaireCommande.commandes_pour(idArticle);
    if(!cmds.est_vide()){
        Cellule<Commande::Base> * i = cmds.recup_tete();
        while ( i!=cmds.recup_sentinelle())
        {
            clients.ajouter_trie(gestionnaireClient.chercher_client(i->get().ref()));
            i = i->get_next();
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
    Liste<Commande::Base>  cmds = gestionnaireCommande.commandes_de(idClient);
    if(!cmds.est_vide()){
        Cellule<Commande::Base> * i = cmds.recup_tete();
        while ( i!=cmds.recup_sentinelle())
        {
            article.ajouter_trie(gestionnaireArticle.chercher(i->get().ref()));
            i = i->get_next();
        }
    }
    return article;
}

int modifier_commande(typeId idCommande, typeId idClient, typeId idArticle, unsigned long quantite){
    Cellule<Commande::Base> * p = gestionnaireCommande.chercher(idCommande);
    if( p == NULL)return CMD_PAS_TROUVER;
    Cellule<Client::Base> * pc = gestionnaireClient.chercher_client(idClient);
    if(pc == NULL)return CLIENT_PAS_TROUVER;
    Cellule<Client::Base> * pa = gestionnaireClient.chercher_client(p->get().ref_client());
    if(pa == NULL){
        return ARTICLE_PAS_TROUVER;
    }    
    if(p->get().ref_article() != idArticle){
        Cellule<Article::Base> * pa = gestionnaireArticle.chercher(p->get().ref_article());
        if(pa == NULL){
            return ARTICLE_PAS_TROUVER;
        }else{
            Cellule<Article::Base> * pa = gestionnaireArticle.chercher(idArticle);
             if((pa->get().get_quantite()-quantite + 0.0)<0){
                return PAS_SUFFISANT; 
             } 
            int code = gestionnaireArticle.mettre_a_jour(pa->get().get_reference(),pa->get().get_libelle().c_str(),pa->get().get_prix(),pa->get().get_quantite()-quantite,pa->get().get_seuil());
            if(code == ERROR_CODE){
                return ERREUR_SYSTEME;
            }
             pa = gestionnaireArticle.chercher(p->get().ref_article());
             code = gestionnaireArticle.mettre_a_jour(pa->get().get_reference(),pa->get().get_libelle().c_str(),pa->get().get_prix(),pa->get().get_quantite() + p->get().nombre(),pa->get().get_seuil());
            if(code == ERROR_CODE){
                return ERREUR_SYSTEME;
            }
           
    
        }
    }else{
        Cellule<Article::Base> * pa = gestionnaireArticle.chercher(idArticle);
            if((pa->get().get_quantite() + p->get().nombre()-quantite + 0.0)<0){
                return PAS_SUFFISANT;
            }
            int code = gestionnaireArticle.mettre_a_jour(idArticle,pa->get().get_libelle().c_str(),pa->get().get_prix(), pa->get().get_quantite() + p->get().nombre()-quantite,pa->get().get_seuil());
            if(code == ERROR_CODE){
                return ERREUR_SYSTEME;
            }
        
        
    }
    return gestionnaireCommande.modifier(idCommande,idClient,idArticle,quantite,p->get().status());    
    
}

/*

*/
int commander_article(typeId idClient,typeId idArticle, unsigned long quantite){
    Cellule<Client::Base> * pc = gestionnaireClient.chercher_client(idClient);
    Cellule<Article::Base> * pa = gestionnaireArticle.chercher(idArticle);

    if(pa->get().tester_quantite(quantite) < 0){
        return PAS_SUFFISANT;
    }
    int code = gestionnaireArticle.mettre_a_jour(idArticle,pa->get().get_libelle().c_str(),pa->get().get_prix(),pa->get().get_quantite()-quantite,pa->get().get_seuil());
    if(code == ERROR_CODE){
        return ERREUR_SYSTEME;
    }
    code = gestionnaireCommande.creer(pc->get().get_numero(),pa->get().get_reference(),quantite);
    if(code == ERROR_CODE){
        return ERREUR_SYSTEME;
    }
    return PAS_DERREUR;
};
int commander_article(const char * nomClient ,const char * libelle, unsigned long quantite){
    Cellule<Client::Base> * pc = gestionnaireClient.chercher_client(nomClient);
    if(pc == NULL){
        return CLIENT_PAS_TROUVER;
    }
    Cellule<Article::Base> * pa = gestionnaireArticle.chercher(libelle);
    if(pa == NULL){
        return ARTICLE_PAS_TROUVER;
    }
    if(pa->get().tester_quantite(quantite) < 0){
        return PAS_SUFFISANT;
    }
    pa->get().ajouter_quantite(-quantite);
    int code = gestionnaireCommande.creer(pc->get().get_numero(),pa->get().get_reference(),quantite);
    if(code == ERROR_CODE){
        return ERREUR_SYSTEME;
    }
    return PAS_DERREUR;
};
int supprimer_livraison(typeId idLivraison){
Cellule<Livraison::Base > * l = gestionnaireLivraison.chercher(idLivraison);
    if(!l){
        return PAS_TROUVER;
    }   
    return annuler_commande( l->get().ref_commande());
}
/*

*/
int livrer_commande(typeId idCommande,typeId idClient){
     Cellule <Commande::Base> * c = gestionnaireCommande.chercher(idCommande);
     if(!c){
         return CMD_PAS_TROUVER;
     }
     if(c->get().status() == Commande::ANNULER){
         return CMD_DEJA_ANNULER;
     }
     if(c->get().status() == Commande::TERMINER){
         return CMD_DEJA_LIVRER;
     }
    int code = gestionnaireCommande.lancer_livraison(idCommande);
    if( code  != SUCCESS_CODE){
        return code;
    };
    return gestionnaireLivraison.creer(idCommande,idClient,c->get().nombre());
};
int annuler_commande(typeId id){
     Cellule <Commande::Base> * c = gestionnaireCommande.chercher(id);
     if(!c){
         return CMD_PAS_TROUVER;
     }
     if(c->get().status() == Commande::ANNULER){
         return CMD_DEJA_ANNULER;
     }
     if(c->get().status() == Commande::TERMINER){
         return CMD_DEJA_LIVRER;
     }
     int code = gestionnaireCommande.annuler(id);
    if( code  != SUCCESS_CODE){
        return code;
    };
    Cellule<Livraison::Base> * l = gestionnaireLivraison.livraisons_apropos(c->get().ref());
    if(!l){
        return LIVRAISON_PAS_TROUVER;
    }
    return gestionnaireLivraison.supprimer(l->get().ref());
}
typeId  meilleur_client_de(typeId idArticle){
    Liste<Commande::Base> c = gestionnaireCommande.commandes_pour(idArticle);
    if(c.est_vide()){
        return 0;
    }
    Cellule<Commande::Base> * p = c.recup_tete();
    std::map<typeId, int> lp;
    while (p!= c.recup_sentinelle())
    {
        if(lp[p->get().ref_client()]){
            lp.insert(std::pair<typeId,int>(p->get().ref_client(),lp[p->get().ref_client()]++));

        }else{
            lp.insert(std::pair<typeId,int>(p->get().ref_client(),1));
        }
        p = p->get_next();
    }
    std::map<typeId,int>::iterator i, max;
    i = lp.begin();
    long taille = lp.size() - 1;
    max = i;
    i++;
    while (taille >= 0){
        
        if(i->second > max->second){
            max = i;
        }
        taille--;
    }
    
    return max->first;
}
