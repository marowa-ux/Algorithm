#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int no_items;
    no_items = 6;
    int price[6] = {6,2,1,8,3,5};
    int weight[6] = {6, 10, 3, 5, 1, 3};
    int  w = 6;
    int wgt = 0;

    float profit = 0.0, remaining;

    float value_per_weight[6];

    vector <pair <float, pair<int, int>>> itemTable;

    for(int i = 0; i<no_items; i++){
        value_per_weight[i] = (float)price[i]/weight[i];

        itemTable.push_back(make_pair(value_per_weight[i], make_pair(price[i], weight[i])));
    }

    cout<<"vi/wi \t\t Price \t\t Weight\n";
    cout<<"------\t\t-------\t\t------\n";

    for(int i = 0; i<no_items; i++){
        cout<<itemTable[i].first<<"\t\t"<<itemTable[i].second.first<<"\t\t"<<itemTable[i].second.second<<endl;
    }

    sort(itemTable.begin(), itemTable.end());

    cout<<"SORTED-------\n\n";
    cout<<"vi/wi \t\t Price \t\t Weight\n";
    cout<<"------\t\t-------\t\t------\n";

    for(int i = 5; i>=0; i--){
        cout<<itemTable[i].first<<"\t\t"<<itemTable[i].second.first<<"\t\t"<<itemTable[i].second.second<<endl;
    }



    for (int i = 5; i >= 0; i--) {
        if ( wgt + itemTable[i].second.second <= w) {
            wgt = wgt + itemTable[i].second.second;
            profit = profit + itemTable[i].second.first;
        } else {
            remaining = w - wgt;
            float perWi = itemTable[i].second.first/itemTable[i].second.second;
            profit = profit + remaining*(perWi);
        
            break;
        }
    }

     cout << "Maximum profit: " << profit << endl;

}