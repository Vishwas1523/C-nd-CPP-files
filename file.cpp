#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream file("wow.txt");
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            cout<<line<<endl;
        }
        
    }
    file.close();
    return 0;
}