#pragma once
#include "CompteCourant.h"
#include "Devise.h"
#include "Client.h"
namespace banque {
    
    class ComptePayant :  virtual public CompteCourant
    {
    public:
        ComptePayant(Devise *d,Devise *d2,Client *c1);

    private:
        static double t_pay;
    };
};
