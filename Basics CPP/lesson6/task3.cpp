//task 3
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

void makeFile(){
     char filename[25];      //massiv for file name
    int i = 0;
     char ch;
     ch = cin.get();
    while(ch != '\n'){
             filename[i] = ch;
             ch = cin.get();
             ++i;
    }
    char endfn[5] = {'.','t','x','t','\0'};//add .txt
    for(int j = 0; j < 5; j++, i++){
           filename[i] = endfn[j];
    }
    ofstream outf(filename); //make *.txt
    //massiv ASCII char coding
    char alfa[53] = {32,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,
    97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122};
    //random filling *.txt
    srand(static_cast<unsigned int>(time(0)));
    for(int j = 0; j < 100; j++){
            outf<< alfa[rand()%53];
    }         
    outf.close();
}

int main()
{
    cout<<"Input first file name: ";
    makeFile();
    cout<<"Input second file name: ";
    makeFile();
    
    system("pause");
    return 0;
}

