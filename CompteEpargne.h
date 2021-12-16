#pragma once
#include "Compte.h"
namespace banque {
    class CompteEpargne :  virtual public Compte
    {
    private:
        double TauxInteret;
    public:
        CompteEpargne(Client* titu, Devise* sol, double TI);
        void calculeInteret();
    };
};
