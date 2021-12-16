#include "Euro.h"
#include "Dollar.h"
#include "MAD.h"
#include <iostream>
using namespace std;
using namespace banque;
float Euro::T_Dollar = 1;
float Euro::T_MAD = 10;

banque::Euro::Euro(double val)
    :Devise(val)
{

}
Dollar* banque::Euro::convertToDollar()
{
    Dollar* D = new Dollar(this->convert(T_Dollar));
    return D;
}
MAD* banque::Euro::convertToMad()
{
    MAD* M = new MAD(this->convert(T_MAD));
    return M;
}

Euro* banque::Euro::convertToEuro()
{

    return this;
}

void banque::Euro::afficher() const
{
    this->Devise::afficher();
    cout << "Euro" << endl;
}


