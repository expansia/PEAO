#ifndef LAS_HPP
#define LAS_HPP

#include <string>

class Las
{
private:
    std::string mqsCodeProcess, mqsNumeroDeLot;
public:
    Las(const std::string& qsCodeProcess, const std::string& qsNumLot);
    inline std::string fnLireCodeProcess() const {return mqsCodeProcess;}
    inline std::string fnLireNumeroDeLot() const {return mqsNumeroDeLot;}
    inline void fnChangerNumeroDeLot(const std::string &numLot){mqsNumeroDeLot = numLot;}
    inline void fnChangerCodeProcess(const std::string &codeProcess){mqsCodeProcess = codeProcess;}
    ~Las();
};

#endif // LAS_HPP
