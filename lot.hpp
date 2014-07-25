#ifndef LOT_HPP
#define LOT_HPP

#include <string>
#include <list>

class Contenant;

/**
 * @class Lot
 * @brief Classe Representant un Lot.
 *
 * Cette classe possede la masse totale ainsi que le numero de lot d'un lot.
 * Elle comporte egalement la liste des contenants qui lui sont associes.
 * Elle assure la gestion de ces derniers.
 *
 */
class Lot
{
private:
    std::string msNumeroLotArticle;
    std::string msMasseTotale;
    std::list<Contenant*> mlstContenants;
public:
    Lot( const std::string & sNumeroLot, const std::string & sMasseTotale );

    inline std::string fnLireNumeroLotArticle() const {return msNumeroLotArticle;}
    inline std::string fnLireMasseTotale() const {return msMasseTotale;}
    inline void fnChangerNumeroLotArticle( const std::string & sNumLotArticle )
        {msNumeroLotArticle = sNumLotArticle;}
    inline void fnChangerMasseTotale( const std::string & sMasseArticle ){msMasseTotale = sMasseArticle;}

    bool bfnAjouterContenant( const std::string & sMasseNetteCont,
                             const std::string & sNumCont,
                             const bool & bContCompl );

    void fnViderListeContenant();
    ~Lot();
};

#endif // LOT_HPP
