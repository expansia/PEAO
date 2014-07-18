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

/**
 * @brief GestionnaireFenetre::GestionnaireFenetre
 * @param ptrPEAO
 */

/**
* @brief Description en une ligne de la méthode.
*
* @param NomParam1: Description du paramètre 1.
* @return Description de la valeur de retour
* @see Pour renvoyer vers une autre définition
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
* @brief Description en une ligne de la méthode.
*
* @param NomParam1: Description du paramètre 1.
* @return Description de la valeur de retour
* @see Pour renvoyer vers une autre définition
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
* @brief Description en une ligne de la méthode.
*
* @param NomParam1: Description du paramètre 1.
* @return Description de la valeur de retour
* @see Pour renvoyer vers une autre définition
*/
PEAO *GestionnaireFenetre::ptrfnObtenirPointeurPEAO()
{
    return mptrMemoPEAO;
}

/**
* @brief Description en une ligne de la méthode.
*
* @param NomParam1: Description du paramètre 1.
* @return Description de la valeur de retour
* @see Pour renvoyer vers une autre définition
*/
GestionnaireFenetre::~GestionnaireFenetre()
{

}
