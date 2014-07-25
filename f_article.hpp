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
private:
    Ui::F_Article *ui;
    GestionnaireFenetre *mptrGestionnaireFenetre;
    void closeEvent ( QCloseEvent * e );
public:
    explicit F_Article( GestionnaireFenetre *gf,  QWidget *parent = 0 );
    ~F_Article();

private slots:
    void on_btValiderArt_clicked();
    void on_btAnnulerArt_clicked();
};

#endif // F_ARTICLE_HPP
