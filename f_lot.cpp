#include "f_lot.hpp"
#include "ui_f_lot.h"
#include "gestionnairefenetre.hpp"
#include <QMessageBox>

/**
* @brief Constructeur de la classe F_Lot.
* Liaison du composant avec l'arborescence Qt.
* Création de l'interface graphique pour éditer la fenêtre.
* @param parent: Objet auquel le composant(de Qt) sera lié.
*/
F_Lot::F_Lot(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::F_Lot)
{
    mptrGestionnaireFenetre = NULL;
    if( ui )ui->setupUi(this);
}

/**
* @brief Mémorisation du pointeur vers l'objet GestionnaireFenetre .
* Création d'un accés de la fenetre vers l'objet GestionnaireFenetre.
* @param memoPtrGF: Pointeur vers GestionnaireFenetre.
*/
void F_Lot::fnMemoPtrGestionnaireFenetre(GestionnaireFenetre *memoPtrGF)
{
    mptrGestionnaireFenetre = memoPtrGF;
}


/**
* @brief Reception du pointeur constant de la liste de libelle d'article.
* Et ecriture de ces libelles dans le menu deroulant correspondant.
* @param ptrListLib: Pointeur constant de la liste de libelle.
*/
void F_Lot::fnEditionMenuDeroulantChoixArticle(const std::list<std::string> *ptrListLib)
{
    //vider le menu deroulant
    if( ui )ui->cbChoixArticle->clear();
    //parcour de toute la liste
    if( ptrListLib ){
        for(std::list<std::string>::const_iterator cstIt = ptrListLib->begin();
           cstIt !=  ptrListLib->end(); ++cstIt)
        {
            //ajout du libelle dans le menu deroulant
            if( ui && ui->cbChoixArticle )ui->cbChoixArticle->addItem( QString( (*cstIt).c_str() ));
        }
    }
}

/**
* @brief Reception du signal d'annulation du formulaire de lot
* La fenetre se ferme.
*/
void F_Lot::on_btAnnulerFormLot_clicked()
{
    close();
}

/**
* @brief Reception du signal du bouton de soumission du formulaire de lot.
* Dans un premier temps la fonction va vérifier si tous les champs ont bien été remplis.
* Si tel est le cas ces données vont être envoyées à l'objet
* GestionnaireFenetre.
*/
void F_Lot::on_btValiderFormLot_clicked()
{
    QString textErreur="", receptNumeroDeLot, receptChoixArticle, receptMasseTotaleLot;
    if( ui && ui->leNumLotArticle )receptNumeroDeLot = ui->leNumLotArticle->text();
    //recuperation du numéro de lot du formulaire
    if( ui && ui->cbChoixArticle )receptChoixArticle = ui->cbChoixArticle->currentText();
    //recuperation du choix de l'article dans le menu déroulant
    if( ui && ui->leMasseTotaleLot )receptMasseTotaleLot = ui->leMasseTotaleLot->text();
    //recuperation de la masse totale du formulaire
    if(receptNumeroDeLot.size() == 0)//si champ numéro de lot vide
    {
        textErreur+="Erreur: numéro de lot non entré \n";
        //Stock du message d'erreur dans la chaine à afficher dans la fenetre de résultat
    }
    if(receptChoixArticle.size() == 0)//si champ code process vide
    {
        textErreur+="Erreur: aucun article selectionne\n";
    }
    if(receptMasseTotaleLot.size() == 0)//si champ code process vide
    {
        textErreur+="Erreur: masse totale non entree";
    }
    if(textErreur.size() != 0)//si message d'erreur
    {
        //Entré de la valeur des champs entrés dans la chaine
        QMessageBox::information(this, "Formulaire LAS", textErreur);
        //fenetre pour signaler l'erreur
        return;
    }
        //affichage de la fenêtre
        if( mptrGestionnaireFenetre )mptrGestionnaireFenetre->fnReceptionnerInformationsCreationLot(
                     receptChoixArticle.toStdString(),  receptNumeroDeLot.toStdString(),
                    receptMasseTotaleLot.toStdString());
        close();
}

/**
* @brief Destructeur de la classe F_Lot.
* Supression de l'interface d'édition de la fenêtre.
*/
F_Lot::~F_Lot()
{
    delete ui;
}
