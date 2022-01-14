#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool comp(vector<int> a, vector<int> b) {
        return  a[2] > b[2];
}

int main() {

        int n;

        cout << "Enter number of items : ";
        cin >> n;

        vector<int> value(n), weight(n);

        for(int i=0;i<n;i++) {
                cout << "Enter value and weight of item - " << i+1 << " : ";
                cin >> value[i] >> weight[i];
        }

        int w;
        cout << "Enter the knapsack capacity : ";
        cin >> w;

        vector<vector<int> > v(n,vector<int>(3,0));

        for(int i=0;i<n;i++) {
                v[i][0] = value[i];
                v[i][1] = weight[i];
                v[i][2] = value[i]/weight[i];
        }

        sort(v.begin(),v.end(),comp);

        //long long int result = 0;

        for(int i=0;i<n;i++) {
                cout << v[i][0] << " " << v[i][1] << " " << v[i][2] << endl;
        }

        //cout << "Maximum Value : " << result << endl;

        return 0;

}
