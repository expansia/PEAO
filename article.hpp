#ifndef ARTICLE_HPP
#define ARTICLE_HPP

#include <string>
#include <list>

class Lot;

class Article
{
private:
    std::list<Lot*> mlstLot;
    std::string mstNumeroArticle, mstLibelleArticle;

public:
    Article(const std::string& qsNumArt,const std::string& qsLibArt);
    inline std::string fnLireNumArticle() const {return mstNumeroArticle;}
    inline std::string fnLireLibelleArticle() const {return mstLibelleArticle;}
    inline void fnChangerNumArticle(const std::string &numArt){mstNumeroArticle = numArt;}
    inline void fnChangerLibelleArticle(const std::string &libArt){mstLibelleArticle = libArt;}
    bool bfnCreerLot(const std::string &sNumLot);
    void fnViderListeLot();
    ~Article();
};

#endif // ARTICLE_HPP
