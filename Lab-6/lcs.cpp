#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int compute_lcs(string str1, string str2, int i, int j, vector<vector<int> > &dp) {

        if(i==0 or j==0) {
                return 0;
        }

        if(dp[i][j]!=-1) {
                return dp[i][j];
        }

        if(str1[i-1]==str2[j-1]) {
                return dp[i][j] = 1 + compute_lcs(str1,str2,i-1,j-1,dp);
        }

        return dp[i][j] = max(compute_lcs(str1,str2,i-1,j,dp), compute_lcs(str1,str2,i,j-1,dp));
}

int main() {

        string s1, s2;

        cout << "Enter the string 1 : ";
        getline(cin,s1);

        cout << "Enter the string 2 : ";
        getline(cin,s2);

        int n1 = s1.length();
        int n2 = s2.length();

        vector<vector<int> > dp(1001, vector<int>(1001,-1));

        int result = compute_lcs(s1,s2,n1,n2,dp);

        cout << "Length of longest common subsequence is : " << result << endl;

        return 0;
}
