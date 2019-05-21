#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Array{
    T *ptr;
    int length;
    public:
        Array(T a[], int len);
        void print();
};

template <typename T>
Array<T>::Array(T a[], int len){
    ptr = new T[len];
    length = len;
    for(int i = 0; i<len; i++){
        ptr[i] = a[i];
    }
}

template <typename T>
void Array<T>::print(){
    cout << "==========Printing array============\n";
    for(int i = 0; i< length; i++){
        cout << ptr[i] <<" ";
    }
    cout << endl;
}

int main(){
    int temp[] = {1,2,3,4,5};
    Array<int> intArray(temp, 5);
    intArray.print();

    char temp2[] = {'a', 'b', 'c', 'd'};
    Array<char> charArray(temp2, 5);
    charArray.print();
    return 0;
}