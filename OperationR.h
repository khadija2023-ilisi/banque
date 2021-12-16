#pragma once
#include "Operation.h"
#include <iostream>
using namespace std;
namespace banque {
  //  class Devise;
//    class Compte;
    class OperationR : public Operation
    {
    public:
        OperationR(Devise* d, Compte* c);
        void afficher() const override;
    private:

    };

};

