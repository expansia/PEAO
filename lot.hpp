#ifndef LOT_HPP
#define LOT_HPP

#include <string>


class Lot
{
private:
    std::string msNumeroLotArticle;
public:
    Lot(const std::string &sNumeroLot);
    ~Lot();
};

#endif // LOT_HPP
