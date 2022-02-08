#include <iostream>
//#include <stdexcept>
using namespace std;

class OffTheField {
public:
	OffTheField(int dx, int dy) {
        cout << "The coordinates " << dx << ". " << dy <<" takes the robot out of the field!\n";
	}
};

class IllegalCommand {
public:
	IllegalCommand(int dx, int dy) {
		cout << "The orientation " << dx << ". " << dy <<" is not in the right range!\n";
	}
};

class Robot {
public:
    Robot(int size = 10) {
        m_x = 0;
        m_y = 0;
        m_Size = size;
        field = new int* [m_Size];
        for(int i = 0; i < m_Size; ++i)
            field[i] = new int [m_Size];
    }
    ~Robot(){
        for (int i = 0; i < m_Size; ++i)
        delete[] field[i];
        delete [] field;
    }
    void Move(int dx, int dy){
        if(((dx + m_x) >= m_Size || (dx + m_x) < 0) && ((dy + m_y) >= m_Size || (dy + m_y) < 0)){
            throw IllegalCommand(dx, dy);
        }
        else if(((dx + m_x) >= m_Size || (dx + m_x) < 0) || ((dy + m_y) >= m_Size || (dy + m_y) < 0)){
            throw OffTheField(dx + m_x, dy + m_y);
        }
        else {
            m_x += dx;
            m_y += dy;
            cout << "robot moved in point: x = "<< m_x <<", y = " << m_y << endl;
        }

    }
private:
    int m_Size;
    int** field;
    int m_x;
    int m_y;
};


int main() {
    Robot robot;
    int x;
    int y;
    cin >> x >>y;
    try
	{
		while(x != 0 || y != 0){
            robot.Move(x,y);
            cin >> x >>y;
		}
	}
	catch (const OffTheField& otf)
	{
		cerr << "Error: Off The Field"  << endl;
	}
	catch (const IllegalCommand& ic)
	{
		cerr << "Error: Illegal Command" << endl;
	}

	return 0;
}

