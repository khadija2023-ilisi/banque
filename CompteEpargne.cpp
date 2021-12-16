#include "CompteEpargne.h"
#include <iostream>
#include <assert.h>
banque::CompteEpargne::CompteEpargne(Client* titu, Devise* sol, double TI)
	:Compte(titu, sol)
{
	assert(TI >= 0 && TI <= 100);
	this->TauxInteret = TI;
}

void banque::CompteEpargne::calculeInteret()
{
	double a = this->TauxInteret / 100;
	Devise* p = &this->pourcentage(a);
	this->crediter(p);
}
