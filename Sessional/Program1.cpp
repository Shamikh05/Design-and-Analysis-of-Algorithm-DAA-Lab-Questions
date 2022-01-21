#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool comp(vector<int> a, vector<int> b) {
        return a[2] < b[2];
}

int main () {

        int n;
        cout << "Enter the number of activities : ";
        cin >> n;

        vector<vector<int> > v(n,vector<int>(3,0));

        cout << "Enter the id, starting time, ending time of all activities :" << endl;

        for(int i=0;i<n;i++) {

                char ch;
                cin >> ch >> v[i][1] >> v[i][2];

                v[i][0] = int(ch);
        }

        char c;
        cout << "Enter the activity of your choice : ";
        cin >> c;

        int choice = int(c);
        int start;
        int end;

        for(int i=0;i<n;i++) {
                if(v[i][0]==choice) {
                        start = v[i][1];
                        end = v[i][2];
                }
        }

        sort(v.begin(),v.end(),comp);

        int i = 0;
        int j = 1;

        int result = 1;

        cout << "Activities Selected : " << char(v[0][0]);

        while(j<n) {

                if( ( (v[i][2] <= v[j][1]) && ( (v[j][2] <= start) || (v[j][1] >= end) ) ) || v[j][0]==choice ) {

                        cout << ", " << char(v[j][0]);
                        result++;
                        i = j;
                        j++;
                }
                else {
                        j++;
                }
        }

        cout << "\nMaximum number of activities that can be selected is : " << result << endl;

        return 0;
}
