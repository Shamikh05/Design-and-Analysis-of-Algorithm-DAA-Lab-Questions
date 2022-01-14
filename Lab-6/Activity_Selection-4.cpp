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

        cout << "Enter the id, starting time, ending time of all activities :" << endl;

        for(int i=0;i<n;i++) {

                char ch;
                cin >> ch >> v[i][1] >> v[i][2];

                v[i][0] = int(ch);
                v[i][3] = v[i][2] - v[i][1];
        }

        sort(v.begin(),v.end(),comp);

        int k = 1;
        while (k<n) {

                if(v[k][1]==v[k-1][1]) {
                        v.erase(v.begin()+k-1);
                        k--;
                        n--;
                }
                k++;
        }

        int i = 0;
        int j = 1;

        int ans = v[0][2] - v[0][1];

        cout << "Acticities selected are : " << char(v[0][0]);

        while(j<n) {

                if(v[i][2] <= v[j][1]) {
                        cout << "," << char(v[j][0]);
                        ans += v[j][2] - v[j][1];
                        i = j;
                        j++;
                }
                else {
                        j++;
                }
        }

        cout << endl;

        cout << "\nMaximum sum of interval is : " << ans << endl;

        return 0;
}
