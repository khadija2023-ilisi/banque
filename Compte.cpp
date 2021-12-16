#include "Compte.h"
#include "Client.h"
#include "Devise.h"
#include "MAD.h"
#include "Dollar.h"
#include "Euro.h"
#include "OPerationR.h"
#include "OPerationV.h"
#include <typeinfo>
#include <iostream>
using namespace std;
using namespace banque;
Devise* Compte::plafond = new Devise(2000);
int Compte::compteur = 0;
banque::Compte::Compte(Client* titu, Devise* sol) :numcompte(++compteur)
{
	this->titulaire = titu;
	this->solde = sol;
	//this->ref = new GC(1);
}
banque::Compte::Compte(Compte& c) :numcompte(++compteur)
{
	this->solde = new Devise(*c.solde);
	//this->ref = c.ref;
	//this->ref->increment();
	this->titulaire = c.titulaire;
}
void banque::Compte::crediter(Devise* M)
{
	
	MAD* m1=0;
	Euro* e1=0;
	Dollar* d1=0;
	if (typeid(M).name() != typeid(this->solde).name())
	{
		printf("000000000000000000000000\n");
		switch (this->solde->return_type())
		{
		case 1: {m1 = M->convertToMad(); *(this->solde) = *(this->solde) + *m1; break; }
		case 2: {e1 = M->convertToEuro(); *(this->solde) = *(this->solde) + *e1; break; }
		case 3: { d1 = M->convertToDollar(); *(this->solde) = *(this->solde) + *d1; break; }
		default:printf("0\n");
		}
	}else
		*(this->solde) = *(this->solde) + *M;
	
	OperationV* V = new OperationV(M, this);
	this->mesOp.push_back(V);
	delete m1, e1, d1;
}

Compte& banque::Compte::operator=(const Compte& C)
{
	if (this != &C)//v=v tester sur sur cas
	{
		//supprimer la referrence du ancien titulaire
		/*if (this->titulaire != NULL)//&& this->ref)
		{
			//if (this->ref->decriment() == 0)
			//{
				//delete this->ref;
				//this->ref = NULL;
			//}

		}*/
		this->solde = C.solde;
		this->titulaire = C.titulaire;
		//this->ref = C.ref;
		//this->ref->increment();

	}//end of if
	return *this;
}

bool banque::Compte::debiter(Devise* M)
{
	if (*(this->solde) <= *M || *M >= *(Compte::plafond))
		return false;
	MAD* m1=0;
	Euro* e1=0;
	Dollar* d1=0;
	if (typeid(M) != typeid(this->solde))
	{
		switch (this->solde->return_type())
		{
		case 1: m1 = M->convertToMad(); *(this->solde) = *(this->solde) - *m1; break;
		case 2: e1 = M->convertToEuro(); *(this->solde) = *(this->solde) - *e1; break;
		case 3: d1 = M->convertToDollar(); *(this->solde) = *(this->solde) - *d1; break;
		default:exit(0);
		}
	}

	else
		*(this->solde) = *(this->solde) - *M;
	OperationR *R = new OperationR(M, this);
	this->mesOp.push_back(R);
	delete m1, e1, d1;
	return true;
}

bool banque::Compte::verser(Devise* M, Compte& C)
{
	if (this->debiter(M))
	{
		C.crediter(M);
		return true;
	}
	return false;
}



void banque::Compte::consulter() const
{
	cout << "num compte :" << numcompte << endl;
	this->solde->afficher();
	cout << "titulaire\n";
	this->titulaire->afficher();


}

void banque::Compte::afficher() const
{
	cout << "Num du compte : " << this->numcompte << "\n"<<"solde ";
	this->solde->afficher();
	//this->titulaire->afficher(); cout << endl;
	for (Operation* X : this->mesOp)
	{
		X->afficher();
	}
}

bool banque::Compte::checkSup(Devise* d) const
{
	return *this->solde >= *d;
}

Devise& banque::Compte::pourcentage(double a) const
{
	Devise* res = new Devise(a);
	return (*res * (*this->solde));

}

banque::Compte::~Compte()
{
	if (this->titulaire)// && this->ref->decriment() == 0)
	{
		delete this->titulaire;
		this->titulaire = NULL;
	}
}

