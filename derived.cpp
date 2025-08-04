#include <iostream>
using namespace std;
class base{
    public:
    base(int){}
    void getdata(){}
};
class derived: public base{
    public:
    derived (int a) : base(a){}
    void setdata(){}
};
int main(){
derived obj(5);
return 0;
}