#include "Devise.h"
#include "Compte.h"
#include "OperationR.h"

banque::OperationR::OperationR(Devise* d, Compte* c)
	:Operation(d,c)
{
}

void banque::OperationR::afficher() const
{
	this->Operation::afficher();
	cout << "Retrait\n\n";
}
