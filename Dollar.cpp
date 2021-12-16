#include "Dollar.h"
#include "MAD.h"
#include "Euro.h"
#include <iostream>
using namespace std;
using namespace banque;
float Dollar::T_MAD = 10;
float Dollar::T_Euro = 1;
banque::Dollar::Dollar(double val)
    :Devise(val)
{

}

Dollar* banque::Dollar::convertToDollar()
{
    return this;
}
MAD* banque::Dollar::convertToMad()
{
    MAD* M = new MAD(this->convert(T_MAD));
    return M;
}

Euro* banque::Dollar::convertToEuro()
{
    Euro* E = new Euro(this->convert(this->T_Euro));
    return E;
}

void banque::Dollar::afficher() const
{
    this->Devise::afficher();
    cout << "Dollar" << endl;
}
