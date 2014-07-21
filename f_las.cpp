/******************************************************************************
 *   Société      : EXPANSIA PCAS - route d'Aramon 30390 Aramon (FRANCE)      *
 *   Projet       : PEAO                                                      *
 ******************************************************************************
 *   Module           : Affichage                                             *
 *   Fichier          : f_las.cpp                                             *
 *   Classe           : F_LAS                                                 *
 *   Date de création : 17/07/2014                                            *
 *   Auteur           : Cyril Charbonneau                                     *
 *   Langage          : C++                                                   *
 ******************************************************************************
 *   Logiciel                   : Qt 5.3                                      *
 *   Options de compilation     :                                             *
 *   Options d'édition de liens :                                             *
 ******************************************************************************/


#include "f_las.hpp"
#include "ui_f_las.h"
#include <QMessageBox>
#include "gestionnairefenetre.hpp"

/**
* @brief Constructeur de la classe F_LAS.
* Liaison du composant avec l'arborescence Qt.
* Création de l'interface graphique pour éditer la fenêtre.
* @param parent: Objet auquel le composant(de Qt) sera lié.
*/
F_LAS::F_LAS(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::F_LAS)
{
    ui->setupUi(this);
}

/**
* @brief Mémorisation du pointeur vers l'objet GestionnaireFenetre .
* Création d'un accés de la fenetre vers l'objet GestionnaireFenetre.
* @param memoPtrGF: Pointeur vers GestionnaireFenetre.
*/
void F_LAS::fnMemoPtrGestionnaireFenetre(GestionnaireFenetre *memoPtrGF)
{
    mptrGestionnaireFenetre = memoPtrGF;
}

/**
* @brief Reception du signal du bouton de soumission du formulaire LAS.
* Dans un premier temps la fonction va vérifier si tous les champs ont bien été remplis.
* Si tel est le cas ces données vont être envoyées à l'objet
* GestionnaireFenetre.
*/
void F_LAS::on_buttonBox_accepted()
{
    QString textAAfficher="", receptNumeroDeLot, receptCodeProcess;
    receptNumeroDeLot = ui->leNumLot->text();
    //recuperation du numéro de lot du formulaire
    receptCodeProcess = ui->leCodeProcess->text();
    //recuperation du code process du formulaire
    if(receptNumeroDeLot.size() == 0)//si champ numéro de lot vide
    {
        textAAfficher+="Erreur: numéro de lot non entré \n";
        //Stock du message d'erreur dans la chaine à afficher dans la fenetre de résultat
    }
    if(receptCodeProcess.size() == 0)//si champ code process vide
    {
        textAAfficher+="Erreur: code process non entré";
    }
    if(textAAfficher.size() != 0)//si message d'erreur
    {
        //Entré de la valeur des champs entrés dans la chaine
        //textAAfficher += "Code process : "+receptCodeProcess +
          //      "\nNuméro de lot : " + receptNumeroDeLot;
        QMessageBox::information(this, "Formulaire LAS", textAAfficher);
        //fenetre pour signaler l'erreur
        return;
    }
        //affichage de la fenêtre
        mptrGestionnaireFenetre->fnReceptionnerInformationsCreationLAS(
                     receptCodeProcess.toStdString(),  receptNumeroDeLot.toStdString() );

}

/**
* @brief Destructeur de la classe F_LAS.
* Supression de l'interface d'édition de la fenêtre.
*/
F_LAS::~F_LAS()
{
    delete ui;
}
