#ifndef F_CONTENANT_HPP
#define F_CONTENANT_HPP

#include <QDialog>

class GestionnaireFenetre;

namespace Ui {
class F_Contenant;
}

class F_Contenant : public QDialog
{
    Q_OBJECT
private:
    Ui::F_Contenant *ui;
    GestionnaireFenetre *mptrGestionnaireFenetre;
    unsigned int muiNombreContenant;
public:
    explicit F_Contenant(QWidget *parent = 0);
    void fnMemoPtrGestionnaireFenetre(GestionnaireFenetre *memoPtrGF);
    void envoiDonneesLot( const std::string &sChoixArticle, const std::string &sNumeroLot,
                                        const std::string &sMasseTot );
    void fnEcrireInformationsContenant( const std::string &sChaineAEcrire );
    ~F_Contenant();

private slots:
    void on_btAjoutContenant_clicked();

    void on_btSortirForm_clicked();
};

#endif // F_CONTENANT_HPP
