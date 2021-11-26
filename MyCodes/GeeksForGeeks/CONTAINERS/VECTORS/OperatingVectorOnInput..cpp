#include <iostream>
#include <vector>

const int MIN = -2147483648 + 2;
const int MX = 1e5 +5;
using namespace std;

vector<int> vec(MX);

int partitionArray(int low, int high, char ch){

    int tv = vec[int(low+high)/2];
    vec[int(low+high)/2] = vec[high];
    vec[high] = tv;

    int pivot_element = vec[high];
    int x = low-1;
    for(int y=0; y<high; y++){
        if(ch=='b'){
            if(vec[y]< pivot_element){
                x++;

                int temp = vec[x];
                vec[x] = vec[y];
                vec[y] = temp;
            }
        }
        if(ch=='f'){
            if(vec[y] > pivot_element){
                x++;

                int temp = vec[x];
                vec[x] = vec[y];
                vec[y] = temp;
            }
        }
    }
    int t = vec[x+1];
    vec[x+1] = vec[high];
    vec[high] = t;
    return x+1;
}

void quickSort(int low, int high, char ch){
    if(low<high){
        int partition = partitionArray(low, high, ch);
        quickSort(low, partition-1, ch);
        quickSort(partition+1, high, ch);
    }
}

void switchFunc(char ch, int num){
    switch(ch){
    
        case 'a':
        {
                    vec.push_back(num);
                    break;
        }       
        case 'b':
        {
                    quickSort(0, vec.size()-1, 'b');
                    break;                 
        }
        case 'c':
        {
                    vector<int> rvec(vec.size(), 0);
                    for(auto itr = vec.begin(); itr!=vec.end(); itr++){
                        rvec.push_back(*itr);        
                    }
                    vec = rvec;
                    break;
        }
        case 'd':
        {
                    cout<<vec.size()<<endl;
                    break;
        }
        case 'e':
        {
                    for(auto itr = vec.begin(); itr!=vec.end(); itr++){
                    cout<<*itr<<" ";
                    }
                    cout<<endl;
                    break;            
        }
        case 'f':
        {
                    quickSort(0, vec.size()-1, 'f');
                    break;                 
        }
        default:
                    cout<<"\nPls Enter valid options"<<endl;
        }

}

void solve(){
    int Q;
    cin>>Q;
    char arr[Q];
    for(int i=0; i<Q; i++){
        char ch;
        cin>>ch;
        arr[i] = ch;
    }

    for(int i=0; i<Q; i++){
        if(arr[i]=='a'){
            switchFunc('a', int(arr[i+1]));
            i = i+1;
        }else {
            switchFunc(arr[i], MIN);
        }
    }

}


int main(){

    int T;
    cin>>T;
    while(T--){
        //vector<int> vec;
        solve();
    }
    return 0;
}