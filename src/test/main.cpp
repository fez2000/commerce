#include <iostream>
#include "main.h"
 
using namespace std;
int main(){
     Client::Base mon_client(1, 'tchuente', 'patrice', '15/01/1998', 'Mas');
    
     Article::Article bg("","");
     bg.creer("tomate",100,44,20);
     bg.creer("omate",10,4,2);
     return 0;
}