#ifndef LISTE_H_INCLUDE
#define LISTE_H_INCLUDE
#include "../Cellule/Cellule.h"
#include <fstream>
template <class T>class Liste
{
protected:
    Cellule<T> * tete;
    Cellule<T> * sentinelle;
    unsigned long taille;
public:
    Liste();
    ~Liste();
    bool est_vide();
    int ajouter(Cellule<T> *);
    int ajouter_trie(Cellule<T> *);
    int ajouter_apres(Cellule<T>* , Cellule<T> *);
    int ajouter_avant(Cellule<T>* , Cellule<T> *);
    int enlever(Cellule<T> v);
    
};

template <class T> Liste<T>::Liste(){
    
    tete = sentinelle = new Cellule<T> ;
  
    taille = 0;
} 
template <class T> Liste<T>::~Liste(){
   
}
template <class T> bool Liste<T>::est_vide(){
    return taille == 0;
}
template <class T> int Liste<T>::ajouter(Cellule<T> * v){
    
    v->next(tete);
    tete->previous(v);
    tete = v;
    taille++;
    return 1;
}
template <class T> int Liste<T>::ajouter_apres(Cellule<T> * v, Cellule<T> * a){
    
    v->get_next()->previous(a);
    a->next(v->get_next());
    v->next(a);
    a->previous(v);
    taille++;
    return 1;
}
template <class T> int Liste<T>::ajouter_avant(Cellule<T>*  v, Cellule<T>  *a){
    if(v->get() == tete->get()){
        return ajouter(a);
    }
    v->get_prev()->next(a);
    a->previous(v->get_prev());
    v->previous(a);
    a->next(v);
    taille++;
    return 1;
}
template <class T> int Liste<T>::ajouter_trie(Cellule<T> * a){
    if(taille == 0){
        ajouter(a);
        return 0;
        
    }
    Cellule<T> * b = tete;
    while ((*b)< (*a))
    {
        b = b->get_next();
    }
    return ajouter_avant(b,a);
};
template <class T> int Liste<T>::enlever(Cellule<T> v){
    if(taille == 0){
        return 1;
    }

    if(v.get() == tete->get() ){
        tete = v.get_next();
    }else{
       v.get_prev()->next(v.get_next());     
    }
    
    taille--;
    return 1;
}

#endif