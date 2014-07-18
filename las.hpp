#ifndef LAS_HPP
#define LAS_HPP

#include <QString>

class Las
{
private:
    QString mqsCodeProcess, mqsNumeroDeLot;
public:
    Las(const QString& qsCodeProcess, const QString& qsNumLot);
};

#endif // LAS_HPP
