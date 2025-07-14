#include<iostream>
using namespace std;

#define MAX_NO_OF_MATRICES 10

int M[MAX_NO_OF_MATRICES][MAX_NO_OF_MATRICES];
int S[MAX_NO_OF_MATRICES][MAX_NO_OF_MATRICES];

/*
d[] is the array if matrix dimensions
*/
void find_mcm_order(int d[], int no_of_matrices)
{
	for(int i=0; i<=no_of_matrices; i++)
		for(int j=0; j<=no_of_matrices; j++)
			M[i][j] = 0;

	for(int len=2; len<=no_of_matrices; len++)
	{
		for(int i=1; i<=no_of_matrices-len+1; i++)
		{
			int j = i+len-1;
			M[i][j] = INT_MAX;

			for(int k=i; k<=j-1; k++)
			{
				int q = M[i][k] + M[k+1][j] + d[i-1]*d[k]*d[j];
				if(q < M[i][j])
				{
					M[i][j] = q;
					S[i][j] = k;
				}
			}
		}
	}
}

void print_mcm_order(int i, int j)
{
	if(i==j)
		cout << "A" << i;
	else
	{
		cout << "(";
		print_mcm_order(i, S[i][j]);
		print_mcm_order(S[i][j]+1, j);
		cout << ")";
	}
}

int main()
{
	int d[MAX_NO_OF_MATRICES], no_of_matrices, num;

	puts("Enter number of matrices");
	cin >> no_of_matrices;

	puts("Enter matrix dimensions");
	for(int i=0; i<=no_of_matrices; i++)
		cin >> d[i];

	find_mcm_order(d, no_of_matrices);
	for(int i=0; i<=no_of_matrices; i++)
	{
		for(int j=0; j<=no_of_matrices; j++)
		{
			cout << M[i][j] << " ";
		}
		cout << endl;
	}

	print_mcm_order(1, no_of_matrices);

	return 0;
}
