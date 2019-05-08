#ifndef SERIALISATION_OUTILS_H
#define SERIALISATION_OUTILS_H
#include <iosfwd>
#include <string>
#include <sstream>
#include <typeinfo>
//
// Exemple un peu abusif; on pourrait faire plus
// simple avec de la surcharge de fonctions
//
template <class T>
   struct Serialisation {
      static string formater(const T &val) {
         stringstream sstr;
         sstr << '\"' << typeid(T).name() << "\" "
              << val;
         return sstr.str();
      }
   };
template <>
   struct Serialisation<std::string> {
      static std::string formater(const std::string &val) {
         std::stringstream sstr;
         sstr << '\"' << typeid(std::string).name() << "\" "
              << '\"' << val << '\"';
         return sstr.str();
      }
   };
#endif