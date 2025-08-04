#include <iostream>
using namespace std;

class B; 
class A {
private:
    int a;

public:
    A(int val) { a = val; }

    friend int add(A obj1, B obj2); 
};

class B {
private:
    int b;

public:
    B(int val) { b = val; }

    friend int add(A obj1, B obj2);  
};


int add(A obj1, B obj2) {
    return obj1.a + obj2.b;  
}

int main() {
    A a(10);
    B b(20);

    cout << "Sum = " << add(a, b) << endl;  
    return 0;
}
