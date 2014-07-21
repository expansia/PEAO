#include "las.hpp"

/**
* @brief Constructeur de la classe Las.
*
* @param qsCodeProcess: Code Process de la LAS.
* @param qsNumLot: Numero de lot de la LAS.
*/
Las::Las(const std::string &qsCodeProcess, const std::string &qsNumLot)
{
    mqsCodeProcess = qsCodeProcess;
    mqsNumeroDeLot = qsNumLot;
}

/**
* @brief Destructeur de la classe Las.
*
*/
Las::~Las()
{

}
