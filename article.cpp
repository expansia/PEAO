#include "article.hpp"
#include "lot.hpp"

/**
* @brief Constructeur de la classe Article.
*
* @param qsNumArt: Numero d'article.
* @param qsLibArt: Libelle de l'article.
*/
Article::Article(const std::string& qsNumArt,const std::string& qsLibArt)
{
    mstNumeroArticle = qsNumArt;
    mstLibelleArticle = qsLibArt;
}

/**
* @brief Fonction pour creer un nouveau lot.
*
* @param qsNumLot: Le numero de lot en provenance du formulaire de la LAS.
* @return false si l'objet Lot n'a pas pu etre instancié, true sinon.
*/
bool Article::bfnCreerLot(const std::string &sNumLot)
{
   Lot *lotTmp = new Lot( sNumLot );
   if( NULL != lotTmp )mlstLot.push_back( lotTmp );
   return NULL != lotTmp;

}

/**
* @brief Fonction pour vider la liste de lot.
*
*/
void Article::fnViderListeLot()
{
    //si la liste est vide
    if( mlstLot.empty() )return;
    for( std::list<Lot*>::iterator it = mlstLot.begin() ;
        it != mlstLot.end() ; ++it)
    {
       delete (*it);
    }
    mlstLot.clear();
}


/**
* @brief Destructeur de la classe Article.
*
*/
Article::~Article()
{
    fnViderListeLot();
}
