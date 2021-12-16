#pragma once
#include "Operation.h"
#include <iostream>
using namespace std;
namespace banque {
    class OperationV :public Operation
    {
    public:
        OperationV(Devise* d, Compte* c);
        void afficher() const override;
    private:
    };
};


