/******************************************************************************
 *   Société      : EXPANSIA PCAS - route d'Aramon 30390 Aramon (FRANCE)      *
 *   Projet       : PEAO                                                      *
 ******************************************************************************
 *   Module           : Affichage                   *
 *   Fichier          : f_principale.cpp                                        *
 *   Classe           : F_Principale                                      *
 *   Date de création : 17/07/2014                                            *
 *   Auteur           : Cyril Charbonneau                                            *
 *   Langage          : C++                                                   *
 ******************************************************************************
 *   Logiciel                   :                                           *
 *   Options de compilation     :                                             *
 *   Options d'édition de liens :                                             *
 ******************************************************************************/

#include "constantes.hpp"
#include "f_principale.hpp"
#include "gestionnairefenetre.hpp"
#include "ui_f_principale.h"
#include <QMessageBox>
#include <QStandardItemModel>

/**
* @brief Constructeur de la classe F_Principale.
* Liaison du composant avec l'arborescence Qt.
* Création de l'interface graphique pour éditer la fenêtre.
* @param parent: Objet auquel le composant(de Qt) sera lié.
*/
F_Principale::F_Principale( GestionnaireFenetre *gf,  QWidget *parent ) :
    QMainWindow( parent ),
    ui( new Ui::F_Principale )
{
    muiNombreContenant = 0;
    muiNombreLot = 0;
    mptrGestionnaireFenetre = gf;
    muiNombreArticle = 0;
    if( ui )ui->setupUi( this );
    modeleTreeView = new QStandardItemModel;
    ui->tvLAS->setModel( modeleTreeView );

//Ecriture des titres de colonnes dans la table de contenants
    model2 = new QStandardItemModel( 100, 3 );
    model2->setHorizontalHeaderItem( 0, new QStandardItem( "Numéro de contenant" ) );
    model2->setHorizontalHeaderItem( 1, new QStandardItem( "Masse nette" ) );
    model2->setHorizontalHeaderItem( 2, new QStandardItem( "Fractionné" ) );

    ui->tableV->setModel( model2 );
}


/**
* @brief Reception du signal du bouton pour débuter une opération LAS.
* L'information sera envoyé à l'objet GestionnaireFenetre.
*/
void F_Principale::on_btnInitialiserOperation_clicked()
{
    //si une opération est déja en cours
   if( mptrGestionnaireFenetre && mptrGestionnaireFenetre->bfnOperationEnCours() )
   {
       QMessageBox::information( this, "Impossible de demarrer une nouvelle operation",
                                "Une operation est deja en cours de traitement" );
       return;
   }
    if( mptrGestionnaireFenetre )mptrGestionnaireFenetre->fnInitialiserOperation();
    if( ui && ui-> lbOperationEnCours )ui->lbOperationEnCours->setText( "Operation en cours" );
}

/**
* @brief Affichage des informations de la LAS.
*
* @param codeProcess: Code process de la LAS
* @param numeroDeLot: Numero de lot de la LAS
*/
void F_Principale::fnAfficherLAS(
        const std::string & codeProcess, const std::string & numeroDeLot )
{
    std::string strBase = "Code process : " + codeProcess + "    Numero de lot : " + numeroDeLot;
    if( ui && ui-> infoLAS )ui->infoLAS->setText( QString( strBase.c_str() ) );
}

/**
* @brief Affichage des informations du nouvel article dans la fenetre principalle.
*
* @param numArticle: Numero d'article.
* @param libArticle: Libelle de l'article.
*/
void F_Principale::fnAfficherNouvelArticle(
        const std::string & numArticle, const std::string & libArticle )
{
    QStandardItem *itemTreeView = new QStandardItem( QString( libArticle.c_str() ) );
    modeleTreeView->appendRow( itemTreeView );
    itemTreeView->setEditable(0);
}
//A modifier parametres en trop

/**
* @brief Affichage des informations du nouveau lot dans la fenetre principalle.
*
* @param numArticle: Numero d'article.
* @param libArticle: Libelle de l'article.
*/
void F_Principale::fnAfficherLot(
        const std::string & sChoixArticle,
        const std::string & sNumeroLot,
        const std::string & sMasseTot )
{

    QStandardItem *ptrItem = trouverItemArticleModel( sChoixArticle );
    if( NULL == ptrItem )
    {
        return;
    }
    else
    {
        QStandardItem *itemTreeView = new QStandardItem( QString( sNumeroLot.c_str() ) );
        ptrItem->appendRow( itemTreeView );
        itemTreeView->setEditable(0);
    }
}
//A modifier parametres en trop

/**
 * @brief Trouve l'Item correspondant a l'article correspondant au libelle envoye en parametre.
 * @param sLibelleArticle le libelle de l'article
 * @return L'adresse de l'objet representatif de l'article recherche dans le QTreeView.
 * NULL si l'objet n'a pas ete trouve.
 */
