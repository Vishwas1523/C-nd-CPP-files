#include <iostream>
using namespace std;
class student{
private:
    string name;
    int age;
public:
    void get_set_value(string, int);
};
void student:: get_set_value(string s, int i){
cout<<"The name is: "<<s<<endl;
cout<<"The age is: "<<i<<endl;
}
int main(){
    student gadha;
    gadha.get_set_value("Vishwas", 20);
    return 0;
}