/******************************************************************************
 *   Société      : EXPANSIA PCAS - route d'Aramon 30390 Aramon (FRANCE)      *
 *   Projet       : PEAO                                                      *
 ******************************************************************************
 *   Module           : Affichage                                             *
 *   Fichier          : main.cpp                                              *
 *   Classe           :                                                       *
 *   Date de création : 17/07/2014                                            *
 *   Auteur           : Cyril Charbonneau                                     *
 *   Langage          : C++                                                   *
 ******************************************************************************
 *   Logiciel                   : Qt 5.3                                      *
 *   Options de compilation     :                                             *
 *   Options d'édition de liens :                                             *
 ******************************************************************************/

#include "f_las.hpp"
#include "peao.hpp"
#include <QApplication>

/**
* @brief Fonction principale du programme.
*
* @param argc: nombre d'argument sur la ligne de commande.
* @param argv: liste des arguments.
* @return 0 si OK, EXIT_FAILURE sinon
* @see Pour renvoyer vers une autre définition
*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PEAO peao;
    if( false == peao.bfnLancerProgrammePrincipal() )
    {
        return EXIT_FAILURE;
    }
    return a.exec();
}


/** @mainpage PEAO
 *
 * Ce logiciel est conçu pour assister une procédure de pesée assistée par ordinateur(PEAO).
 *
 *
 * @section Intro Introduction
 *
 * Description plus complète du logiciel
 *  (sur plusieurs lignes).
 *
 * On fera la liste de ses différentes caractéristiques:
 * 		- carctéristique 1
 * 		- carctéristique 2
 *
 * @section Invoking Exécution
 *
 * Comment faire pour lancer le logiciel et ses différents paramètres.
 *
 *
 * @section Configuration Fichier de configuration
 *
 * Expliquer si le logiciel a besoin d'un fichier de configuration
 * où il doit se trouver, le nom qu'il doit porter, et comment le
 * remplir (syntaxe du fichier).
 *
 *
 * @section Trace Fichier de trace
 *
 * Voir fichier de configuration.
 *
 *
 * @section Option Paramètres du programme
 *
 * Description complète de tous les paramètres du programme.
 *
 *
 * @subsection Param1 Paramètre 1
 *
 * Description de ce paramètre.
 *
 * @subsection Param2 Paramètre 2
 *
 * Description de ce paramètre.
 *
 *
 * @section howto Comment utiliser le programme
 *
 * @subsection  Fonct1 Comment utiliser la fonction1?
 *
 * Description de l'utilisation de la fonction1.
 *
 * @subsection  Fonct2 Comment utiliser la fonction2?
 *
 * Description de l'utilisation de la fonction2.
 *
 *
 * @section supports Environnement d'exécution
 *
 * Ce logiciel a été développé sur le système suivant:
 *
 *   - Windows 7 Pro 64
 *
 *
 * @section depends Dépendances
 *
 * Ce programme utilise différentes bibliothèque pour pouvoir fonctionner.
 * Les bibliothèques suivantes doivent être installées avant de compiler
 * le programme:
 *
 * - Qt
 * - lib2
 * - lib3
 *
 * incude:
 *   -Iinclude1
 *   -Iinclude2
 *
 * lib:
 *   -lmalib1
 *
 * @section compilation Compilation
 *
 * Décrire les différentes étapes de compilation du logiciel.
 *
 * The executable file is now in folder src.
 *
 * @section install Installation
 *
 * Décrire la procédure complète d'installation sur un poste ne possédant aucun
 * outils de développement (poste utilisateur).
 *
 *
 * @section license Licence
 *
 * Décrire les termes de la licence sous laquelle est distribué le logiciel.
 *
 */
