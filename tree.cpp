#include <iostream>
using namespace std;
class Tree{
    int value;
    
    public:
    Tree *left = NULL;
    Tree * right = NULL;
    Tree(int a){
        value = a;
        // left = x;
        // right = y;
    }
};
int main(){
Tree obj1(5), obj2(6), obj3(7);
obj1.left = &obj2;
obj1.right = &obj3;
return 0;
}