#include "ComptePayant.h"
double t_pay = 0.05;
banque::ComptePayant::ComptePayant( Devise* d,Devise *d2, Client* c1)
	:CompteCourant(c1,d,d2),Compte(c1,d)
{
}
