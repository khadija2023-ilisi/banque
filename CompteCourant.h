#pragma once
#include "Compte.h"
#include "Devise.h"
#include "Client.h"
namespace banque {
	class CompteCourant : virtual public Compte
	{
	private:
		Devise* decouvert;
	public:
		CompteCourant(Client* c, Devise* s, Devise* d);
		bool debiter(Devise* M)override ;
	};
};

