#ifndef AUTOSWAP_H
#define AUTOSWAP_H
#include "QString"
#include <map>

class AutoSwap
{
public:
    AutoSwap(QString const &str);
    QString _aswap();
private:
    QString txt;
    std::map<QString, QString> mp = {{"RUB" , "₽"}, {"руб.", "₽"}, {"евро", "€"}, {"права", "©"},
                                     {"промилле", "‰"}, {"знак", "®"}};
};
#endif // AUTOSWAP_H
