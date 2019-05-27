#ifndef STAT_H_INCLUDE
#define STAT_H_INCLUDE
#include "../Liste/Liste.h"
#include "../fonctions/fonctions.h"
#include <map>
#include "../Cellule/Cellule.h"
#include "../Liste/Liste.h"
    namespace Stat{
        class Base
        {
        private:
            unsigned long quantiteVendu;
            unsigned long quantiteCommander;
            typeId element;
        public:
            Base();
            Base(typeId,unsigned long,unsigned long);
            ~Base();
        };
        
        Base::Base(/* args */)
        {
        }
        
        Base::~Base()
        {
        }
        
        class Stat
        {
        private:
            
        public:
            Stat();
            ~Stat();
        };
        
        Stat::Stat(/* args */)
        {
        }
        
        Stat::~Stat()
        {
        }
        
    }

#endif