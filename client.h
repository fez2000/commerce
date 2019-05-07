#ifndef CLIENT_H_INCLUDE
#define CLIENT_H_INCLUDE
namespace client
{
    /* 
        @brief classe de base d'un client permettant d'effectuer des operations elementaire sur un client
        @methodes:
            -update: pour mettre a jour un client
    */
    class base
    {
    private:
        /* data */
    public:
        base(/* args */);
        ~base();
        int update();
    };
    
   
} // client
#endif