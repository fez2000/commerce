#ifndef ARTICLES_H_INCLUDE
#define ARTICLES_H_INCLUDE
#include "Article.h"
#include "../Cellule/Cellule.h"
#include "../Liste/Liste.h"
#define FICAL  "./BD/atricle.txt"
#define FICAST  "./BD/atricle.temporaire.txt"
#define FICAS  "./BD/atricle.txt" 

#include <map>
    namespace Article{
        /* 
        @brief classe de gestion des  atricles permettant d'effectuer des operations sur un ensemble d'atricle
        @proprietes:
                -table: tableau qui lie d'id d'une commande et sa cellule;
                -maxNumeroGenerer: represente l'id de la prochaine de commande a creer
        @methodes:
            -update: qui permet de chercher un  atricle un   atricle et de le mettre a jour
            -remove: qui permet de supprimer un atricle 
            -create: qui permet de creer un nouveau atricle
            -load: qui permet de charger des atricles a partir d'un fichier par defaut atricle.txt
            -store: qui permet de specifier ou serons sauvegerder les cleints par defaut sur le fichier de load si pas specifier
        */
        class   Article: public Liste< Base >
        {
        private:
            std::map<typeId, Cellule<Base> * > table;//map fonction de la lib map qui permet de creer les tableaux associatifs
            typeId maxNumeroGenerer;//plus grand id generer
            int sauvegarder();
            int charger();
        public:
            Article();
            typeId creer(const char *, double, unsigned long,unsigned long);
            int supprimer(typeId);
            int mettre_a_jour(typeId,const char *, double, unsigned long,unsigned long );
            Cellule<Base>* chercher(const char *);
            Cellule<Base>* chercher(typeId);
            Liste<Base> critiques();
            long double capital(void);
            int charger(const char *);
            int sauvegarder(const char *);
            static Article deserialiser(std::istream&);
            friend std::ostream& operator<<(std::ostream &, const Article &);
            friend std::istream& operator>>(std::istream &, Article &);   
        };
        
    
    };
#endif