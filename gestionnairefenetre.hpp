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

#include "f_las.hpp"
#include "f_principale.hpp"

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
    F_Principale mfenetrePrincipale;
    F_LAS mfenetreLAS;
    PEAO *mptrMemoPEAO;
public:
    GestionnaireFenetre(PEAO *ptrPEAO);
    bool bfnAfficherFenetre(unsigned int choixFenetre);
    bool bfnOperationEnCours();
    void fninitialiserOperation();
    void fnreceptionnerInformationsLAS(const QString& qsCodeProcess, const QString& qsNumLot);
    ~GestionnaireFenetre();
};

#endif // GESTIONNAIREFENETRE_HPP
