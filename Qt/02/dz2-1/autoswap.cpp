#include "autoswap.h"

AutoSwap::AutoSwap(QString const &str) : txt(str) {}

QString AutoSwap::_aswap() {
    std::map<QString, QString>::iterator it;
    it = mp.find(txt);
    if(it != mp.end())
        return it->second;
    return txt;
}

