/******************************************************************************
 *   Société      : EXPANSIA PCAS - route d'Aramon 30390 Aramon (FRANCE)      *
 *   Projet       : PEAO                                                      *
 ******************************************************************************
 *   Module           :                    *
 *   Fichier          : peao.hpp                                              *
 *   Classe           : PEAO                                                  *
 *   Date de création : 17/07/2014                                            *
 *   Auteur           : Cyril Charbonneau                                     *
 *   Langage          : C++                                                   *
 ******************************************************************************
 *   Logiciel                   : Qt 5.3                                      *
 *   Options de compilation     :                                             *
 *   Options d'édition de liens :                                             *
 ******************************************************************************/

#ifndef PEAO_HPP
#define PEAO_HPP

#include <string>
#include <list>

class GestionnaireFenetre;
class Las;

/**
 * @class PEAO
 * @brief Classe de base du logiciel.
 *
 * Cette classe instancie toutes les classes nécéssaires au démarrage du logiciel.
 * Elle transmet les instructions aux autres classes durant le fonctionnement du logiciel.
 * Elle sert également d'intermédiaire lors de la transmission de
 * données d'un module à un autre.
 *
 * exemple:
 * peao.bfnLancerProgrammePrincipal()
 * //Lancement du programme et affichage de la fenetre principale
 *
 */
class PEAO
{
private:
    bool mb_OperationEnCours;
    GestionnaireFenetre *mGF_gestFenetre;
    Las *mLas;
public:
    PEAO();
    bool bfnLancerProgrammePrincipal();
    void fnInitialiserOperation();
    void fnQuitterOperation();
    bool bfnOperationEnCours()const;
    bool fnReceptionnerInformationsCreationLAS(const std::string &qsCodeProcess, const std::string &sNumLot);
    bool fnReceptionnerInformationsCreationArticle(const std::string& sNumArt, const std::string& sLibArt);
    bool bfnReceptionnerInformationsCreationLot(const std::string &sChoixArticle,
                                                const std::string &sNumeroLot, const std::string &sMasseTot);
    bool bfnReceptionnerInformationsCreationContenant(
                        const std::string &sLibArticle, const std::string &sNumLotArticle,
                        const std::string &sMasseNetteContenant, const std::string &sNumContenant ,
                        const bool &bContComplet );
    const std::list<std::string> *lstfnRetourListeLibelle()const;
    ~PEAO();
};

#endif // PEAO_HPP
