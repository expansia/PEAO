#include "article.hpp"
#include "lot.hpp"

/**
* @brief Constructeur de la classe Article.
*
* @param qsNumArt: Numero d'article.
* @param qsLibArt: Libelle de l'article.
*/
Article::Article( const std::string & sNumArt,const std::string & sLibArt )
{
    mstNumeroArticle = sNumArt;
    mstLibelleArticle = sLibArt;
}

/**
* @brief Fonction pour creer un nouveau lot.
*
* @param qsNumLot: Le numero de lot en provenance du formulaire de la LAS.
* @return false si l'objet Lot n'a pas pu etre instancié, true sinon.
*/
bool Article::bfnCreerLot( const std::string & sNumLot, const std::string & sMasseTot )
{
   Lot *lotTmp = new Lot( sNumLot , sMasseTot );
   if( NULL != lotTmp )mlstLot.push_back( lotTmp );
   return NULL != lotTmp;

}

/**
* @brief Fonction de recuperation des donnees du formulaire d'un contenant.
* La fonction transfere les donnees necessaires a la creation d'un contenant a l'objet Lot,
* selectionne a l'aide du parametre sNumLotArt.
* @param sNumLotArticle: Le numero de lot qui contient le contenant.
* @param sMasseNetteContenant: La masse nette du contenant.
* @param sNumContenant: Le numero du contenant.
* @param bContComplet: Le choix entre contenant fractionne et complet.
* @return true si l'objet Contenant a bien ete instancie, false sinon.
*/
bool Article::bfnAjouterContenant( const std::string & sNumLotArticle,
                    const std::string & sMasseNetteContenant, const std::string & sNumContenant ,
                    const bool & bContComplet )
{
    bool granted;
    Lot *ptrLot = ptrArtRetourLot( sNumLotArticle );
    if( NULL == ptrLot )
    {
        granted = false;
    }
    else
    {
      granted = ptrLot->bfnAjouterContenant( sMasseNetteContenant, sNumContenant, bContComplet ) ;
    }
    return granted;
}

/**
* @brief Fonction pour vider la liste de lot.
*
*/
void Article::fnViderListeLot()
{
    //si la liste est vide
    if( mlstLot.empty() )return;
    for( std::list<Lot*>::iterator it = mlstLot.begin() ;
        it != mlstLot.end() ; ++it )
    {
       delete (*it);
    }
    mlstLot.clear();
}


/**
* @brief Fonction recherchant le lot possedant le numero envoye en parametre.
* @param sNumLot: Le numero de lot du lot a rechercher.
* @return Un pointeur vers le lot si il a ete trouve. NULL si le lot n'a pas ete trouve.
*/
Lot *Article::ptrArtRetourLot( const std::string & sNumLot )
{
    //recherche dans la liste du lot correspondant au numero de lot(sNumLot)
    for( std::list<Lot*>::iterator it = mlstLot.begin() ;
        it != mlstLot.end() ; ++it )
    {
        //si le lot est trouve
        if( (*it) && sNumLot == (*it)->fnLireNumeroLotArticle() )
        {
            return (*it);
        }
    }
    return NULL;
}


/**
* @brief Destructeur de la classe Article.
*
*/
Article::~Article()
{
    fnViderListeLot();
}
