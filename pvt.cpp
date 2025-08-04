#include <iostream>
using namespace std;
class pvtltd
{
private:
    int p = 9, r = 9, i = 10, v = 56, a = 90, t = 89, e = 71;
public:
friend int print(const pvtltd & obj){
    cout<<obj.p<<endl
    <<obj.v;
}
};
int main()
{
    pvtltd obj1;
    print(obj1);
    return 0;
}