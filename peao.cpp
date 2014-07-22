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
     if( mGF_gestFenetre )return mGF_gestFenetre->bfnAfficherFenetre(F_PRINCIPALE);
     return false;
}

/**
* @brief Initialisation d'une nouvelle opération de PEAO.
* L'attribut mb_OperationEnCours est mis a true.
* La fenetre du formulaire de la LAS est affiché.
*/
void PEAO::fnInitialiserOperation()
{
    mb_OperationEnCours=true;

    if( mGF_gestFenetre )mGF_gestFenetre->bfnAfficherFenetre(F_FORM_LAS);

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
* Renvoie la valeur du booleen mb_OperationEnCours && NULL != Las.
* @return true si une operation est en cours de traitement et que l'
* objet Las est bien instancié. false sinon.
*/
bool PEAO::bfnOperationEnCours() const
{
    return mb_OperationEnCours && NULL != mLas;
}

/**
* @brief Fonction de recuperation des donnees en provenance de l'objet
* GestionnaireFenetre concernant la LAS.
* La fonction reçoit le code process ainsi que le numero de lot de LAS
* et s'en sert pour instancier un nouvel objet LAS.
* Il ne peut y avoir qu'une seule LAS instanciee.
* @param qsCodeProcess: Le code process en provenance du formulaire de la LAS.
* @param qsNumLot: Le numero de lot en provenance du formulaire de la LAS.
* @return false si l'objet Las n'a pas pu etre instancié, true sinon.
*/
bool PEAO::fnReceptionnerInformationsCreationLAS(
        const std::string& qsCodeProcess,const std::string& qsNumLot)
{
    mLas = new Las(qsCodeProcess, qsNumLot);
    return NULL != mLas;
}


/**
* @brief Fonction de recuperation des donnees en provenance de l'objet
* GestionnaireFenetre concernant un Lot.
* La fonction reçoit le choix de l'article ainsi que le numero de lot article
* et les transferre a la LAS.
* @param sChoixArticle: Le choix de l'article en provenance du formulaire du Lot.
* @param sNumeroLot: Le numero de lot en provenance du formulaire du Lot.
* @return false si l'objet Lot n'a pas pu etre instancié, true sinon.
*/
bool PEAO::bfnReceptionnerInformationsCreationLot(
        const std::string &sChoixArticle, const std::string &sNumeroLot)
{
    if( mLas )return mLas -> bfnReceptionnerInformationsCreationLot(sChoixArticle, sNumeroLot);
    return false;
}


/**
* @brief Fonction de recuperation des donnees en provenance de l'objet
* GestionnaireFenetre concernant un article.
* La fonction reçoit le numero d'article ainsi que le libelle de l'article
* et l'envoi a l'objet Las.
* @param qsNumArt: Le numero d'article en provenance du formulaire de l'article.
* @param qsLibArt: Le libelle de en provenance du formulaire de l'article.
* @return false si l'objet Article n'a pas pu etre instancié, true sinon.
*/
bool PEAO::fnReceptionnerInformationsCreationArticle(
        const std::string& qsNumArt,const std::string& qsLibArt)
{
    //A modifier
    bool retour = false;
    if( NULL == mLas )
    {
        retour = false;
    }
    else
    {
        if( mLas )retour = mLas->fnCreerArticle(qsNumArt, qsLibArt);
        retour = false;
    }
    return retour;
    //mLas = new Las(qsCodeProcess, qsNumLot);
    //return NULL != mLas;
}

/**
* @brief Fonction recuperant et renvoyant la liste de libelle contenu dans l'objet Las.
* @return La liste des libelle. NULL si aucun article n'est instancié.
*/
const std::list<std::string> *PEAO::lstfnRetourListeLibelle()const
{
    if( NULL == mLas )
    {
        return NULL;
    }
    if( mLas )return mLas->fnRetourListeLibelle();
    return NULL;
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
