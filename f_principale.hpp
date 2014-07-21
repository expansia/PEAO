/******************************************************************************
 *   Société      : EXPANSIA PCAS - route d'Aramon 30390 Aramon (FRANCE)      *
 *   Projet       : PEAO                                                      *
 ******************************************************************************
 *   Module           : Affichage                   *
 *   Fichier          : f_principale.hpp                                        *
 *   Classe           : F_Principale                                      *
 *   Date de création : 17/07/2014                                            *
 *   Auteur           : Cyril Charbonneau                                            *
 *   Langage          : C++                                                   *
 ******************************************************************************
 *   Logiciel                   :                                           *
 *   Options de compilation     :                                             *
 *   Options d'édition de liens :                                             *
 ******************************************************************************/

#ifndef F_PRINCIPALE_HPP
#define F_PRINCIPALE_HPP

#include <QMainWindow>

class GestionnaireFenetre;

namespace Ui {
class F_Principale;
}

/**
 * @class F_Principale
 * @brief Classe contenant le menu d'accueil.
 *
 * Cette classe est invoquée au lancement du logiciel.
 * Elle permet d'entrer le choix de l'opération à effectuer
 * (commencer une nouvelle opération, configurer le logiciel...).
 * Ces informations sont transmisent à la l'objet "PEAO".
 *
 * exemple:
 * mfenetrePrincipale.show();
 * //pour afficher la fenetre
 *
 */
class F_Principale : public QMainWindow
{
    Q_OBJECT

public:
    explicit F_Principale(QWidget *parent = 0);
    void fnMemoPtrGestionnaireFenetre(GestionnaireFenetre *memoPtrGF);
    void fnEcrireInformationsLAS(const std::string &codeProcess, const std::string &numeroDeLot);
    void fnEcrireInformationsNouvelArticle(
            const std::string &numArticle, const std::string &libArticle);
    ~F_Principale();

private slots:

    void on_btnInitialiserOperation_clicked();
    void on_btnQuitterOperation_clicked();

    void on_btAjoutArticle_clicked();

private:
    GestionnaireFenetre *mptrGestionnaireFenetre;
    Ui::F_Principale *ui;
};

#endif // F_PRINCIPALE_HPP
