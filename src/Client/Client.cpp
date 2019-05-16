#include <fstream>

#include "Client.h"

namespace Client{
using namespace std;

    Base::Base(int num_client, char nom_client, char prenom_client, char date_naiss_client, char sexe)
    {
        
    }

    bool Base::tester_reference(unsigned long ref){
        return numeroClient == ref;
    };
    
    Base::~Base()
    {
    }
} // client

    