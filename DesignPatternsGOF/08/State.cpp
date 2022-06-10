#include <iostream>
using namespace std;

class StateContext;
class HaveCoin;
class NoHaveCoin;
class SoldCoffee;
class NoCoffee;

class State {
    string _message;
public:
    State(const string& message) : _message(message) {
        cout << _message << endl;
    }
    virtual ~State() {}
    virtual void returnCoin(StateContext*) {};
    virtual void buttonBuyPressed(StateContext*) {};
    virtual void noMoreCoffee(StateContext*) {};
    virtual void coffeeAvailable(StateContext*) {};
    virtual void dropeCoin(StateContext*) {};
    string getMessage() const { return _message; }
};
//===============================================================
class StateContext {
private:
    int _countCoffee;
    State* state;
public:
    StateContext(State* state) : state(state) {}
    ~StateContext() { delete state; }

    void ReturnCoin() {
        cout << "Return the coin ..." << endl;
        state->returnCoin(this);
    }
    void ButtonBuyPressed() {
        cout << "The buy button is pressed ..." << endl;
        _countCoffee--;
        state->buttonBuyPressed(this);
        if (_countCoffee > 0) {
            cout << "Coffee is available ..." << endl;
            state->coffeeAvailable(this);
        }
        else {
            cout << "Sorry, no more coffee ..." << endl;
            state->noMoreCoffee(this);
        }
    }
    void DropeCoin() {
        cout << "Drope the coin ..." << endl;
        state->dropeCoin(this);
    }

    void SetState(State* s) {
        cout << "Chaging state from " << state->getMessage() << " to " << s->getMessage() << "..." << endl;
        delete state;
        state = s;
    }
    State* GetState() const { return state; }
    string getMessage() const { return state->getMessage(); }
    void setCountCoffee(int countCoffee) { _countCoffee = countCoffee; }
};
//===============================================================
class HaveCoin : public State {
public:
    HaveCoin() : State("Got a coin") {}
    void returnCoin(StateContext* state) override;
    void buttonBuyPressed(StateContext* state) override;
};
class NoHaveCoin : public State {
public:
    NoHaveCoin() : State("Give me a coin") {}
    void dropeCoin(StateContext* state) override;
};
class SoldCoffee : public State {
public:
    SoldCoffee() : State("Coffee bought") {}
    void noMoreCoffee(StateContext*) override;
    void coffeeAvailable(StateContext*) override;
};
class NoCoffee : public State {
public:
    NoCoffee() : State("Don't have coffee") {}
    void noCoffee(StateContext* state);
};
//===============================================================
void HaveCoin::returnCoin(StateContext* state) {
    state->SetState(new NoHaveCoin);
}
void HaveCoin::buttonBuyPressed(StateContext* state) {
    state->SetState(new SoldCoffee);
}
void NoHaveCoin::dropeCoin(StateContext* state) {
    state->SetState(new HaveCoin);
}
void SoldCoffee::coffeeAvailable(StateContext* state) {
        state->SetState(new NoHaveCoin);
}
void SoldCoffee::noMoreCoffee(StateContext* state) {
    state->SetState(new NoCoffee);
}
void NoCoffee::noCoffee(StateContext* state) {
    cout << state->getMessage() << endl;
}


int main() {
    StateContext* pStateContext = new (nothrow) StateContext(new NoHaveCoin());
    pStateContext->setCountCoffee(2);
    if (pStateContext != nullptr) {
        pStateContext->DropeCoin();
        pStateContext->ButtonBuyPressed();
        cout << "\n=================\n\n";
        pStateContext->DropeCoin();
        pStateContext->ButtonBuyPressed();
        delete pStateContext;
    }

    return 0;
}
