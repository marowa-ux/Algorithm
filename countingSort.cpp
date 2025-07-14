#include<iostream>
using namespace std;

void printArry(int arr[], int size){
    for(int i= 0; i<size; i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;
}

void countSort(int arr[], int n, int k){
    int *B = new int[n];  
    int *C = new int[k+1];
    
    for (int i = 0; i <= k; ++i) {
        C[i] = 0;
    }
    //Print Array Intial 0
    cout<<"Print Array as initial value zero: ";
    printArry(C, k);
    
     for (int j = 0; j < n; ++j) {
        C[arr[j]]++;
    }
    //Print Count element
    cout<<"Print Count Array: ";
    printArry(C, n);
    for (int i = 1; i <= k; ++i) {
        C[i] += C[i - 1];
    }
    //Modify the count array
    cout<<"Modify Count Array: ";
    printArry(C, k);
    for (int j = n - 1; j >= 0; --j) {
        B[C[arr[j]] - 1] = arr[j];
        C[arr[j]]--;
    }
    //Build Output array
    cout<<"Final Sorted Array: ";
    printArry(B, n);

}

int main(){

    int arr[] = {1, 4, 1, 2, 7, 5, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    countSort(arr, n, 8);


    return 0;
}