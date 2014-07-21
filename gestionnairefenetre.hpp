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
class F_Principale;
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
    PEAO *mptrMemoPEAO;
public:
    GestionnaireFenetre(PEAO *ptrPEAO);
    bool bfnAfficherFenetre( const unsigned int &choixFenetre );
    bool bfnOperationEnCours();
    void fnInitialiserOperation();
    bool fnReceptionnerInformationsLAS( const std::string &qsCodeProcess,
                                        const std::string &qsNumLot );
    ~GestionnaireFenetre();
};

#endif // GESTIONNAIREFENETRE_HPP
