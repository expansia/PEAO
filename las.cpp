#include "las.hpp"
#include "article.hpp"

/**
* @brief Constructeur de la classe Las.
*
* @param sCodeProcess: Code Process de la LAS.
* @param sNumLot: Numero de lot de la LAS.
*/
Las::Las(const std::string &sCodeProcess, const std::string &sNumLot)
{
    msCodeProcess = sCodeProcess;
    msNumeroDeLot = sNumLot;
}

/**
* @brief Fonction pour creer un nouvel article.
*
* @param sCodeProcess: Le code process en provenance du formulaire de la LAS.
* @param sNumLot: Le numero de lot en provenance du formulaire de la LAS.
* @return false si l'objet Article n'a pas pu etre instancié, true sinon.
*/
bool Las::fnCreerArticle(const std::string &sNumArticle, const std::string &sLibArticle)
{
    //instanciation de l'article avec les parametres
    mlstLibelle.push_back( std::string( sLibArticle ) );
    Article *tmp = new Article( sNumArticle, sLibArticle );
    //ajouter l'article a la liste
    if( NULL != tmp )mlstArticles.push_back(tmp);
    return NULL != tmp;
}

/**
* @brief Fonction renvoyant la liste de libelle.
* @return La liste des libelle. NULL si aucun article n'est instancié.
*/
const std::list<std::string> *Las::fnRetourListeLibelle()const
{
    if( mlstLibelle.empty() )
    {
        return NULL;
    }
    return &mlstLibelle;
}

/**
* @brief Fonction de transfert des donnees pour la creation d'un lot vers l'article en question.
* @param sChoixArt: Le choix de l'article en provenance du formulaire du Lot.
* @param sNumLot: Le numero de lot en provenance du formulaire du Lot.
* @param sMasseTotale: La masse totale du lot.
* @return false si l'objet Lot n'a pas pu etre instancié, true sinon.
*/
bool Las::bfnReceptionnerInformationsCreationLot(
        const std::string &sChoixArt, const std::string &sNumLot, const std::string &sMasseTotale)
{
    bool granted=false;
    Article *tmp = ptrArtRetourArticle( sChoixArt );
    if( NULL == tmp )
    {
        granted = false;
    }
    else
    {
    granted = tmp -> bfnCreerLot(sNumLot, sMasseTotale);
    }
    return granted;
}

/**
* @brief Fonction recherchant l'article possedant le libelle envoye en parametre.
* @param sLibelleArt: Le libelle de l'article recherche.
* @return L'article trouve. NULL si l'article n'a pas ete trouve.
*/
Article *Las::ptrArtRetourArticle( const std::string &sLibelleArt )
{
    //recherche dans la liste de l'article correspondant au libelle(sChoixArt)
    for( std::list<Article*>::iterator it = mlstArticles.begin() ;
        it != mlstArticles.end() ; ++it)
    {
        //si l'article est trouve
        if( (*it) && sLibelleArt == (*it)->fnLireLibelleArticle() )
        {
            return (*it);
        }
    }
    return NULL;
}

/**
* @brief Fonction de recuperation des donnees du formulaire d'un contenant.
* La fonction transfere les donnees necessaires a la creation d'un contenant a l'objet Article,
* selectionne a l'aide du parametre sLibArt.
* @param sLibArt: Le libelle de l'article qui possede le lot.
* @param sNumLotArt: Le numero de lot qui contient le contenant.
* @param sMasseNetteCont: La masse nette du contenant.
* @param sNumCont: Le numero du contenant.
* @param bContCompl: Le choix entre contenant fractionne et complet.
* @return true si l'objet Contenant a bien ete instancie, false sinon.
*/
bool Las::bfnAjouterContenant(const std::string &sLibArt, const std::string &sNumLotArt,
                    const std::string &sMasseNetteCont, const std::string &sNumCont ,
                    const bool &bContCompl )
{
    bool granted;
    //reception du pointeur vers le bon article
    Article *ptrArticle = ptrArtRetourArticle( sLibArt );
    if( ptrArticle == NULL )
    {
        granted = false;
    }
    else
    {
        //appel de la fonction dans l'article correspondant
        granted = ptrArticle->bfnAjouterContenant( sNumLotArt, sMasseNetteCont, sNumCont, bContCompl );
    }
    return granted;
}

/**
* @brief Fonction pour vider la liste d'article.
*
*/
void Las::fnViderListeArticle()
{
    //si la liste est vide
    if( mlstArticles.empty() )return;
    for( std::list<Article*>::iterator it = mlstArticles.begin() ;
        it != mlstArticles.end() ; ++it)
    {
       delete (*it);
    }
    mlstArticles.clear();
}

/**
* @brief Destructeur de la classe Las.
*
*/
Las::~Las()
{
    fnViderListeArticle();
}
