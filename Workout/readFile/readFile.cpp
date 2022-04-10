#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;
const int SizeFIO = 12;

class Student {
public:
    void setFname(char* name) {
        for (int i = 0; i < SizeFIO; ++i)
            f_name[i] = name[i];
    }
    void setSname(char* name) {
        for (int i = 0; i < SizeFIO; ++i)
            s_name[i] = name[i];
    }
    void setTname(char* name) {
        for (int i = 0; i < SizeFIO; ++i)
            t_name[i] = name[i];
    }
    void setYearBird(char* year_bird) {
        yearBird = atoi(year_bird);
    }
    void setCurs(char* curs_) {
        curs = atoi(curs_);
    }
    void setSex(char ch) {
        sex = ch;
    }
    int getCurs() const {
        return curs;
    }
    char getSex() const {
        return sex;
    }
    void printStudent() {
        for (int i = 0; i < SizeFIO; ++i)
            cout << f_name[i];
        cout << ", ";
        for (int i = 0; i < SizeFIO; ++i)
            cout << s_name[i];
        cout << ", ";
        for (int i = 0; i < SizeFIO; ++i)
            cout << t_name[i];
        cout << ", " << yearBird << ", " << curs << ", " << sex << ";\n";
    }
    void ClearStudent(){
        memset(f_name, 0, sizeof(f_name));
        memset(s_name, 0, sizeof(s_name));
        memset(t_name, 0, sizeof(t_name));
        yearBird = 0;
        curs = 0;
        sex = ' ';
    }
private:
    char f_name[SizeFIO];
    char s_name[SizeFIO];
    char t_name[SizeFIO];
    unsigned int yearBird;
    unsigned int  curs;
    char sex;
};

//в принципе не нужна по условию
void printStudent(vector<Student>& stv) {
    for (vector<Student>::iterator it = stv.begin(); it != stv.end(); ++it) {
        it->printStudent();
    }
}
//функция подсчета чоловiкiв
int maxManCurs(vector<Student>& stv) {
    vector<int> curs;
    for (vector<Student>::iterator it = stv.begin(); it != stv.end(); ++it) {
        if (it->getSex() == 'Ч') {
            curs.push_back(it->getCurs());
        }
    }
    unordered_map<int, int> curs_map;
    for (auto it : curs) {
        ++curs_map[it];
    }
    int max = 0;
    int maxMan = 0;
    for (auto it : curs_map) {
        if (it.second > max) {
            max = it.second;
            maxMan = it.first;
        }
    }
    return maxMan;
}

int main() {
    setlocale(LC_ALL, "ru");
    ifstream fin; 
    fin.open("students.txt"); //файл из которого считываем
    if (fin.is_open()) {
        char ch;
        vector<Student> studenb; //вектор куда складываем студентов
        Student student; //экземпляр класса Студент куда считываем
        char tempCh[SizeFIO]{}; //временный чаровый массив
        short count = 0; //счетчик запятых
        int i = 0; //просто счетчик
        int pr = 0; //счетчик возможных пробелов
        while (fin.get(ch)) { //читаем посимвольно до конца файла
            if (ch != ',' && ch != ';') { 
                if (ch != ' ' && ch != '\n')
                    tempCh[i - pr] = ch; //добавляем во временный массив
                else
                    ++pr; //счет пробелов
                ++i;
            }
            else if (ch == ';') {
                if (count == 5) { //пол
                    student.setSex(*tempCh);
                    memset(tempCh, 0, sizeof(tempCh));
                }
                i = 0;
                pr = 0;
                count = 0;
                studenb.push_back(student);
                student.ClearStudent();
            }
            else {
                if (count == 0) { //если запятых еще не было, то это фамилия
                    student.setFname(tempCh); //добавляем имя из временного массива в экземпляр класса
                    memset(tempCh, 0, sizeof(tempCh)); //очищаем временный массив
                }
                if (count == 1) { //имя
                    student.setSname(tempCh);
                    memset(tempCh, 0, sizeof(tempCh));
                }
                if (count == 2) { //отчество
                    student.setTname(tempCh);
                    memset(tempCh, 0, sizeof(tempCh));
                }
                if (count == 3) { //год рождения
                    student.setYearBird(tempCh);
                    memset(tempCh, 0, sizeof(tempCh));
                }
                if (count == 4) { //курс
                    student.setCurs(tempCh);
                    memset(tempCh, 0, sizeof(tempCh));
                }
                //обнуляем счетчики, кроме запятых (запятые обнулять после ;)
                i = 0;
                pr = 0;
                count++;
            }
        }
        printStudent(studenb);
        cout <<"Найбiльше чоловiкiв на " << maxManCurs(studenb) <<" курсi.\n";
    }
    else {
        cout << "File don't open!";
    }
    
    fin.close();
    return 0;
}