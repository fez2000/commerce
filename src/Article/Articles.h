#ifndef ARTICLES_H_INCLUDE
#define ARTICLES_H_INCLUDE
#include "Article.h"
    namespace Article{
        /* 
        @brief classe de base d'un  atricle permettant d'effectuer des operation elementaire sur un  atricle
        @methodes:
            -update: qui permet de chercher un  atricle un   atricle et de le mettre a jour
            -remove: qui permet de supprimer un atricle 
            -create: qui permet de creer un nouveau atricle
            -load: qui permet de charger un atricle un  atricle a partir d'un fichier par defaut atricle.txt
            -store: qui permet de specifier ou serons sauvegerder les cleints par defaut sur le fichier de load si pas specifier
        */
        class   Article
        {
        private:
            /* data */
        public:
            Article(/* args */);
            ~Article();
            int create();
            int remove();
            int update();
            Base find();
            int load();
            int store();
        };
        
    }
#endif