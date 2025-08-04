#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class wow{
    private: 
    int a;
    static int count;
    public:
    static int coun2(){
        count = 0;
    }
    wow(){
        cout<<"Enter the value of the private member of object number "
        <<++count<< ":" <<endl;
        cin>>a;
    }
    friend void swapp(wow&, wow&);
    void show();
};
void wow :: show(){
    cout<<"The value of the private member of object number "
        <<++count<< ":" <<endl
    <<a<<endl;
}
void swapp(wow& obj1, wow& obj2){
    int temp = obj1.a;
    obj1.a = obj2.a;
    obj2.a = temp;
}
int wow :: count = 0;
int main(){
wow obj1, obj2;
obj1;
obj2;
wow :: coun2();
obj1.show();
obj2.show();
swapp(obj1, obj2);
cout<<"After swapping the value we get:"<<endl;
wow :: coun2();
obj1.show();
obj2.show();
return 0;
}