#include "contenant.hpp"

/**
* @brief Constructeur de la classe Contenant.
*
* @param sMasseNetteContenant: Masse nette du contenant.
* @param sNumContenant: Numero du contenant.
* @param bContComplet: booleen determinant si il s'agit d'un contenant complet ou fractionne.
*/
Contenant::Contenant(const std::string &sMasseNetteContenant,
                     const std::string &sNumContenant,
                     const bool &bContComplet)
{
    msNumeroContenant = sMasseNetteContenant;
    msMasseNette = sNumContenant;
    mbComplet = bContComplet;
}

/**
* @brief Destructeur de la classe Contenant.
*
*/
Contenant::~Contenant()
{
}
