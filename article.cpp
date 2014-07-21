#include "article.hpp"

/**
* @brief Constructeur de la classe Article.
*
* @param qsNumArt: Numero d'article.
* @param qsLibArt: Libelle de l'article.
*/
Article::Article(const std::string& qsNumArt,const std::string& qsLibArt)
{
    stNumeroArticle = qsNumArt;
    stLibelleArticle = qsLibArt;
}

/**
* @brief Destructeur de la classe Article.
*
*/
Article::~Article()
{

}
