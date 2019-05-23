#include <bits/stdc++.h>
using namespace std;
template <typename T>
T lowerBound(T arr[], T key, int size){
    int lb = 0;
    int ub = size -1;
    T element = arr[size-1];
    int mid;
    while(lb<=ub){
        mid = (lb+ub)/2;
        if ( arr[mid] >= key && arr[mid] < element){
            element = arr[mid];
        }
        if (lb == ub){
            return element;
        }
        if (key <= arr[mid]){
            ub = mid - 1;
        }
        else {
            lb = mid + 1;
        }
    }
    return element;
}
int main(){
    int *arr;
    int size;
    int element;
    cout << "enter size: ";
    cin >> size;
    arr = new int[size];
    cout << "\nenter " << size << " elements:";
    for( int i = 0; i < size; i++){
        cin >> arr[i];
    }
    cout << "\nenter key: ";
    cin >> element;
    int key = lowerBound<int>(arr, element, size);
    cout << "\nelement " << key << "\n";
    return 0;
}