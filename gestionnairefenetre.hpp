/******************************************************************************
 *   Société      : EXPANSIA PCAS - route d'Aramon 30390 Aramon (FRANCE)      *
 *   Projet       : PEAO                                                      *
 ******************************************************************************
 *   Module           : Affichage                   *
 *   Fichier          : gestionnairefenetre.hpp                                        *
 *   Classe           : GestionnaireFenetre                                      *
 *   Date de création : 17/07/2014                                            *
 *   Auteur           : Cyril Charbonneau                                            *
 *   Langage          : C++                                                   *
 ******************************************************************************
 *   Logiciel                   :                                           *
 *   Options de compilation     :                                             *
 *   Options d'édition de liens :                                             *
 ******************************************************************************/

#ifndef GESTIONNAIREFENETRE_HPP
#define GESTIONNAIREFENETRE_HPP

#include <string>

class F_LAS;
class F_Lot;
class F_Principale;
class F_Contenant;
class F_Article;
class PEAO;

/**
 * @class GestionnaireFenetre
 * @brief Classe de gestion des fenetres.
 *
 * Cette classe permet de gérer l'affichage des différentes fenetres du logiciel.
 * Elle assure également le liens entre les fenêtres et "PEAO"
 * pour transmettre les données.
 *
 * exemple:
 * mGF_gestFenetre->bfnAfficherFenetre(F_PRINCIPALE);
 * //pour demander à afficher une fenetre
 *
 */
class GestionnaireFenetre
{
private:
    F_Principale *mfenetrePrincipale;
    F_LAS *mfenetreLAS;
    F_Article *mfenetreArticle;
    PEAO *mptrMemoPEAO;
    F_Contenant *mptrMemoFenetreContenant;
    F_Lot *mptrFenetreLot;
public:
    GestionnaireFenetre(PEAO *ptrPEAO);
    bool bfnAfficherFenetre( const unsigned int &choixFenetre );
    bool bfnOperationEnCours();
    void fnInitialiserOperation();
    bool fnDemandeAjoutLot();
    void fnReceptionnerInformationsCreationLAS( const std::string &sCodeProcess,
                                        const std::string &sNumLot );
    void fnReceptionnerInformationsCreationLot(const std::string &sChoixArt,
                                               const std::string &sNumLot, const std::string &sMasseTotale);
    void fnReceptionnerInformationsCreationArticle(const std::string &sNumArticle, const std::string &sLibArticle);
    bool bfnReceptionnerInformationsCreationContenant(
                        const std::string &sLibArt, const std::string &sNumLotArt,
                        const std::string &sMasseNetteCont, const std::string &sNumCont ,
                        const bool &bContCompl );
    ~GestionnaireFenetre();
};

#endif // GESTIONNAIREFENETRE_HPP
