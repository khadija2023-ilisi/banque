#include "CompteCourant.h"
#include <assert.h> 
banque::CompteCourant::CompteCourant(Client* c, Devise* s, Devise* d)
	:Compte(c, s)
{
	assert(*s >= *d);
	this->decouvert = d;
}

bool banque::CompteCourant::debiter(Devise* M)
{
	if (this->checkSup(&(*M + *this->decouvert)))
		return this->Compte::debiter(M);
	return false;
}
