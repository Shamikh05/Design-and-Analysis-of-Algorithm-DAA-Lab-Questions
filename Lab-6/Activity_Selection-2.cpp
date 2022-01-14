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

        vector<vector<int> > v(n,vector<int>(3,0));

        cout << "Enter the id, starting time, ending time of all activities :" << endl;

        for(int i=0;i<n;i++) {

                char ch;
                cin >> ch >> v[i][1] >> v[i][2];

                v[i][0] = int(ch);
        }

        char c;
        cout << "Enter the selected choice activity : ";
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

        int ans = 1;

        while(j<n) {

                if( ( (v[i][2] < v[j][1]) && ( (v[j][2] < start) || (v[j][1] > end) ) ) || v[j][0]==choice ) {
                        ans++;
                        i = j;
                        j++;
                }
                else {
                        j++;
                }
        }

        cout << "The maximum activities that can be selected is : " << ans << endl;

        return 0;
}
