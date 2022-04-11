#include <iostream>

using namespace std;

void BinaryPrinting(int n, int*cnt){
    if(n<=1) return;
    if(n>1){
        (*cnt)++;
        cout<<*cnt<<endl;
    }
    BinaryPrinting(n-1,cnt);
    BinaryPrinting(n-1, cnt);
}

int main(){
    int n=10, cnt=0;
    BinaryPrinting(n, &cnt);
    return 0;
}