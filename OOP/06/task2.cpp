#include <iostream>


template< class CharT, class Traits >
std::basic_ostream<CharT, Traits>& endll( std::basic_ostream<CharT, Traits>& os )
{
    os.put(os.widen('\n'));
    os.put(os.widen('\n'));
    os.flush();
 
    return os;
}

int main() {
    
    std::cout << "A" << endll;
    std::cout << "B";

return 0;
}

