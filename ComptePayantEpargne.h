#pragma once
#include "ComptePayant.h"
#include "CompteEpargne.h"
namespace banque {
    class ComptePayantEpargne :  public CompteEpargne, public ComptePayant
    {
    public:
        ComptePayantEpargne(Client* c1, Devise* d1, Devise* d2, double ti);

    };

};