QStandardItem *F_Principale::trouverItemArticleModel( const std::string & sLibelleArticle )
{
    QStandardItem *retour = NULL;
   // QString qsNumeroDeLot( sLibelleArticle.c_str() ) ;
    QList<QStandardItem *> lListeArticle = modeleTreeView->findItems( sLibelleArticle.c_str() );

    for( int i = 0 ;i < lListeArticle.size() ; ++i )
    {

        if( sLibelleArticle.c_str() ==  lListeArticle.at( i )->text() )
        {
            retour = lListeArticle.at( i );
            break;
        }
    }
    return retour;
}


/**
 * @brief Trouve l'Item correspondant au lot correspondant au libelle et au numero de lot
 * envoye en parametre.
 * @param sLibelleArticle le libelle de l'article.
 * @param sNumeroLot le numero de lot.
 * @return L'adresse de l'objet representatif du lot recherche dans le QTreeView.
 * NULL si l'objet n'a pas ete trouve.
 */
QStandardItem *F_Principale::trouverItemLotModel(  const std::string & sLibelleArticle,
        const std::string & sNumeroLot )
{
    QStandardItem *retour = NULL;
    QStandardItem *ptrItemArt = trouverItemArticleModel( sLibelleArticle ), *ptrItemLot;
    if( NULL != ptrItemArt )
    {
        //QString qsNumeroDeLot( sLibelleArticle.c_str() ) ;
        //QList<QStandardItem *> lListeArticle = ptrItemArt->findItems( sLibelleArticle );

        for( int i = 0 ;i < ptrItemArt->rowCount () ; ++i )
        {
            ptrItemLot = ptrItemArt->takeChild ( i );
            if( QString(sNumeroLot.c_str() ) ==  ptrItemLot->text() )
            {
                retour = ptrItemLot;
                break;
            }
        }
    }
    return retour;
}


/**
* @brief Affichage des informations du nouveau contenant dans la fenetre principalle.
*
* @param : sMasseCont : La masse nette du contenant.
* @param : bCompl : Le booleen determinant si le contenant est complet ou fractionne.
* @param : sNumCont : Le numero du contenant.
*/
void F_Principale::fnAfficherContenant( const std::string & sMasseCont,
                                        const bool & bCompl,
                                        const std::string & sNumCont)
{

    model2->setItem( muiNombreContenant, 0, new QStandardItem( QString( sNumCont
                                                                        .c_str() ) ));
    model2->setItem( muiNombreContenant, 1, new QStandardItem( QString( sMasseCont
                                                                        .c_str() ) ));
    if( bCompl )
    {
        model2->setItem( muiNombreContenant, 2, new QStandardItem( QString( "Complet" ) ) );
    }
    else
    {
        model2->setItem( muiNombreContenant, 2, new QStandardItem( QString( "Fractionne" ) ) );

    }

    muiNombreContenant++;

    /*QStandardItem *ptrItem = trouverItemLotModel( sLibArt, sNumLot );// a debuger))))))))))
    if( NULL == ptrItem )
    {
        return;
    }
    else
    {
        QStandardItem *item = new QStandardItem( QString( sNumCont.c_str() ) );
        ptrItem->appendRow( item );
        //itemTreeView->setEditable(0);
    }*/
}

/**
* @brief Reception du signal du bouton pour stopper une opération LAS.
* (à définir plus tard)
*/
void F_Principale::on_btnQuitterOperation_clicked()
{
    close();
}

/**
* @brief Reception du signal du bouton pour ajouter un article.
* Verification qu'une operation est bien en cours,
* et demande d'affichage du formulaire de l'article.
*/
void F_Principale::on_btnAjouterArticle_clicked()
{
    //si operation en cours
    if( mptrGestionnaireFenetre && mptrGestionnaireFenetre->bfnOperationEnCours() )
    {
       if( mptrGestionnaireFenetre )mptrGestionnaireFenetre->bfnAfficherFenetre( F_FORM_ARTICLE );
    }
    else
    {
        QMessageBox::information( this, "Impossible d'ajouter un nouvel article",
                                 "L'operation n'est pas initialisee" );
    }
}

/**
* @brief Reception du signal du bouton pour ajouter un lot à un article.
* Envoi de l'information a l'objet GestionnaireFenetre.
*/
void F_Principale::on_btnAjouterLot_clicked()
{
    if(  mptrGestionnaireFenetre && false == mptrGestionnaireFenetre->fnDemandeAjoutLot() )
    {
        QMessageBox::information( this, "Impossible d'ajouter un nouveau lot",
                                 "Veuillez entrer au moins 1 article." );
    }
}


/**
* @brief Destructeur de la classe F_Principale.
* Supression de l'interface d'édition de la fenêtre.
*/

F_Principale::~F_Principale()
{
    delete ui;
}
