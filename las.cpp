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
    mqsCodeProcess = qsCodeProcess;
    mqsNumeroDeLot = qsNumLot;
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
    lstLibelle.push_back( std::string( qsLibArticle ) );
    Article *tmp = new Article( qsNumArticle, qsLibArticle );
    //ajouter l'article a la liste
    if( NULL != tmp )lstArticles.push_back(tmp);
    return NULL != tmp;
}

/**
* @brief Fonction renvoyant la liste de libelle.
* @return La liste des libelle. NULL si aucun article n'est instancié.
*/
const std::list<std::string> *Las::fnRetourListeLibelle()const
{
    if( lstLibelle.empty() )
    {
        return NULL;
    }
    return &lstLibelle;
}


/**
* @brief Fonction pour vider la liste d'article.
*
*/
void Las::fnViderListeArticle()
{
    //si la liste est vide
    if( lstArticles.empty() )return;
    for( std::list<Article*>::iterator it = lstArticles.begin() ;
        it != lstArticles.end() ; ++it)
    {
       delete (*it);
    }
    lstArticles.clear();
}

/**
* @brief Destructeur de la classe Las.
*
*/
Las::~Las()
{
    fnViderListeArticle();
}
