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
    Lot *ptrArtRetourLot( const std::string & sNumLot );
    void fnViderListeLot();
public:
    Article( const std::string & sNumArt,const std::string & sLibArt );

    inline std::string fnLireNumArticle() const {return mstNumeroArticle;}
    inline std::string fnLireLibelleArticle() const {return mstLibelleArticle;}

    inline void fnChangerNumArticle( const std::string & numArt ){mstNumeroArticle = numArt;}
    inline void fnChangerLibelleArticle( const std::string & libArt ){mstLibelleArticle = libArt;}

    bool bfnCreerLot( const std::string & sNumLot, const std::string & sMasseTot );
    bool bfnAjouterContenant( const std::string & sNumLotArticle,
                             const std::string & sMasseNetteContenant,
                             const std::string & sNumContenant,
                             const bool & bContComplet );
    ~Article();
};

#endif // ARTICLE_HPP
