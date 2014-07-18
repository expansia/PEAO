/******************************************************************************
 *   Société      : EXPANSIA PCAS - route d'Aramon 30390 Aramon (FRANCE)      *
 *   Projet       : PEAO                                                      *
 ******************************************************************************
 *   Module           : Affichage                   *
 *   Fichier          : gestionnairefenetre.cpp                                        *
 *   Classe           : GestionnaireFenetre                                      *
 *   Date de création : 17/07/2014                                            *
 *   Auteur           : Cyril Charbonneau                                            *
 *   Langage          : C++                                                   *
 ******************************************************************************
 *   Logiciel                   :                                           *
 *   Options de compilation     :                                             *
 *   Options d'édition de liens :                                             *
 ******************************************************************************/

#include "gestionnairefenetre.hpp"
#include "constantes.hpp"
#include "peao.hpp"

/**
* @brief Constructeur de la classe GestionnaireFenetre.
* Liaison de l'objet vers PEAO.
* Création des fenetres accueillant les menus et les formulaires.
* Envoi d'un pointeur vers l'objet courrant aux fenetres créées.
* @param ptrPEAO: pointeur vers la classe PEAO.
*/
GestionnaireFenetre::GestionnaireFenetre(PEAO *ptrPEAO)
{
    //mémorisation du pointeur vers l'objet PEAO
    mptrMemoPEAO=ptrPEAO;
    /*envoie d'un pointeur de l'objet courant(GestionnaireFenetre)
    vers les classes fenetre*/
    mfenetrePrincipale.fnMemoPtrGestionnaireFenetre(this);
    mfenetreLAS.fnMemoPtrGestionnaireFenetre(this);
}

/**
* @brief Fonction d'affichage des fenetres du logiciel.
* En fonction du parametre reçu la fonction va afficher la fenetre correspondante.
* @param choixFenetre: Un entier determinant la fenetre a afficher.
* @return false si un probleme est survenu lors de l'affichage. true sinon.
*/
bool GestionnaireFenetre::bfnAfficherFenetre(unsigned int choixFenetre)
{
    switch(choixFenetre)
    {
    case F_PRINCIPALE:
        mfenetrePrincipale.show();
        break;
    case F_FORM_LAS:
        mfenetreLAS.show();
        break;
    case F_FORM_CONTENANT:
        break;
    case F_FORM_ARTICLE:
        break;
    case F_FORMLOT:
        break;
    default:
        return false;
        break;
    }
    return true;
}

/**
* @brief Fonction de recuperation des donnees du formulaire de la LAS.
* La fonction reçoit le code process ainsi que le numero de lot de LAS
* et les renvoie a l'objet PEAO
* @param qsCodeProcess: Le code process en provenance du formulaire de la LAS.
* @param qsNumLot: Le numero de lot en provenance du formulaire de la LAS.
*/
void GestionnaireFenetre::fnreceptionnerInformationsLAS(const QString& qsCodeProcess, const QString& qsNumLot)
{
    mptrMemoPEAO->fnreceptionnerInformationsLAS(qsCodeProcess, qsNumLot);
}

/**
* @brief Appel de la fonction de vérification si une operation est en cours.
* Appel de la fonction bfnOperationEnCours() par le pointeur mptrMemoPEAO.
* @return true si une operation est en cours, false sinon.
*/
bool GestionnaireFenetre::bfnOperationEnCours()
{
    return mptrMemoPEAO->bfnOperationEnCours();
}

/**
* @brief Appel de la fonction pour démarrer une operation PEAO dans l'objet PEAO.
* Appel de la fonction fninitialiserOperation() par le pointeur mptrMemoPEAO.
*/
void GestionnaireFenetre::fninitialiserOperation()
{
    mptrMemoPEAO->fninitialiserOperation();
}


/**
* @brief Destructeur de la classe GestionnaireFenetre.
*/
GestionnaireFenetre::~GestionnaireFenetre()
{

}
