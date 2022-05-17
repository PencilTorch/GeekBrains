#pragma once
#include <ctime>
#include "automat.h"

class proxyAutomat : public ISellSystem {
public:
    proxyAutomat(const std::string& location, double recievedMoney) :
        automat(new Automaton(location, recievedMoney)) {
        lastReport = 0;
        interval = 3600;
    }
    ~proxyAutomat() { delete automat; }

    void changePrice(std::string name, float newPrice) override {
        goods_price[name] = newPrice;
    }
    void sellProduct(std::string name) override {
        if (goods_count[name] > 0) {
            recieved_money += goods_price[name];
        }
        else {
            std::cerr << "Not enough goods" << std::endl;
        }
    }
    void addProduct(std::string name, size_t count) override {
        goods_count[name] += count;
    }
    double allMoneyReport() {
        updateData();
        return recieved_money - spent_money;
    }
    const std::string& getLocationReport() {
        updateData();
        return location;
    }
    std::map <std::string, size_t> goodsCountReport() {
        updateData();
        return goods_count;
    }
    std::map <std::string, float> goodsPriceReport() {
        updateData();
        return goods_price;
    }
    void setInterval(int _interval) { interval = _interval; }
private:
    Automaton* automat;
    int interval;
    std::time_t lastReport;
    bool checkTime() const {
        std::time_t Now = std::time(0);
        return (Now - lastReport > interval);
    }
    void updateData() {
        if (checkTime()) {
            location = automat->getLocationReport();
            recieved_money = automat->allMoneyReport();
            goods_price = automat->goodsPriceReport();
            goods_count = automat->goodsCountReport();
            lastReport = std::time(0);
            std::cout << "update data\n";
        }
        else
            std::cout << "data from proxy\n";
    }

    std::string location;
    double recieved_money;
    double spent_money;
    std::map <std::string, float> goods_price;
    std::map <std::string, size_t> goods_count;
};