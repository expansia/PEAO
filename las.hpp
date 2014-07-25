#ifndef LAS_HPP
#define LAS_HPP

class Article;

#include <string>
#include <list>

/**
 * @class Las
 * @brief Classe Representant une liste a servir.
 *
 * Cette classe englobe tous les objets entre par l'utilisateur.
 * Elle possede un numero de lot(LAS) ainsi qu'un code process.
 * Il est possible de gerer les articles entrés par cette classe.
 *
 */
class Las
{
private:
    std::string msCodeProcess, msNumeroDeLot;
    std::list<Article*> mlstArticles;
    std::list<std::string> mlstLibelle;
    Article *ptrArtRetourArticle( const std::string & sLibelleArt );
public:
    Las( const std::string & sCodeProcess, const std::string & sNumLot );
    bool fnCreerArticle( const std::string & qsNumArticle, const std::string & sLibArticle );
    inline std::string fnLireCodeProcess() const {return msCodeProcess;}
    inline std::string fnLireNumeroDeLot() const {return msNumeroDeLot;}
    inline void fnChangerNumeroDeLot( const std::string & numLot ){msNumeroDeLot = numLot;}
    inline void fnChangerCodeProcess( const std::string & codeProcess ){msCodeProcess = codeProcess;}
    void fnViderListeArticle();
    bool bfnCreerLot( const std::string & sChoixArt, const std::string & sNumLot,
                                                const std::string & sMasseTotale );
    bool bfnAjouterContenant( const std::string & sLibArt,
                             const std::string & sNumLotArt,
                             const std::string & sMasseNetteCont,
                             const std::string & sNumCont,
                             const bool & bContCompl );
    const std::list<std::string> *fnRetourListeLibelle()const;
    ~Las();
};

#endif // LAS_HPP
