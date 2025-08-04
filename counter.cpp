#include <iostream>
using namespace std;
class counter{
private:
static int count;
public:
counter(){
    cout<<"the number of object is "<<++count<<endl;
}
};
int counter:: count = 0;
int main(){
counter ab, ac;
ab;
ac;
return 0;
}