#include <iostream>
#include "main.h"
 
using namespace std;
int main(){
     Client::Base mon_client(1, 'tchuente', 'patrice', '15/01/1998', 'Mas');
    
     Article::Article bg("","");
     bg.creer("tomate",100,44,20);
     cout <<  *bg.chercher("tomate") << "\n";
     bg.mettre_a_jour(bg.chercher("tomate")->get().get_reference(),"tomates",1245.3,345,200);
     return 0;
}