#include <iostream>
using namespace std;
class box{
    private:
    int length, width, height;
    public:
    box(int, int , int);
    friend int volume(const box& obj);
};
box::box(int a, int b, int c){
    length = a;
    width = b;
    height = c;
}
int volume(const box& obj){
 return obj.length*obj.width*obj.height;
}
int main(){
box obj1(4,1,8);
cout<<volume(obj1);
return 0;
}