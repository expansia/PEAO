#ifndef F_ARTICLE_HPP
#define F_ARTICLE_HPP

class GestionnaireFenetre;

#include <QDialog>

namespace Ui {
class F_Article;
}

/**
 * @class F_Article
 * @brief Classe contenant le formulaire de création d'un article.
 *
 * Cette classe est invoquée lorsque l'utilisateur clique sur le bouton
 * "ajouter article" de la fenêtre principalle.
 * Elle permet de renseigner le libellé de l'article et le numéro d'article.
 * Ces informations sont transmises à l'objet "PEAO".
 *
 */
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
