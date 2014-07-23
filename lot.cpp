#include "lot.hpp"
#include "contenant.hpp"

/**
* @brief Constructeur de la classe Lot.
*
* @param sNumLot: Numero de lot article.
* @param sNumLot: Masse totale du lot article.
*/
Lot::Lot(const std::string &sNumeroLot, const std::string &sMasseTotale)
{
    msNumeroLotArticle = sNumeroLot;
    msMasseTotale = sMasseTotale;
}

/**
* @brief Fonction pour creer un contenant dans le lot.
* La fonction transfere les donnees necessaires a la creation d'un contenant au constructeur
* de ce dernier.
* @param sMasseNetteCont: La masse nette du contenant.
* @param sNumCont: Le numero du contenant.
* @param bContCompl: Le choix entre contenant fractionne et complet.
* @return true si l'objet Contenant a bien ete instancie, false sinon.
*/
bool Lot::bfnCreerContenant( const std::string &sMasseNetteCont,
                                 const std::string &sNumCont ,
                                 const bool &bContCompl )
{
    bool granted = true;
    Contenant *tmp = new Contenant(sMasseNetteCont, sNumCont, bContCompl);
    if( NULL ==tmp )
    {
        granted = false;
    }
    else
    {
        mlstContenants.push_back( tmp );
    }
    return granted;
}

/**
* @brief Fonction pour vider la liste de contenants.
*
*/
void Lot::fnViderListeContenant()
{
    //si la liste est vide
    if( mlstContenants.empty() )return;
    for( std::list<Contenant*>::iterator it = mlstContenants.begin() ;
        it != mlstContenants.end() ; ++it)
    {
       if( (*it) )delete (*it);
    }
    mlstContenants.clear();
}

/**
* @brief Destructeur de la classe Lot.
*
*/
Lot::~Lot()
{
    fnViderListeContenant();
}
