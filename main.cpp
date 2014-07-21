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

#include "peao.hpp"
#include <QApplication>

/**
* @brief Fonction principale du programme.
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
 * Ce logiciel est conçu pour assister une procédure de pesée de contenants chimiques.
 * Les fonctions nécessaires sont les suivantes:
 * -Receptions des données de la LAS.
 * -Impression des étiquettes.
 * -Reception des données d'une balance.
 * -Impression des comptes rendus.
 * -Mémorisation des opérations sur un serveur.
 *
 * @section Introduction
 *
 * Le logiciel demande dans un premier temps a l'utilisateur de choisir l'action qu'il
 * désire effectuer.
 * Initialisation d'une opération.
 *
 * Entrée des informations relatives à la LAS (code process, numéro de lot(LAS)).
 *
 * Idem pour les articles(numéro d'article, libelle article),
 * l'utilsateur peut rentrer autant d'articles qu'il souhaite.
 *
 * Entrées des lots obligatoirement associées a un article entré précédemment, et précision
 * du numéro de lot(article).
 *
 * Entrée des contenants obligatoirement associés a un lot entré précédemment,
 * et précision du numéro de contenant .
 * L'utilisateur précisera si il s'agit d'un contenant fractionné ou complet.
 *
 * Apres cela l'utilisateur doit imprimmer
 * les étiquettes de chaque contenant.
 *
 * Les étiquettes possèderont un code barre.
 *
 *
 *
 * Caractéristiques:
 * 		- carctéristique 1
 * 		- carctéristique 2
 *
 * @section Invoking Exécution
 *
 * Le logiciel est en phase de développement, il se lance donc par le biais de l'IDE Qt Creator
 * Exécuter ProjetPEAO.exe
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
 *
 * incude:
 *  #include <QApplication>
 *
 * lib:
 *
 * @section compilation Compilation
 *
 * Qt Creator linke et compile automatiquement.
 *
 * @section install Installation
 *
 * Voir documentation sur l'installation des outils pour le développement
 * sur :
 * "J:\Usine\Projets\PEAO\docs"
 *
 * Pour récuperer les sources taper la commande suivante sous Git Bash:
 *
 * "git clone https://github.com/expansia/PEAO.git"
 *
 * Adresse web du dépot github: "https://github.com/expansia/PEAO"
 *
 * Assurez vous qu'il y est bien les fichiers suivant dans le répertoire de l'exécutable:
 * icudt52.dll
 * icuin52.dll
 * icuuc52.dll
 * libgcc_s_dw2-1.dll
 * libstdc++-6.dll
 * libwinpthread-1.dll
 * Qt5Core.dll
 * Qt5Gui.dll
 * Qt5Widgets.dll
 * platforms/qminimal.dll
 * platforms/qminimald.dll
 * platforms/qoffscreen.dll
 * platforms/qoffscreend.dll
 * platforms/qwindows.dll
 * platforms/qwindowsd.dll
 *
 * Executer PEAO.exe
 *
 *
 * @section license Licence
 *
 *
 * Le logiciel est fourni gratuitement.
 */
