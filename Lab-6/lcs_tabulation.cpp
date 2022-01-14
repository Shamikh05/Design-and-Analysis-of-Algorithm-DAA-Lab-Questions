#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {

        string s1, s2;

        cout << "Enter the string 1 : ";
        getline(cin,s1);

        cout << "Enter the string 2 : ";
        getline(cin,s2);

        int n1 = s1.length();
        int n2 = s2.length();

        vector<vector<int> >dp(n1+1,vector<int>(n2+1,0));

        for(int i=1;i<=n1;i++) {

            for(int j=1;j<=n2;j++) {

                if(s1[i-1]==s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        for(int i=0;i<=n1;i++) {

            for(int j=0;j<=n2;j++) {

                cout << dp[i][j] << " ";
            }

            cout << endl;
        }

        cout << "Length of longest common subsequence is : " << dp[n1][n2] << endl;

        return 0;
}
