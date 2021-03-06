#ifndef CONTENANT_HPP
#define CONTENANT_HPP

#include <string>

/**
 * @class Contenant
 * @brief Classe Representant un Contenant.
 *
 * Cette classe possede la masse nette du contenant son numéro de contenant
 * et s'il s'agit d'un contenant fractionné ou complet.
 */
class Contenant
{
private:
    std::string msNumeroContenant, msMasseNette;
    bool mbComplet;
public:
    Contenant( const std::string & sMasseNetteContenant,
              const std::string & sNumContenant ,
              const bool & bContComplet );
    inline std::string fnLireNumeroContenant() const {return msNumeroContenant;}
    inline std::string fnLireMasseNette() const {return msMasseNette;}
    inline bool fnLireContComplet() const {return mbComplet;}
    inline void fnChangerNumeroContenant( const std::string & sNumCont ){msNumeroContenant = sNumCont;}
    inline void fnChangerMasseNette( const std::string & sMasseNette ){msMasseNette = sMasseNette;}
    inline void fnChangerContComplet( const bool & bComplet ){mbComplet = bComplet;}
    ~Contenant();
};

#endif // CONTENANT_HPP
