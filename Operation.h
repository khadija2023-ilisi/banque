#pragma once
#include <iostream>
#include <time.h>
#include "Compte.h"
namespace banque {
	//class Compte;
	class banque::Devise;
	class Operation
	{
	public:
		Operation(Devise* d, Compte* c);
		virtual void afficher() const;
	private:
		const int num;
		static int cpt;
		Devise* montant;
		std::string date;
		std::string time;
		Compte* C;
	};
};


