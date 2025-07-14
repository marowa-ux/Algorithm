#include <iostream>
using namespace std;

void merge(int arr[], int start, int mid, int end) {
    int n1 = mid - start + 1; 
    int n2 = end - mid;

  
    int L[n1+1], R[n2+1];

    
    for (int i = 0; i < n1; i++){
        L[i] = arr[start + i];
    }
        
    for (int j = 0; j < n2; j++){
         R[j] = arr[mid + 1 + j];
    }
       
    int i = 0, j = 0, k;

for ( k = start; k <= end; k++) {
    if ( L[i] <= R[j]) {
        arr[k] = L[i];
        i++;
    } else if (j < n2) {
        arr[k] = R[j];
        j++;
    }
}

}

void mergeSort(int arr[], int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2; 
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

int main() {
    int arr[] = {2, 7, 6, 4, 3, 5, 1};
    int n = sizeof(arr) / sizeof(int);
    cout<<n<<endl;

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
        
    cout << endl;

    return 0;
}
