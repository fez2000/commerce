#ifndef COMMANDE_H_INCLUDE
#define COMMANDE_H_INCLUDE

    namespace commande{
        /* 
            @brief classe de base des commandes permettant d'effectuer des operations elementaire sur une commande
            @methodes:
            -update: pour mettre a jour un article
        */
        class Base
        {
        private:
            /* data */
        public:
            Base(/* args */);
            ~Base();
            int updtat();
        };
           
    }
#endif