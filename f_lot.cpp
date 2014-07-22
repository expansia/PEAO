#include "f_lot.hpp"
#include "ui_f_lot.h"

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
    ui->setupUi(this);
}

/**
* @brief Reception du pointeur constant de la liste de libelle d'article.
* Et ecriture de ces libelles dans le menu deroulant correspondant.
* @param ptrListLib: Pointeur constant de la liste de libelle.
*/
void F_Lot::fnEditionMenuDeroulantChoixArticle(const std::list<std::string> *ptrListLib)
{
    //vider le menu deroulant
    ui->cbChoixArticle->clear();
    //parcour de toute la liste
    for(std::list<std::string>::const_iterator cstIt = ptrListLib->begin();
       cstIt !=  ptrListLib->end(); ++cstIt)
    {
        //ajout du libelle dans le menu deroulant
        ui->cbChoixArticle->addItem( QString( (*cstIt).c_str() ));
    }
}

/**
* @brief Destructeur de la classe F_Lot.
* Supression de l'interface d'édition de la fenêtre.
*/
F_Lot::~F_Lot()
{
    delete ui;
}
