#include "ComptePayantEpargne.h"

banque::ComptePayantEpargne::ComptePayantEpargne(Client* c1, Devise* d1, Devise* d2, double ti)
	:CompteCourant(c1,d1,d2),Compte(c1,d1),CompteEpargne(c1,d1,ti),ComptePayant(d1,d2,c1)
{
}
