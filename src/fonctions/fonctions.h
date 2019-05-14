#ifndef FONCTIONS_H_INCLUDE
#define FONCTIONS_H_INCLUDE
#include <fstream>
#include <string>
bool est_premier(long );
long prochain_nb_premier(long);
std::ostream& serialiser(std::ostream &os, const std::string &s);
std::istream& deserialiser(std::istream &is, std::string &s);
#endif