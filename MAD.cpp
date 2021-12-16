#include "MAD.h"
#include "Dollar.h"
#include "Euro.h"
#include <iostream>
using namespace std;
using namespace banque;
float MAD::T_Dollar = 0.1;
float MAD::T_Euro = 0.1;
banque::MAD::MAD(double val)
    :Devise(val)
{

}

Dollar* banque::MAD::convertToDollar()
{
    Dollar* D = new Dollar(this->convert(T_Dollar));
    return D;
}
MAD* banque::MAD::convertToMad()
{
    return this;
}

Euro* banque::MAD::convertToEuro()
{
    Euro* E=new Euro(this->convert(this->T_Euro));
    return E;
}

void banque::MAD::afficher() const
{
    this->Devise::afficher();
    cout << "MAD" << endl;
}
