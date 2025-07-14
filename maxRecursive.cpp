#include<iostream>
#include<climits>

using namespace std;

int Max(int arr[], int p, int r);

int Max(int arr[], int p, int r)
{
	int max = INT_MIN;
	if(p == r)
		return arr[p];
	else if(p < r)
	{
		int mid = (p+r)/2;
		int max1 = Max(arr, p, mid);
		int max2 = Max(arr, mid+1, r);
		max = (max1>max2) ? max1 : max2;
	}
	return max;
}

void main()
{
	int arr[] = {10, 40, 30, 50, 20};

	cout << "Max:: " << Max(arr, 0, 4) << endl;
}
