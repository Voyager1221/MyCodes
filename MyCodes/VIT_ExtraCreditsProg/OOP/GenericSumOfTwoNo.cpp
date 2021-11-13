/*
Problem No. 4

* Write a function of sum of two numbers in c++.
* The two number may be two integer or two float
  data type numbers.
* The drive program for this is given below

    #include <iostream>
    #include <vector>
    using namespace std;

    //define template sum() function here

    int main(){
        cout<<"\nThe sum of two int number 11,12 is = "<<sum(11, 12);
        cout<<"\nThe sum of two float number 1.1, 1.2 is = "<<sum(1.1, 1.2);
        return 0;
    }
*/

#include <iostream>
#include <vector>

using namespace std;

template <class T> //Making the function generic
T sum(T x, T y){ 
    return x+y; //Returning the sum
}

int main(){
    //Calling sum function for addition of integers
    cout<<"\nThe sum of two int number 11,12 is : "<<sum(11, 12); 
    
    //Calling sum function for addition of floating nos.
    cout<<"\nThe sum of two float number 1.1, 1.2 is = "<<sum(1.1, 1.2)<<endl;
}