#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int dp[100][100];

int compute_mcm(int* p, int i, int j) {
        if (i==j) {
                return 0;
        }
        if (dp[i][j] != -1) {
                return dp[i][j];
        }

        dp[i][j] = INT_MAX;

        for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], compute_mcm(p,i,k) + compute_mcm(p,k+1,j) + p[i-1]*p[k]*p[j]);
        }
        return dp[i][j];
}

int MatrixChainOrder(int* p, int n){
        int i = 1, j = n - 1;
        return compute_mcm(p, i, j);
}

int main() {

        int n;
        cin >> n;

        int arr[n];

        for(int i=0;i<n;i++) {
                cin >> arr[i];
        }

        memset(dp, -1, sizeof dp);

        cout << "Minimum number of multiplications required is : " << MatrixChainOrder(arr, n);

        for(int i=0;i<n;i++) {

                for(int j=0;j<n;j++) {
                        cout << dp[i][j] << " ";
                }
                cout << endl;
        }

        return 0;
}
