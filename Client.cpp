#include "Client.h"
#include <iostream>
#include "Compte.h"
using namespace std;
using namespace banque
;
banque::Client::Client(string n, string p, string add)
{
	this->nom = n;
	this->prenom = p;
	this->adresse = add;
}

void banque::Client::afficher() const
{
	cout << "nom:" << this->nom << "\n";
	cout << "prenom:" << this->prenom << "\n";
	cout << "Adresse:" << this->adresse << "\n";
	for (int i = 0; i < this->mescmpts.size(); i++)
		this->mescmpts[i]->afficher();
}
void banque::Client::addCompte(Compte& cmpt)
{
	this->mescmpts.push_back(&cmpt);
}