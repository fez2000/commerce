#include <iostream>
#include "fonctions.h"
#include <math.h>
#include <string.h>
#include <vector>

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
bool is_affirmatif(const char * choix){
    int i =0;
    std::vector<const char *> Choix;
    Choix.push_back("OUI");
    Choix.push_back("O");
    Choix.push_back("YES");
    Choix.push_back("Y");
    Choix.push_back("oui");
    Choix.push_back("o");
    Choix.push_back("yes");
    Choix.push_back("y");
    while ( i < 8 )
    {
        if(strcmp(choix,Choix[i]) == 0){
            return true;
        }
        i++;
    }
    return false;
};
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

