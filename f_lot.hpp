#ifndef F_LOT_HPP
#define F_LOT_HPP

#include <QDialog>

class GestionnaireFenetre;

namespace Ui {
class F_Lot;
}

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
