#include "las.hpp"
#include "article.hpp"

/**
* @brief Constructeur de la classe Las.
*
* @param qsCodeProcess: Code Process de la LAS.
* @param qsNumLot: Numero de lot de la LAS.
*/
Las::Las(const std::string &qsCodeProcess, const std::string &qsNumLot)
{
    msCodeProcess = qsCodeProcess;
    msNumeroDeLot = qsNumLot;
}

/**
* @brief Fonction pour creer un nouvel article.
*
* @param qsCodeProcess: Le code process en provenance du formulaire de la LAS.
* @param qsNumLot: Le numero de lot en provenance du formulaire de la LAS.
* @return false si l'objet Article n'a pas pu etre instancié, true sinon.
*/
bool Las::fnCreerArticle(const std::string &qsNumArticle, const std::string &qsLibArticle)
{
    //instanciation de l'article avec les parametres
    mlstLibelle.push_back( std::string( qsLibArticle ) );
    Article *tmp = new Article( qsNumArticle, qsLibArticle );
    //ajouter l'article a la liste
    if( NULL != tmp )mlstArticles.push_back(tmp);
    return NULL != tmp;
}

/**
* @brief Fonction renvoyant la liste de libelle.
* @return La liste des libelle. NULL si aucun article n'est instancié.
*/
const std::list<std::string> *Las::fnRetourListeLibelle()const
{
    if( mlstLibelle.empty() )
    {
        return NULL;
    }
    return &mlstLibelle;
}

/**
* @brief Fonction de transfert des donnees pour la creation d'un lot vers l'article en question.
* @param sChoixArt: Le choix de l'article en provenance du formulaire du Lot.
* @param sNumLot: Le numero de lot en provenance du formulaire du Lot.
* @return false si l'objet Lot n'a pas pu etre instancié, true sinon.
*/
bool Las::bfnReceptionnerInformationsCreationLot(
        const std::string &sChoixArt, const std::string &sNumLot)
{
    bool granted=false;
    //recherche dans la liste de l'article correspondant au libelle
    for( std::list<Article*>::iterator it = mlstArticles.begin() ;
        it != mlstArticles.end() ; ++it)
    {
        //si l'article est trouve
        if( (*it) && sChoixArt == (*it)->fnLireLibelleArticle() )
        {
            granted = (*it) -> bfnCreerLot(sNumLot);
            break;
        }
    }
    return granted;
}

/**
* @brief Fonction pour vider la liste d'article.
*
*/
void Las::fnViderListeArticle()
{
    //si la liste est vide
    if( mlstArticles.empty() )return;
    for( std::list<Article*>::iterator it = mlstArticles.begin() ;
        it != mlstArticles.end() ; ++it)
    {
       delete (*it);
    }
    mlstArticles.clear();
}

/**
* @brief Destructeur de la classe Las.
*
*/
Las::~Las()
{
    fnViderListeArticle();
}
