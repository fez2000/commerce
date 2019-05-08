#include "Data.h"
#include <iostream>
#include <algorithm>
#include <locale>
#include <string>
#include <vector>
// using...
using namespace std;
/*
bool Deserialiseur::deserialiser(istream &is) {
   if (!is) return false;
   string s;
   if (!::deserialiser(is, s)) return false;
   auto it = find_if(
      begin(reconstr_), end(reconstr_),
      [&](unique_ptr<Reconstructeur> &p) {
         return s == p->nom_lisible();
      });
   if (it == end(reconstr_)) return false;
   (*it)->reconstruire(is);
   return true;
}*/