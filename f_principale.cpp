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

#include "f_principale.hpp"
#include "gestionnairefenetre.hpp"
#include "ui_f_principale.h"
#include <QMessageBox>

/**
* @brief Constructeur de la classe F_Principale.
* Liaison du composant avec l'arborescence Qt.
* Création de l'interface graphique pour éditer la fenêtre.
* @param parent: Objet auquel le composant(de Qt) sera lié.
*/
F_Principale::F_Principale(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::F_Principale)
{
    ui->setupUi(this);
}

/**
* @brief Mémorisation du pointeur vers l'objet GestionnaireFenetre .
* Création d'un accés de la fenetre vers l'objet GestionnaireFenetre.
* @param memoPtrGF: Pointeur vers GestionnaireFenetre.
*/
void F_Principale::fnMemoPtrGestionnaireFenetre(GestionnaireFenetre *memoPtrGF)
{
    mptrGestionnaireFenetre=memoPtrGF;
}


/**
* @brief Reception du signal du bouton pour débuter une opération LAS.
* L'information sera envoyé à l'objet GestionnaireFenetre.
*/
void F_Principale::on_btnInitialiserOperation_clicked()
{
    //si une opération est déja en cours
   if( mptrGestionnaireFenetre->bfnOperationEnCours() )
   {
       QMessageBox::information(this, "Impossible de demarrer une nouvelle operation",
                                "Une operation est deja en cours de traitement");
       return;
   }
    mptrGestionnaireFenetre->fnInitialiserOperation();
    ui->lbOperationEnCours->setText( "Operation en cours" );
}

/**
* @brief Affichage des informations de la LAS.
*
* @param codeProcess: Code process de la LAS
* @param numeroDeLot: Numero de lot de la LAS
*/
void F_Principale::fnEcrireInformationsLAS(
        const std::string &codeProcess, const std::string &numeroDeLot)
{
    std::string strBase = "Code process : " + codeProcess + "    Numero de lot : " + numeroDeLot;
    ui->infoLAS->setText( QString( strBase.c_str() ) );
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
*/
void F_Principale::on_btAjoutArticle_clicked()
{
    if( mptrGestionnaireFenetre->bfnOperationEnCours() )
    {

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


