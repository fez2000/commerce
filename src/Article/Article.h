#ifndef ARTICLE_H_INCLUDE
#define ARTICLE_H_INCLUDE
    namespace   Article
{
    /* 
        @brief classe de base d'un  atricle permettant d'effectuer des operations elementaire sur un atricle
        @methodes:
            -update: pour mettre a jour un  atricle
    */
    class Base
    {
    private:
        /* data */
    public:
        Base(/* args */);
        ~Base();
        int update();
    };
    
} //    atricle

#endif