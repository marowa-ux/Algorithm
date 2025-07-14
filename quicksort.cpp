#include<iostream>
using namespace std;

 int Partition(int arr[], int lb, int ub){
    int pivot = arr[lb];
    int start = lb;
    int end = ub;

    while(start<end){
        while(arr[start] <= pivot){
            start++;
        }
        while(arr[end]>pivot){
            end--;
        }
        if(start<end){
            swap(arr[start], arr[end]);
        }
    }
    swap(arr[lb], arr[end]);

    return end;
}

void quickSort(int arr[], int lb, int ub){
    if(lb<ub){
        int pivot = Partition(arr, lb, ub);
        quickSort(arr, lb, pivot - 1);
        quickSort(arr, pivot+1, ub);

    }
}

int main(){

    int arr[] = {2, 7, 6, 4, 3, -5, 1};
    int n = sizeof(arr) / sizeof(int);
    cout<<n<<endl;

    quickSort(arr, 0, n-1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
        
    cout << endl;

}