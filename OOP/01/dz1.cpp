#include <iostream>
#include <cstdint>
#include <cmath>

class Stack {
    public:
		void reset() {
            if(size > 0){
                int it = 0;
                while(arrStack[it] != 0) {
                    arrStack[it] = 0;
                    ++it;
                }
                size = 0;
            }
		}
		bool push(int m){
            if(size < 10) {
                arrStack[size] = m;
                ++size;
                return true;
            }
            else
                return false;
		}
        void pop() {
            if(size > 0) {
                --size;
                arrStack[size] = 0;
            }
            else {
                std::cout <<"stack is empty"<<std::endl;
            }
        }
        void print() {
            std::cout<<"(";
            int it = 0;
            while(arrStack[it] != 0) {
                std::cout<<arrStack[it];
                ++it;
                if(arrStack[it] != 0)
                    std::cout<<" ";
            }
            std::cout<<")\n";
        }

    private:
        int arrStack[10] = {0};
        int size = 0;
};

class RGBA {
    public:
        RGBA() {
        m_red = 0;
        m_green = 0;
        m_blue = 0;
        m_alpha = 255;
        }
        RGBA(int red, int green, int blue, int alpha) {
            m_red = static_cast<std::uint8_t>(red);
            m_green = static_cast<std::uint8_t>(green);
            m_blue = static_cast<std::uint8_t>(blue);
            m_alpha = static_cast<std::uint8_t>(alpha);
        }
        void print() {
            std::cout<<static_cast<unsigned short>(m_red)<<" "<<static_cast<unsigned short>(m_green)<<" "
            <<static_cast<unsigned short>(m_blue)<<" "<<static_cast<unsigned short>(m_alpha)<<std::endl;
        }
    private:
        std::uint8_t m_red;
        std::uint8_t m_green;
        std::uint8_t m_blue;
        std::uint8_t m_alpha;
};


class Power {
public:
    Power() {
        m = 0;
        n = 0;
    }
    void set(int first, int second) {
        m = first;
        n = second;
    }
    void calculate() {
        std::cout << pow(m, n) <<std::endl;
    }
private:
    int m;
    int n;
};

int main() {
    // task 1
    Power power1;
    power1.set(2,2);
    power1.calculate();
    Power power2;
    power2.calculate();
    // task 2
    RGBA rgb1(100, 100, 0, 150);
    rgb1.print();
    RGBA rgb2;
    rgb2.print();
    // task 3
    Stack stack;
    stack.reset();
    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();
    stack.pop();

return 0;
}