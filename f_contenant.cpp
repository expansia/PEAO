#include "f_contenant.hpp"
#include "ui_f_contenant.h"
#include "gestionnairefenetre.hpp"
#include <QMessageBox>

/**
* @brief Constructeur de la classe F_Contenant.
* Liaison du composant avec l'arborescence Qt.
* Création de l'interface graphique pour éditer la fenêtre.
* @param parent: Objet auquel le composant(de Qt) sera lié.
*/
F_Contenant::F_Contenant(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::F_Contenant)
{
    mptrGestionnaireFenetre=NULL;
    ui->setupUi(this);
}

/**
* @brief Fonction de transfert des donnees pour la creation des contenants associés au lot
* vers le formulaire en question.
* @param sChoixArticle: Le choix de l'article en provenance du formulaire du Lot.
* @param sNumeroLot: Le numero de lot en provenance du formulaire du Lot.
* @param sMasseTot: La masse totale du lot.
*/
void F_Contenant::envoiDonneesLot( const std::string &sChoixArticle, const std::string &sNumeroLot,
                                    const std::string &sMasseTot )
{
    if( ui && ui->lbMasseTotaleLot )ui->lbMasseTotaleLot->setText( QString( sMasseTot.c_str() ) );
    if( ui && ui->lbLibArt )ui->lbLibArt->setText( QString( sChoixArticle.c_str() ) );
    if( ui && ui->lbNumLotArt )ui->lbNumLotArt->setText( QString( sNumeroLot.c_str() ) );
    muiNombreContenant = 0;
}

/**
* @brief Reception du signal du bouton d'ajout d'un contenant au lot concerné du formulaire Contenant.
* Dans un premier temps la fonction va vérifier si tous les champs ont bien été remplis.
* Si tel est le cas ces données vont être envoyées à l'objet
* GestionnaireFenetre.
*/
void F_Contenant::on_btAjoutContenant_clicked()
{
    bool bContComplet=true;
    QString textErreur="", receptNumeroContenant, receptMasseNetteCont;

    if( ui && ui->leNumCont )receptNumeroContenant = ui->leNumCont->text();
    //recuperation du numéro d'e lot'article du formulaire
    if( ui && ui->leMasseNetteCont )receptMasseNetteCont = ui->leMasseNetteCont->text();
    //recuperation du libelle de l'article du formulaire
    if( ui && ui->rdContComplet )
    {
        bContComplet = ui->rdContComplet->isChecked ();
    }
    //recuperation du choix entre complet et fractionne du formulaire
    if(receptNumeroContenant.size() == 0)//si champ numéro de contenant vide
    {
        textErreur+="Erreur: numéro de contenant non entré \n";
        //Stock du message d'erreur dans la chaine à afficher dans la fenetre de résultat
    }
    if(receptMasseNetteCont.size() == 0)//si champ masse nette
    {
        textErreur+="Erreur: Masse nette contenant non entree\n";
    }
    if( ( ui && ui->rdContComplet && false == ui->rdContComplet->isChecked() ) &&
            ( ui && ui->rdContFractionne && false == ui->rdContFractionne->isChecked() ) )
        //si choix contenant complet non renseigne
    {
        textErreur+="Erreur: choix contenant complet ou fractionne non renseigne";
    }
    if(textErreur.size() != 0)//si message d'erreur
    {
        QMessageBox::information(this, "Formulaire Contenant", textErreur);
        //fenetre pour signaler l'erreur
        return;
    }
        if( mptrGestionnaireFenetre )
        {
            if( ui && ui->lbLibArt && ui->lbNumLotArt && ui->leMasseNetteCont && ui->leNumCont )
            {
                if( false == mptrGestionnaireFenetre->bfnAjouterContenant(
                        ui->lbLibArt->text().toStdString(), ui->lbNumLotArt->text().toStdString(),
                        ui->leMasseNetteCont->text().toStdString(),  ui->leNumCont->text().toStdString() ,
                        bContComplet ) )
                {
                    QMessageBox::information(this, "Formulaire Contenant", "Erreur: Le contenant n'a pas pu etre cree");
                }
            }
        }

}

/**
* @brief Affichage des informations du nouveau contenant dans la fenetre du formulaire des contenants.
*
* @param : sChaineAEcrire : Chaine a ecrire dans une des etiquettes.
*/
void F_Contenant::fnEcrireInformationsContenant( const std::string &sChaineAEcrire )
{
    //choisir l'etiquette en fonction de la taille de la liste de stockage des libelles
    //si la taille de la liste depasse 3 on choisit l'etiquette en fonction d'un modulo
    switch( muiNombreContenant % 3 )
    {
    case 0:
       if( ui && ui->lbFormContenant1  ) ui->lbFormContenant1->setText( QString( sChaineAEcrire.c_str() ) );
        break;

    case 1:
        if( ui && ui->lbFormContenant2 )ui->lbFormContenant2->setText( QString( sChaineAEcrire.c_str() ) );
        break;

    case 2:
        if( ui && ui->lbFormContenant3 )ui->lbFormContenant3->setText( QString( sChaineAEcrire.c_str() ) );
        break;
    default:
        break;
     }
    muiNombreContenant++;
}


/**
* @brief Mémorisation du pointeur vers l'objet GestionnaireFenetre .
* Création d'un accés de la fenetre vers l'objet GestionnaireFenetre.
* @param memoPtrGF: Pointeur vers GestionnaireFenetre.
*/
void F_Contenant::fnMemoPtrGestionnaireFenetre(GestionnaireFenetre *memoPtrGF)
{
    mptrGestionnaireFenetre = memoPtrGF;
}

/**
* @brief Destructeur de la classe F_Contenant.
* Supression de l'interface d'édition de la fenêtre.
*/
F_Contenant::~F_Contenant()
{
    delete ui;
}

/**
* @brief Reception du signal du bouton pour quitter le formulaire des contenants.
*/
void F_Contenant::on_btSortirForm_clicked()
{
    close();
}
