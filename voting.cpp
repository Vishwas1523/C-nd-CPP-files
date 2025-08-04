#include <iostream>
using namespace std;
class voting
{
private:
    int age;

public:
    voting()
    {
        cout << "Enter you age:" << endl;
        cin >> age;
    }
    friend bool canyou(voting &);
};
bool canyou(voting &obj) { return obj.age >= 18; }
int main()
{
    voting obj1;
    obj1;
    if (canyou(obj1))
        cout << "You can vote!";
    else
        cout << "You cannot vote!";
    return 0;
}