#include "Operation.h"
#include "Compte.h"
#include "Devise.h"
#include <iostream>
using namespace std;
int banque::Operation::cpt = 0;
banque::Operation::Operation(Devise* d, Compte* c) :num(++cpt)
{
	this->C = c;
	this->montant = d;
	this->date = __DATE__;
	this->time = __TIME__;
}

void banque::Operation::afficher() const
{
	cout << "\n";
	//this->C->afficher();
	this->montant->afficher();
	cout << "date & time : " << this->date << " ";
	cout << this->time << "\n"; cout << "Operation \n";
}
