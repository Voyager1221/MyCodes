#include <iostream>
#include <vector>
using namespace std;

// Reversing the original array implicitly
void swap(vector<int>&vec, int l, int r){
    int temp = vec[l];
    vec[l] = vec[r];
    vec[r] = temp;
}

// Using Double Pointer 
void reverseTheArray_inPlace(vector<int>&vec, int l, int r){
    // Base Condition
    if(l>=r){
        return ;
    }
    swap(vec, l, r);
    reverseTheArray_inPlace(vec, l+1, r-1);
}

// Using Single Pointer
void reverseTheArray_inPlace_singlePointer(vector<int>&vec, int index, int n){
    // Base Condition
    if(index>=(n/2)){
        return;
    }
    swap(vec, index, n-1-index);
    reverseTheArray_inPlace_singlePointer(vec, index+1, n);
}




// Explicitly reversing the array
vector<int>* reverseTheArray(int index, int n, vector<int>&vec){
    vector<int>*temp = new vector<int>;
    
    // Base condition
    if(index == n){
        return temp;
    }
    temp = reverseTheArray(index+1, n, vec);
    (*temp).push_back(vec[index]);
    return temp;
}

int main(){

    int n;
    cout<<"Enter the size of array: "<<endl;
    cin>>n;

    vector<int>vec(n);

    cout<<"Enter the elements of array: "<<endl;
    for(int i=0; i<n; i++){
        
        cin>>vec[i];
    
    }
    vector<int>*res = reverseTheArray(0, n, vec);
    cout<<"Printing the array reversed explicitly."<<endl;
    for(int i=0; i<n; i++){
        cout<<(*res)[i]<<" ";
    }
    cout<<endl;

    reverseTheArray_inPlace(vec, 0, n-1);

    cout<<"Printing the array reversed in-place. Using Double Pointer."<<endl;
    for(int i=0; i<n; i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;

    reverseTheArray_inPlace_singlePointer(vec, 0, n);
   cout<<"Printing the array reversed in-place. Using Single Pointer. Here we are reversing the reversed array."<<endl;
    for(int i=0; i<n; i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;



    return 0;
}