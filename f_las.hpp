/******************************************************************************
 *   Société      : EXPANSIA PCAS - route d'Aramon 30390 Aramon (FRANCE)      *
 *   Projet       : PEAO                                                      *
 ******************************************************************************
 *   Module           : Affichage                                             *
 *   Fichier          : f_las.hpp                                             *
 *   Classe           : F_LAS                                                 *
 *   Date de création : 17/07/2014                                            *
 *   Auteur           : Cyril Charbonneau                                     *
 *   Langage          : C++                                                   *
 ******************************************************************************
 *   Logiciel                   : Qt 5.3                                      *
 *   Options de compilation     :                                             *
 *   Options d'édition de liens :                                             *
 ******************************************************************************/

#ifndef F_LAS_HPP
#define F_LAS_HPP

#include <QDialog>

class GestionnaireFenetre;

namespace Ui {
class F_LAS;
}

/**
 * @class F_LAS
 * @brief Classe contenant le formulaire de création d'une LAS.
 *
 * Cette classe est invoquée au début d'une opération de PEAO.
 * Elle permet de renseigner le code process et le numéro de lot,
 * informations permettant d'identifier une LAS.
 * Ces informations sont transmises à l'objet "PEAO".
 *
 * exemple:
 * F_LAS mfenetreLAS;
 * mfenetreLAS.show();
 * //pour afficher la fenetre
 *
 */
class F_LAS : public QDialog
{
    Q_OBJECT

private:
    GestionnaireFenetre *mptrGestionnaireFenetre;
    Ui::F_LAS *ui;

public:
    explicit F_LAS(QWidget *parent = 0);
    void fnMemoPtrGestionnaireFenetre(GestionnaireFenetre *memoPtrGF);
    ~F_LAS();

private slots:
    void on_buttonBox_accepted();

};

#endif // F_LAS_HPP
