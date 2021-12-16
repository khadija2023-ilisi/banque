#include "OperationV.h"

banque::OperationV::OperationV(Devise* d, Compte* c)
	:Operation(d,c)
{
}

void banque::OperationV::afficher() const
{
	this->Operation::afficher();
	cout << "Virement\n\n";
}
