// banque.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Client.h"
#include "Compte.h"
#include "CompteCourant.h"
#include "CompteEpargne.h"
#include "Devise.h"
#include "Dollar.h"
#include "Euro.h"
#include "MAD.h"
#include "OperationR.h"
#include "OperationV.h"
using namespace std;
using namespace banque;

int main()
{
   /*
    MAD* M = D->convertToMad();
    M->afficher();
    Euro* E = M->convertToEuro();
    E->afficher();
   delete D,M,E;*/ 
    Dollar* D1 = new Dollar(2000);
    Dollar* D2 = new Dollar(200);
    Dollar* D3 = new Dollar(350);
    Euro* e1 = new Euro(3500);
    Euro* e2 = new Euro(3500);
    MAD* m1 = new MAD(1000);
    Client* c1 = new Client("user1", "last1", "casablanca");
    CompteCourant* cmpt1 = new CompteCourant(c1,D1,D2);
    CompteEpargne* cmpt2 = new CompteEpargne(c1, e2, 0.25);
    c1->addCompte(*cmpt1);
    c1->addCompte(*cmpt2);
    cmpt1->crediter(D3);
    cmpt1->crediter(e1->convertToDollar());
    cmpt1->crediter(m1->convertToDollar());
    cmpt2->crediter(D3->convertToEuro());
    cmpt2->crediter(m1->convertToEuro());
    /*******************************************/
    /*Affichage*/
    c1->afficher();
    
    delete D1, D2, c1, cmpt1,D3,e1;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
