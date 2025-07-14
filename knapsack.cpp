#include <iostream>
using namespace std;

void knapsack(int W, int wt[], int val[], int n) {
    int k[n + 1][W + 1];


    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                k[i][w] = 0;
            else if (wt[i - 1] <= w)
                k[i][w] = max(val[i - 1] + k[i - 1][w - wt[i - 1]], k[i - 1][w]);
            else
                k[i][w] = k[i - 1][w];
        }
    }

    int result = k[n][W];

    cout<<"Maximum value is: "<<result<<endl;

   int i = n, j = W;
   while(i>0 && j>0){
    if(k[i][j] == k[i-1][j]){
        cout<< i << "= 0"<<endl;
        i--;
    }
    else{
        cout<< i << "= 1"<<endl;
        i--;
        j = j - wt[i];
    }
   }
}



int main() {
    int n;
    int W;


    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the maximum capacity of the knapsack: ";
    cin >> W;

    int val[n], wt[n];

    cout << "Enter the values and weights of each item:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << " - pi: ";
        cin >> val[i];
        cout << "Item " << i + 1 << " - wi: ";
        cin >> wt[i];
    }


    //int result = knapsack(W, wt, val, n);
    //cout << "The maximum is " << result << endl;

    knapsack(W, wt, val, n);

    return 0;
}
