#ifndef F_CONTENANT_HPP
#define F_CONTENANT_HPP

#include <QDialog>

class GestionnaireFenetre;

namespace Ui {
class F_Contenant;
}

/**
 * @class F_Contenant
 * @brief Classe contenant le formulaire de création d'un contenant.
 *
 * Cette classe est invoquée lorsque l'utilisateur clique sur le bouton
 * "ajouter contenant" de la fenêtre principalle.
 * Elle permet de renseigner la masse nette du contenant son numéro de contenant
 * et s'il s'agit d'un contenant fractionné ou complet.
 * Ces informations sont transmises à l'objet "PEAO".
 *
 */
class F_Contenant : public QDialog
{
    Q_OBJECT
private:
    Ui::F_Contenant *ui;
    GestionnaireFenetre *mptrGestionnaireFenetre;
    unsigned int muiNombreContenant;
    void closeEvent ( QCloseEvent * e );
public:
    explicit F_Contenant( GestionnaireFenetre *gf,  QWidget *parent = 0 );
    void envoiDonneesLot( const std::string &sChoixArticle, const std::string &sNumeroLot,
                                        const std::string & sMasseTot );
    void fnAfficherContenant( const std::string & sChaineAEcrire );
    ~F_Contenant();

private slots:
    void on_btAjoutContenant_clicked();

    void on_btSortirForm_clicked();
};

#endif // F_CONTENANT_HPP
