#include <iostream>
#include "main.h"
 
using namespace std;
int main(){
     
      bool recommencer=true;
          int i(5),a=0;/* Declaration des variables*/
                cout << "MENU ARTICLES" << endl;
      do{
          cout <<"1)Ajout d'un article)"<< endl;
        cout <<"2)Articles (liste des articles enregistré)"<< endl;
        cout <<"3)Modifie un article"<< endl;
        cout <<"4)suppresion d'un article"<< endl;
          cout <<"5)Retour au menu principal"<< endl;
        cout<<"Entre le numero choisie dans le menu  : ";
          cin >> i;
      switch (i){
        case 1:
              cout << "Ajout d'un article"<< endl;
        break;
        case 2:
              cout << "Articles (liste des articles enregistré)"<< endl;
        break;
        case 3:
              cout << "Modifie un article"<< endl;
        break;
        case 4:
              cout << "suppresion d'un article"<< endl;
        break;
        case 5:
              cout << "Retour au menu principal:"<< endl;
        break;
        default:
                cout << "Mauvais choix Voulez vous recommencer le programme ? \n 1-pour oui\n 2-pour non\n" ;
                cin >> a;
                if(a==1){
                    recommencer=true;
                      }
                else{
                    recommencer=false;
                    
                }      
        break;
      }

      }while (recommencer==true);

     return 0;
}