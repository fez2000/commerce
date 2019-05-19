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

