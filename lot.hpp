#ifndef LOT_HPP
#define LOT_HPP

#include <string>
#include <list>

class Contenant;

class Lot
{
private:
    std::string msNumeroLotArticle;
    std::string msMasseTotale;
    std::list<Contenant*> mlstContenants;
public:
    Lot(const std::string &sNumeroLot, const std::string &sMasseTotale);
    bool bfnCreerContenant( const std::string &sMasseNetteCont,
                                     const std::string &sNumCont ,
                                     const bool &bContCompl );
    inline std::string fnLireNumeroLotArticle() const {return msNumeroLotArticle;}
    inline std::string fnLireMasseTotale() const {return msMasseTotale;}
    inline void fnChangerNumeroLotArticle(const std::string &sNumLotArticle){msNumeroLotArticle = sNumLotArticle;}
    inline void fnChangerMasseTotale(const std::string &sMasseArticle){msMasseTotale = sMasseArticle;}
    void fnViderListeContenant();
    ~Lot();
};

#endif // LOT_HPP
