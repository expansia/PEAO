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
#include "f_principale.hpp"
#include "f_las.hpp"
#include "f_article.hpp"
#include "f_lot.hpp"
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
    mptrMemoPEAO=NULL;
    mfenetreLAS = new F_LAS();
    mfenetrePrincipale = new F_Principale();
    mfenetreArticle = new F_Article();
    mptrFenetreLot = new F_Lot();
    //mémorisation du pointeur vers l'objet PEAO
    mptrMemoPEAO = ptrPEAO;
    /*envoie d'un pointeur de l'objet courant(GestionnaireFenetre)
    vers les classes fenetre*/
    if( mfenetrePrincipale )
    {
        mfenetrePrincipale->fnMemoPtrGestionnaireFenetre( this );
    }
    if( mfenetreLAS )
    {
        mfenetreLAS->fnMemoPtrGestionnaireFenetre( this );
    }
    if( mfenetreArticle )
    {
        mfenetreArticle->fnMemoPtrGestionnaireFenetre( this );
    }
    if( mptrFenetreLot )
    {
        mptrFenetreLot -> fnMemoPtrGestionnaireFenetre( this );
    }
}

/**
* @brief Fonction d'affichage des fenetres du logiciel.
* En fonction du parametre reçu la fonction va afficher la fenetre correspondante.
* @param choixFenetre: Un entier determinant la fenetre a afficher.
* @return false si un probleme est survenu lors de l'affichage. true sinon.
*/
bool GestionnaireFenetre::bfnAfficherFenetre(const unsigned int &choixFenetre)
{
    switch(choixFenetre)
    {
    case F_PRINCIPALE:
        if( mfenetrePrincipale )
        {
            mfenetrePrincipale->show();
        }
        break;
    case F_FORM_LAS:
       if( mfenetreLAS )
       {
           mfenetreLAS->show();
       }
        break;
    case F_FORM_CONTENANT:
        break;
    case F_FORM_ARTICLE:
        if( mfenetreArticle )
        {
            mfenetreArticle->show();
        }
        break;
    case F_FORMLOT:
        if( mptrFenetreLot )
        {
            mptrFenetreLot->show();
        }
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
void GestionnaireFenetre::fnReceptionnerInformationsCreationLAS(
        const std::string &qsCodeProcess, const std::string &qsNumLot)
{
    //verification si l'objet Las a bien ete instancie
    if( mptrMemoPEAO  && mptrMemoPEAO->fnReceptionnerInformationsCreationLAS(
                qsCodeProcess, qsNumLot ) )
    {
         if( mfenetrePrincipale )mfenetrePrincipale->fnEcrireInformationsLAS(qsCodeProcess, qsNumLot);
    }
}


/**
* @brief Fonction de recuperation des donnees du formulaire de la LAS.
* La fonction reçoit le code process ainsi que le numero de lot de LAS
* et les renvoie a l'objet PEAO
* @param qsCodeProcess: Le code process en provenance du formulaire de la LAS.
* @param qsNumLot: Le numero de lot en provenance du formulaire de la LAS.
*/
void GestionnaireFenetre::fnReceptionnerInformationsCreationLot(
        const std::string &sChoixArt, const std::string &sNumLot)
{
    //verification si l'objet Lot a bien ete instancie
    if(  mptrMemoPEAO && mptrMemoPEAO->bfnReceptionnerInformationsCreationLot(
                sChoixArt, sNumLot ) )
    {
         if( mfenetrePrincipale )
         {
             mfenetrePrincipale->fnEcrireInformationsLot(sChoixArt, sNumLot);
         }
    }
}



/**
* @brief Fonction de recuperation des donnees du formulaire d'e la LAS'un article.
* La fonction reçoit le numero d'article ainsi que son libelle
* et les renvoie a l'objet PEAO.
* @param qsCodeProcess: Le code process en provenance du formulaire de la LAS.
* @param qsNumLot: Le numero de lot en provenance du formulaire de la LAS.
*/
void GestionnaireFenetre::fnReceptionnerInformationsCreationArticle(
        const std::string &qsNumArticle, const std::string &qsLibArticle)
{
    //verification si l'objet Article a bien ete instancie
    if(  mptrMemoPEAO && mptrMemoPEAO->fnReceptionnerInformationsCreationArticle(
                qsNumArticle, qsLibArticle ) )
    {
         if( mfenetrePrincipale )
         {
             mfenetrePrincipale->fnEcrireInformationsNouvelArticle(qsNumArticle, qsLibArticle);
         }
    }
    else
    {
        //si l'article n'a pas ete instancie
    }
}

/**
* @brief Appel de la fonction de vérification si une operation est en cours.
* Appel de la fonction bfnOperationEnCours() par le pointeur mptrMemoPEAO.
* @return true si une operation est en cours, false sinon.
*/
bool GestionnaireFenetre::bfnOperationEnCours()
{
    if( mptrMemoPEAO )
    {
        return mptrMemoPEAO->bfnOperationEnCours();
    }
    return false;
}

/**
* @brief Recuperation d'un pointeur vers la liste de libelle.
* Appel de la fonction bfnOperationEnCours() par le pointeur mptrMemoPEAO.
* @return true si au moins un article est instancie, false sinon.
*/
bool GestionnaireFenetre::fnDemandeAjoutLot()
{
    bool validation = true;
        const std::list<std::string> *tmpListLib;
        if( mptrMemoPEAO )
        {
            tmpListLib = mptrMemoPEAO->lstfnRetourListeLibelle();
        }
    if( NULL == tmpListLib )
    {
        validation = false;
    }
    else
    {
        if( mptrFenetreLot )
        {
            mptrFenetreLot->fnEditionMenuDeroulantChoixArticle(tmpListLib);
        }
        bfnAfficherFenetre( F_FORMLOT );
    }
    return validation;
}

/**
* @brief Appel de la fonction pour démarrer une operation PEAO dans l'objet PEAO.
* Appel de la fonction fninitialiserOperation() par le pointeur mptrMemoPEAO.
*/
void GestionnaireFenetre::fnInitialiserOperation()
{
    if( mptrMemoPEAO )
    {
        mptrMemoPEAO->fnInitialiserOperation();
    }
}


/**
* @brief Destructeur de la classe GestionnaireFenetre.
*/
GestionnaireFenetre::~GestionnaireFenetre()
{
    delete mfenetrePrincipale;
    delete mfenetreLAS;
    delete mfenetreArticle;
    delete mptrFenetreLot;
}
