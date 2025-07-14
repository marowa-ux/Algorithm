#include<iostream>
using namespace std;


void countSort(int arr[], int n, int k){
    int *B = new int[n];  
    int *C = new int[k+1];
    
    for (int i = 0; i <= k; ++i) {
        C[i] = 0;
    }

    
     for (int j = 0; j < n; ++j) {
        C[arr[j]]++;
    }
  
    for (int i = 1; i <= k; ++i) {
        C[i] += C[i - 1];
    }
  
    for (int j = n - 1; j >= 0; --j) {
        B[C[arr[j]] - 1] = arr[j];
        C[arr[j]]--;
    }

    for (int i = 0; i < n; ++i) {
        arr[i] = B[i];
    }

 

}
void binarySearch(int arr[], int f_index, int l_index, int item, int &position) {  
    while (f_index <= l_index) {
        int m_index = (f_index + l_index) / 2;
        if (item < arr[m_index]) {
            l_index = m_index - 1;
        } else if (item > arr[m_index]) {
            f_index = m_index + 1;
        } else {
            position = m_index;
            break;
        }
    }
}

int main() {
    int arr[] = {1, 4, 1, 2, 7, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    countSort(arr, n, 8);

   for(int i= 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    int position = -1; 
    int item;
    cout<<"Enter the item you want search: ";
    cin>>item;

    binarySearch(arr, 0, n - 1, item, position);

    if (position != -1) {
        cout << "Found " << item << " at index " << position << endl;
    } else {
        cout << "Not Found" << endl;
    }
   

    return 0;
}