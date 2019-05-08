#ifndef SERIALISATION_OUTILS_H
#define SERIALISATION_OUTILS_H
#include <iosfwd>
#include <string>
#include <sstream>
#include <typeinfo>
#include <vector>
#include <memory>
//
// Exemple un peu abusif; on pourrait faire plus
// simple avec de la surcharge de fonctions
//
/*template <class T>
   struct Serialisation {
      static std::string formater(const T &val) {
         std::stringstream sstr;
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

   class Reconstructeur {
   std::string nom_lisible_;
public:
   Reconstructeur(const std::string &nom_lisible)
      : nom_lisible_{nom_lisible}
   {
   }
   virtual ~Reconstructeur() = default;
   std::string nom_lisible() const
      { return nom_lisible_; }
   virtual void reconstruire(std::istream &) = 0;
};
#include "Incopiable.h"
class Deserialiseur : Incopiable {
   std::vector<std::unique_ptr<Reconstructeur>> reconstr_;
   Deserialiseur() = default;
public:
   bool deserialiser(std::istream &);
   static Deserialiseur &get() {
      static Deserialiseur singleton;
      return singleton;
   }
   void ajouter(std::unique_ptr<Reconstructeur> p)
      { if (p) reconstr_.push_back(p); }
};
*/
#endif