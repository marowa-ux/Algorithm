#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int dine[7] = {1, 2, 5, 10, 20, 50, 100};
    int v = 34;

    vector<int>iteam;

    for (int i = 6; i >= 0; i--) {
        while (v >= dine[i]) {
            v = v - dine[i];
            iteam.push_back(dine[i]);
        }
    }

    for(int i = 0; i<iteam.size(); i++){
        cout<<iteam[i]<<" ";
    }
}
