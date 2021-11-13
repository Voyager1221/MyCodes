/*
Program No.3

* Write a class template for sorting of array of integer 
  or float or character data type elements. 
* Define the class functions outside the class. 
* Use any sorting method. 
* Use the same class structure given below.

    #include <iostream>
    #include <vector>
    using namespace std;
    template <typename T>
    class MyBubbleSort{
        T arr[20];
        int size;
        
    public: 
        MyBubbleSort(int size); //constructor
        void sort(); //sorting method
        void readArray(); //this function will read array
        void printArray(); //this function will print array    
    };

    //Define class member functions here

    int main() //driver main function
    {
        MyBubbleSort <int> b1(10);
        cout<<"\nEnter 10 elements:";
        b1.readArray();
        b1.BubbleSort();
        cout<<"\n The sorted array is \n";
        b1.printArray();
        return 0;
    }

*/

#include <iostream>
#include <vector>

using namespace std;

template <class T>   //Making the class generic
class MyBubbleSort{
    T arr[20];      //Creating a generic array
    int size;

    public:

        MyBubbleSort(int size){ //Constructor, to store the size of array
            this->size = size;
        }    
        //Declaring the functions
        void sort();
        void readArray();
        void printArray();

};

//Defining all the member function of the class MyBubbleSort
template <class T>    //Making template function
void MyBubbleSort<T>::sort(){
    int temp_size = this->size;  //Storing array size in variable
    T* temp_arr = this->arr;    //Storing array's base address in variable
 
    //Performing Bubble Sort
 /*    
    for(int i=0; i<this->size; i++){
        for(int j =0; j<this->size-1; j++){
            if(this->arr[j]>this->arr[j+1]){
                int temp = temp_arr[j];
                temp_arr[j] = temp_arr[j+1];
                temp_arr[j+1] = temp;
            }
        }
    }       
*/

    for(int i=0; i<temp_size; i++){
        for(int j =0; j<temp_size-1; j++){
            if(temp_arr[j]>temp_arr[j+1]){    
                int temp = temp_arr[j];
                temp_arr[j] = temp_arr[j+1];
                temp_arr[j+1] = temp;
            }
        }
    }        
}

template <class T>
void MyBubbleSort<T>::readArray(){ //Taking array input from the user
    for(int i=0; i<this->size; i++){
        cin>>this->arr[i];
    }
}


template <class T>
void MyBubbleSort<T>::printArray(){ //Printing the sorted array
    cout<<"\n";
    for(int i=0; i<this->size; i++){
        cout<<this->arr[i]<<" ";    
    }
}

int main(){
    int n;
    cout<<"\nEnter the length of array : ";
    cin>>n; //Taking the length of array

    MyBubbleSort <int> b1(n);  //object creation, also passing the datatype
    cout<<"\nEnter "<<n<<" elements : "<<endl;
    b1.readArray();
    b1.sort();
    cout<<"\nThe sorted array is \n";
    b1.printArray();

    MyBubbleSort <float> b2(n);
    cout<<"\n\nEnter "<<n<<" elements : "<<endl;
    b2.readArray();
    b2.sort();
    cout<<"\nThe sorted array is \n";
    b2.printArray();

    return 0;     
}