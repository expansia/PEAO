#ifndef ARTICLE_HPP
#define ARTICLE_HPP

#include <string>

class Article
{
private:
    std::string stNumeroArticle, stLibelleArticle;
    inline std::string fnLireNumArticle() const {return stNumeroArticle;}
    inline std::string fnLireLibelleArticle() const {return stLibelleArticle;}
    inline void fnChangerNumArticle(const std::string &numArt){stNumeroArticle = numArt;}
    inline void fnChangerLibelleArticle(const std::string &libArt){stLibelleArticle = libArt;}
public:
    Article(const std::string& qsNumArt,const std::string& qsLibArt);
    ~Article();
};

#endif // ARTICLE_HPP
