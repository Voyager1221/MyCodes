// #include <iostream>
// #include <vector>
// using namespace std;

// int partitionIndex(vector<int> &vec_pi, int low, int high){
//     int tv = vec_pi[(low+high)/2];
//     vec_pi[(low+high)/2] = vec_pi[high];
//     vec_pi[high] = tv;
//     cout<<"vecpi[mid]: "<<vec_pi[(low+high)/2]<<endl;
//     cout<<"vecpi[high]:"<<vec_pi[high]<<endl;
//     int pivot_element = vec_pi[high];
//     int x = low-1;
//     for(int y=low; y<high; y++){    
//         if(vec_pi[y]>pivot_element){
//             x++;
//             cout<<"\nValuers of vec_pi[y]: "<<vec_pi[y]<<endl;
//             cout<<"\nValue of pivot_element: "<<pivot_element<<endl;
//             int temp = vec_pi[y];
//             vec_pi[y] = vec_pi[x];
//             vec_pi[x] = temp;
//         }
//     }
//     int t = vec_pi[x+1];
//     vec_pi[x+1] = vec_pi[high];
//     vec_pi[high] = t;

//     return x+1;
// }

// void quickSort(vector<int> &vec, int low, int high){
//     if(low<high){
//         int p_index = partitionIndex(vec, low, high);
//         quickSort(vec, low, p_index-1);
//         quickSort(vec, p_index+1, high);
//     }
// }

// int checkEnergy(vector<int> &vec){
//     int flag=1;
//     long long cnt=0;
//     while(flag!=0){
//         for(int i=0; i<vec.size(); i++){
//             if(vec[i]>=0){
//                 cnt++;
//                 vec[i] = vec[i]-1;
//             }else{
//                 flag=0;
//                 break;
//             }
//         }
//     }
//     return cnt;
// }

// void solve(){
//     int N;
//     cin>>N;
//     vector<int> vec;
//     for(int i=0; i<N; i++){
//         int num;
//         cin>>num;
//         vec.push_back(num);
//     }
//     quickSort(vec, 0, vec.size()-1);
//     cout<<"Printin the vec: "<<endl;
//     for(int i: vec){
//         cout<<vec[i]<<" ";
//     }
//     cout<<endl;
//     //cout<<"The ans is : "<<checkEnergy(vec)<<endl;
//     //cout<<"\nSize of vec is: "<<vec.size()<<endl;
// }

// int main() {
// 	// your code goes here
// 	int T;
// 	cin>>T;
// 	while(T--){
// 	    solve();
// 	}
// 	return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int checkEnergy(vector<int> &vec){
    int flag=1;
    long long cnt=0;
    while(flag!=0){
        for(int i=0; i<vec.size(); i++){
            if(vec[i]>=0){
                cnt++;
                vec[i] = vec[i]-1;
            }else{
                flag=0;
                break;
            }
        }
    }
    return cnt;
}

void solve(){
    int N;
    cin>>N;
    vector<int> vec;
    for(int i=0; i<N; i++){
        int num;
        cin>>num;
        vec.push_back(num);
    }
    int l = vec.size();
    sort(vec, vec + l);
    cout<<"Printin the vec: "<<endl;
    for(int i: vec){
        cout<<vec[i]<<" ";
    }
     cout<<endl;
}

int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--){
	    solve();
	}
	return 0;
}
