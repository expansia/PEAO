#ifndef LAS_HPP
#define LAS_HPP

class Article;

#include <string>
#include <list>

class Las
{
private:
    std::string mqsCodeProcess, mqsNumeroDeLot;
    std::list<Article*> lstArticles;
    std::list<std::string> lstLibelle;
public:
    Las(const std::string& qsCodeProcess, const std::string& qsNumLot);
    bool fnCreerArticle(const std::string &qsNumArticle, const std::string &qsLibArticle);
    inline std::string fnLireCodeProcess() const {return mqsCodeProcess;}
    inline std::string fnLireNumeroDeLot() const {return mqsNumeroDeLot;}
    inline void fnChangerNumeroDeLot(const std::string &numLot){mqsNumeroDeLot = numLot;}
    inline void fnChangerCodeProcess(const std::string &codeProcess){mqsCodeProcess = codeProcess;}
    void fnViderListeArticle();
    const std::list<std::string> *fnRetourListeLibelle()const;
    ~Las();
};

#endif // LAS_HPP
