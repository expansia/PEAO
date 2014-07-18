/******************************************************************************
 *   Société      : EXPANSIA PCAS - route d'Aramon 30390 Aramon (FRANCE)      *
 *   Projet       : PEAO                                                      *
 ******************************************************************************
 *   Module           : Affichage                                             *
 *   Fichier          : peao.cpp                                              *
 *   Classe           : PEAO                                                  *
 *   Date de création : 17/07/2014                                            *
 *   Auteur           : Cyril Charbonneau                                     *
 *   Langage          : C++                                                   *
 ******************************************************************************
 *   Logiciel                   : Qt 5.3                                      *
 *   Options de compilation     :                                             *
 *   Options d'édition de liens :                                             *
 ******************************************************************************/

#include "peao.hpp"
#include "constantes.hpp"

/**
 * @brief Constructeur de la classe PEAO.
 *
 * Les attributs de la classe sont initialisées aux valeurs par défaut.
 * Par défaut, aucune opération n'est en cours.
 * Un pointeur vers PEAO est transmis à l'objet
 * "GestionnaireFenetre".
 * Création du gestionnaire de fenêtre (qui possède un pointeur sur l'objet
 * PeAO).
 */
PEAO::PEAO()
{
    mb_OperationEnCours = false;
    mGF_gestFenetre     = new GestionnaireFenetre(this);
}


/**
 * @brief Lance la fenêtre principale.
 *
 * Fonction affichant la fenetre principale où l'utilisateur peut
 * choisir l'opération qu'il désire effectuer.
 * @return true si la fenêtre s'est bien lancée, false sinon.
 */
bool PEAO::bfnLancerProgrammePrincipal()
{
     return mGF_gestFenetre->bfnAfficherFenetre(F_PRINCIPALE);
}

/**
* @brief Description en une ligne de la méthode.
*
* @param NomParam1: Description du paramètre 1.
* @return Description de la valeur de retour
* @see Pour renvoyer vers une autre définition
*/
/**
 * @brief PEAO::fninitialiserOperation
 * Fonction permettant d'initialiser une opération de PEAO.
 *
 */
void PEAO::fninitialiserOperation()
{
    mb_OperationEnCours=true;
    mGF_gestFenetre->bfnAfficherFenetre(F_FORM_LAS);

}

/**
* @brief Description en une ligne de la méthode.
*
* @param NomParam1: Description du paramètre 1.
* @return Description de la valeur de retour
* @see Pour renvoyer vers une autre définition
*/
void PEAO::fnQuitterOperation()
{
    mb_OperationEnCours=false;
}

/**
* @brief Description en une ligne de la méthode.
*
* @param NomParam1: Description du paramètre 1.
* @return Description de la valeur de retour
* @see Pour renvoyer vers une autre définition
*/
bool PEAO::bfnOperationEnCours()
{
    return mb_OperationEnCours;
}

/**
* @brief Description en une ligne de la méthode.
*
* @param NomParam1: Description du paramètre 1.
* @return Description de la valeur de retour
* @see Pour renvoyer vers une autre définition
*/
PEAO::~PEAO()
{
}
