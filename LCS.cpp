#include <iostream>
#include <cstring> 

using namespace std;

const int MAX_SIZE = 100; 

int c[MAX_SIZE+1][MAX_SIZE+1]; 
char b[MAX_SIZE+1][MAX_SIZE+1]; 

// compute the length of LCS and store the direction
void lcsLength(const char* X, const char* Y, int m, int n) {
    for (int i = 0; i <= m; i++) {
        c[i][0] = 0;
    }
    for (int j = 0; j <= n; j++) {
        c[0][j] = 0;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i-1] == Y[j-1]) {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 'D'; // Diagonal (copy)
            } else if (c[i-1][j] >= c[i][j-1]) {
                c[i][j] = c[i-1][j];
                b[i][j] = 'U'; // Up (skipY)
            } else {
                c[i][j] = c[i][j-1];
                b[i][j] = 'L'; // Left (skipX)
            }
        }
    }
}

// Function to print LCS
void printLCS(int i, int j, const char* X) {
    if (i == 0 || j == 0) return;
    if (b[i][j] == 'D') {
        printLCS(i-1, j-1, X);
        cout << X[i-1];
    } else if (b[i][j] == 'U') {
        printLCS(i-1, j, X);
    } else {
        printLCS(i, j-1, X);
    }
}

// print the LCS table
void printTable(int m, int n) {
    cout << "LCS Table:\n";
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
}

// print the direction table
void printDirectionTable(int m, int n) {
    cout << "Direction Table:\n";
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    const char X[] = "ABBCAAC";
    const char Y[] = "ACCBCCA";
    int m = strlen(X);
    int n = strlen(Y);

    lcsLength(X, Y, m, n);

    printTable(m, n);
    printDirectionTable(m, n);

    cout << "LCS of " << X << " and " << Y << " is ";
    printLCS(m, n, X);
    cout << endl;

    return 0;
}
