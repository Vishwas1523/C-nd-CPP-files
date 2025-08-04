#include <iostream>
using namespace std;
class testing{
    int abb;
    public:
    testing & set(){
        abb = 65;
        return *this;
    }
    testing & get(){
        cout<<abb;
        return *this;
    }
    void wow(string s){
        cout<<endl<<s;
    }
};
int main(){
testing obj1;
obj1.set().get().wow("Vishwas Mahan hai!");
return 0;
}