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
 * @brief Constructeur de la classe Peao.
 * Les attributs de la classe sont initialisées aux valeurs par défaut.
 * Par défaut, aucune opération n'est en cours.
 * Un pointeur vers Peao est transmis à l'objet
 * "GestionnaireFenetre".
 * Création du gestionnaire de fenêtre (qui possède un pointeur sur l'objet
 * Peao).
 */
Peao::Peao()
{
    mGF_gestFenetre     = NULL;
    mb_OperationEnCours = false;
    mGF_gestFenetre     = new GestionnaireFenetre( this );
    mLas                = NULL;
}


/**
 * @brief Lance la fenêtre principale.
 * Fonction affichant la fenetre principale où l'utilisateur peut
 * choisir l'opération qu'il désire effectuer.
 * @return true si la fenêtre s'est bien lancée, false sinon.
 */
bool Peao::bfnLancerProgrammePrincipal()
{
     if( mGF_gestFenetre )return mGF_gestFenetre->bfnAfficherFenetre( F_PRINCIPALE );
     return false;
}

/**
* @brief Initialisation d'une nouvelle opération de Peao.
* L'attribut mb_OperationEnCours est mis a true.
* La fenetre du formulaire de la LAS est affiché.
*/
void Peao::fnInitialiserOperation()
{
    mb_OperationEnCours = true;

    if( mGF_gestFenetre )mGF_gestFenetre->bfnAfficherFenetre( F_FORM_LAS );

}

/**
* @brief Fonction d'arret d'une operation en cours.
* L'attribut mb_OperationEnCours est mis a false.
* a définir plus tard.
*/
void Peao::fnQuitterOperation()
{
    mb_OperationEnCours = false;
}

/**
* @brief Fonction determinant si une operation est en cours de traitement.
* Renvoie la valeur du booleen mb_OperationEnCours && NULL != Las.
* @return true si une operation est en cours de traitement et que l'
* objet Las est bien instancié. false sinon.
*/
bool Peao::bfnOperationEnCours() const
{
    return mb_OperationEnCours && NULL != mLas;
}

/**
* @brief Fonction de recuperation des donnees en provenance de l'objet
* GestionnaireFenetre concernant la LAS.
* La fonction reçoit le code process ainsi que le numero de lot de LAS
* et s'en sert pour instancier un nouvel objet LAS.
* Il ne peut y avoir qu'une seule LAS instanciee.
* @param sCodeProcess: Le code process en provenance du formulaire de la LAS.
* @param sNumLot: Le numero de lot en provenance du formulaire de la LAS.
* @return false si l'objet Las n'a pas pu etre instancié, true sinon.
*/
bool Peao::fnCreerLAS(
        const std::string & sCodeProcess,const std::string & sNumLot )
{
    mLas = new Las( sCodeProcess, sNumLot );
    return NULL != mLas;
}

/**
* @brief Fonction de recuperation des donnees du formulaire d'un contenant.
* La fonction transfere les donnees necessaires a la creation d'un contenant a l'objet Las.
* @param sLibArt: Le libelle de l'article qui possede le lot.
* @param sNumLotArt: Le numero de lot qui contient le contenant.
* @param sMasseNetteCont: La masse nette du contenant.
* @param sNumCont: Le numero du contenant.
* @param bContCompl: Le choix entre contenant fractionne et complet.
* @return true si l'objet Contenant a bien ete instancie, false sinon.
*/
bool Peao::bfnAjouterContenant( const std::string & sLibArticle, const std::string & sNumLotArticle,
                    const std::string & sMasseNetteContenant, const std::string & sNumContenant ,
                    const bool & bContComplet )
{
    bool retour = false;
    if ( NULL == mLas )
    {
        retour = false;
    }
    else
    {
        retour = mLas->bfnAjouterContenant( sLibArticle, sNumLotArticle, sMasseNetteContenant,
                                           sNumContenant, bContComplet );
    }
    return retour;
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
bool Peao::bfnCreerLot(
        const std::string & sChoixArticle, const std::string & sNumeroLot, const std::string & sMasseTot)
{
    if( mLas )return mLas -> bfnCreerLot( sChoixArticle, sNumeroLot, sMasseTot );
    return false;
}


/**
* @brief Fonction de recuperation des donnees en provenance de l'objet
* GestionnaireFenetre concernant un article.
* La fonction reçoit le numero d'article ainsi que le libelle de l'article
* et l'envoi a l'objet Las.
* @param sNumArt: Le numero d'article en provenance du formulaire de l'article.
* @param sLibArt: Le libelle de en provenance du formulaire de l'article.
* @return false si l'objet Article n'a pas pu etre instancié, true sinon.
*/
bool Peao::fnCreerArticle(
        const std::string & sNumArt,const std::string & sLibArt)
{
    //A modifier
    bool retour = false;
    if( NULL == mLas )
    {
        retour = false;
    }
    else
    {
        if( mLas )
        {
            retour = mLas->fnCreerArticle( sNumArt, sLibArt );
        }
        else
        {
         retour = false;
        }
    }
    return retour;
    //mLas = new Las(sCodeProcess, sNumLot);
    //return NULL != mLas;
}

/**
* @brief Fonction recuperant et renvoyant la liste de libelle contenu dans l'objet Las.
* @return La liste des libelle. NULL si aucun article n'est instancié.
*/
const std::list<std::string> * Peao::lstfnRetourListeLibelle()const
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
Peao::~Peao()
{
    if( NULL != mLas )delete mLas;
    if( NULL != mGF_gestFenetre )delete mGF_gestFenetre;
}
