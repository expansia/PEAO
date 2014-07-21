#ifndef F_ARTICLE_HPP
#define F_ARTICLE_HPP

class GestionnaireFenetre;

#include <QDialog>

namespace Ui {
class F_Article;
}

class F_Article : public QDialog
{
    Q_OBJECT

public:
    explicit F_Article(QWidget *parent = 0);
    void fnMemoPtrGestionnaireFenetre(GestionnaireFenetre *memoPtrGF);
    ~F_Article();

private slots:
    void on_btValiderArt_clicked();

    void on_btAnnulerArt_clicked();

private:
    Ui::F_Article *ui;
    GestionnaireFenetre *mptrGestionnaireFenetre;
};

#endif // F_ARTICLE_HPP
