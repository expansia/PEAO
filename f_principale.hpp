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
#include <string>
#include <list>

class GestionnaireFenetre;
class QStandardItemModel;
class QStandardItem;

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
private:
    //std::list<std::string> lstLibelleArticle;
    unsigned int muiNombreArticle, muiNombreLot, muiNombreContenant; //TMP
    GestionnaireFenetre *mptrGestionnaireFenetre;
    QStandardItemModel *modeleTreeView, *model2;

    Ui::F_Principale *ui;

public:
    explicit F_Principale( GestionnaireFenetre *gf,  QWidget * parent = 0 );
    void fnAfficherLAS( const std::string & codeProcess, const std::string & numeroDeLot );
    void fnAfficherLot( const std::string & sChoixArticle, const std::string & sNumeroLot,
                                  const std::string & sMasseTot );
    QStandardItem *trouverItemArticleModel(const std::string & qsNumeroLot );
    QStandardItem *trouverItemLotModel(const std::string & sLibelleArticle ,  const std::string & sNumeroLot);
    void fnAfficherNouvelArticle(
    const std::string &numArticle, const std::string & libArticle );
    void fnAfficherContenant(const std::string & sLibArt, const bool &bCompl
                                            , const std::string & sNumCont);
    ~F_Principale();

private slots:

    void on_btnInitialiserOperation_clicked();
    void on_btnQuitterOperation_clicked();
    void on_btnAjouterArticle_clicked();
    void on_btnAjouterLot_clicked();
};
#endif // F_PRINCIPALE_HPP
