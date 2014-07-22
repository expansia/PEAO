#ifndef F_LOT_HPP
#define F_LOT_HPP

#include <QDialog>

namespace Ui {
class F_Lot;
}

class F_Lot : public QDialog
{
    Q_OBJECT
private:
    Ui::F_Lot *ui;
public:
    explicit F_Lot(QWidget *parent = 0);
    void fnEditionMenuDeroulantChoixArticle(const std::list<std::string> *ptrListLib);
    ~F_Lot();

};

#endif // F_LOT_HPP
