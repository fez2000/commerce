#include <iostream>
#include "main.h"
 
using namespace std;
int main(){
     
     Client::Client mon_client;
     
     mon_client.creer_client("tchuente", "patrice", "15/01/1998", "M");

     //mon_client.supprimer_client(3);
   /* 
     Article::Article bg;
     Commande::Commande a;
     a.creer(1,1,56);
     //a.supprimer(1);
     bg.creer("tomate",100,44,20);
     bg.supprimer(1);
     cout <<  *bg.chercher("tomate") << "\n";
     bg.mettre_a_jour(bg.chercher("tomate")->get().get_reference(),"tomates",1245.3,345,200);
     */
     return 0;
}