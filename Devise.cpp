#include "Devise.h"
#include "Dollar.h"
#include "MAD.h"
#include "Euro.h"
#include <iostream>
using namespace std;
using namespace banque;
Devise::Devise(double val)
{
	this->valeur = val;
}

Devise& Devise::operator+(const Devise& M) const
{
	Devise* res = new Devise(this->valeur + M.valeur);
	return *res;
}

Devise& Devise::operator-(const Devise& M) const
{
	Devise* res = new Devise(this->valeur - M.valeur);
	return *res;
}
Devise& banque::Devise::operator*(const Devise& M) const
{
	Devise* res = new Devise(this->valeur * M.valeur);
	return *res;
}

void banque::Devise::operator*(double d)
{
	this->valeur *= d;
}

bool Devise::operator<=(const Devise& M) const
{
	return this->valeur <= M.valeur;
}

bool Devise::operator>=(const Devise& M) const
{
	return this->valeur >= M.valeur;
}

double banque::Devise::convert(double taux)
{
	return this->valeur * taux;
}

Dollar* banque::Devise::convertToDollar()
{
	return nullptr;
}

MAD* banque::Devise::convertToMad()
{
	return nullptr;
}

Euro* banque::Devise::convertToEuro()
{
	return nullptr;
}

void Devise::afficher() const
{
	cout << "le montant est :" << this->valeur << " ";
}

int banque::Devise::return_type()
{
	if (typeid(this).name() == typeid(MAD*).name())
		return 1;
	if (typeid(this).name() == typeid(Euro*).name())
		return 2;
	if (typeid(this).name() == typeid(Dollar*).name())
		return 3;
}
