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
#include "peao.hpp"
#include "ui_f_principale.h"
#include <QMessageBox>

/**
* @brief Description en une ligne de la méthode.
*
* @param NomParam1: Description du paramètre 1.
* @return Description de la valeur de retour
* @see Pour renvoyer vers une autre définition
*/
F_Principale::F_Principale(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::F_Principale)
{
    ui->setupUi(this);
}

/**
* @brief Description en une ligne de la méthode.
*
* @param NomParam1: Description du paramètre 1.
* @return Description de la valeur de retour
* @see Pour renvoyer vers une autre définition
*/
void F_Principale::fnMemoPtrGestionnaireFenetre(GestionnaireFenetre *memoPtrGF)
{
    mptrGestionnaireFenetre=memoPtrGF;
}

/**
* @brief Description en une ligne de la méthode.
*
* @param NomParam1: Description du paramètre 1.
* @return Description de la valeur de retour
* @see Pour renvoyer vers une autre définition
*/
F_Principale::~F_Principale()
{
    delete ui;
}

/**
* @brief Description en une ligne de la méthode.
*
* @param NomParam1: Description du paramètre 1.
* @return Description de la valeur de retour
* @see Pour renvoyer vers une autre définition
*/
void F_Principale::on_boutonCommencerLAS_clicked()
{
    //si une opération est déja en cours
   if( mptrGestionnaireFenetre->ptrfnObtenirPointeurPEAO()->
            bfnOperationEnCours() )
   {
       QMessageBox::information(this, "Impossible de demarrer une nouvelle operation",
                                "Une operation est deja en cours de traitement");
       return;
   }
    mptrGestionnaireFenetre->ptrfnObtenirPointeurPEAO()->
            fninitialiserOperation();
}

void F_Principale::on_boutonCommencerLAS_2_clicked()
{
    close();
}
