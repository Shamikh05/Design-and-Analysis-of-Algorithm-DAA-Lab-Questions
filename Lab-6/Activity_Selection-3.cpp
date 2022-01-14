#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool comp(vector<int> start, vector<int> end) {
        return start[2] < end[2];
}

int main () {

        int n;
        cout << "Enter the number of activities : ";
        cin >> n;

        vector<vector<int> > v(n,vector<int>(4,0));

        int m = INT_MAX;

        cout << "Enter the id, starting time, ending time of all activities :" << endl;

        for(int i=0;i<n;i++) {

                char ch;
                cin >> ch >> v[i][1] >> v[i][2];

                v[i][0] = int(ch);
                v[i][3] = v[i][2] - v[i][1];

                m = min(m,v[i][3]);
        }

        sort(v.begin(),v.end(),comp);

        int i = 0;
        int j = 1;

        int ans = 1;

        cout << char(v[0][0]);

        while(j<n) {

                if( (v[i][2] < v[j][1]) && (v[j][3] != m) ) {
                        cout << "," << char(v[j][0]);
                        ans++;
                        i = j;
                        j++;
                }
                else {
                        j++;
                }
        }

        cout << "\nThe maximum activities that can be selected is : " << ans << endl;

        return 0;
}
