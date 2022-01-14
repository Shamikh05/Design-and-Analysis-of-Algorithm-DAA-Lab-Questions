#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int,int> start, pair<int,int> end) {
        return start.second < end.second;
}

int main () {

        int n;
        cout << "Enter the number of activities : ";
        cin >> n;

        vector<pair<int,int> > v(n);

        cout << "Enter the starting times of all activities :" << endl;

        for(int i=0;i<n;i++) {
                cin >> v[i].first;
        }

        cout << "Enter the ending times of all activities :" << endl;

        for(int i=0;i<n;i++) {
                cin >> v[i].second;
        }

        sort(v.begin(),v.end(),comp);

        int i = 0;
        int j = 1;

        int ans = 1;

        while(j<n) {

                if(v[i].second < v[j].first) {
                        ans++;
                        i = j;
                        j++;
                }
                else {
                        j++;
                }
        }

        cout << "The maximum activities that can be executed is : " << ans << endl;

        return 0;
}
