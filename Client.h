#pragma once
#include <iostream>
#include <vector>
using namespace std;
namespace banque {
	class Compte;
	class Client
	{
	private:
		string nom;
		string prenom;
		string adresse;
		vector<Compte*> mescmpts;
	public:
		Client(string, string, string);
		void afficher() const;
		void addCompte(Compte& cmpt);
	};

};