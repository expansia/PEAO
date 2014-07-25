#ifndef F_LOT_HPP
#define F_LOT_HPP

#include <QDialog>

class GestionnaireFenetre;

namespace Ui {
class F_Lot;
}

/**
 * @class F_Lot
 * @brief Classe contenant le formulaire de création d'un lot.
 *
 * Cette classe est invoquée lorsque l'utilisateur clique sur le bouton
 * "ajouter lot" de la fenêtre principalle.
 * Elle permet de renseigner la masse nette totale et le numéro de lot,
 * Ces informations sont transmises à l'objet "PEAO".
 *
 */
class F_Lot : public QDialog
{
    Q_OBJECT
private:
    Ui::F_Lot *ui;
    GestionnaireFenetre *mptrGestionnaireFenetre;
    void closeEvent ( QCloseEvent * e );
public:
    explicit F_Lot( GestionnaireFenetre *gf, QWidget * parent = 0 );
    void fnEditionMenuDeroulantChoixArticle( const std::list<std::string> * ptrListLib );
    ~F_Lot();

private slots:
    void on_btAnnulerFormLot_clicked();
    void on_btValiderFormLot_clicked();
};

#endif // F_LOT_HPP
