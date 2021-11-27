#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const int MX = 1e5 +5;

//Quick SOrt using mid value as pivot
int partitionIndex(vector<int> &vec_pi, int low, int high, string ch){
    int tv = vec_pi[(low+high)/2];
    vec_pi[(low+high)/2] = vec_pi[high];
    vec_pi[high] = tv;

    int pivot_element = vec_pi[high];
    int x = low-1;
    for(int y=low; y<high; y++){
        if(!ch.compare("b")){
            if(vec_pi[y]<pivot_element){
                x++;

                int temp = vec_pi[y];
                vec_pi[y] = vec_pi[x];
                vec_pi[x] = temp;
            }
        }
        if(!ch.compare("f")){
            if(vec_pi[y]>pivot_element){
                x++;

                int temp = vec_pi[y];
                vec_pi[y] = vec_pi[x];
                vec_pi[x] = temp;
            }
        }

    }
    int t = vec_pi[x+1];
    vec_pi[x+1] = vec_pi[high];
    vec_pi[high] = t;

    return x+1;
}

void quickSort(vector<int> &vec, int low, int high, string ch){
    if(low<high){
        int p_index = partitionIndex(vec, low, high, ch);
        quickSort(vec, low, p_index-1, ch);
        quickSort(vec, p_index+1, high, ch);
    }
}

void switchFunc(vector<int> &vec, string ch){
    switch(ch[0]){
        case 'b':{
            cout<<"\nDoing quickSort in ascending order."<<endl;
            quickSort(vec, 0, vec.size()-1, ch);           
            break;
        }

        case 'c':{
                    cout<<"\nReversing the vector elements."<<endl;
                    vector<int> rvec(vec.size());
                    int i=0;
                    for(auto itr = vec.rbegin(); itr!=vec.rend(); itr++){
                        
                        rvec[i] = *itr;
                        i++;        
                    }
                    vec = rvec;
                    break;
        }
        
        case 'd':{
            cout<<"\nPrinting the size of vector."<<endl;
            cout<<vec.size()<<endl;
            break;
        }
        
        case 'e':{
            cout<<"\nPrinting the vector."<<endl;
            for(auto itr = vec.begin(); itr!=vec.end(); itr++){
                    cout<<*itr<<" ";
            }
            cout<<"\n"<<endl;
            break;
        }
        
        case 'f':{
            cout<<"\nSortingthe vector elements in descending order."<<endl;
            quickSort(vec, 0, vec.size()-1, ch); 
            break;
        }

        default:{
            cout<<"\nPls enter valid choice."<<endl;
        }
    }
}

void solve(){
    int Q;
    cin>>Q;
    string arr[2*Q];
    string in[2*Q];
    //string s;
    int temp = Q;
    vector<int> vec;
    string prev="";
    for(int i=0; i<temp; i++){
        string s;
        if(!prev.compare("a")){
            int num;
            cin>>num;
            vec.push_back(num);
            temp +=1;
            s = to_string(num);
        } else{ 
            cin>>s;
            arr[i] = s;
        }
        in[i] = s;
        prev = s;
        // cout<<"\nThe value of s is :"<<s<<endl;
    }
    // std::cout<<"\nThe value of updated temp is: "<<temp<<std::endl;
    // std::cout<<"\nPrinting out arr of choices: "<<std::endl;
    // for(int i=0; i<temp; i++){
    //     std::cout<<arr[i]<<" ";
    // }

    // std::cout<<"\nPrinting in:"<<endl;
    // for(int i=0; i<temp; i++){
    //     cout<<in[i]<<" ";
    // }

    // cout<<"\nPrinting the vector:"<<endl;
    // for(auto i=vec.begin(); i!=vec.end(); i++){
    //     cout<<*i<<" ";
    // }
    for(int i=0; i<temp; i++){
        cout<<"\n"<< arr[i];
        if(!arr[i].compare("a")){
            i +=1 ;
        }else{
            switchFunc(vec, arr[i]);
            }
    }
}

int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }

    //  vector<int> vec({13,2,63,41,598,16,7});
    //  quickSort(vec,0,vec.size()-1, "b");
    // for(auto i:vec){
    //      cout<<i<<" ";
    //  }
    // cout<<"\nPrinting with iterator."<<endl;
    // for(vector<int>::iterator itr= vec.begin(); itr!=vec.end(); itr++){
    //     cout<<*itr<<" ";
    // }
    // cout<<vec[3]<<endl;
    return 0;
}