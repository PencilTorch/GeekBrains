#include <iostream>
#include <cstdlib>
#include <ctime>
using std::cout;
using std::cin;
using std::endl;

//=====ENUMS=====
enum GameStatus {
    CONTINUES,
    WON_PLAYER,
    WON_NPC,
    DRAW
};
enum Cells {
    CROSS = 'X',
    ZERO = 'O',
    EMPTY = '_'
};

//=====FUNCTIONS=====
int __fastcall getRandomNumber(int min, int max);

inline void clearSCR(){
     system("cls");
}

//=====STRUCTs=====
#pragma pack(push, 1)
struct Game {
    Game() {
        fieldSize = 3;
        gStatus = GameStatus::CONTINUES;
        initGame();
        firstStep();
    }
    ~Game() {
        deinitGame();
    }
    unsigned short fieldSize;
    Cells** ppField = nullptr;
    GameStatus gStatus;
    Cells NPC;
    Cells Player;
    unsigned short turn;
    void initGame() {
        this->ppField = new Cells * [fieldSize];
        for (int i = 0; i < fieldSize; i++) {
            ppField[i] = new Cells[fieldSize];
        }
        for (int y = 0; y < fieldSize; y++) {
            for (int x = 0; x < fieldSize; x++) {
                this->ppField[y][x] = Cells::EMPTY;
            }
        }
    }
    void deinitGame() {
        for (int i = 0; i < fieldSize; i++) {
            delete ppField[i];
        }
        delete this->ppField;
        this->ppField = nullptr;
        cout << "Game end\n";
    }
    void firstStep() {
        if (getRandomNumber(0, 1000) > 500) {
            NPC = Cells::CROSS;
            Player = Cells::ZERO;
            turn = 1;
        }
        else {
            NPC = Cells::ZERO;
            Player = Cells::CROSS;
            turn = 0;
        }
    }
};
#pragma pack(pop)

struct Coord {
    Coord() {
        y = 0;
        x = 0;
    }
    int y;
    int x;
    void copyCoord(int y, int x) {
        this->y = y;
        this->x = x;
    }
};

//=====FUNCTIONS=====
void __fastcall printGame(const Game& other);
GameStatus __fastcall getWon(Game& other);
bool __fastcall preWin(Game& other, Coord& coord);
bool __fastcall preFail(Game& other, Coord& coord);
void __fastcall getCoordPlayer(const Game& other, Coord& coord);
void __fastcall getCoordNPC(Game& other, Coord& coord);
void __fastcall nextStep(Game& other, Coord& coord);
bool __fastcall drawGame(const Game& other);
void __fastcall congrat(const Game& other);

/*=====MAIN=====*/
int main() {
Game g;
Coord c;
printGame(g);
do
{
    clearSCR();
    printGame(g);
    nextStep(g, c);
    g.gStatus = getWon(g);
} while (g.gStatus == GameStatus::CONTINUES);
clearSCR();
printGame(g);
congrat(g);

system("pause");
return 0;
}

//=====FUNCTIONS=====
int __fastcall getRandomNumber(int min, int max) {
    srand(static_cast<unsigned int>(time(0)));
    int randomNum = rand() % max - min;
    return randomNum;
}

void __fastcall printGame(const Game& other) {
    cout << "Game Cross-Zero\n";
    cout << "Player game: " << (char)other.Player << " , NPC play: " << (char)other.NPC << endl;
    cout << "    ";
    for (int i = 0; i < other.fieldSize; i++) {
        cout << i + 1 << "   ";
    }
    cout << endl;
    for (int y = 0; y < other.fieldSize; y++) {
        cout << y + 1 << " | ";
        for (int x = 0; x < other.fieldSize; x++) {
            cout << (char)other.ppField[y][x] << " | ";
        }
        cout << endl;
    }
}

void __fastcall getCoordPlayer(const Game& other, Coord& coord) {
    do {
        cout << "Enter coordinate X: ";
        cin >> coord.x;
        cout << "Enter coordinate Y: ";
        cin >> coord.y;
    } while (coord.x <= 0 || coord.x > other.fieldSize
        || coord.y <= 0 || coord.y > other.fieldSize
        || other.ppField[coord.y - 1][coord.x - 1] != Cells::EMPTY);
    coord.y--;
    coord.x--;
}

