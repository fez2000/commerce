#include "lang.h"
#include "string.h"
std::string bdlangpath;
std::map<const char *,const char *> lang;

int charger(const char * fichier_lang="fr"){
    bool chercherBalise = true,chevronsOuvrant = false;
    char c;
    std::string balise,baliseF,continu;

    std::ifstream fichier;
        fichier.exceptions ( std::ifstream::failbit | std::ifstream::badbit );
        try{
            fichier.open( cat_many(5,bdlangpath.c_str(),fichier_lang,"/",fichier_lang,".txt").c_str()  );
            if(fichier){
                while (fichier>>c)
                {
                    if(chercherBalise){
                        if(c=='<'){
                            if(!chevronsOuvrant)
                                chevronsOuvrant = true; 
                            else
                            {
                                balise.push_back(c);
                            }
                            
                        }else{
                            if(c=='>'){
                                if(chevronsOuvrant){
                                    chevronsOuvrant = false;
                                
                                    chercherBalise = false;
                                }else{
                                return ERREUR_FIC_LANG; 
                                }
                            }else{
                                balise.push_back(c);
                            }
                        }

                    }
                    else{
                        if(c=='<'){
                            if(!chevronsOuvrant)
                                chevronsOuvrant = true; 
                            else
                            {
                                baliseF.push_back(c);
                            }
                        }else{
                            if(c == '>' ){
                                if(chevronsOuvrant){
                                    if(0 == balise.compare(baliseF.c_str())){
                                        lang.insert(std::pair<const char *,const char * >(balise.c_str(),continu.c_str()));
                                    }else{
                                        continu.push_back('<');
                                        continu.append(baliseF.c_str());
                                        continu.push_back('>');
                                        continu.clear();
                                        balise.clear();
                                        baliseF.clear();
                                    }
                                }else
                                {
                                    continu.push_back(c);
                                }
                                
                            }else{
                                continu.push_back(c);
                            }
                        }
                    }
                }
                return PAS_DERREUR;
                    
                fichier.close();
            }
        }
        catch(std::ifstream::failure& ex){
            //std::cout <<ex.what()<< std::endl;
            return ERROR_CODE;
        }
    return PAS_DERREUR;

};