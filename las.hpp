#ifndef LAS_HPP
#define LAS_HPP

class Article;

#include <string>
#include <list>

class Las
{
private:
    std::string msCodeProcess, msNumeroDeLot;
    std::list<Article*> mlstArticles;
    std::list<std::string> mlstLibelle;
public:
    Las(const std::string& qsCodeProcess, const std::string& qsNumLot);
    bool fnCreerArticle(const std::string &qsNumArticle, const std::string &qsLibArticle);
    inline std::string fnLireCodeProcess() const {return msCodeProcess;}
    inline std::string fnLireNumeroDeLot() const {return msNumeroDeLot;}
    inline void fnChangerNumeroDeLot(const std::string &numLot){msNumeroDeLot = numLot;}
    inline void fnChangerCodeProcess(const std::string &codeProcess){msCodeProcess = codeProcess;}
    void fnViderListeArticle();
    bool bfnReceptionnerInformationsCreationLot(
            const std::string &sChoixArt, const std::string &sNumLot);
    const std::list<std::string> *fnRetourListeLibelle()const;
    ~Las();
};

#endif // LAS_HPP
