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
#include "las.hpp"
#include "gestionnairefenetre.hpp"

/**
 * @brief Constructeur de la classe PEAO.
 * Les attributs de la classe sont initialisées aux valeurs par défaut.
 * Par défaut, aucune opération n'est en cours.
 * Un pointeur vers PEAO est transmis à l'objet
 * "GestionnaireFenetre".
 * Création du gestionnaire de fenêtre (qui possède un pointeur sur l'objet
 * PeAO).
 */
PEAO::PEAO()
{
    mGF_gestFenetre     = NULL;
    mb_OperationEnCours = false;
    mGF_gestFenetre     = new GestionnaireFenetre(this);
    mLas                = NULL;
}


/**
 * @brief Lance la fenêtre principale.
 * Fonction affichant la fenetre principale où l'utilisateur peut
 * choisir l'opération qu'il désire effectuer.
 * @return true si la fenêtre s'est bien lancée, false sinon.
 */
bool PEAO::bfnLancerProgrammePrincipal()
{
     return mGF_gestFenetre->bfnAfficherFenetre(F_PRINCIPALE);
}

/**
* @brief Initialisation d'une nouvelle opération de PEAO.
* L'attribut mb_OperationEnCours est mis a true.
* La fenetre du formulaire de la LAS est affiché.
*/
void PEAO::fnInitialiserOperation()
{
    mb_OperationEnCours=true;

    mGF_gestFenetre->bfnAfficherFenetre(F_FORM_LAS);

}

/**
* @brief Fonction d'arret d'une operation en cours.
* L'attribut mb_OperationEnCours est mis a false.
* a définir plus tard.
*/
void PEAO::fnQuitterOperation()
{
    mb_OperationEnCours=false;
}

/**
* @brief Fonction determinant si une operation est en cours de traitement.
* Renvoie la valeur du booleen mb_OperationEnCours.
* @return true si une operation est en cours de traitement. false sinon.
*/
bool PEAO::bfnOperationEnCours()
{
    return mb_OperationEnCours;
}

/**
* @brief Fonction de recuperation des donnees en provenance de l'objet
* GestionnaireFenetre concernant la LAS.
* La fonction reçoit le code process ainsi que le numero de lot de LAS
* et s'en sert pour instancier un nouvel objet LAS.
* Il ne peut y avoir qu'une seule LAS instanciee.
* @param qsCodeProcess: Le code process en provenance du formulaire de la LAS.
* @param qsNumLot: Le numero de lot en provenance du formulaire de la LAS.
*/
bool PEAO::fnReceptionnerInformationsLAS(
        const std::string& qsCodeProcess,const std::string& qsNumLot)
{
    mLas = new Las(qsCodeProcess, qsNumLot);
    return NULL != mLas;
}


/**
* @brief Destructeur de la classe GestionnaireFenetre.
* Destruction des objets alloues dynamiquement(mLas, mGF_gestFenetre)
*/
PEAO::~PEAO()
{
    if( NULL != mLas )delete mLas;
    if( NULL != mGF_gestFenetre )delete mGF_gestFenetre;
}
