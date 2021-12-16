#pragma once
#include <iostream>
#include <list>
using namespace std;
namespace banque {
	class Client;
	class Operation;
	class Devise;
	class Compte
	{
		//attribues
	private:
		static int compteur;
		const int numcompte;
		Client* titulaire;
		Devise* solde;
		static Devise* plafond;
		list<Operation*> mesOp;
		//GC* ref;
		//les methodes
	public:
		Compte(Client*, Devise*);//avec parametres
		Compte(Compte&);//constructeur de recopie
		Compte& operator=(const Compte&);//operateur d'affectation
		void crediter(Devise* M);
		virtual bool debiter(Devise* M);
		bool verser(Devise* M, Compte& C);
		void consulter() const;
		virtual void afficher() const;
	protected:bool checkSup(Devise* d) const;
	protected: Devise& pourcentage(double a)const;
	public:~Compte();
	};
};


