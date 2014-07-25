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
    muiNombreLot = 0;
    mptrGestionnaireFenetre = gf;
    muiNombreArticle = 0;
    if( ui )ui->setupUi( this );
    modeleTreeView = new QStandardItemModel;
    ui->tvLAS->setModel( modeleTreeView );
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
    std::string strBase =  "Numero Article : " + numArticle +
            "    Libelle de l'article' : " + libArticle;
    //choisir l'etiquette en fonction de la taille de la liste de stockage des libelles
    //si la taille de la liste depasse 3 on choisit l'etiquette en fonction d'un modulo
    switch( muiNombreArticle % 3 )
    {
    case 0:
        if( ui && ui->lbArticle1 )ui->lbArticle1->setText( QString( strBase.c_str() ) );
        break;

    case 1:
        if( ui && ui->lbArticle2 )ui->lbArticle2->setText( QString( strBase.c_str() ) );
        break;

    case 2:
        if( ui && ui->lbArticle3 )ui->lbArticle3->setText( QString( strBase.c_str() ) );
        break;
    default:
        break;
     }
    muiNombreArticle++;

    QStandardItem *itemTreeView = new QStandardItem( QString( libArticle.c_str() ) );
    modeleTreeView->appendRow( itemTreeView );
    itemTreeView->setEditable(0);

}

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
    std::string strBase =  "Libelle Article : " + sChoixArticle +
            "    Numero de lot' : " + sNumeroLot + "    Numero de lot' : " + sMasseTot;
    //choisir l'etiquette en fonction de la taille de la liste de stockage des libelles
    //si la taille de la liste depasse 3 on choisit l'etiquette en fonction d'un modulo
    switch( muiNombreLot % 3 )
    {
    case 0:
       if( ui && ui->lbLot1  ) ui->lbLot1->setText( QString( strBase.c_str() ) );
        break;

    case 1:
        if( ui && ui->lbLot2 )ui->lbLot2->setText( QString( strBase.c_str() ) );
        break;

    case 2:
        if( ui && ui->lbLot3 )ui->lbLot3->setText( QString( strBase.c_str() ) );
        break;
    default:
        break;
     }
    muiNombreLot++;

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

/**
 * @brief Trouve l'Item correspondant a l'article correspondant au libelle envoye en parametre.
 * @param sLibelleArticle
 * @return
 */
QStandardItem *F_Principale::trouverItemArticleModel( /*const int & column ,*/
                                                      const std::string & sLibelleArticle )
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
 * @brief Trouve l'Item correspondant a l'article correspondant au libelle envoye en parametre.
 * @param sLibelleArticle
 * @return
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
* @param : sChaineAEcrire : Chaine a ecrire dans une des etiquettes.
*/
void F_Principale::fnAfficherContenant( const std::string & sLibArt, const std::string & sNumLot
                                        , const std::string & sNumCont)
{
    //choisir l'etiquette en fonction de la taille de la liste de stockage des libelles
    //si la taille de la liste depasse 3 on choisit l'etiquette en fonction d'un modulo
    /*switch( muiNombreContenant % 3 )
    {
    case 0:
       if( ui && ui->lbContenant1  ) ui->lbContenant1->setText( QString( sChaineAEcrire.c_str() ) );
        break;

    case 1:
        if( ui && ui->lbContenant2 )ui->lbContenant2->setText( QString( sChaineAEcrire.c_str() ) );
        break;

    case 2:
        if( ui && ui->lbContenant3 )ui->lbContenant3->setText( QString( sChaineAEcrire.c_str() ) );
        break;
    default:
        break;
     }
    muiNombreContenant++;*/

    QStandardItem *ptrItem = trouverItemLotModel( sLibArt, sNumLot );// a debuger))))))))))
    if( NULL == ptrItem )
    {
        return;
    }
    else
    {
        QStandardItem *itemTreeView = new QStandardItem( QString( sNumCont.c_str() ) );
        ptrItem->appendRow( itemTreeView );
        itemTreeView->setEditable(0);
    }
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
