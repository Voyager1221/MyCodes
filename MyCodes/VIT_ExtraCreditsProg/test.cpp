#include <iostream>
using namespace std;

int main(){
    int a=3, b=4, *p, *q;
    cout<< a << " " << b << endl;
    p = &a;
    q = &b;

    cout << "p : " << *(p) << " q : " << *(q) << endl;
    *p = *p + *q;
    *q = *p - *q;
    *p = *p - *q;
    cout << "p : " << *(p) << " q : " << *(q) << endl;

    cout<<"\nParsing Char to Integer"<<endl;
    char ch = 1;
    cout<<int(ch)<<endl;
    cout<<int(ch)*4<<endl;
    return 0;
}