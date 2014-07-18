/******************************************************************************
 *   Société      : EXPANSIA PCAS - route d'Aramon 30390 Aramon (FRANCE)      *
 *   Projet       : PEAO                                                      *
 ******************************************************************************
 *   Module           :                                                       *
 *   Fichier          : constantes.hpp                                        *
 *   Classe           :                                                       *
 *   Date de création : 17/07/2014                                            *
 *   Auteur           : Cyril Charbonneau                                     *
 *   Langage          : C++                                                   *
 ******************************************************************************
 *   Logiciel                   : Qt 5.3                                      *
 *   Options de compilation     :                                             *
 *   Options d'édition de liens :                                             *
 ******************************************************************************/

#ifndef CONSTANTES_HPP
#define CONSTANTES_HPP

/**
* @enum eFenetre
* @brief Nom des fenêtres affichées par le gestionnaire de fenêtre.
*/

enum{F_PRINCIPALE, F_FORM_LAS, F_FORM_CONTENANT, F_FORM_ARTICLE, F_FORMLOT};

//représentation des actions possibles à effectuer par l'objet PEAO
/**
* @enum eAction
* @brief représentation des actions possibles à effectuer par l'objet PEAO.
*/
enum{INITIALISER_OPERATION, SAISIR_INFOLAS, CREER_ARTICLE};
#endif // CONSTANTES_HPP