void __fastcall getCoordNPC(Game& other, Coord& coord) {
    if(preWin(other, coord)) {
        return;
    }
    if(preFail(other, coord)) {
        return;
    }
    //if center free..
    if (other.ppField[1][1] == Cells::EMPTY) {
        coord.y = 1;
        coord.x = 1;
    }
    else {
    //seach free angular
    short ang = 0;
    Coord otherCells[4];
    otherCells[0].copyCoord(0, 0);
    otherCells[1].copyCoord(2, 0);
    otherCells[2].copyCoord(0, 2);
    otherCells[3].copyCoord(2, 2);
    Coord* pCoordAng = nullptr;
    for (int i = 0; i < 4; i++) {
        if(other.ppField[otherCells[i].y][otherCells[i].x] == Cells::EMPTY) {
            ++ang;
            if (pCoordAng != nullptr) {
                Coord* tempArr = new Coord[ang];
                for (int k = 0; k < ang-1; k++) {
                    tempArr[k].copyCoord(pCoordAng[k].y, pCoordAng[k].x);
                }
                tempArr[ang - 1].copyCoord(otherCells[i].y, otherCells[i].x);
                delete[] pCoordAng;
                pCoordAng = new Coord[ang];
                for (int k = 0; k < ang; k++) {
                    pCoordAng[k].copyCoord(tempArr[k].y, tempArr[k].x);
                }
                delete[] tempArr;
                tempArr = nullptr;
            }
            else {
                 pCoordAng = new Coord[ang];
                pCoordAng[ang - 1].copyCoord(otherCells[i].y, otherCells[i].x);
            }
        }
    }
    if (ang > 0) {
        short index = getRandomNumber(0, ang);
        coord.copyCoord(pCoordAng[index].y, pCoordAng[index].x);
        delete[] pCoordAng;
        pCoordAng = nullptr;
    }
    //seach other free cells
    else {
        otherCells[0].copyCoord(0, 1);
        otherCells[1].copyCoord(1, 0);
        otherCells[2].copyCoord(1, 2);
        otherCells[3].copyCoord(2, 1);
        for (int i = 0; i < 4; i++) {
            if (other.ppField[otherCells[i].y][otherCells[i].x] == Cells::EMPTY) {
                ++ang;
                if (pCoordAng != nullptr) {
                    Coord* tempArr = new Coord[ang];
                    for (int k = 0; k < ang - 1; k++) {
                        tempArr[k].copyCoord(pCoordAng[k].y, pCoordAng[k].x);
                    }
                    tempArr[ang - 1].copyCoord(otherCells[i].y, otherCells[i].x);
                    delete[] pCoordAng;
                    pCoordAng = new Coord[ang];
                    for (int k = 0; k < ang; k++) {
                        pCoordAng[k].copyCoord(tempArr[k].y, tempArr[k].x);
                    }
                    delete[] tempArr;
                    tempArr = nullptr;
                }
                else {
                    pCoordAng = new Coord[ang];
                    pCoordAng[ang - 1].copyCoord(otherCells[i].y, otherCells[i].x);
                }
            }
        }
        if(ang > 0) {
            short index = getRandomNumber(0, ang);
            coord.copyCoord(pCoordAng[index].y, pCoordAng[index].x);
            delete[] pCoordAng;
            pCoordAng = nullptr;
            }
        }
    }
}

void __fastcall nextStep(Game& other, Coord& coord) {
    if (other.turn % 2 == 0) {
        getCoordPlayer(other, coord);
        other.ppField[coord.y][coord.x] = other.Player;
    }
    else {
        getCoordNPC(other, coord);
        other.ppField[coord.y][coord.x] = other.NPC;
    }
    other.turn++;
}

GameStatus __fastcall getWon(Game& other) {
    //cells
    for (int i = 0; i < other.fieldSize; i++) {
        if (other.ppField[i][0] == other.ppField[i][1] && other.ppField[i][0] == other.ppField[i][2]) {
            if (other.ppField[i][0] == other.Player) {
                return GameStatus::WON_PLAYER;
            }
            if (other.ppField[i][0] == other.NPC) {
                return GameStatus::WON_NPC;
            }
        }
    }
    //rows
    for (int i = 0; i < other.fieldSize; i++) {
        if (other.ppField[0][i] == other.ppField[1][i] && other.ppField[0][i] == other.ppField[2][i]) {
            if (other.ppField[0][i] == other.Player) {
                return GameStatus::WON_PLAYER;
            }
            if (other.ppField[0][i] == other.NPC) {
                return GameStatus::WON_NPC;
            }
        }
    }
    //diagonal 1
    if (other.ppField[0][0] == other.ppField[1][1] && other.ppField[0][0] == other.ppField[2][2]) {
        if (other.ppField[0][0] == other.Player) {
            return GameStatus::WON_PLAYER;
        }
        if (other.ppField[0][0] == other.NPC) {
            return GameStatus::WON_NPC;
        }
    }
    //diagonal 2
    if (other.ppField[0][2] == other.ppField[1][1] && other.ppField[0][2] == other.ppField[2][0]) {
        if (other.ppField[1][1] == other.Player) {
            return GameStatus::WON_PLAYER;
        }
        if (other.ppField[1][1] == other.NPC) {
            return GameStatus::WON_NPC;
        }
    }
    if (drawGame(other)) {
        return GameStatus::DRAW;
    }
    return GameStatus::CONTINUES;
}

bool __fastcall drawGame(const Game& other) {
    for (size_t y = 0; y < other.fieldSize; y++) {
        for (size_t x = 0; x < other.fieldSize; x++) {
            if (other.ppField[y][x] == Cells::EMPTY)
                return false;
        }
    }
    return true;
}

void __fastcall congrat(const Game& other) {
    if (other.gStatus == GameStatus::WON_PLAYER) {
        cout << "You victory! Congratulations!" << endl;
    }
    else if (other.gStatus == GameStatus::WON_NPC) {
        cout << "You fail this game." << endl;
    }
    else if (other.gStatus == GameStatus::DRAW) {
        cout << "This drawn game." << endl;
    }
}

bool __fastcall preWin(Game& other, Coord& coord) {
    for (int y = 0; y < other.fieldSize; y++) {
        for (int x = 0; x < other.fieldSize; x++) {
            if(other.ppField[y][x] == Cells::EMPTY) {
                other.ppField[y][x] = other.NPC;
                if(getWon(other) == GameStatus::WON_NPC) {
                    other.ppField[y][x] = Cells::EMPTY;
                    coord.copyCoord(y,x);
                    return true;
                }
                other.ppField[y][x] = Cells::EMPTY;
            }
        }
    }
    return false;
}

bool __fastcall preFail(Game& other, Coord& coord) {
    for (int y = 0; y < other.fieldSize; y++) {
        for (int x = 0; x < other.fieldSize; x++) {
            if(other.ppField[y][x] == Cells::EMPTY) {
                other.ppField[y][x] = other.Player;
                if(getWon(other) == GameStatus::WON_PLAYER) {
                    other.ppField[y][x] = Cells::EMPTY;
                    coord.copyCoord(y,x);
                    return true;
                }
                other.ppField[y][x] = Cells::EMPTY;
            }
        }
    }
    return false;
}