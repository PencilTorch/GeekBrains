#include "Mediator.h"

int main() {
    
    Calendar* cal = new Calendar;
    Mediator* med = new Mediator(cal);
    std::vector<Device*> device = { new Coffee(med), new TeaPot(med), new Alarm(med) };
    for (auto it : device) {
        med->AddDevice(it);
    }
    for (auto it : device) {
        med->Notify(it);
    }
    
    for (auto it : device) {
        delete it;
    }
    delete med;
    delete cal;
    return 0;
}